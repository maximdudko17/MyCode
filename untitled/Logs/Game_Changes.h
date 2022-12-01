#ifndef UNTITLED_GAME_CHANGES_H
#define UNTITLED_GAME_CHANGES_H
#include "../FieldCell/Field.h"
#include "../Player.h"
#include <string>
#include <ctime>

class Game_Changes {
private:
    std::string message;
    std::string time_cur;
    std::string prefix;

public:
    std::string get_message();

    std::string get_time();

    std::string get_prefix();

    std::string get_level();

    void Player_Message(Player& player);

    void Field_Message(Field& field);

    void Event_Message(Field& field);

    void Time_Change();

    void Create_Message(std::string c_message);

    void Create_Prefix(std::string c_prefix);

    friend std::ostream& operator<<(std::ostream& out, const Game_Changes& obj);
};


#endif //UNTITLED_GAME_CHANGES_H
