#ifndef UNTITLED_FIELD_H

#define UNTITLED_FIELD_H
#include <iostream>
#include "../Player.h"
#include "Cell.h"
#include <vector>

class Field {
private:
    int x_size;
    int y_size;
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

    int get_x_size();

    int get_y_size();

    void change_plus_player_position_x(int n);

    void change_plus_player_position_y(int n);

    void change_equal_player_position_x(int n);

    void change_equal_player_position_y(int n);

    int get_player_position_x();

    int get_player_position_y();

    void create_map();

    void get_mat_event(int I, int J, Event_Interface* eventInterface);

    Cell get_mat(int I, int J);

    int random_pos(Field& field);

    void add_key(Field& field);

    void action_event();

    bool is_event();

    void player_moved();

    void none_moved();
};
#endif UNTITLED_FIELD_H


