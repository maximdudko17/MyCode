#ifndef UNTITLED_EVENT_BONUS_POTION_H
#define UNTITLED_EVENT_BONUS_POTION_H
#include "../Event_Groups/Event_Group_Bonus.h"


class Event_Bonus_Potion: public Event_Group_Bonus {
public:
    void effect(Player& player) final;
};


#endif //UNTITLED_EVENT_BONUS_POTION_H
