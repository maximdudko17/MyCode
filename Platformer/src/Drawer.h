#include <SFML/Graphics.hpp>
#include "FieldCell/Cell.h"
#include "FieldCell/Field.h"
#ifndef UNTITLED_DRAWER_H
#define UNTITLED_DRAWER_H


class Drawer {
public:
    void draw(Cell cell, Field& field, sf::RenderWindow &window);
};


#endif //UNTITLED_DRAWER_H
