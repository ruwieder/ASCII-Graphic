#include <vector>
#include "Coord.cpp"
#include "Object.cpp"
#include "Camera.cpp"
#include "settings.cpp"
#include <cmath>
#pragma once


class Scene {
private:
    std::vector<Camera> cameras{};
    std::vector<Cube> cubes{};
    std::vector<Plane> planes{};
public:
    void add_object(Cube cube){
        cubes.push_back(cube);
    };

    void add_object(Plane plane){
        planes.push_back(plane);
    };

    void add_camera(Camera camera){
        camera.id = cameras.size();
        camera.scene = this;
        cameras.push_back(camera);
    };
};
