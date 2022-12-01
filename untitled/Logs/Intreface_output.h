#ifndef UNTITLED_INTREFACE_OUTPUT_H
#define UNTITLED_INTREFACE_OUTPUT_H
#include "Game_Changes.h"
class Interface_output{
public:
    virtual ~Interface_output()=default;
    virtual void print(const Game_Changes& obj)=0;

};

#endif //UNTITLED_INTREFACE_OUTPUT_H
