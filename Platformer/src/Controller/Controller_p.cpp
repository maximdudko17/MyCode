#include "Controller_p.h"

void get_direction(){

}
void Controller_p::controller(Field &f, Player &player, Command_Reader& command_reader,Logger& logger,Game_Changes& game_changes) {
    if (command_reader.get_direction() == UP){
        if  (not f.get_mat(f.get_player_position_y()-1,f.get_player_position_x()).wall_is()){
            f.none_moved();
            f.change_plus_player_position_y(-1);
            if(f.get_player_position_y() < 1) {
                f.change_equal_player_position_y(f.get_y_size() - 2);
            }
            logger.Player_Change(game_changes, logger, player);
            logger.Field_Change(game_changes, logger, f);
            logger.Event_Change(game_changes, logger, f);
        }
        else{
            logger.Wall(game_changes,logger);
        }
    }
    if (command_reader.get_direction() == DOWN) {
        if (not f.get_mat(f.get_player_position_y() + 1, f.get_player_position_x()).wall_is()) {
            f.none_moved();
            f.change_plus_player_position_y(1);
            if (f.get_player_position_y() > f.get_y_size() - 2) {
                f.change_equal_player_position_y(1);
            }
            logger.Player_Change(game_changes, logger, player);
            logger.Field_Change(game_changes, logger, f);
            logger.Event_Change(game_changes, logger, f);
        }
        else{
            logger.Wall(game_changes,logger);
        }
        }
    if (command_reader.get_direction() == LEFT) {
        if (not f.get_mat(f.get_player_position_y(), f.get_player_position_x() - 1).wall_is()) {
            f.none_moved();
            f.change_plus_player_position_x(-1);
            if (f.get_player_position_x() < 1) {
                f.change_equal_player_position_x(f.get_x_size() - 2);
            }
            logger.Player_Change(game_changes, logger, player);
            logger.Field_Change(game_changes, logger, f);
            logger.Event_Change(game_changes, logger, f);
        }
        else{
            logger.Wall(game_changes,logger);
        }
    }
    if (command_reader.get_direction() == RIGHT){
        if  (not f.get_mat(f.get_player_position_y(),f.get_player_position_x()+1).wall_is()){
            f.none_moved();
            f.change_plus_player_position_x(1);
            if(f.get_player_position_x() > f.get_x_size() - 2) {
                f.change_equal_player_position_x(1);
            }
            logger.Player_Change(game_changes, logger, player);
            logger.Field_Change(game_changes, logger, f);
            logger.Event_Change(game_changes, logger, f);
        }
        else{
            logger.Wall(game_changes,logger);
        }
    }
    f.action_event();
    f.player_moved();
    if(player.get_health()<=0){
        end_game = true;
    }
    command_reader.stop_move();
}

bool Controller_p::END(){
    return end_game;
}


