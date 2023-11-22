#ifndef UNTITLED_EVENT_ELSE_NONE_H
#define UNTITLED_EVENT_ELSE_NONE_H
#include "../Event_Groups/Event_Group_Else.h"


class Event_ELse_None: public Event_Group_Else{
public:
    void effect(Player& player) final;
};


#endif //UNTITLED_EVENT_ELSE_NONE_H
