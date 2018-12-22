/*
 * Graphics.c
 *
 *  Created on: Nov 3, 2018
 *      Author: nds
 */
#include "Graphics.h"
#include "clouds.h"
#include "AC.h"
#include "NyanCat1.h"
#include "NyanCat2.h"
#include "NyanCat3.h"
#include <nds.h>

#define SIMULATION

#define PROBABILITY 0.12 //porbability of obstacle
#define TILE_OFFSET 16 //offset for tile memory
#define WALL_PAL (0xf<<12) //palette for buildings
#define OBST_PAL (0xe<<12) //palette for obstacles
//initial background shift and sprite position
int bg_shift_main = 511, bg_shift_back = 511,
		x_pos_sprite = 16, y_pos_sprite = 140;
//sprite starts on left side
int inc = 1;
bool jump = false;
int cat_rot = 1;
//initial graphic to display for graphic
int cat_state=1;
//map pointers
u16* mainMap;
u16* backMap;
//sprite graphics pointers
u16* gfx1, *gfx2, *gfx3, *gfx_active;
int gfx_cnt=0;
//definition of tile numbers
enum TileNum{Transp, Floor, Gray, AC};
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
u8 FloorTile[32]={     0xee,0xee,0xee,0xff,
					   0xee,0xee,0xee,0xff,
					   0xee,0xee,0xee,0xff,
					   0xee,0xee,0xee,0xff,
					   0xee,0xee,0xee,0xff,
					   0xee,0xee,0xee,0xff,
					   0xee,0xee,0xee,0xff,
					   0xee,0xee,0xee,0xff};
u8 GrayTile[32]={      0xee,0xee,0xee,0xee,
					   0xee,0xee,0xee,0xee,
					   0xee,0xee,0xee,0xee,
					   0xee,0xee,0xee,0xee,
					   0xee,0xee,0xee,0xee,
					   0xee,0xee,0xee,0xee,
					   0xee,0xee,0xee,0xee,
					   0xee,0xee,0xee,0xee};

void graphics_build(enum OBSTACLE_TYPE obstacle, int row, int index);

void graphics_init(void){
	//Enable VRAM
	VRAM_A_CR = VRAM_ENABLE| VRAM_A_MAIN_BG;

	//Set mode and background
	REG_DISPCNT = MODE_3_2D|DISPLAY_BG1_ACTIVE|DISPLAY_BG2_ACTIVE;

	//initializing BG control
	BGCTRL[1] = BG_32x64|BG_COLOR_16|BG_MAP_BASE(0)|BG_TILE_BASE(1);
	BGCTRL[2] = BG_32x64|BG_COLOR_16|BG_MAP_BASE(2)|BG_TILE_BASE(2);

	//setting map pointers
	mainMap = BG_MAP_RAM(0);
	backMap = BG_MAP_RAM(2);

}

void graphics_init_sprite(void){
	//VRAM B for sprite
	VRAM_B_CR = VRAM_ENABLE|VRAM_B_MAIN_SPRITE_0x06400000;

	//allocating memory for sprite graphics
	gfx1 = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	gfx2 = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	gfx3 = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);

	//copying palette and tiles
	dmaCopy(NyanCat1Pal,SPRITE_PALETTE,NyanCat1PalLen);
	dmaCopy(NyanCat1Tiles,gfx1,NyanCat1TilesLen);
	dmaCopy(NyanCat2Tiles,gfx2,NyanCat1TilesLen);
	dmaCopy(NyanCat3Tiles,gfx3,NyanCat3TilesLen);

	//initializing sprite
	oamInit(&oamMain, SpriteMapping_1D_32, false);
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

void graphics_setup_BG1(void){
	//copying palette, tiles and map
	dmaCopy(cloudsPal, BG_PALETTE, cloudsPalLen);
	dmaCopy(cloudsMap,backMap,cloudsMapLen);
	dmaCopy(cloudsTiles, BG_TILE_RAM(2), cloudsTilesLen);
	//dmaCopy(cloudsMap,&backMap[32*32],cloudsMapLen);

	//bottom half of BG is the switched image of top half
	int row,col;
	for(row=0;row<32;row++){
		for(col=0;col<32;col++){
			backMap[32*32+row*32+col]=cloudsMap[row*32+31-col]|TILE_FLIP_H;
		}
	}
}

void graphics_setup_BG2(void){
	//setting custop colors
	BG_PALETTE[0xfe]=ARGB16(1,15,15,15);
	BG_PALETTE[0xff]=ARGB16(1,0,0,0);

	//coping custom tiles into memory
	dmaCopy(FullTileTransp,&BG_TILE_RAM(1)[Transp*TILE_OFFSET],32);
	dmaCopy(GrayTile,&BG_TILE_RAM(1)[Gray*TILE_OFFSET],32);
	dmaCopy(FloorTile,&BG_TILE_RAM(1)[Floor*TILE_OFFSET],32);

	//copying tiles and palette of AC
	//TODO: change this to balcony
	dmaCopy(ACTiles,&BG_TILE_RAM(1)[AC*TILE_OFFSET],ACTilesLen);
	dmaCopy(ACPal,&BG_PALETTE[0xe0],ACPalLen);

	//designing initial map
	double var;
	int row, index=0;
	for(row=0;row<32;row+=2){
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
	for(row=0;row<32;row+=2){
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
	switch(obstacle){
	case NO_OBST: 	for(i=0;i<32;i++){
						if(i==0 || i==31){
							mainMap[(row+index*32)*32+i]=Gray|WALL_PAL;
							mainMap[(row+1+index*32)*32+i]=Gray|WALL_PAL;
						}else if(i==1){
							mainMap[(row+index*32)*32+i]=Floor|WALL_PAL;
							mainMap[(row+1+index*32)*32+i]=Floor|WALL_PAL;
						}else if(i==30){
							mainMap[(row+index*32)*32+i]=Floor|TILE_FLIP_H|WALL_PAL;
							mainMap[(row+1+index*32)*32+i]=Floor|TILE_FLIP_H|WALL_PAL;
						}else{
							mainMap[(row+index*32)*32+i]=Transp|WALL_PAL;
							mainMap[(row+1+index*32)*32+i]=Transp|WALL_PAL;
						}
					} break;
	case LEFT_OBST:	for(i=0;i<32;i++){
						if(i==0 || i==31){
							mainMap[(row+index*32)*32+i]=Gray|WALL_PAL;
							mainMap[(row+1+index*32)*32+i]=Gray|WALL_PAL;
						}else if(i==1){
						mainMap[(row+index*32)*32+i]=Floor|WALL_PAL;
						mainMap[(row+1+index*32)*32+i]=Floor|WALL_PAL;
						}else if(i==2){
							mainMap[(row+index*32)*32+i]=AC|OBST_PAL;
							mainMap[(row+1+index*32)*32+i]=(AC+2)|OBST_PAL;
						}else if(i==3){
							mainMap[(row+index*32)*32+i]=(AC+1)|OBST_PAL;
							mainMap[(row+1+index*32)*32+i]=(AC+3)|OBST_PAL;
						}else if(i==30){
							mainMap[(row+index*32)*32+i]=Floor|TILE_FLIP_H|WALL_PAL;
							mainMap[(row+1+index*32)*32+i]=Floor|TILE_FLIP_H|WALL_PAL;
						}else{
							mainMap[(row+index*32)*32+i]=Transp|WALL_PAL;
						}
					} break;
	case RIGHT_OBST:for(i=0;i<32;i++){
						if(i==0 || i==31){
							mainMap[(row+index*32)*32+i]=Gray|WALL_PAL;
							mainMap[(row+1+index*32)*32+i]=Gray|WALL_PAL;
						}else if(i==1){
						mainMap[(row+index*32)*32+i]=Floor|WALL_PAL;
						mainMap[(row+1+index*32)*32+i]=Floor|WALL_PAL;
						}else if(i==29){
							mainMap[(row+index*32)*32+i]=AC|TILE_FLIP_H|OBST_PAL;
							mainMap[(row+1+index*32)*32+i]=(AC+2)|TILE_FLIP_H|OBST_PAL;
						}else if(i==28){
							mainMap[(row+index*32)*32+i]=(AC+1)|TILE_FLIP_H|OBST_PAL;
							mainMap[(row+1+index*32)*32+i]=(AC+3)|TILE_FLIP_H|OBST_PAL;
						}else if(i==30){
							mainMap[(row+index*32)*32+i]=Floor|TILE_FLIP_H|WALL_PAL;
							mainMap[(row+1+index*32)*32+i]=Floor|TILE_FLIP_H|WALL_PAL;
						}else{
							mainMap[(row+index*32)*32+i]=Transp|WALL_PAL;
						}
					} break;
	default:		break;
	}
}

void graphics_update_map(int index){
	int row;
	double var;
	//designing new map
	for(row=0;row<32;row+=2){
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
			if(x_pos_sprite<209){
			cat_rot=0;
			x_pos_sprite++;
			}else{
			inc = 0;
			x_pos_sprite = 208;
			jump = false;
			}
		}else{
			//check if sprite has reached the left wall
			if(x_pos_sprite>15){
			cat_rot=1;
			x_pos_sprite--;
			}else{
				inc = 1;
				x_pos_sprite = 16;
				jump = false;
			}
		}
	}
	//cycling through sprite graphics to make it move
	if(++gfx_cnt==100){
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

void graphics_handle_input(void){
	//checking if cat is already jumping
	if(!jump){
		scanKeys();
#ifdef DEVICE
		if(keysHeld()==KEY_A){
			jump = !jump;
		}
#endif
#ifdef SIMULATION
		//if no: begin jump
		if(keysDown()==KEY_A){
			jump = !jump;
			if(inc){
				x_pos_sprite=8;
			}else{
				x_pos_sprite=216;
			}
		}
#endif
	}
}
