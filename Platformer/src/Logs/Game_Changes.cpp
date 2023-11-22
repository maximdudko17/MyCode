#include "Game_Changes.h"
std::string Game_Changes::get_message(){
    return  message;
}

std::string Game_Changes::get_time(){
    return  time_cur;
}

std::string Game_Changes::get_prefix(){
    return  prefix;
}
void Game_Changes::Player_Message(Player& player){
    std::string health = std::to_string(player.get_health());
    std::string money = std::to_string(player.get_money());
    std::string s1 = "health: ";
    std::string s2 = "money: ";
    message =  s1 + health + " " + s2 + money;
}

void Game_Changes::Field_Message(Field& field) {
    std::string get_player_position_x = std::to_string(field.get_player_position_x());
    std::string get_player_position_y = std::to_string(field.get_player_position_y());
    std::string s1 = "get_player_position_x: ";
    std::string s2 = "get_player_position_y: ";
    message = s1 + get_player_position_x + " " + s2 + get_player_position_y + " ";
}

void Game_Changes::Event_Message(Field& field){
    if(field.is_event()) message = "Is event!";
    else message = "None";
}

void Game_Changes::Create_Message(std::string c_message){
    message = c_message;

}

void Game_Changes::Time_Change(){
    std::time_t current_time = std::time(0);
    std::tm* timestamp = std::localtime(&current_time);
    char buffer[80];
    strftime(buffer, 80, "%c", timestamp);
    time_cur = buffer;
}

void Game_Changes::Create_Prefix(std::string c_prefix){
    prefix = c_prefix;
}

std::ostream& operator<<(std::ostream& out, const Game_Changes& obj){
    out << obj.time_cur;
    out << " ";
    out << obj.prefix;
    out << " ";
    out << obj.message << std::endl;
    return out;
}

