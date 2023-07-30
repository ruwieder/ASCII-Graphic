#include <iostream>
#include <string>
#include "settings.cpp"
#include "Console.cpp"
#include "Coord.cpp"
#include "Object.cpp"

void resize_console(){
    std::string _width = std::to_string(CONSOLE_WIDTH);
    std::string _height = std::to_string(CONSOLE_HEIGHT + 2);
    std::string _command = "mode " + _width + ", " + _height;
    system(_command.c_str());
}

using My::Console;

int main(){
    resize_console();

    Console console = Console();
    for (size_t i = 20; i < 50; i++){
        console.set(i + 50, i, 180);
    }
    
    console.draw_buffer();

    system("pause");
}
