#include <SFML/Graphics.hpp>
#include "Controller/Command_Reader.h"
#include "Player.h"
#include "FieldCell/Cell.h"
#include "FieldCell/Field.h"
#include "Drawer.h"
#include "Controller/Controller_p.h"
#include "Logs/Game_Changes.h"
#include "Logs/Logger.h"
#include "Controller/Command_File.h"
#include <stdlib.h>
#include "Field_Gen/Level_Gen.h"



int main() {
    Player player(3);
    Cell cell( 0, player);
    Field field(player,35,25);
    Level_Gen level_gen;
    field = level_gen.switch_mapgen_level(player);
    Drawer drawer;
    Logger logger;
    Controller_p controller;
    Command_Reader command_reader;
    Command_File command_file;
    command_reader.read_commands(command_file);
    Game_Changes game_changes;
    int window_width = field.get_x_size()*cell.get_cell_size();
    int window_height = field.get_y_size()*cell.get_cell_size();
    int out, out_file;
    std::cout<<"Enter log level"<<std::endl;
    std::cin>>out;
    logger.switch_level(out);
    std::cout<<"Enter output level"<<std::endl;
    std::cin>>out_file;
    logger.switch_out(out_file);
    logger.Start(game_changes, logger);
    if(field.get_x_size() < 0  or field.get_y_size() < 0){
        logger.Minus(game_changes, logger);
    }
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "untitled", sf::Style::Close);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(183,212,167));

        drawer.draw(cell, field, window);

        command_reader.player_handler(command_file);

        controller.controller(field,player,command_reader,logger,game_changes);

        field.add_key(field);

        if(controller.END() and player.get_health() != 0){
            logger.WIN(game_changes, logger);
            window.close();
        }

        if(controller.END() and player.get_health() == 0){
            logger.LOSE(game_changes, logger);
            window.close();
        }

        window.display();

        sf::sleep(sf::milliseconds(100));
    }
    logger.End(game_changes, logger);
    return 0;
}
