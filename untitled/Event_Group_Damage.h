#ifndef UNTITLED_EVENT_GROUP_DAMAGE_H
#define UNTITLED_EVENT_GROUP_DAMAGE_H
#include "Event_Interface.h"
#include "Player.h"


class Event_Group_Damage: public Event_Interface{
public:
    void damage(Player &player){
        player.damage();
    }
    void death(Player &player){
        player.death();
    }
};


#endif //UNTITLED_EVENT_GROUP_DAMAGE_H
