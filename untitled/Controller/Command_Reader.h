#include <SFML/Graphics.hpp>
#include "conio.h"
#include <iostream>
#include "Command_File.h"
#include "Command_Interface.h"
#include "Control_Console.h"
#ifndef UNTITLED_CONTROLLER_H
#define UNTITLED_CONTROLLER_H

class Command_Reader {
private:
    MoveDirection direction;
    std::map<char, MoveDirection> setting;
    char command;
    int counter = 0;
    Command_Interface* command_read = new Control_Console;

public:

    void player_handler(Command_File& command_file);

    void stop_move();

    char get_direction();

    void read_commands(Command_File& command_file);

};


#endif //UNTITLED_CONTROLLER_H
