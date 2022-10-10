#ifndef UNTITLED_FIELD_H

#define UNTITLED_FIELD_H
#include <iostream>
#include "../Controller/Command_Reader.h"
#include "../Player.h"
#include "Cell.h"
#include "../Events/Event_Damage_Arrow.h"
#include <vector>

class Field {
private:
    int cell_size = 32;
    int x_size;
    int y_size;
    int window_width;
    int window_height;
    typedef std::vector<std::vector<Cell>> CellMatrix;
    size_t x_mat;
    size_t y_mat;
    CellMatrix mat;
    int player_position_x;
    int player_position_y;
    Player& player = player;

public:
    Field(Player& player, int Xsize, int Ysize);

    Field(const Field& obj);

    Field& operator=(const Field& obj);

    Field(Field&& obj);

    Field& operator=(Field&& obj);

    int get_window_width();

    bool get_end_game();

    int get_window_height();

    int get_x_size();

    int get_y_size();

    void change_plus_player_position_x(int n);

    void change_plus_player_position_y(int n);

    void change_equal_player_position_x(int n);

    void change_equal_player_position_y(int n);

    int get_player_position_x();

    int get_player_position_y();

    void create_map();


    Cell get_mat(int I, int J);

    int random_pos();

    void add_arrow(Field& field);

    void add_coin(Field& field);

    void add_skull(Field& field);

    void add_potion(Field& field);

    void add_wall(Field& field);

    void add_key(Field& field, Player& player);

    void action_event();

    void player_moved();

    void none_moved();
};
#endif UNTITLED_FIELD_H


