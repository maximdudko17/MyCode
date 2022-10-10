#include <SFML/Graphics.hpp>
#include "conio.h"
#ifndef UNTITLED_CONTROLLER_H
#define UNTITLED_CONTROLLER_H


class Command_Reader {
private:
    bool UP = false;
    bool DOWN = false;
    bool RIGHT = false;
    bool LEFT = false;
public:
    bool get_up();

    bool get_down();

    bool get_right();

    bool get_left();

    void player_handler();

};


#endif //UNTITLED_CONTROLLER_H
