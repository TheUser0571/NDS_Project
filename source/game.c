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

void game_over(void){
	graphics_game_over();
	game_state=GAMEOVER;
}

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
	if(keysDown()==KEY_A){
		graphics_jump();
	}else if(keysDown()==KEY_START){
		game_init();
	}
}

void game_checkCollision(void){
	if(graphics_checkCollision()){
		//game_over();
		timer_disable();
	}
}

void game_play(void){
	//game_checkCollision();
	game_checkInput();

}

