/*
 * game.c
 *
 *  Created on: Dec 22, 2018
 *      Author: nds
 */
#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "Graphics.h"
#include "Audio.h"
#include "Timer.h"

//powerup definitions
int powerup_cnt=0;
int slowmo_count=0, boost_count=0, shield_count=0;
int powerup_state=NONE_STATE;

enum GameState{ACTIVE, GAMEOVER};

int game_state=ACTIVE;

void game_activateShield(void);
void game_activateSlowmo(void);
void game_activateBoost(void);
void game_pickupPowerup(enum POWERUP_TYPE type);
void game_shift_main();

void game_shift_back(){
	graphics_shift_back();
}
void game_shift_sprite(){
	graphics_shift_sprite(powerup_state);
}

void game_init(void){
	game_state=ACTIVE;
	powerup_state=NONE_STATE;
	//Init powerup time count
	powerup_cnt	=0;
	slowmo_count=0;
	boost_count	=0;
	shield_count=0;
	//Initializing VRAM and BGCNT
	graphics_init();
	//setting up BG1
	graphics_setup_BG1();
	//setting up BG2
	graphics_setup_BG2();
	//setting up BG0
	graphics_setup_BG0();
	//initializing sprite
	graphics_init_sprite();
	//setting up timers
	timer_setup(&game_shift_main, &game_shift_back, &game_shift_sprite);
	//play music
	Audio_Init();
	Audio_PlayMusic();
}

void game_checkInput(void){
	scanKeys();
	//if no: begin jump
	if(keysDown()==KEY_A||keysHeld()==KEY_A){
		graphics_jump(powerup_state);
	}else if(keysDown()==KEY_START){
		game_init();
	}else if(keysDown()==KEY_B){
		game_activateSlowmo();
	}else if(keysDown()==KEY_X){
		game_activateBoost();
		powerup_cnt=0;
	}else if(keysDown()==KEY_Y){
		game_activateShield();
		powerup_cnt=0;
	}
}

void game_play(void){
	graphics_updateScreen();
	game_checkInput();
}

void game_activateShield(void){
	if(shield_count && powerup_state!=SHIELD_STATE && powerup_state!=BOOST_STATE){
		if(powerup_state==SLOW_STATE){
			Audio_endSlowmo();
			timer_endSlowmo();
			printf("\nSlowmo deactivated\n");
		}
		shield_count--;
		powerup_cnt=0;
		powerup_state=SHIELD_STATE;
		printf("\nShield activated\nshield_count: %d\n", shield_count);
	}
}

void game_activateSlowmo(void){
	if(slowmo_count && powerup_state!=SLOW_STATE && powerup_state!=BOOST_STATE){
		if(powerup_state==SHIELD_STATE || powerup_state==MINI_SHIELD_STATE){
			graphics_setSpriteVisibility(false);
			printf("\nShield deactivated\n");
		}

		slowmo_count--;
		Audio_startSlowmo();
		timer_startSlowmo();
		powerup_cnt=0;
		powerup_state=SLOW_STATE;
		printf("\nSlowmo activated\nslowmo_count: %d",slowmo_count);
	}
}

void game_activateBoost(void){
	if(boost_count && powerup_state!=BOOST_STATE){
		if(powerup_state==SLOW_STATE){
			Audio_endSlowmo();
			timer_endSlowmo();
			printf("\nSlowmo deactivated\n");
		}else if(powerup_state==SHIELD_STATE || powerup_state==MINI_SHIELD_STATE){
			graphics_setSpriteVisibility(false);
			printf("\nShield deactivated\n");
		}
		boost_count--;
		timer_startBoost();
		Audio_startBoost();
		powerup_cnt=0;
		powerup_state=BOOST_STATE;
		printf("\nBoost activated\nboost_count: %d\n",boost_count);
	}
}

void game_pickupPowerup(enum POWERUP_TYPE type){
	if(powerup_state!=BOOST_STATE){
		switch(type){
		case SLOWMO: 	slowmo_count++;
						printf("\nslowmo_count: %d\n",slowmo_count);
						break;
		case BOOST: 	boost_count++;
						printf("\nboost_count: %d\n",boost_count);
						break;
		case SHIELD: 	shield_count++;
						printf("\nshield_count: %d\n",shield_count);
						break;
		default:		break;
		}
	}
}

void game_shift_main(){
	//Control of powerup timers
	if(powerup_state!=NONE_STATE){
		powerup_cnt++;
		if(powerup_state==SLOW_STATE && powerup_cnt==250){
			Audio_endSlowmo();
			timer_endSlowmo();
			powerup_cnt=0;
			powerup_state=NONE_STATE;
			printf("\nSlowmo deactivated\n");
		}else if(powerup_state==BOOST_STATE && powerup_cnt==600){
			Audio_endBoost();
			timer_endBoost();
			powerup_cnt=0;
			powerup_state=MINI_SHIELD_STATE;
			graphics_clearRainbow();
			printf("\nBoost deactivated\n");
		}else if(powerup_state==SHIELD_STATE && powerup_cnt==400){
			powerup_cnt=0;
			powerup_state=NONE_STATE;
			graphics_setSpriteVisibility(false);
			printf("\nShield deactivated\n");
		}else if(powerup_state==MINI_SHIELD_STATE && powerup_cnt==200){
			powerup_cnt=0;
			powerup_state=NONE_STATE;
			graphics_setSpriteVisibility(false);
		}else if(powerup_state==BOOST_STATE){
			graphics_toggleRainbow();
		}
	}

	//Checking for collision
	switch(graphics_checkCollision(powerup_state)){
		case SLOWMOCOL:
			game_pickupPowerup(SLOWMO);
			break;
		case BOOSTCOL:
			game_pickupPowerup(BOOST);
			break;
		case SHIELDCOL:
			game_pickupPowerup(SHIELD);
			break;
		case OBSTACLECOL:
			timer_disable();
			graphics_game_over();
			break;
		case NONECOL:
			break;
	}

	//Shift main
	graphics_shift_main();
}
