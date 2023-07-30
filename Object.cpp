#include "Coord.cpp"

//abstract class for scene structures
struct Object{
public:
    Coord pos;
    virtual coord_type get_collision_length();
};


class Plane:Object {
    coord_type get_collision_length();
};


class Cube:Object {
    coord_type get_collision_length();
};