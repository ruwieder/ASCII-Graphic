#include "Coord.cpp"
#include "settings.cpp"
#include <stdint.h>

class Camera{
public:
    Coord camera_pos = Coord(0x7fff, 0x7fff, 0x7fff);
    Coord camera_direction = Coord(0, 0, 0x7fff);
    uint8_t id;
    Scene* scene;
    void calculate(){
        uint16_t delta_y = screen_width / CONSOLE_WIDTH;
        uint16_t delta_z = screen_height * ratio / CONSOLE_HEIGHT;
        for (size_t y = 0; y < CONSOLE_WIDTH; y++)
        {
            for (size_t z = 0; z < CONSOLE_HEIGHT; z++)
            {
                get_closest_length(Coord(
                    camera_pos.x + lens_length,
                    camera_pos.y + (y - (CONSOLE_WIDTH / 2)) * delta_y,
                    camera_pos.z + (z - (CONSOLE_HEIGHT / 2)) * delta_z
                ));
            }
        }
    };

private:
    const uint16_t lens_length = 256;
    const float screen_width = static_cast<float>(lens_length) / tan(HALF_FOV);
    const float screen_height = screen_width * ratio;
    uint16_t get_closest_length(Coord ray_direction){};
};