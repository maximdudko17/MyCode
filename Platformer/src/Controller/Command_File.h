#ifndef UNTITLED_COMMAND_FILE_H
#define UNTITLED_COMMAND_FILE_H
#include <iostream>
#include <fstream>
#include <string>


class Command_File{
    std::ifstream file;
    std::string str;
public:
    Command_File();
    ~Command_File();
// Порядок ввода команд: 1 - Вверх 2 - Вниз 3 - Влево 4 - Вправо
    void read_str() ;
    char  get_char(int n);
    void def_commands();
};


#endif //UNTITLED_COMMAND_FILE_H
