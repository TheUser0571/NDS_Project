/*
 * Graphics.c
 *
 *  Created on: Nov 3, 2018
 *      Author: nds
 */
#include <nds.h>
#include <stdio.h>
#include "math.h"
#include "Graphics.h"
#include "Timer.h"
#include "clouds.h"
#include "Balcony2.h"
#include "Building2.h"
#include "NyanCat1.h"
#include "NyanCat2.h"
#include "NyanCat3.h"
#include "NyanCat4.h"
#include "NyanCat5.h"
#include "NyanCat6.h"
#include "game_over.h"
#include "clock.h"
#include "rainbow.h"
#include "shield.h"
#include "rainbow2.h"
#include "numbers.h"
#include "big_rainbow.h"
#include "big_shield.h"
#include "big_clock.h"
#include "nums.h"
#include "keyboard.h"
#include "start.h"


#define SIMULATION

#define PROBABILITY 0.2 //initial probability
#define POWERUP_PROB 0.1 //powerup probability (0.05)
#define TILE_OFFSET 16 //offset for tile memory
#define WALL_PAL (0xa<<12) //palette for buildings
#define OBST_PAL (0xe<<12) //palette for obstacles
#define GO_PAL (0xc<<12) //palette for game over screen
#define SLOWMO_PAL (0xb<<12) //palette for slomo powerup
#define BOOST_PAL (0xd<<12) //palette for boost powerup
#define SHIELD_PAL (0xf<<12) //palette for shield powerup
#define RAINBOW_PAL (0x9<<12) //palette for rainbow at boost
#define NUMBERS_PAL_SUB (0xa<<12) //palette for numbers
#define BIG_CLOCK_PAL_SUB (0xb<<12)
#define BIG_RAINBOW_PAL_SUB (0xc<<12)
#define BIG_SHIELD_PAL_SUB (0xd<<12)
#define NUMS_PAL_SUB (0xe<<12)
#define WALL_PAL_OFFSET 0xa0
#define OBST_PAL_OFFSET 0xe0
#define BOOST_PAL_OFFSET 0xd0
#define SLOMO_PAL_OFFSET 0xb0
#define SHIELD_PAL_OFFSET 0xf0
#define NUMBERS_PAL_SUB_OFFSET 0xa0
#define BIG_CLOCK_PAL_SUB_OFFSET 0xb0
#define BIG_RAINBOW_PAL_SUB_OFFSET 0xc0
#define BIG_SHIELD_PAL_SUB_OFFSET 0xd0
#define NUMS_PAL_SUB_OFFSET 0xe0
#define GO_PAL_OFFSET 0xc0
#define RAINBOW_PAL_OFFSET 0x90
#define GO_OFFSET 17
#define RAINBOW_OFFSET 210
#define BUTTON_OFFSET 100

//definition of tile numbers
enum TileNum{Transp, Floor, Gray};

enum ObstTiles{EMPTY, BALCONY, CLOCK=7, RAINBOW=11, SHIELD_T=15};
//definition of obstacle types
enum OBSTACLE_TYPE{NO_OBST, LEFT_OBST, RIGHT_OBST};

double prob = PROBABILITY; //porbability of obstacle

//initial background shift and sprite position
int bg_shift_main = 511, bg_shift_back = 511,
		x_pos_sprite = 32, y_pos_sprite = 144;
//sprite starts on left side
int inc = 1;
bool jump = false, hide_sprite=false;
int cat_rot = 1;
int speed = 100;
//initial graphic to display for graphic
int cat_state=1;
//map pointers
u16* mainMap, *backMap, *obstMap, *backMap_sub, *mainMap_sub;
//tiles pointers
u16* backTiles, *mainTiles, *obstTiles, *backTiles_sub, *mainTiles_sub;
//sprite graphics pointers
u16* gfx1=NULL, *gfx2=NULL, *gfx3=NULL, *gfx_active=NULL;
int gfx_cnt=0;
int obst_cnt=1;
//powerup definitions
int hide_count=0;
//console for timer display
PrintConsole console;
//cutom tiles
u8 FullTileTransp[32]={0,0,0,0,
					   0,0,0,0,
					   0,0,0,0,
					   0,0,0,0,
					   0,0,0,0,
					   0,0,0,0,
					   0,0,0,0,
					   0,0,0,0,};

u8 FullTileWhite[32]={0xff,0xff,0xff,0xff,
					  0xff,0xff,0xff,0xff,
					  0xff,0xff,0xff,0xff,
					  0xff,0xff,0xff,0xff,
					  0xff,0xff,0xff,0xff,
					  0xff,0xff,0xff,0xff,
					  0xff,0xff,0xff,0xff,
					  0xff,0xff,0xff,0xff};

void graphics_build(enum OBSTACLE_TYPE obstacle, int row, int index);
void graphics_addPowerup(enum POWERUP_TYPE type, int row, int index);
void graphics_clearPowerup(int row);
void graphics_pickupPowerup(enum POWERUP_TYPE type);

void graphics_init(void){
	bg_shift_main = 511;
	bg_shift_back = 511;
	x_pos_sprite = 32;
	y_pos_sprite = 144;
	inc = 1;
	cat_state=1;
	jump = false;
	hide_sprite=false;
	speed = 100;
	cat_rot = 1;
	gfx_cnt=0;
	obst_cnt =1;
	hide_count=0;
	//Enable VRAM A for main screen
	VRAM_A_CR = VRAM_ENABLE|VRAM_A_MAIN_BG;
	//Vram C for sub screen
	VRAM_C_CR = VRAM_ENABLE|VRAM_C_SUB_BG;
	//VRAM B for sprite
	VRAM_B_CR = VRAM_ENABLE|VRAM_B_MAIN_SPRITE_0x06400000;

	//Set mode and background
	REG_DISPCNT = MODE_3_2D|DISPLAY_BG0_ACTIVE|DISPLAY_BG1_ACTIVE|DISPLAY_BG2_ACTIVE;
	REG_DISPCNT_SUB = MODE_3_2D|DISPLAY_BG2_ACTIVE|DISPLAY_BG1_ACTIVE|DISPLAY_BG0_ACTIVE;

	//initializing BG control
	BGCTRL[1] = BG_32x64|BG_COLOR_16|BG_MAP_BASE(0)|BG_TILE_BASE(1);
	BGCTRL[2] = BG_32x64|BG_COLOR_16|BG_MAP_BASE(2)|BG_TILE_BASE(2);
	BGCTRL[0] = BG_32x64|BG_COLOR_16|BG_MAP_BASE(4)|BG_TILE_BASE(3);
	BGCTRL_SUB[2] = BG_32x32|BG_COLOR_16|BG_MAP_BASE(0)|BG_TILE_BASE(1);
	BGCTRL_SUB[1] = BG_32x32|BG_COLOR_16|BG_MAP_BASE(1)|BG_TILE_BASE(2);

	//setting map pointers
	mainMap = BG_MAP_RAM(0);
	backMap = BG_MAP_RAM(2);
	obstMap = BG_MAP_RAM(4);
	backMap_sub = BG_MAP_RAM_SUB(0);
	mainMap_sub = BG_MAP_RAM_SUB(1);

	//setting tile pointers
	mainTiles = BG_TILE_RAM(1);
	backTiles = BG_TILE_RAM(2);
	obstTiles = BG_TILE_RAM(3);
	backTiles_sub = BG_TILE_RAM_SUB(1);
	mainTiles_sub = BG_TILE_RAM_SUB(2);

	//initializing console for timer display
	consoleClear();
	consoleInit(&console, //console
				0, //BG layer
				BgType_Text4bpp, //BG type
				BgSize_T_256x256, //BG size
				2, //map base
				5, //tile base
				false, //main engine
				true); //default font
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
	dmaCopy(cloudsMap, backMap, cloudsMapLen);
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

	//copying game over screen
	dmaCopy(game_overTiles, &mainTiles[GO_OFFSET*TILE_OFFSET],game_overTilesLen);
	dmaCopy(game_overPal, &BG_PALETTE[GO_PAL_OFFSET],game_overPalLen);

	//copying rainbow for boost
	dmaCopy(rainbow2Tiles,&mainTiles[RAINBOW_OFFSET*TILE_OFFSET],game_overTilesLen);
	dmaCopy(rainbow2Pal,&BG_PALETTE[RAINBOW_PAL_OFFSET],rainbow2PalLen);

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

	//copying powerup tiles and palette
	dmaCopy(clockPal,&BG_PALETTE[SLOMO_PAL_OFFSET],clockPalLen);
	dmaCopy(clockTiles,&obstTiles[CLOCK*TILE_OFFSET],clockTilesLen);
	dmaCopy(rainbowPal,&BG_PALETTE[BOOST_PAL_OFFSET],rainbowPalLen);
	dmaCopy(rainbowTiles,&obstTiles[RAINBOW*TILE_OFFSET],rainbowTilesLen);
	dmaCopy(shieldPal,&BG_PALETTE[SHIELD_PAL_OFFSET],shieldPalLen);
	dmaCopy(shieldTiles,&obstTiles[SHIELD_T*TILE_OFFSET],shieldTilesLen);

	//initializing map to empty
	int row, col;
	for(row=0;row<64;row++){
		for(col=0;col<32;col++){
			obstMap[row*32+col]=EMPTY|OBST_PAL;
		}
	}

	//designing initial map
	double var;
	int index=1;
	for(row=2;row<32;row+=4){
		var = ((double)rand()/RAND_MAX);
		if(var<prob){
			if(var<prob/2){
				graphics_build(LEFT_OBST, row, index);
			}else{
				graphics_build(RIGHT_OBST, row, index);
			}
		}else{
			graphics_build(NO_OBST, row, index);
		}
	}

}

void graphics_setupBG2_sub(void){
	//defining palette and tiles
	BG_PALETTE_SUB[0x0f]=ARGB16(1,31,31,31); //white
	dmaCopy(FullTileWhite,backTiles_sub,32); //0=full white tile
	dmaCopy(big_clockPal,&BG_PALETTE_SUB[BIG_CLOCK_PAL_SUB_OFFSET],big_clockPalLen);
	dmaCopy(big_clockTiles, &backTiles_sub[TILE_OFFSET],big_clockTilesLen);
	dmaCopy(big_rainbowPal,&BG_PALETTE_SUB[BIG_RAINBOW_PAL_SUB_OFFSET],big_rainbowPalLen);
	dmaCopy(big_rainbowTiles, &backTiles_sub[TILE_OFFSET*(1+BUTTON_OFFSET)],big_rainbowTilesLen);
	dmaCopy(big_shieldPal,&BG_PALETTE_SUB[BIG_SHIELD_PAL_SUB_OFFSET],big_shieldPalLen);
	dmaCopy(big_shieldTiles,&backTiles_sub[TILE_OFFSET*(1+2*BUTTON_OFFSET)],big_shieldTilesLen);
	//initializing map to all-white
	int row,col;
	for(row=0;row<32;row++){
		for(col=0;col<32;col++){
			backMap_sub[row*32+col]=0;
		}
	}
	//drawing slowmo button
	for(row=0;row<10;row++){
		for(col=0;col<10;col++){
			backMap_sub[(row+13)*32+col]=(row*10+col+1)|BIG_CLOCK_PAL_SUB;
		}
	}
	//drawing boost button
	for(row=0;row<10;row++){
		for(col=0;col<10;col++){
			backMap_sub[(row+13)*32+col+11]=(row*10+col+101)|BIG_RAINBOW_PAL_SUB;
		}
	}
	//drawing shield button
	for(row=0;row<10;row++){
		for(col=0;col<10;col++){
			backMap_sub[(row+13)*32+col+22]=(row*10+col+201)|BIG_SHIELD_PAL_SUB;
		}
	}
}

void graphics_setupBG1_sub(void){
	//copying palette and tiles
	dmaCopy(FullTileTransp,mainTiles_sub,32);
	dmaCopy(numbersTiles,&mainTiles_sub[TILE_OFFSET],numbersTilesLen);
	dmaCopy(numsPal,&BG_PALETTE_SUB[NUMS_PAL_SUB_OFFSET],numsPalLen);
	dmaCopy(numsTiles,&mainTiles_sub[TILE_OFFSET*(1+352)],numsTilesLen);
	//dmaCopy(numbersPal,&BG_PALETTE_SUB[NUMBERS_PAL_SUB_OFFSET],numbersPalLen);
	BG_PALETTE_SUB[0xaf]=ARGB16(1,5,0,31); //making numbers blue
	//initializing map to transparent
	int row,col;
	for(row=0;row<32;row++){
		for(col=0;col<32;col++){
			mainMap_sub[row*32+col]=0;
		}
	}
	graphics_drawNum(SLOWMO,0);
	graphics_drawNum(BOOST,0);
	graphics_drawNum(SHIELD,0);
}

void graphics_build(enum OBSTACLE_TYPE obstacle, int row, int index){
	int i;
	//check for type of obstacle
	int low=2,high=3;
	if(obst_cnt>=low && obst_cnt<=high) obstacle=NO_OBST;
	switch(obstacle){
	case NO_OBST: 	for(i=0;i<32;i++){
						obstMap[(row+index*32)*32+i]=EMPTY|OBST_PAL;
						obstMap[(row+1+index*32)*32+i]=EMPTY|OBST_PAL;
					}
					obst_cnt++;
					prob+=0.15;
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
					obst_cnt=1;
					prob=PROBABILITY;
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
					obst_cnt=1;
					prob=PROBABILITY;
					break;
	default:		break;
	}
}

void graphics_update_map(int index){
	int row, col;
	//initializing map to empty
	for(row=0;row<32;row++){
		for(col=0;col<32;col++){
			obstMap[(row+index*32)*32+col]=EMPTY|OBST_PAL;
		}
	}
	double var;
	//designing new map
	for(row=30;row>0;row-=4){
		var = ((double)rand()/RAND_MAX);
		if(var<POWERUP_PROB){
			if(var<POWERUP_PROB/3){
				graphics_addPowerup(SLOWMO, row-2, index);
			}else if(var>2*POWERUP_PROB/3){
				graphics_addPowerup(BOOST, row-2, index);
			}else{
				graphics_addPowerup(SHIELD, row-2, index);
			}
		}
		if(var<prob){
			if(var<prob/2){
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

void graphics_shift_sprite(int powerup_state){
	//check if sprite is jumping, if yes - shift sprite
	if(jump && powerup_state!=BOOST_STATE){
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
	if(powerup_state==BOOST_STATE){
		jump=true;
			//check if sprite is on the left
		if(x_pos_sprite<106){
		inc=1;
		cat_rot=0;
		x_pos_sprite++;
		}else if(x_pos_sprite>118){
		inc=0;
		cat_rot=1;
		x_pos_sprite--;
		}else if(x_pos_sprite<118 && x_pos_sprite>106){
			if(cat_rot){
				x_pos_sprite++;
			}else{
				x_pos_sprite--;
			}
		}
	}else if(powerup_state==SHIELD_STATE || powerup_state==MINI_SHIELD_STATE){
		hide_count++;
		if(hide_sprite && hide_count==20){
			hide_sprite=false;
			hide_count=0;
		}else if(hide_count==40){
			hide_sprite=true;
			hide_count=0;
		}
	}
	//cycling through sprite graphics to make it move
	if(++gfx_cnt==25){
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
			SpriteSize_32x32,//sprite size
			SpriteColorFormat_256Color,//Color format
			gfx_active,//Loaded graphic to display
			-1,//Affine rotation to use (-1 none)
			false,//Double size if rotating
			hide_sprite,//Hide this sprite
			cat_rot, false,//Horizontal or vertical flip
			false);//Mosaic


}

void graphics_shift_back(void){
	//shifting background

	if(--bg_shift_back<0){
		bg_shift_back=511;
	}
}

void graphics_jump(int powerup_state){
	//checking if cat is already jumping
	if(!jump && powerup_state!=BOOST_STATE){
	//if no: begin jump
		jump = !jump;
		if(inc){
			x_pos_sprite=24;
		}else{
			x_pos_sprite=200;
		}
	}
}

int graphics_checkCollision(int powerup_state){
	//Calculating position of sprite on the map
	int row = (y_pos_sprite+bg_shift_main)/8;
	int col=x_pos_sprite/8;
	//accounting for rotation
	if(cat_rot){
		col+=1;
	}else{
		col+=3;
	}
	//no collision or pickup in boost state
	if(powerup_state==BOOST_STATE){
		return NONECOL;
	}
	int i;
	for(i=0;i<4;i++){
		//accounting for map end
		if((row+i)>63) row-=64;
		//Checking if map entry at sprite postion is empty
		if(obstMap[(row+i)*32+col]&(0x03ff)){
			//if not: check for powerup
			if((obstMap[(row+i)*32+col]&(0xf000))==SLOWMO_PAL){
				//delete the picked up powerup
				graphics_clearPowerup(row);
				return SLOWMOCOL;
			}else if((obstMap[(row+i)*32+col]&(0xf000))==BOOST_PAL){
				graphics_clearPowerup(row);
				return BOOSTCOL;
			}else if((obstMap[(row+i)*32+col]&(0xf000))==SHIELD_PAL){
				graphics_clearPowerup(row);
				return SHIELDCOL;
			//if no powerup return obstacle
			}else if(powerup_state!=SHIELD_STATE && powerup_state!=MINI_SHIELD_STATE){
				return OBSTACLECOL;
			}
		}
	}
	return NONECOL;
}

void graphics_game_over(void){
	consoleClear();
	consoleSetWindow(&console,  0, //x
							    2, //y
							   31, //with
							   31);//height
	int row, col, row_offset=5+bg_shift_main/8, col_offset=8;
	for(row=0;row<12;row++){
		for(col=0;col<16;col++){
			//checking for end of map and continuing at beginning
			if(row+row_offset>63){
			//drawing game over screen in main Map
				mainMap[(row+row_offset-64)*32+col+col_offset]=(GO_OFFSET+(row*16+col))|GO_PAL;
				obstMap[(row+row_offset-64)*32+col+col_offset]=EMPTY|OBST_PAL;
			}else{
				mainMap[(row+row_offset)*32+col+col_offset]=(GO_OFFSET+(row*16+col))|GO_PAL;
				obstMap[(row+row_offset)*32+col+col_offset]=EMPTY|OBST_PAL;
			}
		}
	}

	//initializing map to all-white
	for(row=0;row<32;row++){
		for(col=0;col<32;col++){
			backMap_sub[row*32+col]=0;
		}
	}
	//deactivating BG1
	REG_DISPCNT_SUB = MODE_3_2D|DISPLAY_BG2_ACTIVE|DISPLAY_BG0_ACTIVE;
}
void graphics_updateScreen(void){
	//shifting backgrounds and sprite
	REG_BG2VOFS=bg_shift_back;
	REG_BG1VOFS=bg_shift_main;
	REG_BG0VOFS=bg_shift_main;
	oamUpdate(&oamMain);
}

void graphics_addPowerup(enum POWERUP_TYPE type, int row, int index){
	int offset = 15;
	switch(type){
	case SLOWMO:	obstMap[(row+index*32)*32+offset]=CLOCK|SLOWMO_PAL;
					obstMap[(row+index*32)*32+offset+1]=(CLOCK+1)|SLOWMO_PAL;
					obstMap[(row+1+index*32)*32+offset]=(CLOCK+2)|SLOWMO_PAL;
					obstMap[(row+1+index*32)*32+offset+1]=(CLOCK+3)|SLOWMO_PAL;
					break;
	case BOOST:		obstMap[(row+index*32)*32+offset]=RAINBOW|BOOST_PAL;
					obstMap[(row+index*32)*32+offset+1]=(RAINBOW+1)|BOOST_PAL;
					obstMap[(row+1+index*32)*32+offset]=(RAINBOW+2)|BOOST_PAL;
					obstMap[(row+1+index*32)*32+offset+1]=(RAINBOW+3)|BOOST_PAL;
					break;
	case SHIELD:	obstMap[(row+index*32)*32+offset]=SHIELD_T|SHIELD_PAL;
					obstMap[(row+index*32)*32+offset+1]=(SHIELD_T+1)|SHIELD_PAL;
					obstMap[(row+1+index*32)*32+offset]=(SHIELD_T+2)|SHIELD_PAL;
					obstMap[(row+1+index*32)*32+offset+1]=(SHIELD_T+3)|SHIELD_PAL;
					break;
	default:		break;
	}
}

void graphics_clearPowerup(int row){
	int i, offset = 15;
	for(i=row-1;i<=row+6;i++){
		obstMap[i*32+offset]=EMPTY|OBST_PAL;
		obstMap[i*32+offset+1]=EMPTY|OBST_PAL;
	}
}

void graphics_drawRainbow(void){
	int row=y_pos_sprite/8+bg_shift_main/8+1;
	int i,k, col_offset=14;
	for(i=0;i<8;i++){
		for(k=0;k<4;k++){
			if(row+i>63){
				mainMap[(row+i-64)*32+col_offset+k]=(RAINBOW_OFFSET+(4*i)+k)|RAINBOW_PAL;
			}
			else{
				mainMap[(row+i)*32+col_offset+k]=(RAINBOW_OFFSET+(4*i)+k)|RAINBOW_PAL;
			}
		}
	}

}

void graphics_clearRainbow(void){
	int i,k;
	for(i=0;i<64;i++){
		for(k=0;k<4;k++){
			mainMap[i*32+14+k]=0|WALL_PAL;
		}
	}
}

void graphics_setSpriteVisibility(int visible){
	hide_sprite = visible;
}

void graphics_toggleRainbow(void){
	if(!(bg_shift_main%8) && x_pos_sprite>105 && x_pos_sprite<119){
		graphics_clearRainbow();
		graphics_drawRainbow();
	}
}

void graphics_drawNumber(int row_offset, int col_offset, int number){
	int row,col;
	if(row_offset<0||row_offset>23||col_offset<0||col_offset>27) return;
	for(row=0;row<8;row++){
		for(col=0;col<4;col++){
			mainMap_sub[(row+row_offset)*32+col+col_offset]=((4*8*number)+row*4+col+1)|NUMBERS_PAL_SUB;
		}
	}
}

void graphics_updatePoints(int points){
	int pts[5];
	pts[0]=points/10000;
	points%=10000;
	pts[1]=points/1000;
	points%=1000;
	pts[2]=points/100;
	points%=100;
	pts[3]=points/10;
	points%=10;
	pts[4]=points;
	int col,num=0;
	for(col=0;col<20;col+=4){
		graphics_drawNumber(2,col+6,pts[num]);
		num++;
	}
}

void graphics_drawNum(enum POWERUP_TYPE type, int num){
	if(num>9){
		num=9;
	}
	int offset=0;
	if(num%2){
		offset=(num/2)*8+2;
	}else{
		offset=(num/2)*8;
	}
	switch(type){
	case SLOWMO:	mainMap_sub[13*32+8]=(353+offset)|NUMS_PAL_SUB;
					mainMap_sub[13*32+9]=(354+offset)|NUMS_PAL_SUB;
					mainMap_sub[14*32+8]=(357+offset)|NUMS_PAL_SUB;
					mainMap_sub[14*32+9]=(358+offset)|NUMS_PAL_SUB;
					break;
	case BOOST:		mainMap_sub[13*32+19]=(353+offset)|NUMS_PAL_SUB;
					mainMap_sub[13*32+20]=(354+offset)|NUMS_PAL_SUB;
					mainMap_sub[14*32+19]=(357+offset)|NUMS_PAL_SUB;
					mainMap_sub[14*32+20]=(358+offset)|NUMS_PAL_SUB;
					break;
	case SHIELD:	mainMap_sub[13*32+30]=(353+offset)|NUMS_PAL_SUB;
					mainMap_sub[13*32+31]=(354+offset)|NUMS_PAL_SUB;
					mainMap_sub[14*32+30]=(357+offset)|NUMS_PAL_SUB;
					mainMap_sub[14*32+31]=(358+offset)|NUMS_PAL_SUB;
					break;
	default:		break;

	}
}

void graphics_setConsole(enum POWERUP_TYPE type){
	switch(type){
	case SLOWMO:	consoleSetWindow(&console, //console
									 3, //x
									 19, //y
									 5, //with
									 1); //height
					break;
	case BOOST:		consoleSetWindow(&console, //console
									 14, //x
									 18, //y
									 5, //with
									 1); //height
					break;
	case SHIELD:	consoleSetWindow(&console, //console
									 25, //x
									 18, //y
									 5, //with
									 1); //height
					break;
	}
}

void graphics_initKeyboard(void){
	//Enable VRAM A for main screen
	VRAM_A_CR = VRAM_ENABLE|VRAM_A_MAIN_BG;
	//Vram C for sub screen
	VRAM_C_CR = VRAM_ENABLE|VRAM_C_SUB_BG;

	//Set mode and background
	REG_DISPCNT = MODE_3_2D|DISPLAY_BG0_ACTIVE;
	REG_DISPCNT_SUB = MODE_3_2D|DISPLAY_BG0_ACTIVE;

	//initializing BG_SUB control for keyboard display
	BGCTRL_SUB[0] = BG_32x32|BG_COLOR_256|BG_MAP_BASE(0)|BG_TILE_BASE(1);

	//initializing console (main) for name display
	consoleClear();
	consoleInit(&console, //console
				0, //BG layer
				BgType_Text4bpp, //BG type
				BgSize_T_256x256, //BG size
				0, //map base
				1, //tile base
				true, //main engine
				true); //default font

	//copying tiles, palette and map of keyboard
	dmaCopy(keyboardTiles,BG_TILE_RAM_SUB(1),keyboardTilesLen);
	dmaCopy(keyboardPal,BG_PALETTE_SUB,keyboardPalLen);
	dmaCopy(keyboardMap,BG_MAP_RAM_SUB(0),keyboardMapLen);

	//asking for name
	consoleSetWindow(&console, //console
					 8, //x
					 5, //y
					 16, //with
					 1); //height
	printf("\x1b[37;1mEnter your name:");

	//starting instruction
	consoleSetWindow(&console, //console
					 6, //x
					 22, //y
					 20, //with
					 1); //height
	printf("\x1b[37;1mPress \x1b[31;1mstart\x1b[37;1m to begin");
}

void graphics_dispName(char *name,int NAME_MAX){
	consoleSetWindow(&console, //console
					 (32-NAME_MAX)/2, //x
					 7, //y
					 NAME_MAX, //with
					 1); //height
	printf("\x1b[32;1m%s",name);
}

void graphics_initWelcome(void){
	//Enable VRAM A for main screen
	VRAM_A_CR = VRAM_ENABLE|VRAM_A_MAIN_BG;
	//Vram C for sub screen
	VRAM_C_CR = VRAM_ENABLE|VRAM_C_SUB_BG;

	//Set mode and background
	REG_DISPCNT = MODE_3_2D|DISPLAY_BG0_ACTIVE;
	REG_DISPCNT_SUB = MODE_3_2D|DISPLAY_BG0_ACTIVE;

	//initializing BG_SUB control for keyboard display
	BGCTRL[0] = BG_32x32|BG_COLOR_256|BG_MAP_BASE(0)|BG_TILE_BASE(1);

	//initializing console (main) for name display
	consoleClear();
	consoleInit(&console, //console
				0, //BG layer
				BgType_Text4bpp, //BG type
				BgSize_T_256x256, //BG size
				0, //map base
				1, //tile base
				false, //main engine
				true); //default font

	//copying tiles, palette and map of keyboard
	dmaCopy(startTiles,BG_TILE_RAM(1),startTilesLen);
	dmaCopy(startPal,BG_PALETTE,startPalLen);
	dmaCopy(startMap,BG_MAP_RAM(0),startMapLen);


	//asking for name
	consoleSetWindow(&console, //console
					 1, //x
					 1, //y
					 31, //with
					 31); //height
	printf("\x1b[37;1m");
	printf("Hi! I'm NyanNyanCat.\nNice to meet you :-)\n");
	printf("I climp buildings and jump\naround (press A).\n\n");
	printf("My superpowers are the boost\n(press X),");
	printf("slowmotion (press B) and shield (press Y)");

	//VRAM B for sprite
	VRAM_B_CR = VRAM_ENABLE|VRAM_B_MAIN_SPRITE_0x06400000;
}

void graphics_init_spriteWelcome(void){
	//animation variable
	cat_state=1;
	gfx_cnt=0;
	x_pos_sprite = 105;
	y_pos_sprite = 130;
	cat_state=1;
	cat_rot = 1;

	oamInit(&oamMain, SpriteMapping_1D_32, false);

	//allocating memory for sprite graphics
	gfx1 = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	gfx2 = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	gfx3 = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);

	//copying palette and tiles
	dmaCopy(NyanCat1Pal,SPRITE_PALETTE,NyanCat1PalLen);
	dmaCopy(NyanCat4Tiles,gfx1,NyanCat4TilesLen);
	dmaCopy(NyanCat5Tiles,gfx2,NyanCat5TilesLen);
	dmaCopy(NyanCat6Tiles,gfx3,NyanCat6TilesLen);

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
			cat_rot, false,//Horizontal or vertical flip
			false);//Mosaic
	oamUpdate(&oamMain);
}

void graphics_animeWelcomeCat(void){
	if(++gfx_cnt>=25){
		gfx_cnt=0;
		switch(cat_state){
			case 1:	cat_state=2;
					gfx_active=gfx1;
					break;
			case 2:	cat_state=3;
					gfx_active=gfx2;
					break;
			case 3: cat_state=4;
					gfx_active=gfx3;
					break;
			case 4:	cat_state=1;
					gfx_active=gfx1;
					break;
			default: break;
			}
		//updating sprite
		oamSet(	&oamMain,//oam handler
				0,//Number of sprite
				x_pos_sprite, y_pos_sprite,//Coordinates
				0,//Priority
				0,//Palette to use
				SpriteSize_32x32,//sprite size
				SpriteColorFormat_256Color,//Color format
				gfx_active,//Loaded graphic to display
				-1,//Affine rotation to use (-1 none)
				false,//Double size if rotating
				hide_sprite,//Hide this sprite
				cat_rot, false,//Horizontal or vertical flip
				false);//Mosaic
		oamUpdate(&oamMain);
	}
}

void graphics_WelcomeFree(void){
	oamClear(&oamMain,0,1);
	oamFreeGfx(&oamMain, gfx1);
	oamFreeGfx(&oamMain, gfx2);
	oamFreeGfx(&oamMain, gfx3);
}
