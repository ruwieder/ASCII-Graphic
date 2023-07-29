#include <iostream>
#include <cmath>
#define PI 3.1415926535897932l
#define CONSOLE_WIDTH 150
#define CONSOLE_HEIGHT 50
#define SYMBOL_CONST 3.5
#define SYMBOLS_COUNT 8
#define CONSOLE_MODE_COMMAND "mode 150, 52"

class Console{
private:
    uint8_t video_buffer[CONSOLE_WIDTH * CONSOLE_HEIGHT];
    const char symbols[SYMBOLS_COUNT]{' ', '.', ',', ':', ';', 'x', 'X', '@'};
public:
    Console(){
        buffer_init();
    }

    void buffer_init(){
        for (size_t i = 0; i < CONSOLE_HEIGHT * CONSOLE_WIDTH; i++)
            video_buffer[i] = 0;
    }

    void update(){
        for (size_t i = 0; i < CONSOLE_HEIGHT; i++){
            for (size_t j = 0; j < CONSOLE_WIDTH; j++){
                std::cout << video_buffer[CONSOLE_WIDTH * i + j];
            }
        }
    }

    void set(uint16_t x, uint16_t y, uint8_t value){
        video_buffer[y * CONSOLE_WIDTH + x] = value;
    }

    void clear_buffer(){
        for (size_t i = 0; i < CONSOLE_HEIGHT * CONSOLE_WIDTH; i++)
        {
            this->video_buffer[i] = 0;
        }
    }

    void draw_buffer(){
        for (size_t i = 0; i < CONSOLE_HEIGHT; i++){
            for (size_t j = 0; j < CONSOLE_WIDTH; j++)
            {
                std::cout << (symbols[video_buffer[i * CONSOLE_WIDTH + j] >> 5]);
            }
        }
    }
};

int main(){
    system(CONSOLE_MODE_COMMAND); // resize Windows console
    Console console = Console();

    console.set(100, 43, 255);
    console.draw_buffer();

    system("pause");
}
