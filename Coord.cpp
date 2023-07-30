typedef unsigned short coord_type;
#pragma once

struct Coord{
    coord_type x;
    coord_type y;
    coord_type z;
    Coord(coord_type x, coord_type y, coord_type z){
        Coord::x = x;
        Coord::y = y;
        Coord::z = z;
    };
};