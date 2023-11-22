#ifndef UNTITLED_EVENT_INTERFACE_H
#define UNTITLED_EVENT_INTERFACE_H
#include "../Player.h"


class Event_Interface {
public:
    virtual void effect(Player& player)=0;
    virtual ~Event_Interface() {};


};


#endif //UNTITLED_EVENT_INTERFACE_H
