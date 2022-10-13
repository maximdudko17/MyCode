#ifndef UNTITLED_CONTROLLER_P_H
#define UNTITLED_CONTROLLER_P_H
#include "Command_Reader.h"
#include "../FieldCell//Field.h"
#include "../Player.h"


class Controller_p {
private:
    bool end_game = false;
public:
    void controller(Field& field, Player& player,Command_Reader command_reader);

    bool END();

};


#endif //UNTITLED_CONTROLLER_P_H
