#include <iostream>
#include <string>
#include "settings.cpp"
#include "Console.cpp"
#include "Coord.cpp"
#include "Object.cpp"

using My::Console;

int main(){
    Console console = Console();
    console.resize_console();
    for (size_t i = 20; i < 50; i++){
        console.set(i + 50, i, 180);
    }
    
    console.draw_buffer();

    system("pause");
}
