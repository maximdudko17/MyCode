#ifndef UNTITLED_FIELD_GENERATOR_H
#define UNTITLED_FIELD_GENERATOR_H
#include "../FieldCell/Field.h"
#include "../Player.h"

template<class... Rules>
class Field_Generator {
public:
    Field field_gen(Player& player);

private:
    template<typename Rule>
    void add(Field& field);
};

template<typename... Rules>
Field Field_Generator<Rules...>::field_gen(Player& player) {
    Field field(player,35,25);
    (add<Rules>(field), ...);
    return field;
}

template<typename... Rules>
template<typename Rule>
void Field_Generator<Rules...>::add(Field& field)
{
    Rule rule;
    rule.create(field);
}




#endif //UNTITLED_FIELD_GENERATOR_H
