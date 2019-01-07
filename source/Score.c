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
#include <stdlib.h>
#include <fat.h>

#define NBSCORES 10
//best scores
int scores[NBSCORES];
//best scores name
char* names = NULL;
//gamer's name
char gamerName[NAME_MAX];
//position
int position = NBSCORES;
//score counter
int score_cnt;

void Score_shifter(int i, int to_shift, char* to_shiftName);

void Score_writeFile(void) {
	FILE * file = fopen("/nyanscore.txt","w+");
	if(file!=NULL) {
		int i = 0;
		for(i = 0; i < NBSCORES; i++) {
			fprintf(file, "%i %s\n", scores[i],  &names[i*NBSCORES]);
		}
		fclose(file);
	}
}

void Score_readFile(char* gamer) {
	names = malloc(sizeof(char)*NBSCORES*NAME_MAX);
	fatInitDefault();
	sprintf(gamerName, "%s", gamer);
	FILE * file = fopen("/nyanscore.txt","r");
	if(file!=NULL) {
		int i = 0;
		for(i = 0; i < NBSCORES; i++) {
			fscanf(file, "%i %s\n", &scores[i], &names[i*NBSCORES]);
		}
		fclose(file);
	}
	else {
		int i = 0;
		for(i = 0; i < NBSCORES; i++) {
			scores[i] = 0;
			sprintf(&names[i*NBSCORES],"NONAME");
		}
	}
	position = NBSCORES;
	score_cnt = 0;
}

void Score_printscoreboard(void) {
	int i = 0;
	for(i = 0; i < NBSCORES; i++) {
		if		(scores[i] == score_cnt && i <  9)
			printf("\x1b[31;1m\t\t%i %s: %i\n", i+1,
				&names[i*NBSCORES], scores[i]);
		else if (scores[i] != score_cnt && i <  9)
			printf("\x1b[30;1m\t\t%i %s: %i\n", i+1,
				&names[i*NBSCORES], scores[i]);
		else if (scores[i] == score_cnt && i >= 9)
			printf("\x1b[31;1m\t\t%i %s: %i\n", i+1,
				&names[i*NBSCORES], scores[i]);
		else
			printf("\x1b[30;1m\t\t%i%s: %i\n", i+1,
				&names[i*NBSCORES], scores[i]);
	}
	printf("\x1b[30;1m\n Press Start for restarting\n the game\n\n");
	printf("\x1b[30;1m Press X for resetting the\n scores\n\n");
}

void Score_insertResult(void) {
	int i = 0, to_shift = 0;
	char to_shiftName[NAME_MAX];
	for(i = 0; i < NBSCORES; i++) {
		if(scores[i]<score_cnt) {
			to_shift 	 = scores[i];
			sprintf(to_shiftName, "%s", &names[i*NBSCORES]);
			scores[i]	 = score_cnt;
			sprintf(&names[i*NBSCORES], "%s", gamerName);
			break;
		}
	}
	Score_shifter(i, to_shift, to_shiftName);
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


void Score_shifter(int i, int to_shift, char* to_shiftName){
	int j = 0, next;
	char* nextName;
	for(j = i+1; j < NBSCORES; j++) {
		next 	  = scores[j];
		sprintf(nextName, "%s", &names[j*NBSCORES]);

		scores[j] = to_shift;
		sprintf(&names[j*NBSCORES], "%s", to_shiftName);

		to_shift  = next;
		sprintf(to_shiftName, "%s", nextName);
	}
}


void Score_reset(void){
	int i;
	if(scores[0] != 0){
		printf("\x1b[30;1m\n\tReset done");
		for(i = 0; i < NBSCORES; i++) {
			scores[i] = 0;
			sprintf(&names[i*NBSCORES],"NONAME");
		}
		Score_writeFile();
	}
}

void Score_init(void){
	score_cnt=0;
}
