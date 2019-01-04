/*
 * Score.c
 *
 *  Created on: Jan 1, 2019
 *      Author: nds
 */

#include "Score.h"
#include <nds.h>
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
		}
		fclose(file);
	}
}

void Score_readFile(void) {
	fatInitDefault();
	FILE * file = fopen("/nyanscore.txt","r");
	if(file!=NULL) {
		int i = 0;
		for(i = 0; i < NBSCORES; i++) {
			fscanf(file, "%i\n", &scores[i]);
		}
		fclose(file);
	}
	else {
		int i = 0;
		for(i = 0; i < NBSCORES; i++) {
			scores[i] = 0;
		}
	}
	position = NBSCORES;
	score_cnt = 0;
}

void Score_printscoreboard(void) {
	int i = 0;
	for(i = 0; i < NBSCORES; i++) {
		if		(scores[i] == score_cnt && i <  9)
			printf("\x1b[31;1m\t\tposition %i : %i\n", i+1, scores[i]);
		else if (scores[i] != score_cnt && i <  9)
			printf("\x1b[30;1m\t\tposition %i : %i\n", i+1, scores[i]);
		else if (scores[i] == score_cnt && i >= 9)
			printf("\x1b[31;1m\t\tposition %i: %i\n", i+1, scores[i]);
		else
			printf("\x1b[30;1m\t\tposition %i: %i\n", i+1, scores[i]);

	}
	printf("\x1b[30;1m\n Press Start for restarting\n the game\n\n");
	printf("\x1b[30;1m Press X for resetting the\n scores\n\n");
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
	Score_writeFile();
	Score_printscoreboard();
	score_cnt = 0;
}

int Score_increase(int points) {
	score_cnt+= points;
	int i = 0;
	for(i = 0; i < position; i++) {
		//position changing detector
		if(scores[i]<score_cnt) {
			position = i;
			printf("position : %i\n", position+1);
			break;
		}
	}
	return score_cnt;
}


void Score_shifter(int i, int to_shift){
	int j = 0, next;
	for(j = i+1; j < NBSCORES; j++) {
		next = scores[j];
		scores[j] = to_shift;
		to_shift = next;
	}
}


void Score_reset(void){
	int i;
	if(scores[0] != 0){
		printf("\n\tReset done");
		for(i = 0; i < NBSCORES; i++) {
			scores[i] = 0;
		}
		Score_writeFile();
	}
}
