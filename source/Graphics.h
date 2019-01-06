/*
 * Graphics.h
 *
 *  Created on: Nov 3, 2018
 *      Author: nds
 */

#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <nds.h>

//definition of powerup states
enum POWERUP_STATE{NONE_STATE,SLOW_STATE,BOOST_STATE,SHIELD_STATE,MINI_SHIELD_STATE};
//definition of collision report
enum COLLISION_TYPE {SLOWMOCOL,BOOSTCOL,SHIELDCOL,OBSTACLECOL,NONECOL};
//definition of powerup types
enum POWERUP_TYPE{SLOWMO,BOOST,SHIELD};

void graphics_update_map(int index);

void graphics_init(void);

void graphics_init_sprite(void);

void graphics_setup_BG0(void);

void graphics_setup_BG1(void);

void graphics_setup_BG2(void);

void graphics_setupBG2_sub(void);

void graphics_setupBG1_sub(void);

void graphics_drawNumber(int row_offset, int col_offset, int number);

void graphics_shift_main(void);

void graphics_shift_back(void);

void graphics_shift_sprite(int powerup_state);

void graphics_jump(int powerup_state);

int  graphics_checkCollision(int powerup_state);

void graphics_game_over(void);

void graphics_updateScreen(void);

void graphics_drawRainbow(void);

void graphics_clearRainbow(void);

void graphics_setSpriteVisibility(int visible);

void graphics_toggleRainbow(void);

void graphics_updatePoints(int points);

void graphics_drawNum(enum POWERUP_TYPE type, int num);

void graphics_setConsole(enum POWERUP_TYPE type);

void graphics_initKeyboard(void);

void graphics_dispName(char *name,int NAME_MAX);

#endif /* GRAPHICS_H_ */
