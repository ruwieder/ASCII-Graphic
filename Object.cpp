#include <stdint.h>
#include "Coord.cpp"

struct Object{
public:
    Coord pos;
    virtual coord_type get_collision_length();
};
