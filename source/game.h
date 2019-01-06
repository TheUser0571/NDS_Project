/*
 * game.h
 *
 *  Created on: Dec 22, 2018
 *      Author: nds
 */

#ifndef GAME_H_
#define GAME_H_

void game_init(void);

void game_checkInput(void);

void game_play(void);

void game_loadScore(void);

void game_welcomeScreen(void);

void game_nameAcquisition(char *name, int NAME_MAX);

#endif /* GAME_H_ */
