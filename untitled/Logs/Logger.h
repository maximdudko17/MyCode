#pragma once
#include <fstream>
#include <iostream>
#include "Intreface_output.h"
#include "Console_Output.h"
#include "File_Output.h"
#include "Game_Changes.h"


enum LogPriority
{
    Game_Change_Priority, Status_Priority, Warning_Priority
};

class Logger
{
private:
    LogPriority priority = Game_Change_Priority;
    const char* filepath = 0;
    std::ofstream file;
    bool out = false;
    bool out_file = false;
    Interface_output* cons_out = new Console_Output;
    Interface_output* file_out = new File_Output;


public:
    void EnableFileOutput(Logger& logger);

    void Player_Change(Game_Changes& obj, Logger& logger, Player& player);

    void Field_Change(Game_Changes& obj, Logger& logger, Field& field);

    void Event_Change(Game_Changes& obj, Logger& logger, Field& field);

    void Start(Game_Changes& obj, Logger& logger);

    void End(Game_Changes& obj, Logger& logger);

    void WIN(Game_Changes& obj, Logger& logger);

    void LOSE(Game_Changes& obj, Logger& logger);

    void Minus(Game_Changes& obj, Logger& logger);

    void Wall(Game_Changes& obj, Logger& logger);

    void switch_level(int level);

    void switch_out(int level);

private:

    void log(Game_Changes& obj, LogPriority message_priority);

    bool enable_file_output();

    void free_file();
};

