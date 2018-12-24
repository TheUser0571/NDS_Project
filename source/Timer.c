/*
 * Timer.c
 *
 *  Created on: Nov 3, 2018
 *      Author: nds
 */

#include "Timer.h"

int speed;

void timer_setup(void* fun_handler_main, void* fun_handler_back, void* fun_handler_sprite){
	speed=150;
	//initializing timer 0 (BG1)
	irqSet(IRQ_TIMER0, fun_handler_main);
	TIMER_CR(0)=TIMER_ENABLE|TIMER_DIV_64|TIMER_IRQ_REQ;
	TIMER_DATA(0)=TIMER_FREQ_64(speed);
	irqEnable(IRQ_TIMER0);
	//initializing timer 1 (BG2)
	irqSet(IRQ_TIMER1, fun_handler_back);
	TIMER_CR(1)=TIMER_ENABLE|TIMER_DIV_64|TIMER_IRQ_REQ;
	TIMER_DATA(1)=TIMER_FREQ_64(speed/5);
	irqEnable(IRQ_TIMER1);
	//initializing timer 2 (sprite)
	irqSet(IRQ_TIMER2, fun_handler_sprite);
	TIMER_CR(2)=TIMER_ENABLE|TIMER_DIV_64|TIMER_IRQ_REQ;
	TIMER_DATA(2)=TIMER_FREQ_64(250);
	irqEnable(IRQ_TIMER2);
}

void timer_disable(void){
	irqDisable(IRQ_TIMER0);
	irqDisable(IRQ_TIMER1);
	irqDisable(IRQ_TIMER2);
}

void timer_increase_speed(void){
	speed=speed+20;
	TIMER_DATA(0)=TIMER_FREQ_64(speed);
	TIMER_DATA(1)=TIMER_FREQ_64(speed/5);
}
