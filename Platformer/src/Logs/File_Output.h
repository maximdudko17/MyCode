#ifndef UNTITLED_FILE_OUTPUT_H
#define UNTITLED_FILE_OUTPUT_H
#include "Intreface_output.h"
#include <fstream>
#include <iostream>
class File_Output: public Interface_output{
    std::ofstream file;
public:
    File_Output();
    ~File_Output();
    void print(const Game_Changes& obj) final;
};



#endif //UNTITLED_FILE_OUTPUT_H
