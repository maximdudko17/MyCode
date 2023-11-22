#ifndef UNTITLED_EVENT_ELSE_WALL_H
#define UNTITLED_EVENT_ELSE_WALL_H
#include "../Event_Groups/Event_Group_Else.h"

class Event_Else_Wall: public Event_Group_Else{
public:
    void effect(Player& player) final;

};


#endif //UNTITLED_EVENT_ELSE_WALL_H
