#ifndef UNTITLED_CONTROL_CONSOLE_H
#define UNTITLED_CONTROL_CONSOLE_H
#include "Command_Interface.h"


class Control_Console: public Command_Interface{
    void command_read(std::map<char, MoveDirection>& setting, MoveDirection& direction) final;

};


#endif //UNTITLED_CONTROL_CONSOLE_H
