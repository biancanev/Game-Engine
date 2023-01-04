#ifndef gamestate.h
#define gamestate.h

#include "basic.h"
#include "ui.h"

struct GameState {
    struct Window* Window;
    struct Camera camera;
    struct UI interface;
};

struct Controls {
    unsigned int (*w)();//w
    unsigned int (*a)();//a
    unsigned int (*s)();//s
    unsigned int (*d)();//d
    unsigned int (*lc)();//left click
    unsigned int (*rc)();//right click
};

#endif