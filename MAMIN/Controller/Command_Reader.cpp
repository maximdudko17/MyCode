#include "Command_Reader.h"

bool Command_Reader::get_up(){
    return UP;
}
bool Command_Reader::get_down(){
    return DOWN;
}
bool Command_Reader::get_right(){
    return RIGHT;
}
bool Command_Reader::get_left(){
    return LEFT;
}
void Command_Reader::player_handler(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        UP = true;
        DOWN = false;
        RIGHT = false;
        LEFT = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        UP = false;
        DOWN = true;
        RIGHT = false;
        LEFT = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        UP = false;
        DOWN = false;
        RIGHT = false;
        LEFT = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        UP = false;
        DOWN = false;
        RIGHT = true;
        LEFT = false;
    }
}
