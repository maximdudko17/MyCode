#include "Logger.h"

void Logger::Player_Change(Game_Changes& obj, Logger& logger, Player& player)
{
    obj.Player_Message(player);
    obj.Create_Prefix("[Game_Player]");
    obj.Time_Change();
    logger.log(obj, Game_Change_Priority);
}

void Logger::Field_Change(Game_Changes& obj, Logger& logger, Field& field)
{
    obj.Field_Message(field);
    obj.Create_Prefix("[Game_Player]");
    obj.Time_Change();
    logger.log(obj, Game_Change_Priority);
}

void Logger::Event_Change(Game_Changes& obj, Logger& logger, Field& field)
{
    obj.Event_Message(field);
    obj.Create_Prefix("[Game_Player]");
    obj.Time_Change();
    logger.log(obj, Game_Change_Priority);
}

void Logger::Start(Game_Changes& obj,Logger& logger)
{
    obj.Create_Message("*/////GAME STARTED/////*");
    obj.Create_Prefix("[Status_Start]");
    obj.Time_Change();
    logger.log(obj, Status_Priority);
}

void Logger::End(Game_Changes& obj,Logger& logger)
{
    obj.Create_Message("*/////GAME CLOSED/////*");
    obj.Create_Prefix("[Status_End]");
    obj.Time_Change();
    logger.log(obj, Status_Priority);
}

void Logger::WIN(Game_Changes& obj,Logger& logger)
{
    obj.Create_Message("*/////YOU WIN/////*");
    obj.Create_Prefix("[Status_WIN]");
    obj.Time_Change();
    logger.log(obj, Status_Priority);
}

void Logger::LOSE(Game_Changes& obj,Logger& logger)
{
    obj.Create_Message("*/////YOU LOSE/////*");
    obj.Create_Prefix("[Status_LOSE]");
    obj.Time_Change();
    logger.log(obj, Status_Priority);
}

void Logger::Minus(Game_Changes& obj,Logger& logger)
{
    obj.Create_Message("*/////WRONG FIELD VALUES/////*");
    obj.Create_Prefix("[WARNING]");
    obj.Time_Change();
    logger.log(obj, Warning_Priority);
}

void Logger::Wall(Game_Changes& obj,Logger& logger)
{
    obj.Create_Message("*/////WALL/////*");
    obj.Create_Prefix("[WARNING]");
    obj.Time_Change();
    logger.log(obj, Warning_Priority);
}


void Logger::switch_level(int level){
    switch (level) {
        case 1:
            priority = Game_Change_Priority;
            break;
        case 2:
            priority = Status_Priority;
            break;
        case 3:
            priority = Warning_Priority;
            break;
        default:
            break;
    }
}

void Logger::switch_out(int level){
    switch(level){
        case 1:
            out = true;
            break;
        case 2:
            out_file = true;
            break;
        case 3:
            out = true;
            out_file = true;
            break;

    }
}

void Logger::log(Game_Changes& obj, LogPriority message_priority)
{

    if (priority <= message_priority)
    {
        if(out)
        {
            cons_out->print(obj);
        }
        if (file and out_file)
        {
            file_out->print(obj);
        }
    }
}


