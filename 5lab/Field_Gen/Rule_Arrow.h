#ifndef UNTITLED_RULE_ARROW_H
#define UNTITLED_RULE_ARROW_H
#include "../FieldCell/Field.h"


template<size_t count>
class Rule_Arrow {
public:
    void create(Field& field);
};

template<size_t count>
void Rule_Arrow<count>::create(Field& field)
{   int x_size = field.get_x_size();
    int i, j, position;
    for (int k = 0; k < count; k++) {
        position = field.random_pos(field);
        i = position / x_size;
        j = position % x_size;
        if (field.get_mat(i,j).none_is()) field.get_mat_event(i,j,new Event_Damage_Arrow);
    }
}





#endif //UNTITLED_RULE_ARROW_H
