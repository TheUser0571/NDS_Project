/*
 * Template Nintendo DS
 * May 2011
 */

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "Graphics.h"
#include "Timer.h"


int main(void){
	//Initializing rand seed with current time
	srand(clock());
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

    while(1)
    	//wait for action
    	graphics_handle_input();
        swiWaitForVBlank();	
}
