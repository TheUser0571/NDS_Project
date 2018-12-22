/*
 * Graphics.c
 *
 *  Created on: Nov 3, 2018
 *      Author: nds
 */
#include "Graphics.h"
#include "clouds.h"
#include "Balcony2.h"
#include "Building2.h"
#include "NyanCat1.h"
#include "NyanCat2.h"
#include "NyanCat3.h"
#include <nds.h>

#define SIMULATION

#define PROBABILITY 0.8 //porbability of obstacle
#define TILE_OFFSET 16 //offset for tile memory
#define WALL_PAL (0xa<<12) //palette for buildings
#define OBST_PAL (0xe<<12) //palette for obstacles
#define WALL_PAL_OFFSET 0xa0
#define OBST_PAL_OFFSET 0xe0
//initial background shift and sprite position
int bg_shift_main = 511, bg_shift_back = 511,
		x_pos_sprite = 32, y_pos_sprite = 144;
//sprite starts on left side
int inc = 1;
bool jump = false;
int cat_rot = 1;
//initial graphic to display for graphic
int cat_state=1;
//map pointers
u16* mainMap, *backMap, *obstMap;
//tiles pointers
u16* backTiles, *mainTiles, *obstTiles;
//sprite graphics pointers
u16* gfx1=NULL, *gfx2=NULL, *gfx3=NULL, *gfx_active=NULL;
int gfx_cnt=0;
double obst_cnt =0;
//definition of tile numbers
enum TileNum{Transp, Floor, Gray};

enum ObstTiles{EMPTY, BALCONY};
//definition of obstacle types
enum OBSTACLE_TYPE{NO_OBST, LEFT_OBST, RIGHT_OBST};

//cutom tiles
u8 FullTileTransp[32]={0,0,0,0,
					   0,0,0,0,
					   0,0,0,0,
					   0,0,0,0,
					   0,0,0,0,
					   0,0,0,0,
					   0,0,0,0,
					   0,0,0,0,};

void graphics_build(enum OBSTACLE_TYPE obstacle, int row, int index);

void graphics_init(void){
	bg_shift_main = 511;
	bg_shift_back = 511;
	x_pos_sprite = 32;
	y_pos_sprite = 144;
	inc = 1;
	cat_state=1;
	jump = false;
	cat_rot = 1;
	gfx_cnt=0;
	obst_cnt =0;
	//Enable VRAM A
	VRAM_A_CR = VRAM_ENABLE| VRAM_A_MAIN_BG;
	//VRAM B for sprite
	VRAM_B_CR = VRAM_ENABLE|VRAM_B_MAIN_SPRITE_0x06400000;

	//Set mode and background
	REG_DISPCNT = MODE_3_2D|DISPLAY_BG0_ACTIVE|DISPLAY_BG1_ACTIVE|DISPLAY_BG2_ACTIVE;

	//initializing BG control
	BGCTRL[1] = BG_32x64|BG_COLOR_16|BG_MAP_BASE(0)|BG_TILE_BASE(1);
	BGCTRL[2] = BG_32x64|BG_COLOR_16|BG_MAP_BASE(2)|BG_TILE_BASE(2);
	BGCTRL[0] = BG_32x64|BG_COLOR_16|BG_MAP_BASE(4)|BG_TILE_BASE(3);

	//setting map pointers
	mainMap = BG_MAP_RAM(0);
	backMap = BG_MAP_RAM(2);
	obstMap = BG_MAP_RAM(4);

	//setting tile pointers
	mainTiles = BG_TILE_RAM(1);
	backTiles = BG_TILE_RAM(2);
	obstTiles = BG_TILE_RAM(3);

}

void graphics_init_sprite(void){

	oamInit(&oamMain, SpriteMapping_1D_32, false);

	//allocating memory for sprite graphics
	gfx1 = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	gfx2 = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	gfx3 = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);

	//copying palette and tiles
	dmaCopy(NyanCat1Pal,SPRITE_PALETTE,NyanCat1PalLen);
	dmaCopy(NyanCat1Tiles,gfx1,NyanCat1TilesLen);
	dmaCopy(NyanCat2Tiles,gfx2,NyanCat2TilesLen);
	dmaCopy(NyanCat3Tiles,gfx3,NyanCat3TilesLen);

	//initializing sprite

	oamSet(	&oamMain,//oam handler
			0,//Number of sprite
			x_pos_sprite, y_pos_sprite,//Coordinates
			0,//Priority
			0,//Palette to use
			SpriteSize_32x32,//Prite size
			SpriteColorFormat_256Color,//Color format
			gfx1,//Loaded graphic to display
			-1,//Affine rotation to use (-1 none)
			false,//Double size if rotating
			false,//Hide this sprite
			true, false,//Horizontal or vertical flip
			false);//Mosaic
	oamUpdate(&oamMain);
}
//setting up background
void graphics_setup_BG2(void){
	//copying palette, tiles and map
	dmaCopy(cloudsPal, BG_PALETTE, cloudsPalLen);
	dmaCopy(cloudsMap,backMap,cloudsMapLen);
	dmaCopy(cloudsTiles, backTiles, cloudsTilesLen);
	//dmaCopy(cloudsMap,&backMap[32*32],cloudsMapLen);

	//bottom half of BG is the switched image of top half
	int row,col;
	for(row=0;row<32;row++){
		for(col=0;col<32;col++){
			backMap[32*32+row*32+col]=cloudsMap[row*32+31-col]|TILE_FLIP_H;
		}
	}
}
//setting up buildings
void graphics_setup_BG1(void){
	//copying palette
	dmaCopy(Building2Pal,&BG_PALETTE[WALL_PAL_OFFSET],Building2PalLen);
	//BG_PALETTE[WALL_PAL_OFFSET+1]=ARGB16(1,0,31,0);

	//coping tiles into memory
	dmaCopy(FullTileTransp,mainTiles,32);
	dmaCopy(Building2Tiles,&mainTiles[TILE_OFFSET],Building2TilesLen);

	int row, col;
	for(row=0;row<64;row+=4){
		for(col=0;col<32;col++){
			if(col==0 || col==31){
				mainMap[row*32+col]=1|WALL_PAL;
				mainMap[(row+1)*32+col]=5|WALL_PAL;
				mainMap[(row+2)*32+col]=9|WALL_PAL;
				mainMap[(row+3)*32+col]=13|WALL_PAL;
			}else if(col==1||col==30){
				mainMap[row*32+col]=2|WALL_PAL;
				mainMap[(row+1)*32+col]=6|WALL_PAL;
				mainMap[(row+2)*32+col]=10|WALL_PAL;
				mainMap[(row+3)*32+col]=14|WALL_PAL;
			}else if(col==2||col==29){
				mainMap[row*32+col]=3|WALL_PAL;
				mainMap[(row+1)*32+col]=7|WALL_PAL;
				mainMap[(row+2)*32+col]=11|WALL_PAL;
				mainMap[(row+3)*32+col]=15|WALL_PAL;
			}else if(col==3||col==28){
				mainMap[row*32+col]=4|WALL_PAL;
				mainMap[(row+1)*32+col]=8|WALL_PAL;
				mainMap[(row+2)*32+col]=12|WALL_PAL;
				mainMap[(row+3)*32+col]=16|WALL_PAL;
			}else{
				mainMap[row*32+col]=0|WALL_PAL;
				mainMap[(row+1)*32+col]=0|WALL_PAL;
				mainMap[(row+2)*32+col]=0|WALL_PAL;
				mainMap[(row+3)*32+col]=0|WALL_PAL;
			}
		}
	}
}

void graphics_setup_BG0(void){

	//copying tiles and palette of balcony
	dmaCopy(FullTileTransp,obstTiles,32);
	dmaCopy(Balcony2Tiles,&obstTiles[BALCONY*TILE_OFFSET],Balcony2TilesLen);
	dmaCopy(Balcony2Pal,&BG_PALETTE[OBST_PAL_OFFSET],Balcony2PalLen);

	//designing initial map
	double var;
	int row, index=0;
	for(row=2;row<32;row+=4){
		var = ((double)rand()/RAND_MAX);
		if(var<PROBABILITY){
			if(var<PROBABILITY/2){
				graphics_build(LEFT_OBST, row, index);
			}else{
				graphics_build(RIGHT_OBST, row, index);
			}
		}else{
			graphics_build(NO_OBST, row, index);
		}
	}
	index=1;
	for(row=2;row<32;row+=4){
		var = ((double)rand()/RAND_MAX);
		if(var<PROBABILITY){
			if(var<PROBABILITY/2){
				graphics_build(LEFT_OBST, row, index);
			}else{
				graphics_build(RIGHT_OBST, row, index);
			}
		}else{
			graphics_build(NO_OBST, row, index);
		}
	}

}

void graphics_build(enum OBSTACLE_TYPE obstacle, int row, int index){
	int i;
	//check for type of obstacle
	if(obst_cnt==0||obst_cnt==1) obstacle=NO_OBST;
	switch(obstacle){
	case NO_OBST: 	for(i=0;i<32;i++){
						obstMap[(row+index*32)*32+i]=EMPTY|OBST_PAL;
						obstMap[(row+1+index*32)*32+i]=EMPTY|OBST_PAL;
					}
					obst_cnt++;
					break;
	case LEFT_OBST:	for(i=0;i<32;i++){
						if(i==4){
							obstMap[(row+index*32)*32+i]=BALCONY|OBST_PAL;
							obstMap[(row+1+index*32)*32+i]=(BALCONY+3)|OBST_PAL;
						}else if(i==5){
							obstMap[(row+index*32)*32+i]=(BALCONY+1)|OBST_PAL;
							obstMap[(row+1+index*32)*32+i]=(BALCONY+4)|OBST_PAL;
						}else if(i==6){
							obstMap[(row+index*32)*32+i]=(BALCONY+2)|OBST_PAL;
							obstMap[(row+1+index*32)*32+i]=(BALCONY+5)|OBST_PAL;
						}else{
							obstMap[(row+index*32)*32+i]=EMPTY|OBST_PAL;
							obstMap[(row+1+index*32)*32+i]=EMPTY|OBST_PAL;
						}
					}
					obst_cnt=0;
					break;
	case RIGHT_OBST:for(i=0;i<32;i++){
						if(i==27){
							obstMap[(row+index*32)*32+i]=BALCONY|TILE_FLIP_H|OBST_PAL;
							obstMap[(row+1+index*32)*32+i]=(BALCONY+3)|TILE_FLIP_H|OBST_PAL;
						}else if(i==26){
							obstMap[(row+index*32)*32+i]=(BALCONY+1)|TILE_FLIP_H|OBST_PAL;
							obstMap[(row+1+index*32)*32+i]=(BALCONY+4)|TILE_FLIP_H|OBST_PAL;
						}else if(i==25){
							obstMap[(row+index*32)*32+i]=(BALCONY+2)|TILE_FLIP_H|OBST_PAL;
							obstMap[(row+1+index*32)*32+i]=(BALCONY+5)|TILE_FLIP_H|OBST_PAL;
						}else{
							obstMap[(row+index*32)*32+i]=EMPTY|OBST_PAL;
							obstMap[(row+1+index*32)*32+i]=EMPTY|OBST_PAL;
						}
					}
					obst_cnt=0;
					break;
	default:		break;
	}
}

void graphics_update_map(int index){
	int row;
	double var;
	//designing new map
	for(row=2;row<32;row+=4){
		var = ((double)rand()/RAND_MAX);
		if(var<PROBABILITY){
			if(var<PROBABILITY/2){
				graphics_build(LEFT_OBST, row, index);
			}else{
				graphics_build(RIGHT_OBST, row, index);
			}
		}else{
			graphics_build(NO_OBST, row, index);
		}
	}
}

void graphics_shift_main(void){
	//setting shift register of BG0
	REG_BG1VOFS=bg_shift_main;
	REG_BG0VOFS=bg_shift_main;
	//decrement shift register and check for limit
	if(--bg_shift_main<0){
		bg_shift_main=511;
		//if limit reached: design new bottom map
		graphics_update_map(1);
	}else if(bg_shift_main==254){
		//if half limit reached: design new top map
		graphics_update_map(0);
	}
}

void graphics_shift_sprite(void){
	//check if sprite is jumping, if yes - shift sprite
	if(jump){
		if(inc){
			//check if sprite has reached the right wall
			if(x_pos_sprite<193){
			cat_rot=0;
			x_pos_sprite++;
			}else{
			inc = 0;
			x_pos_sprite = 192;
			jump = false;
			}
		}else{
			//check if sprite has reached the left wall
			if(x_pos_sprite>31){
			cat_rot=1;
			x_pos_sprite--;
			}else{
				inc = 1;
				x_pos_sprite = 32;
				jump = false;
			}
		}
	}
	//cycling through sprite graphics to make it move
	if(++gfx_cnt==20){
		gfx_cnt=0;
		switch(cat_state){
			case 1:	cat_state=2;
					gfx_active=gfx2;
					break;
			case 2:	cat_state=3;
					gfx_active=gfx3;
					break;
			case 3: cat_state=4;
					gfx_active=gfx2;
					break;
			case 4:	cat_state=1;
					gfx_active=gfx1;
					break;
			default: break;
			}
	}
	//updating sprite position and graphic to display
	oamSet(	&oamMain,//oam handler
			0,//Number of sprite
			x_pos_sprite, y_pos_sprite,//Coordinates
			0,//Priority
			0,//Palette to use
			SpriteSize_32x32,//Prite size
			SpriteColorFormat_256Color,//Color format
			gfx_active,//Loaded graphic to display
			-1,//Affine rotation to use (-1 none)
			false,//Double size if rotating
			false,//Hide this sprite
			cat_rot, false,//Horizontal or vertical flip
			false);//Mosaic

	oamUpdate(&oamMain);
}

void graphics_shift_back(void){
	//shifting background
	REG_BG2VOFS=bg_shift_back;
	if(--bg_shift_back<0){
		bg_shift_back=511;
	}
}

void graphics_jump(void){
	//checking if cat is already jumping
	if(!jump){
	//if no: begin jump
		jump = !jump;
		if(inc){
			x_pos_sprite=24;
		}else{
			x_pos_sprite=200;
		}
	}
}

int graphics_checkCollision(void){
	int row = 17+bg_shift_main%8;
	if(row>511) row-=512;
	int col=x_pos_sprite%8;
	if(cat_rot){
		col-=1;
	}else{
		col+=1;
	}
	if(obstMap[row*32+col]!=0){
		return 1;
	}
	return 0;
}

void graphics_game_over(void){

}
