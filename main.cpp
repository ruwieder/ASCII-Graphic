#include <iostream>
#include <cmath>
#define PI 3.1415926535897932l
#define CONSOLE_WIDTH 150
#define CONSOLE_HEIGHT 50
#define SYMBOL_CONST 3.5
#define CONSOLE_MODE_COMMAND "mode 150, 52"

class Console{
private:
    uint8_t video_buffer[CONSOLE_WIDTH * CONSOLE_HEIGHT];
public:
    Console(){
        buffer_init();
    }

    void buffer_init(){
        for (size_t i = 0; i < CONSOLE_HEIGHT * CONSOLE_WIDTH; i++)
            video_buffer[i] = ' ';
    }

    void update(){
        for (size_t i = 0; i < CONSOLE_HEIGHT; i++){
            for (size_t j = 0; j < CONSOLE_WIDTH; j++){
                std::cout << video_buffer[CONSOLE_WIDTH * i + j];
            }
        }
    }

    void set(uint16_t x, uint16_t y, uint8_t symbol){
        video_buffer[y * CONSOLE_WIDTH + x] = symbol;
    }

    void draw_ellipse(uint8_t x, uint8_t y, unsigned size, uint8_t symbol = '#', float ratio = 1){
        for (uint8_t i = 0; i < CONSOLE_HEIGHT; i++)
    {
        for (uint8_t j = 0; j < CONSOLE_WIDTH; j++)
        {
            if (pow(abs(i - y), 2) + pow(abs(j - x), 2) / SYMBOL_CONST <= size * size){
                    this->set(j, i, symbol);
                }
        }
    }
    }
};

int main(){
    system(CONSOLE_MODE_COMMAND); // resize Windows console
    Console console = Console();

    console.draw_ellipse(75, 25, 10, '^');
    console.update();

    system("pause");
}
