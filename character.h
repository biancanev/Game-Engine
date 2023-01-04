#ifndef character.h
#define character.h

//include libraries
#include <string>
#include <vector>
#include "weapon.h"
#include "basic.h"
#include "sfx.h"

//main character setup
class Pawn : public Entity {
public:
    int id;
    int hp;
    int shield;
    std::string name;
    Weapon wpn;
    Position pos;
    Character* next;
    void destroy(int id);
    void character_info() {

    };
};

class Character : public Pawn {
public:
    void collision(Entity& other) {
        //if character collides with 
        if (auto sound = dynamic_cast<Sound*>(&other)) {

        }
    };
};
#endif