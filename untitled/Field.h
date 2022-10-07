#ifndef UNTITLED_FIELD_H
#define UNTITLED_FIELD_H
#include <iostream>
#include "Controller.h"
#include "Player.h"
#include "Cell.h"
#include "Event_Damage_Arrow.h"
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
    bool end_game = false;

public:
    Field(int Xsize = 35, int Ysize = 25){
        x_size = Xsize;
        y_size = Ysize;
        window_height = cell_size * y_size;
        window_width = cell_size * x_size;
        x_mat = x_size;
        y_mat = y_size;
        player_position_x = (x_size-2)/2;
        player_position_y = (y_size-2)/2;
    }
    Field(const Field& obj):x_size(obj.x_size), y_size(obj.y_size){
        window_height = cell_size * y_size;
        window_width = cell_size * x_size;
        x_mat = x_size;
        y_mat = y_size;
        player_position_x = (x_size-2)/2;
        player_position_y = (y_size-2)/2;
    }

    Field& operator=(const Field& obj){
        if(this != &obj){
            x_size = obj.x_size;
            y_size = obj.y_size;
            window_height = cell_size * obj.y_size;
            window_width = cell_size * obj.x_size;
            x_mat = obj.x_size;
            y_mat = obj.y_size;
            player_position_x = (obj.x_size-2)/2;
            player_position_y = (obj.y_size-2)/2;

        }
        return *this;
    }

    Field(Field&& obj){
        std::swap(x_size, obj.x_size);
        std::swap(y_size, obj.y_size);
    }

    Field& operator=(Field&& obj){
        if(this != &obj){
            std::swap(x_size, obj.x_size);
            std::swap(y_size, obj.y_size);
        }
        return *this;
    }






    int get_window_width(){
        return window_width;
    }

    bool get_end_game(){
        return end_game;
    }

    int get_window_height(){
        return window_height;
    }

    int get_x_size(){
        return x_size;
    }

    int get_y_size(){
        return y_size;
    }


    void create_map(){
        for(size_t i = 0; i < y_mat; i++){
            mat.push_back(std::vector<Cell>());
            for(size_t j = 0; j < x_mat; j++){
                mat.back().emplace_back(0);
                mat[i][j].is_none = true;
            }
        }
        mat[player_position_y][player_position_x].is_player = true;
        mat[player_position_y][player_position_x].is_none = false;
        mat[player_position_y+2][player_position_x+2].is_wall = true;
        mat[player_position_y-2][player_position_x-2].is_wall = true;
        mat[player_position_y+2][player_position_x+2].is_none = false;
        mat[player_position_y-2][player_position_x-2].is_none = false;

    }


    Cell get_mat(int I, int J){
        for(size_t i = 0; i < y_mat; i++) {
            for (size_t j = 0; j < x_mat; j++) {
                if (i==I and j == J){
                    return mat[i][j];
                }
            }
        }
    }


    int add_arrow(){
        int counter = 0;
        for(size_t i = 1; i < y_mat-1; i++){
            for(size_t j = 1; j < x_mat-1; j++) {
                if (mat[i][j].is_none){
                    counter++;
                }
            }
        }
        int rand_cell = rand() % counter;
        int ind_counter = 0;
        int apple_pos = -1;

        for(size_t i = 1; i < y_mat-1; i++){
            for(size_t j = 1; j < x_mat-1; j++) {
                if (ind_counter == rand_cell){
                    apple_pos =  i * x_size + j;
                }
                ind_counter++;
            }
        }

        int apple_counter = 0;

        for(size_t i = 0; i < y_mat; i++){
            for(size_t j = 0; j < x_mat; j++) {
                if (mat[i][j].arrow()){
                    apple_counter++;
                }
            }
        }
        if (apple_counter < 5) mat[apple_pos / x_size][apple_pos % x_size].switch_status();


    }

    void add_wall(){
        int counter = 0;
        for(size_t i = 1; i < y_mat-1; i++){
            for(size_t j = 1; j < x_mat-1; j++) {
                if (mat[i][j].is_none){
                    counter++;
                }
            }
        }
        int rand_cell = rand() % counter;
        int ind_counter = 0;
        int apple_pos = -1;

        for(size_t i = 1; i < y_mat-1; i++){
            for(size_t j = 1; j < x_mat-1; j++) {
                if (ind_counter == rand_cell){
                    apple_pos =  i * x_size + j;
                }
                ind_counter++;
            }
        }

        int wall_counter = 0;

        for(size_t i = 0; i < y_mat; i++){
            for(size_t j = 0; j < x_mat; j++) {
                if (mat[i][j].is_wall){
                    wall_counter++;
                }
            }
        }
        if (wall_counter < 10) mat[apple_pos / x_size][apple_pos % x_size].is_wall = true;
    }

    void move (Controller controller, Player& player){
        if (controller.get_up()){
            if  (not mat[player_position_y-1][player_position_x].is_wall){
                mat[player_position_y][player_position_x].is_player = false;
                mat[player_position_y][player_position_x].is_none = true;
                player_position_y--;
                if(player_position_y < 1) {
                    player_position_y = y_size - 2;
                }
                if(mat[player_position_y][player_position_x].arrow()){
                    mat[player_position_y][player_position_x].switch_status();
                    mat[player_position_y][player_position_x].damage_arrow(player);
                }
                mat[player_position_y][player_position_x].is_none = false;
                mat[player_position_y][player_position_x].is_player = true;
            }
        }
        if (controller.get_down()){
            if(not mat[player_position_y+1][player_position_x].is_wall){
                mat[player_position_y][player_position_x].is_player = false;
                mat[player_position_y][player_position_x].is_none = true;
                player_position_y++;
                if(player_position_y > y_size-2){
                    player_position_y = 1;
                }
                if(mat[player_position_y][player_position_x].arrow()){
                    mat[player_position_y][player_position_x].switch_status();
                    mat[player_position_y][player_position_x].damage_arrow(player);
                }
                mat[player_position_y][player_position_x].is_none = false;
                mat[player_position_y][player_position_x].is_player = true;
            }
        }
        if (controller.get_left()){
            if(not mat[player_position_y][player_position_x-1].is_wall){
                mat[player_position_y][player_position_x].is_player = false;
                mat[player_position_y][player_position_x].is_none = true;
                player_position_x--;
                if(player_position_x < 1){
                    player_position_x = x_size - 2;
                }
                if(mat[player_position_y][player_position_x].arrow()){
                    mat[player_position_y][player_position_x].switch_status();
                    mat[player_position_y][player_position_x].damage_arrow(player);
                }
                mat[player_position_y][player_position_x].is_none = false;
                mat[player_position_y][player_position_x].is_player = true;
            }
        }
        if (controller.get_right()){
            if(not mat[player_position_y][player_position_x+1].is_wall){
                mat[player_position_y][player_position_x].is_player = false;
                mat[player_position_y][player_position_x].is_none = true;
                player_position_x++;
                if(player_position_x > x_size-2){
                    player_position_x = 1;
                }
                if(mat[player_position_y][player_position_x].arrow()){
                    mat[player_position_y][player_position_x].switch_status();
                    mat[player_position_y][player_position_x].damage_arrow(player);
                }
                mat[player_position_y][player_position_x].is_none = false;
                mat[player_position_y][player_position_x].is_player = true;
            }
        }
        if(player.get_health()<=0){
            mat[player_position_y-5][player_position_x-5].is_wall = true;
        }
        if(player.get_health()<=0){
            end_game = true;
        }
    }
};



#endif //UNTITLED_FIELD_H
