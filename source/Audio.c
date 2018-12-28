/*
 * Audio.c
 *
 *  Created on: Dec 27, 2018
 *      Author: nds
 */

#include "Audio.h"

mm_sfxhand boostHand;
mm_sfxhand slowmoHand;
mm_sfxhand shieldHand;

void Audio_Init()
{
	//Init the sound library
	mmInitDefaultMem(soundbank_bin);
	//Load module
	mmLoad(MOD_DIPPYHAPPYPLAINS);
	//Load effects
	mmLoadEffect(SFX_NYANSHORT);
}

void Audio_PlayMusic()
{
	//Start playing music in a loop
	mmStart(MOD_DIPPYHAPPYPLAINS,MM_PLAY_LOOP);
	mmSetModuleVolume(512);
}

void Audio_startBoost(){
	mmPause();
	boostHand = mmEffect(SFX_NYANSHORT);
}

void Audio_endBoost(){
	mmResume();
	mmEffectCancel(boostHand);
}

void Audio_startSlowmo(){
	mm_sound_effect sound;
	sound.id = SFX_NYANSHORT;
	//Set the rate to the default one (1024)
	sound.rate = 512;
	sound.volume = 255;
	sound.panning = 127;
	mmPause();
	slowmoHand = mmEffectEx(&sound);
}

void Audio_endSlowmo(){
	mmResume();
	mmEffectCancel(slowmoHand);
}
