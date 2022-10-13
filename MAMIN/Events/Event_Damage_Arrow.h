#ifndef UNTITLED_EVENT_DAMAGE_ARROW_H
#define UNTITLED_EVENT_DAMAGE_ARROW_H
#include "../Event_Groups/Event_Group_Damage.h"
#include "../Player.h"


class Event_Damage_Arrow: public Event_Group_Damage{
public:
    void effect(Player& player) final;
};


#endif //UNTITLED_EVENT_DAMAGE_ARROW_H
