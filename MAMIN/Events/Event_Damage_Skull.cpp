#include "Event_Damage_Skull.h"
void Event_Damage_Skull::effect(Player& player){
    player.death();
}