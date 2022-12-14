#include "Command_Reader.h"


void Command_Reader::player_handler(Command_File& command_file) {
    // U - UP D - DOWN L - LEFT R - RIGHT
    command_read->command_read(setting, direction);

}

void Command_Reader::read_commands(Command_File& command_file){
    command_file.read_str();
    command_file.def_commands();
    setting[command_file.get_char(1)] = UP;
    setting[command_file.get_char(2)] = DOWN;
    setting[command_file.get_char(3)] = LEFT;
    setting[command_file.get_char(4)] = RIGHT;
}

void Command_Reader::stop_move() {
    direction = STOP;
}

char Command_Reader::get_direction(){
    return direction;
};

