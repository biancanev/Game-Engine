#ifndef sfx.h
#define sfx

#include <string>
#include "basic.h"

class Sound : public Entity {
    std::string file_location;
    Location loc;
};

#endif