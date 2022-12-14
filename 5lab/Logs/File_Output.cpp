#include "File_Output.h"

File_Output::File_Output(){
    file.open("log.txt");
};

File_Output::~File_Output(){
    file.close();
}

void File_Output::print(const Game_Changes& obj){
    file << obj;
}

