#include <iostream>
#include <SFML/Graphics.hpp>
#include <iomanip>
#include "Controller.h"
#include "Player.h"
#include "Cell.h"
#include "Field.h"
#include "Drawer.h"
#include "Event_Damage_Arrow.h"
#include <vector>
#include <stdlib.h>

int main() {
    Cell cell(0);
    Field f(35,25);
    Drawer drawer;
    Player player(3);
    Controller controller;
    Event_Damage_Arrow eventStaticApple;
    f.create_map();

    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(f.get_window_width(), f.get_window_height()), "untitled", sf::Style::Close);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(183,212,167));

        drawer.draw(cell, f, window);

        controller.player_handler();


        f.move(controller,player);

        if(f.get_end_game()){
            window.close();
        }

        f.add_wall();

        f.add_arrow();

        window.display();

        sf::sleep(sf::milliseconds(100));
    }

    return 0;
}
