/*
 * Audio.h
 *
 *  Created on: Dec 27, 2018
 *      Author: nds
 */

#include <nds.h>

#include "soundbank_bin.h"
#include "soundbank.h"

#include <maxmod9.h>
#include <mm_types.h>


#ifndef AUDIO_H_
#define AUDIO_H_

void Audio_Init();
void Audio_PlayMusic();
void Audio_startBoost();
void Audio_endBoost();
void Audio_startSlowmo();
void Audio_endSlowmo();

#endif /* AUDIO_H_ */
