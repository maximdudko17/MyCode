#include "Controller_p.h"

void Controller_p::controller(Field &f, Player &player, Command_Reader command_reader) {
    if (command_reader.get_up()){
        if  (not f.get_mat(f.get_player_position_y()-1,f.get_player_position_x()).wall_is()){
            f.none_moved();
            f.change_plus_player_position_y(-1);
            if(f.get_player_position_y() < 1) {
                f.change_equal_player_position_y(f.get_y_size() - 2);
            }
        }
    }
    if (command_reader.get_down()) {
        if (not f.get_mat(f.get_player_position_y() + 1, f.get_player_position_x()).wall_is()) {
            f.none_moved();
            f.change_plus_player_position_y(1);
            if (f.get_player_position_y() > f.get_y_size() - 2) {
                f.change_equal_player_position_y(1);
            }
        }
    }
    if (command_reader.get_left()) {
        if (not f.get_mat(f.get_player_position_y(), f.get_player_position_x() - 1).wall_is()) {
            f.none_moved();
            f.change_plus_player_position_x(-1);
            if (f.get_player_position_x() < 1) {
                f.change_equal_player_position_x(f.get_x_size() - 2);
            }
        }
    }
    if (command_reader.get_right()){
        if  (not f.get_mat(f.get_player_position_y(),f.get_player_position_x()+1).wall_is()){
            f.none_moved();
            f.change_plus_player_position_x(1);
            if(f.get_player_position_x() > f.get_x_size() - 2) {
                f.change_equal_player_position_x(1);
            }
    }
    }
    f.action_event();
    f.player_moved();
    if(player.get_health()<=0){
        end_game = true;
    }
}

bool Controller_p::END(){
    return end_game;
}

