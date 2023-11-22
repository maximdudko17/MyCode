#ifndef UNTITLED_COMMAND_INTERFACE_H
#define UNTITLED_COMMAND_INTERFACE_H
#include <iostream>
#include <map>
#include <conio.h>

enum MoveDirection
{
    UP, DOWN, RIGHT, LEFT, STOP
};

class Command_Interface{
public:
    virtual ~Command_Interface()=default;
    virtual void command_read(std::map<char, MoveDirection>& setting, MoveDirection& direction)=0;

};

#endif //UNTITLED_COMMAND_INTERFACE_H
