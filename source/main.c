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

int main(void){
	//welcome screen
	game_welcomeScreen();
	game_nameAcquisition();
	//Initializing rand seed with current time
	srand(clock());
	game_init();
    while(1) {
    	//wait for action
    	game_play();
        swiWaitForVBlank();
    }
}
