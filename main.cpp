#include <iostream>
#define CONSOLE_WIDTH 150
#define CONSOLE_HEIGHT 50
#define SYMBOL_CONST 3.5
#define SYMBOLS_COUNT 8
#include "Console.cpp"
#include "Coord.cpp"
#include "Object.cpp"
#define CONSOLE_MODE_COMMAND "mode 150, 52"

using My::Console;

int main(){
    system(CONSOLE_MODE_COMMAND); // resize Windows console
    Console console = Console();
    for (size_t i = 20; i < 50; i++){
        console.set(i + 50, i, 180);
    }
    
    console.draw_buffer();

    system("pause");
}
