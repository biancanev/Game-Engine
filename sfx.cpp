/*****************************************************************
* Source file for sound effects
*
* This file currently has 2 sound types
* 
* Status:
*  - Spatial audio is working
*  - Localized audio has error with nullptr references
*****************************************************************/
#include "sfx.h"
#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>
#include "IrrKlang/irrKlang.h"

#pragma comment(lib, "irrKlang.lib")

//use namespace for irrklang for now for simplicity
using namespace irrklang;
//initialize the sound engine in source file for now. Theoreticalyl, it should go in the main function and be initailized there
ISoundEngine* engine = createIrrKlangDevice();

//Constructor
Sound::Sound(const char* file_name, Location source) {
	file = file_name;//set file to parameter(prevents invalid reading exception)
}

//Destructor
Sound::~Sound() {
	engine->drop();
}

//Spatial sound function
void Sound::callSpatialSound(Location destination, float radius, bool repeat) {
	//get distance between source and target
	float distance = sqrt(pow((source.x - destination.x), 2) + pow((source.y - destination.y), 2) + pow((source.z - destination.z), 2));
	//logic to calculate whether target is within hearing radius
	//logic not really needed, but allows for later changes
	if (distance < radius) {
		//create sound object
		ISound* sound_effect = engine->play3D(file, vec3df(source.x, source.y, source.z), repeat, false, true);
		if (sound_effect) {
			//set range distance
			sound_effect->setMinDistance(radius);
			//get audio length so os can pause thread for roughly the right time;
			int audio_length = sound_effect->getPlayLength();
			//pause
			sound_effect->setMinDistance(radius);
			int audio_length = sound_effect->getPlayLength();
			std::this_thread::sleep_for(std::chrono::milliseconds(audio_length));
		}
	}
}

//Localized sound function
void Sound::callLocalizedSound(bool repeat) {
	ISound* sound_effect = engine->play2D(file, repeat);
	int audio_length = sound_effect->getPlayLength();
	std::this_thread::sleep_for(std::chrono::milliseconds(audio_length));
}
