#include "Cell.h"


void Cell::arrow_new(){
    some_event = new Event_Damage_Arrow;
}

void Cell::skull_new(){
    some_event = new Event_Damage_Skull;
}

void Cell::none_new(){
    some_event = new Event_ELse_None;
}

void Cell::wall_new(){
    some_event = new Event_Else_Wall;
}

void Cell::player_new(){
    some_event = new Event_Else_Player;
}

void Cell::potion_new(){
    some_event = new Event_Bonus_Potion;
}

void Cell::coin_new(){
    some_event = new Event_Bonus_Coin;
}

void Cell::key_new(){
    some_event = new Event_Bonus_Key;
}

Event_Damage_Arrow* Cell::arrow_is(){
    Event_Damage_Arrow* event = dynamic_cast<Event_Damage_Arrow*>(some_event);
    return event;
}

Event_Damage_Skull* Cell::skull_is(){
    Event_Damage_Skull* event = dynamic_cast<Event_Damage_Skull*>(some_event);
    return event;
}

Event_ELse_None* Cell::none_is(){
    Event_ELse_None* event = dynamic_cast<Event_ELse_None*>(some_event);
    return event;
}

Event_Else_Wall* Cell::wall_is(){
    Event_Else_Wall* event = dynamic_cast<Event_Else_Wall*>(some_event);
    return event;
}

Event_Else_Player* Cell::player_is(){
    Event_Else_Player* event = dynamic_cast<Event_Else_Player*>(some_event);
    return event;
}

Event_Bonus_Potion* Cell::potion_is(){
    Event_Bonus_Potion* event = dynamic_cast<Event_Bonus_Potion*>(some_event);
    return event;
}

Event_Bonus_Coin* Cell::coin_is(){
    Event_Bonus_Coin* event = dynamic_cast<Event_Bonus_Coin*>(some_event);
    return event;
}

Event_Bonus_Key* Cell::key_is(){
    Event_Bonus_Key* event = dynamic_cast<Event_Bonus_Key*>(some_event);
    return event;
}

void Cell::arrow_effect(){
    some_event->effect(player);
}

void Cell::potion_effect(){
    some_event->effect(player);
}

void Cell::coin_effect(){
    some_event->effect(player);
}

void Cell::key_effect(){
    some_event->effect(player);
}
void Cell::skull_effect(){
    some_event->effect(player);
}

Event_Interface* Cell::get(){
    return some_event;
}

int Cell::get_cell_size(){
    return cell_size;
}
