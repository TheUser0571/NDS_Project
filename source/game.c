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
#include "Timer.h"

enum GameState{ACTIVE, GAMEOVER};

int game_state=ACTIVE;

void game_init(void){
	game_state=ACTIVE;
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
	timer_setup(&graphics_shift_main, &graphics_shift_back, &graphics_shift_sprite);
}

void game_checkInput(void){
	scanKeys();
	//if no: begin jump
	if(keysDown()==KEY_A||keysHeld()==KEY_A){
		graphics_jump();
	}else if(keysDown()==KEY_START){
		game_init();
	}else if(keysDown()==KEY_B){
		graphics_activateSlowmo();
	}else if(keysDown()==KEY_X){
		graphics_activateBoost();
	}else if(keysDown()==KEY_Y){
		graphics_activateShield();
	}
}

void game_play(void){
	graphics_updateScreen();
	game_checkInput();
}


