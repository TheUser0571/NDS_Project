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


int main(void){
	consoleDemoInit();
	//Initializing rand seed with current time
	srand(clock());
	game_init();
    while(1)
    	//wait for action

    	game_play();
        swiWaitForVBlank();	
}
