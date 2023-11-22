#ifndef UNTITLED_EVENT_BONUS_KEY_H
#define UNTITLED_EVENT_BONUS_KEY_H
#include "../Event_Groups/Event_Group_Bonus.h"


class Event_Bonus_Key: public  Event_Group_Bonus {
public:
    void effect(Player& player) final;

};


#endif //UNTITLED_EVENT_BONUS_KEY_H
