#include <SFML/Graphics.hpp>
#ifndef UNTITLED_CONTROLLER_H
#define UNTITLED_CONTROLLER_H


class Controller {
private:
    bool UP = false;
    bool DOWN = false;
    bool RIGHT = false;
    bool LEFT = false;
public:
    bool get_up(){
        return UP;
    }
    bool get_down(){
        return DOWN;
    }
    bool get_right(){
        return RIGHT;
    }
    bool get_left(){
        return LEFT;
    }
    void player_handler(){
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

};


#endif //UNTITLED_CONTROLLER_H
