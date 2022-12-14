#ifndef UNTITLED_CONSOLE_OUTPUT_H
#define UNTITLED_CONSOLE_OUTPUT_H
#include "Intreface_output.h"


class Console_Output: public Interface_output{
public:
    void print(const Game_Changes& obj) final;

};


#endif //UNTITLED_CONSOLE_OUTPUT_H
