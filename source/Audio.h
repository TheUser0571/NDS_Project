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

void Audio_Init(void);
void Audio_PlayMusic(void);
void Audio_startBoost(void);
void Audio_endBoost(void);
void Audio_startSlowmo(void);
void Audio_endSlowmo(void);
void Audio_pickup(void);

#endif /* AUDIO_H_ */
