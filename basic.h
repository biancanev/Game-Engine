#ifndef BASIC_CLASS_H
#define BASIC_CLASS_H

//define basic structure for storing locations
struct Location {
    //rectalinear coordinates
    float x;
    float y;
    float z;
};

//define basic structure for storing rotations
struct Rotator {
    //degrees on x, y, and z axis
    float roll;
    float pitch;
    float yaw;
};

//define basic structure for storing scaling
struct Scale {
    float x;
    float y;
    float z;
};

//If needed, define structure to store all possible orientations
struct Position {
    Location loc;
    Rotator rot;
    Scale scl;
};

//TODO: Define velocity vectors
struct Velocity {
    Rotator dir;
    int mag;
};

//create basic camera struct
struct Camera {
    Location loc;
    Rotator rot;
};

//Define base entity class for polymorphism
class Entity {
public:
    //track position(location, rotation, scale)
    Position pos;
};
#endif