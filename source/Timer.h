/*
 * Timer.h
 *
 *  Created on: Nov 3, 2018
 *      Author: nds
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <nds.h>

void timer_setup(void* fun_handler_main, void* fun_handler_back, void* fun_handler_sprite);

void timer_disable(void);

void timer_startSlowmo(void);

void timer_endSlowmo(void);

#endif /* TIMER_H_ */
