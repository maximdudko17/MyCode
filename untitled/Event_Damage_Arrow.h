#ifndef UNTITLED_EVENT_DAMAGE_ARROW_H
#define UNTITLED_EVENT_DAMAGE_ARROW_H
#include "Event_Group_Damage.h"
#include "Player.h"
#include <iostream>

class Event_Damage_Arrow: public Event_Group_Damage{
private:
    bool event_is_arrow = false;

public:
    bool status() override{
        return event_is_arrow;
    }

    void status_change() override{
        if(event_is_arrow) event_is_arrow = false;
        else event_is_arrow = true;
    }
};


#endif //UNTITLED_EVENT_DAMAGE_ARROW_H
