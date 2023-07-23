#include <iostream>
#define CONSOLE_WIDTH 150
#define CONSOLE_HEIGHT 50
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
            video_buffer[i] = 0;
    }

    void update(){
        char symbol;
        for (size_t i = 0; i < CONSOLE_HEIGHT; i++){
            for (size_t j = 0; j < CONSOLE_WIDTH; j++){
                switch (video_buffer[CONSOLE_WIDTH * i + j]){
                case 0:
                    symbol = ' ';
                    break;
                case 1:
                    symbol = '#';
                    break;
                default:
                    symbol = '?';
                    break;
                }
                std::cout << symbol;
            }
            std::cout << std::endl;
        }
    }
};

int main(){
    system(CONSOLE_MODE_COMMAND); // resize Windows console

    Console console = Console();

    console.update();
    system("pause");
}
