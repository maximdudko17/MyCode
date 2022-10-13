#ifndef UNTITLED_CELL_H
#define UNTITLED_CELL_H
#include "../Events/Event_Damage_Arrow.h"
#include "../Events/Event_Damage_Skull.h"
#include "../Event_Groups/Event_Interface.h"
#include "../Events/Event_ELse_None.h"
#include "../Events/Event_Else_Wall.h"
#include "../Events/Event_Else_Player.h"
#include "../Events/Event_Bonus_Coin.h"
#include "../Events/Event_Bonus_Key.h"
#include "../Events/Event_Bonus_Potion.h"
#include "../Player.h"
#include <iostream>


class Cell {
private:
    int cell_size = 32;
    Event_Interface* some_event;
    Player& player;

public:
    int v;
    Cell(int v, Player& player): v(v), player(player){}

    void arrow_new();

    void skull_new();

    void none_new();

    void wall_new();

    void player_new();

    void potion_new();

    void coin_new();

    void key_new();

    Event_Damage_Arrow* arrow_is();

    Event_Damage_Skull* skull_is();

    Event_ELse_None* none_is();

    Event_Else_Wall* wall_is();

    Event_Else_Player* player_is();

    Event_Bonus_Potion* potion_is();

    Event_Bonus_Coin* coin_is();

    Event_Bonus_Key* key_is();

    void arrow_effect();

    void potion_effect();

    void coin_effect();

    void key_effect();

    void skull_effect();

    Event_Interface* get();

    int get_cell_size();
};

#endif //UNTITLED_CELL_H
