#include "sfx.h"

int main(){
    Location source = {0.0f, 0.0f, 0.0f};
    Location destination = {0.0f, 0.0f, 0.0f};
    Sound Sound1("solid.wav", source);
    Sound1.callSpatialSound(destination, 6.0f);
    destination = {100.0f, 10.0f, 50.0f};
    Sound1.callSpatialSound(destination, 6.0f);
};