/*
 * Template Nintendo DS
 * May 2011
 */

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "game.h"
#include "Audio.h"

#define NAME_MAX 10

int main(void){
	//welcome screen
	game_welcomeScreen();
	//name acquisition
	char name[NAME_MAX]="          ";
	game_nameAcquisition(name, NAME_MAX);
	//Initializing rand seed with current time
	srand(clock());
	game_loadScore();
	game_init();
    while(1) {
    	//wait for action
    	game_play();
        swiWaitForVBlank();
    }
}
