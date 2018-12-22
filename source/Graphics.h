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

void graphics_setup_BG1(void);

void graphics_setup_BG2(void);

void graphics_shift_main(void);

void graphics_shift_back(void);

void graphics_shift_sprite(void);

void graphics_handle_input(void);

#endif /* GRAPHICS_H_ */
