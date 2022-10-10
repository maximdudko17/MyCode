#include "Event_Bonus_Key.h"
void Event_Bonus_Key::effect(Player& player){
    if(player.get_money()>=3) player.death();
}
