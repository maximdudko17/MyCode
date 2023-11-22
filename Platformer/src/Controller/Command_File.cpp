#include "Command_File.h"

Command_File::Command_File(){
    file.open("File.txt");
};

Command_File::~Command_File(){
    file.close();
}

void Command_File::read_str(){
    if(file.is_open()){
        getline(file,str);
    }
}

void Command_File::def_commands(){
    for(int i = 0; i < str.length(); i++){
        for(int j = i+1; j < str.length(); j++){
            if(str[i] == str[j]) str = ":wsad";
        }
    }
    if(str.length() != 5){
        str = ":wsad";
    }

}

char  Command_File::get_char(int n){
    return str[n];
}

