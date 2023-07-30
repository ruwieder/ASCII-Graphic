#include <vector>
#include "Coord.cpp"
#include "Object.cpp"
#pragma once

class Scene {
private:
    Coord camera_pos = Coord(0x7fff, 0x7fff, 0x7fff);
    Coord camera_direction = Coord(0, 0, 0);

    std::vector<Cube> cubes{};
    std::vector<Plane> planes{};

public:
    void add_object(Cube cube){
        cubes.push_back(cube);
    };

    void add_object(Plane plane){
        planes.push_back(plane);
    };

};