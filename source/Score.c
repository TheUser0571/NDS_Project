/*
 * Score.c
 *
 *  Created on: Jan 1, 2019
 *      Author: nds
 */

#include "Score.h"
#include <string.h>
#include <stdio.h>
#include <fat.h>

#define NBSCORES 10
//best scores
int scores[NBSCORES];
//position
int position = NBSCORES;
//score counter
int score_cnt;

void Score_shifter(int i, int to_shift);

void Score_writeFile(void) {
	FILE * file = fopen("/nyanscore.txt","w+");
	if(file!=NULL) {
		int i = 0;
		for(i = 0; i < NBSCORES; i++) {
			fprintf(file, "%i\n", scores[i]);
			//debug
			printf("score : %i\n", scores[i]);
		}
		fclose(file);
	}
}

void Score_readFile(void) {
	FILE * file = fopen("/nyanscore.txt","r");
	if(file!=NULL) {
		int i = 0;
		for(i = 0; i < NBSCORES; i++) {
			fscanf(file, "%i\n", &scores[i]);
			//debug
			printf("read score : %i\n", scores[i]);
		}
		fclose(file);
	}
	else {
		int i = 0;
		for(i = 0; i < NBSCORES; i++) {
			scores[i] = 0;
		}
		//debug
		printf("init of scores\n");
	}
	position = NBSCORES;
	score_cnt = 0;
}

void Score_printscoreboard(void) {
	int i = 0;
	for(i = 0; i < NBSCORES; i++) {
		printf("position %i : %i\n", i, scores[i]);
	}
}

void Score_insertResult(void) {
	int i = 0, to_shift = 0;
	for(i = 0; i < NBSCORES; i++) {
		if(scores[i]<score_cnt) {
			to_shift = scores[i];
			scores[i] = score_cnt;
			break;
		}
	}
	Score_shifter(i, to_shift);
	position = NBSCORES;
	score_cnt = 0;
	Score_writeFile();
	Score_printscoreboard();
}

void Score_increase(void) {
	score_cnt++;
	int i = 0;
	for(i = 0; i < position; i++) {
		//position changing detector
		if(scores[i]<score_cnt) {
			position = i;
			printf("position : %i\n", position+1);
			break;
		}
	}
}


void Score_shifter(int i, int to_shift) {
	int j = 0, next;
	for(j = i+1; j < NBSCORES; j++) {
		next = scores[j];
		scores[j] = to_shift;
		to_shift = next;
	}
}
