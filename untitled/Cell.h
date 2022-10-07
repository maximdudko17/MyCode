#ifndef UNTITLED_CELL_H
#define UNTITLED_CELL_H
#include "Event_Damage_Arrow.h"
#include <iostream>


class Cell {
private:
    int cell_size = 32;
    Event_Damage_Arrow event_arrow;


public:
    int get_cell_size(){
        return cell_size;
    }
    int v;
    Cell(int v): v(v){}

    bool arrow(){
        event_arrow.status();
    }

    bool switch_status(){
        event_arrow.status_change();
    }

    void damage_arrow(Player& player){
        player.damage();
    }
    bool is_wall = false;
    bool is_player = false;
    bool is_none = false;

};

#endif //UNTITLED_CELL_H
