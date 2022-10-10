#ifndef UNTITLED_EVENT_ELSE_PLAYER_H
#define UNTITLED_EVENT_ELSE_PLAYER_H
#include "../Event_Groups/Event_Group_Else.h"

class Event_Else_Player: public Event_Group_Else {
public:
    void effect(Player& player) final;
};

#endif //UNTITLED_EVENT_ELSE_PLAYER_H
