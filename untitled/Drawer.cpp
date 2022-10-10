#include "Drawer.h"


void Drawer::draw(Cell cell, Field& field, sf::RenderWindow &window){
    sf::Texture wall_texture;
    wall_texture.loadFromFile("Saved Pictures/wall.png");
    sf::Sprite wall;
    wall.setTexture(wall_texture);

    sf::Texture Key_texture;
    Key_texture.loadFromFile("Saved Pictures/Key.png");
    sf::Sprite Key;
    Key.setTexture(Key_texture);

    sf::Texture Coin_texture;
    Coin_texture.loadFromFile("Saved Pictures/Coin.png");
    sf::Sprite Coin;
    Coin.setTexture(Coin_texture);

    sf::Texture Potion_texture;
    Potion_texture.loadFromFile("Saved Pictures/Potion.png");
    sf::Sprite Potion;
    Potion.setTexture(Potion_texture);

    sf::Texture Skull_texture;
    Skull_texture.loadFromFile("Saved Pictures/Skull.png");
    sf::Sprite Skull;
    Skull.setTexture(Skull_texture);

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
            if (field.get_mat(i,j).none_is()) {
                none.setPosition(float(j * cell.get_cell_size()), float(i * cell.get_cell_size()));
                window.draw(none);
            }
            if (field.get_mat(i,j).coin_is()) {
                Coin.setPosition(float(j * cell.get_cell_size()), float(i * cell.get_cell_size()));
                window.draw(Coin);
            }
            if (field.get_mat(i,j).key_is()) {
                Key.setPosition(float(j * cell.get_cell_size()), float(i * cell.get_cell_size()));
                window.draw(Key);
            }
            if (field.get_mat(i,j).potion_is()) {
                Potion.setPosition(float(j * cell.get_cell_size()), float(i * cell.get_cell_size()));
                window.draw(Potion);
            }
            if (field.get_mat(i,j).skull_is()) {
                Skull.setPosition(float(j * cell.get_cell_size()), float(i * cell.get_cell_size()));
                window.draw(Skull);
            }
            if (field.get_mat(i,j).player_is()) {
                snake.setPosition(float(j * cell.get_cell_size()), float(i * cell.get_cell_size()));
                window.draw(snake);
            }
            if (field.get_mat(i,j).arrow_is()) {
                Arrow.setPosition(float(j * cell.get_cell_size()), float(i * cell.get_cell_size()));
                window.draw(Arrow);
            }

            if (field.get_mat(i,j).wall_is()) {
                wall.setPosition(float(j * cell.get_cell_size()), float(i * cell.get_cell_size()));
                window.draw(wall);
            }

        }
    }
}

