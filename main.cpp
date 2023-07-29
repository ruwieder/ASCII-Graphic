#include <iostream>
#define CONSOLE_WIDTH 150
#define CONSOLE_HEIGHT 50
#define SYMBOL_CONST 3.5
#define SYMBOLS_COUNT 8
#include "Console.cpp"
#define CONSOLE_MODE_COMMAND "mode 150, 52"

using My::Console;

int main(){
    system(CONSOLE_MODE_COMMAND); // resize Windows console
    Console console = Console();

    console.set(100, 43, 255);
    console.draw_buffer();

    system("pause");
}
