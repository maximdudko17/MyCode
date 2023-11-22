#ifndef UNTITLED_LEVEL_GEN_H
#define UNTITLED_LEVEL_GEN_H
#include "iostream"
#include "Field_Generator.h"
#include "Rule_Arrow.h"
#include "Rule_Coin.h"
#include "Rule_Potion.h"
#include "Rule_Skull.h"
#include "Rule_Wall.h"
#include "Rule_Player_Position.h"


class Level_Gen {
private:
    int level;

public:
    Field switch_mapgen_level(Player& player){
        std::cout<<"Enter game level (0,1,2)"<<std::endl;
        std::cin >> level;
        Field field(player,35,25);
        switch(level){
            case 0:
                Field_Generator<Rule_Arrow<5>, Rule_Potion<10>, Rule_Wall<5>, Rule_Skull<5>, Rule_Player_Position<2,2>> gen0;
                field = gen0.field_gen(player);
                break;
            case 1:
                Field_Generator<Rule_Player_Position<20,20>,Rule_Arrow<50>,Rule_Coin<10>, Rule_Potion<15>, Rule_Wall<40>, Rule_Skull<20>> gen1;
                field = gen1.field_gen(player);
                break;
            case 2:
                Field_Generator<Rule_Player_Position<25,25>,Rule_Arrow<80>,Rule_Coin<9>, Rule_Potion<20>, Rule_Wall<60>, Rule_Skull<20>> gen2;
                field = gen2.field_gen(player);
                break;
            default:
                Field_Generator<Rule_Player_Position<2,2>,Rule_Arrow<5>,Rule_Coin<12>, Rule_Potion<10>, Rule_Wall<5>, Rule_Skull<5>> gendef;
                field = gendef.field_gen(player);

        }
        return field;

    }
};


#endif //UNTITLED_LEVEL_GEN_H
