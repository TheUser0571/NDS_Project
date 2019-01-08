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
#include "Score.h"

//powerup definitions
int powerup_cnt=0;
int slowmo_count=0, boost_count=0, shield_count=0, points_count=0;
int points=0;
int powerup_state=NONE_STATE;

//name acquisition
char name[NAME_MAX]="         ";

enum GameState{ACTIVE, GAMEOVER};

enum Points{PICKUP = 50, DISTANCE = 1};

int game_state=ACTIVE;

void game_activateShield(void);
void game_activateSlowmo(void);
void game_activateBoost(void);
void game_pickupPowerup(enum POWERUP_TYPE type);
void game_shift_main(void);
void game_over(void);
void game_loadScore(void);

void game_shift_back(){
	if(game_state==ACTIVE){
		graphics_shift_back();
	}
}
void game_shift_sprite(){
	if(game_state==ACTIVE){
		graphics_shift_sprite(powerup_state);
	}
}

void game_init(void){
	game_state=ACTIVE;
	powerup_state=NONE_STATE;
	//Init powerup time count
	powerup_cnt	=0;
	slowmo_count=0;
	boost_count	=0;
	shield_count=0;
	points_count=0;
	points=0;
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
	//initializing BG2_SUB
	graphics_setupBG2_sub();
	//initializing BG1_SUB
	graphics_setupBG1_sub();
	//setting up timers
	timer_setup(&game_shift_main, &game_shift_back, &game_shift_sprite);
	//play music
	Audio_Init();
	Audio_PlayMusic();
}

void game_checkInput(void){
	touchPosition touch;
	scanKeys();
	//if no: begin jump
	if((keysDown()==KEY_A||keysHeld()==KEY_A)&&game_state==ACTIVE){
		graphics_jump(powerup_state);
	}else if(keysDown()==KEY_START){
		game_init();
	}else if(keysDown()==KEY_B&&game_state==ACTIVE){
		game_activateSlowmo();
	}else if(keysDown()==KEY_X&&game_state==ACTIVE){
		game_activateBoost();
	}else if(keysDown()==KEY_X&&game_state==GAMEOVER){
		Score_reset();
	}else if(keysDown()==KEY_Y&&game_state==ACTIVE){
		game_activateShield();
	}else if(keysDown()==KEY_TOUCH&&game_state==ACTIVE){
		touchRead(&touch);
		if(touch.py>103){
			if(touch.px<84){
				game_activateSlowmo();
			}else if(touch.px>172){
				game_activateShield();
			}else{
				game_activateBoost();
			}
		}
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
		}
		shield_count--;
		graphics_drawNum(SHIELD,shield_count);
		powerup_cnt=0;
		powerup_state=SHIELD_STATE;
		consoleClear();
		graphics_setConsole(SHIELD);
	}
}

void game_activateSlowmo(void){
	if(slowmo_count && powerup_state!=SLOW_STATE && powerup_state!=BOOST_STATE){
		if(powerup_state==SHIELD_STATE || powerup_state==MINI_SHIELD_STATE){
			graphics_setSpriteVisibility(false);
		}

		slowmo_count--;
		Audio_startSlowmo();
		timer_startSlowmo();
		graphics_drawNum(SLOWMO,slowmo_count);
		powerup_cnt=0;
		powerup_state=SLOW_STATE;
		consoleClear();
		graphics_setConsole(SLOWMO);
	}
}

void game_activateBoost(void){
	if(boost_count && powerup_state!=BOOST_STATE){
		if(powerup_state==SLOW_STATE){
			Audio_endSlowmo();
			timer_endSlowmo();
		}else if(powerup_state==SHIELD_STATE || powerup_state==MINI_SHIELD_STATE){
			graphics_setSpriteVisibility(false);
		}
		boost_count--;
		timer_startBoost();
		Audio_startBoost();
		graphics_drawNum(BOOST,boost_count);
		powerup_cnt=0;
		powerup_state=BOOST_STATE;
		consoleClear();
		graphics_setConsole(BOOST);
	}
}

void game_pickupPowerup(enum POWERUP_TYPE type){
	if(powerup_state!=BOOST_STATE){
		switch(type){
		case SLOWMO: 	slowmo_count++;
						Score_increase(PICKUP);
						graphics_drawNum(SLOWMO,slowmo_count);
						Audio_pickup();
						break;
		case BOOST: 	boost_count++;
						Score_increase(PICKUP);
						graphics_drawNum(BOOST,boost_count);
						Audio_pickup();
						break;
		case SHIELD: 	shield_count++;
						Score_increase(PICKUP);
						graphics_drawNum(SHIELD,shield_count);
						Audio_pickup();
						break;
		default:		break;
		}
	}
}

void game_shift_main(){
	if(game_state==ACTIVE){
		//Control of powerup timers
		if(powerup_state!=NONE_STATE){
			powerup_cnt++;
			consoleClear();
			if(powerup_state==SLOW_STATE){
				if(powerup_cnt==250){
					Audio_endSlowmo();
					timer_endSlowmo();
					powerup_cnt=0;
					powerup_state=NONE_STATE;
				}else{
					int time = 50-powerup_cnt/5;
					printf("\x1b[31;1m%d.%ds",time/10,time%10);
				}
			}else if(powerup_state==BOOST_STATE){
				graphics_toggleRainbow();
				if(powerup_cnt==600){
					Audio_endBoost();
					timer_endBoost();
					powerup_cnt=0;
					powerup_state=MINI_SHIELD_STATE;
					graphics_clearRainbow();
					consoleClear();
					graphics_setConsole(SHIELD);
				}else{
					int time = 30-powerup_cnt/20;
					printf("\x1b[31;1m%d.%ds",time/10,time%10);
				}
			}else if(powerup_state==SHIELD_STATE){
				if(powerup_cnt==400){
					powerup_cnt=0;
					powerup_state=NONE_STATE;
					graphics_setSpriteVisibility(false);
				}else{
					int time = 40-powerup_cnt/10;
					printf("\x1b[31;1m%d.%ds",time/10,time%10);
				}
			}else if(powerup_state==MINI_SHIELD_STATE){
				if(powerup_cnt==200){
					powerup_cnt=0;
					powerup_state=NONE_STATE;
					graphics_setSpriteVisibility(false);
				}else{
					int time = 20-powerup_cnt/10;
					printf("\x1b[31;1m%d.%ds",time/10,time%10);
				}
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
				game_over();
				break;
			case NONECOL:
				break;
		}
		//every 100ms update points
		if(++points_count==10){
			points_count=0;
			graphics_updatePoints(Score_increase(DISTANCE));
		}
		//Shift main
		graphics_shift_main();
	}
}

void game_over(void){
	timer_disable();
	graphics_game_over();
	Score_insertResult();
	game_state=GAMEOVER;
}

int game_updateName(touchPosition pos,int position){
	int x=pos.px, y=pos.py;
	if(y>37 && y<69){
		if(x<24 && position<NAME_MAX-1){
			name[position]='1';
			return ++position;
		}else if(x< 50 && position<NAME_MAX-1){
			name[position]='2';
			return ++position;
		}else if(x< 76 && position<NAME_MAX-1){
			name[position]='3';
			return ++position;
		}else if(x<102 && position<NAME_MAX-1){
			name[position]='4';
			return ++position;
		}else if(x<128 && position<NAME_MAX-1){
			name[position]='5';
			return ++position;
		}else if(x<154 && position<NAME_MAX-1){
			name[position]='6';
			return ++position;
		}else if(x<180 && position<NAME_MAX-1){
			name[position]='7';
			return ++position;
		}else if(x<209 && position<NAME_MAX-1){
			name[position]='8';
			return ++position;
		}else if(x<237 && position<NAME_MAX-1){
			name[position]='9';
			return ++position;
		}else if(x<256 && position<NAME_MAX-1){
			name[position]='0';
			return ++position;
		}
	}else if(y>74 && y<111){
		if(x<24 && position<NAME_MAX-1){
			name[position]='Q';
			return ++position;
		}else if(x<50 && position<NAME_MAX-1){
			name[position]='W';
			return ++position;
		}else if(x<76 && position<NAME_MAX-1){
			name[position]='E';
			return ++position;
		}else if(x<102 && position<NAME_MAX-1){
			name[position]='R';
			return ++position;
		}else if(x<128 && position<NAME_MAX-1){
			name[position]='T';
			return ++position;
		}else if(x<154 && position<NAME_MAX-1){
			name[position]='Y';
			return ++position;
		}else if(x<180 && position<NAME_MAX-1){
			name[position]='U';
			return ++position;
		}else if(x<209 && position<NAME_MAX-1){
			name[position]='I';
			return ++position;
		}else if(x<237 && position<NAME_MAX-1){
			name[position]='O';
			return ++position;
		}else if(x<256 && position<NAME_MAX-1){
			name[position]='P';
			return ++position;
		}
	}else if(y>115 && y<153){
		if(x<30 && position<NAME_MAX-1){
			name[position]='A';
			return ++position;
		}else if(x< 58 && position<NAME_MAX-1){
			name[position]='S';
			return ++position;
		}else if(x< 86 && position<NAME_MAX-1){
			name[position]='D';
			return ++position;
		}else if(x<114 && position<NAME_MAX-1){
			name[position]='F';
			return ++position;
		}else if(x<142 && position<NAME_MAX-1){
			name[position]='G';
			return ++position;
		}else if(x<170 && position<NAME_MAX-1){
			name[position]='H';
			return ++position;
		}else if(x<223 && position<NAME_MAX-1){
			name[position]='J';
			return ++position;
		}else if(x<234 && position<NAME_MAX-1){
			name[position]='K';
			return ++position;
		}else if(x<256 && position<NAME_MAX-1){
			name[position]='L';
			return ++position;
		}
	}else if(y>158 && y<192){
		if(x<33){
			return position;
		}else if(x< 60 && position<NAME_MAX-1){
			name[position]='Z';
			return ++position;
		}else if(x< 87 && position<NAME_MAX-1){
			name[position]='X';
			return ++position;
		}else if(x<114 && position<NAME_MAX-1){
			name[position]='C';
			return ++position;
		}else if(x<144 && position<NAME_MAX-1){
			name[position]='V';
			return ++position;
		}else if(x<171 && position<NAME_MAX-1){
			name[position]='B';
			return ++position;
		}else if(x<200 && position<NAME_MAX-1){
			name[position]='N';
			return ++position;
		}else if(x<230 && position<NAME_MAX-1){
			name[position]='M';
			return ++position;
		}else if(x>229 && x<256 && position>0){
			name[--position]=' ';
			return position;
		}
	}

	return position;
}

void game_nameAcquisition(){
	//initializing keyboard and console
	graphics_initKeyboard();
	touchPosition pos;
	int position=0;
	while(1){
		//displaying name
		graphics_dispName(name,NAME_MAX);
		//checking input
		scanKeys();
		if(keysDown()==KEY_START){
			if(position==0){
				//name="NONAME";
				sprintf(name,"%s","NONAME   ");
			}
			name[NAME_MAX-1] = '\0';
			Score_readFile(name);
			return;
		} else if(keysDown()==KEY_TOUCH){
			touchRead(&pos);
			position=game_updateName(pos, position);
		}
	}
}

void game_welcomeScreen(void){
	//initializing keyboard and console
	graphics_initWelcome();
	graphics_init_spriteWelcome();
	timer_welcomeAnimation(&graphics_animeWelcomeCat);
	while(1){
		//checking input
		scanKeys();
		//checking input
		if(keysDown()==KEY_START){
			timer_welcomeEnd();
			graphics_WelcomeFree();
			return;
		}
		swiWaitForVBlank();
	}
}

