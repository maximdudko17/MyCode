#include <iostream>
#include <SFML/Graphics.hpp>
#include <iomanip>
#include "Controller/Command_Reader.h"
#include "Player.h"
#include "FieldCell/Cell.h"
#include "FieldCell/Field.h"
#include "Drawer.h"
#include "Events/Event_Damage_Arrow.h"
#include "Controller/Controller_p.h"
#include <vector>
#include <stdlib.h>

int main() {
    Player player(3);
    Cell cell( 0, player);
    Field f(player, 35,25);
    Drawer drawer;
    Controller_p controller;
    Command_Reader command_reader;
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

        command_reader.player_handler();


        controller.controller(f,player,command_reader);

        if(controller.END()){
            window.close();
        }

        f.add_skull(f);

        f.add_potion(f);

        f.add_coin(f);

        f.add_wall(f);

        f.add_arrow(f);

        f.add_key(f,player);

        window.display();

        sf::sleep(sf::milliseconds(100));
    }

    return 0;
}
