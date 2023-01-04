#ifndef camera.h
#define camera.h

#include "basic.h"

struct Camera {
    Location loc;
    Rotator rot;
    float view_angle = 130;
};
#endif