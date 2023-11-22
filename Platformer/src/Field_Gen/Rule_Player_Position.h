#ifndef UNTITLED_RULE_PLAYER_POSITION_H
#define UNTITLED_RULE_PLAYER_POSITION_H
#include "../FieldCell/Field.h"

template<int player_position_y, int player_position_x>
class Rule_Player_Position{
public:
    void create(Field& field);
};

template<int player_position_y, int player_position_x>
void Rule_Player_Position<player_position_y, player_position_x>::create(Field& field) {
    if (player_position_x < field.get_x_size() or player_position_y < field.get_y_size()) {
        field.change_equal_player_position_y(player_position_y);
        field.change_equal_player_position_x(player_position_x);
        field.player_moved();
    }
}


#endif //UNTITLED_RULE_PLAYER_POSITION_H
