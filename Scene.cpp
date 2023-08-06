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

    coord_type get_closest_collision(Coord ray_direction){
        coord_type min_lenght = COORD_MAX;
        coord_type length;
        for (size_t i = 0; i < cubes.size(); i++){   
            length = cubes[i].get_collision_length();

            if (length == 0) length = COORD_MAX;

            if (length < min_lenght)
                min_lenght = length;
        }
        
        for (size_t i = 0; i < planes.size(); i++){   
            length = planes[i].get_collision_length();

            if (length == 0) length = COORD_MAX;

            if (length < min_lenght)
                min_lenght = length;
        }
        return min_lenght;
    };
};
