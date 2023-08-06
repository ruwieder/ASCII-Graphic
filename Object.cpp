#include "Coord.cpp"

//abstract class for scene structures
struct Object{
public:
    Coord pos;
    virtual coord_type get_collision_length();
};


struct Sphere:Object{
    coord_type get_collision_length();
};


struct Plane:Object {
    coord_type get_collision_length();
};


struct Cube:Object {
    coord_type get_collision_length();
};


struct SkySphere:Sphere {
    coord_type get_collision_length();
};

