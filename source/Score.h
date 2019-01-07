/*
 * Score.h
 *
 *  Created on: Jan 1, 2019
 *      Author: nds
 */

#ifndef SCORE_H_
#define SCORE_H_

#define NAME_MAX 10

void Score_readFile(char* gamer);
void Score_insertResult(void);
int  Score_increase(int points);
void Score_reset(void);
void Score_init(void);

#endif /* SCORE_H_ */
