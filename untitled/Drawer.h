#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "Field.h"
#ifndef UNTITLED_DRAWER_H
#define UNTITLED_DRAWER_H


class Drawer {
public:
    void draw(Cell cell, Field& field, sf::RenderWindow &window){
        sf::Texture wall_texture;
        wall_texture.loadFromFile("Saved Pictures/wall.png");
        sf::Sprite wall;
        wall.setTexture(wall_texture);

        sf::Texture Arrow_texture;
        Arrow_texture.loadFromFile("Saved Pictures/Arrow.png");
        sf::Sprite Arrow;
        Arrow.setTexture(Arrow_texture);

        sf::Texture none_texture;
        none_texture.loadFromFile("Saved Pictures/none.png");
        sf::Sprite none;
        none.setTexture(none_texture);

        sf::Texture snake_texture;
        snake_texture.loadFromFile("Saved Pictures/snake.png");
        sf::Sprite snake;
        snake.setTexture(snake_texture);

        for (int i = 0; i < field.get_y_size(); i++) {
            for (int j = 0; j < field.get_x_size(); j++) {
                if (field.get_mat(i,j).is_none) {
                    none.setPosition(float(j * cell.get_cell_size()), float(i * cell.get_cell_size()));
                    window.draw(none);
                }
                if (field.get_mat(i,j).is_player) {
                    snake.setPosition(float(j * cell.get_cell_size()), float(i * cell.get_cell_size()));
                    window.draw(snake);
                }
                if (field.get_mat(i,j).arrow()) {
                    Arrow.setPosition(float(j * cell.get_cell_size()), float(i * cell.get_cell_size()));
                    window.draw(Arrow);
                }

                if (field.get_mat(i,j).is_wall) {
                    wall.setPosition(float(j * cell.get_cell_size()), float(i * cell.get_cell_size()));
                    window.draw(wall);
                }

            }
        }
    }

};


#endif //UNTITLED_DRAWER_H
