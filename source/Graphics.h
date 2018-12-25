/*
 * Graphics.h
 *
 *  Created on: Nov 3, 2018
 *      Author: nds
 */

#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <nds.h>



void graphics_update_map(int index);

void graphics_init(void);

void graphics_init_sprite(void);

void graphics_setup_BG0(void);

void graphics_setup_BG1(void);

void graphics_setup_BG2(void);

void graphics_shift_main(void);

void graphics_shift_back(void);

void graphics_shift_sprite(void);

void graphics_jump(void);

int graphics_checkCollision(void);

void graphics_game_over(void);

void graphics_updateScreen(void);

void graphics_activateSlowmo(void);

#endif /* GRAPHICS_H_ */
