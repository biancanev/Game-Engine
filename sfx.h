/*********************************
* Header file for sound effects
* 
* See sfx.cpp for full description
*********************************/
#ifndef SFX_CLASS_H
#define SFX_CLASS_H

#include <string>
#include "basic.h"


class Sound{
    public:
        const char* file;//file name
        Location source;//location of the sound in 3D space
        Sound(const char* file_name, Location source);//constructor
        ~Sound();//destructor

        void callSpatialSound(Location destination, float radius, bool repeat);//play file in 3D space
        void callLocalizedSound(bool repeat);//play file in 2D space
};

#endif