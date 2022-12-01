#include "Control_Console.h"
void Control_Console::command_read(std::map<char, MoveDirection>& setting, MoveDirection& direction){
    if (_kbhit()) {
        char button = _getch();
        if(setting.count(button)!=0)  direction = setting[button];
    }
}
