#include "Field.h"


Field::Field(Player& player, int Xsize, int Ysize): player(player){
    x_size = Xsize;
    y_size = Ysize;
    x_mat = x_size;
    y_mat = y_size;
    player_position_x = (x_size-2)/2;
    player_position_y = (y_size-2)/2;
    for(size_t i = 0; i < y_mat; i++){
        mat.push_back(std::vector<Cell>());
        for(size_t j = 0; j < x_mat; j++){
            mat.back().emplace_back(0,player);
            mat[i][j].event_new(new Event_ELse_None);
        }
    }
}

Field::Field(const Field& obj): x_size(obj.x_size), y_size(obj.y_size), player(obj.player){
    x_mat = x_size;
    y_mat = y_size;
    player_position_x = (x_size-2)/2;
    player_position_y = (y_size-2)/2;

}

Field& Field::operator=(const Field& obj){
    if(this != &obj){
        for(size_t i = 0; i < y_mat; i++) {
            mat.push_back(std::vector<Cell>());
            for (size_t j = 0; j < x_mat; j++) {
                delete &mat[i][j];
            }
        }
        delete &mat;

        x_size = obj.x_size;
        y_size = obj.y_size;
        x_mat = obj.x_size;
        y_mat = obj.y_size;
        player_position_x = (obj.x_size-2)/2;
        player_position_y = (obj.y_size-2)/2;


        for(size_t i = 0; i < y_mat; i++){
            mat.push_back(std::vector<Cell>());
            for(size_t j = 0; j < x_mat; j++){
                mat.back().emplace_back(0,player);
                mat[i][j].event_new(new Event_ELse_None);
            }
        }

    }
    return *this;
}

Field::Field(Field&& obj){
    std::swap(this->x_size, obj.x_size);
    std::swap(this->y_size, obj.y_size);
    std::swap(this->x_mat, obj.x_mat);
    std::swap(this->y_mat, obj.y_mat);
    std::swap(this->player_position_x, obj.player_position_x);
    std::swap(this->player_position_y, obj.player_position_y);
}

Field& Field::operator=(Field&& obj){
    if(this != &obj){
        std::swap(this->x_size, obj.x_size);
        std::swap(this->y_size, obj.y_size);
        std::swap(this->x_mat, obj.x_mat);
        std::swap(this->y_mat, obj.y_mat);
        std::swap(this->player_position_x, obj.player_position_x);
        std::swap(this->player_position_y, obj.player_position_y);
        std::swap(this->mat, obj.mat);
    }
    return *this;
}

int Field::get_x_size(){
    return x_size;
}

int Field::get_y_size(){
    return y_size;
}

void Field::change_plus_player_position_x(int n){
    player_position_x = player_position_x + n;
}

void Field::change_plus_player_position_y(int n){
    player_position_y = player_position_y + n;
}

void Field::change_equal_player_position_x(int n){
    player_position_x = n;
}

void Field::change_equal_player_position_y(int n){
    player_position_y = n;
}

int Field::get_player_position_x(){
    return  player_position_x;
}

int Field::get_player_position_y(){
    return player_position_y;
}

//void Field::create_map(){
//    for(size_t i = 0; i < y_mat; i++){
//        mat.push_back(std::vector<Cell>());
//        for(size_t j = 0; j < x_mat; j++){
//            mat.back().emplace_back(0,player);
//            mat[i][j].event_new(new Event_ELse_None);
//        }
//    }
//}


Cell Field::get_mat(int I, int J){
    for(size_t i = 0; i < y_mat; i++) {
        for (size_t j = 0; j < x_mat; j++) {
            if (i==I and j == J){
                return mat[i][j];
            }
        }
    }
}

void Field::get_mat_event(int I, int J, Event_Interface* eventInterface){
    for(size_t i = 0; i < y_mat; i++) {
        for (size_t j = 0; j < x_mat; j++) {
            if (i==I and j == J){
                mat[i][j].event_new(eventInterface);
            }
        }
    }
}

int Field::random_pos(Field& field){
    int none_counter = 0;
    for(size_t i = 1; i < y_mat-1; i++){
        for(size_t j = 1; j < x_mat-1; j++) {
            if (field.get_mat(i,j).none_is()){
                none_counter++;
            }
        }
    }
    int rand_cell = rand() % none_counter;
    int ind_counter = 0;
    int pos;

    for(size_t i = 1; i < y_mat; i++){
        for(size_t j = 1; j < x_mat-1; j++) {
            if (ind_counter == rand_cell){
                pos =  i * x_size + j;
            }
            ind_counter++;
        }
    }

    return pos;
}

void Field::add_key(Field& field){
    int key_pos = field.random_pos(field);
    int key_counter = 0;
    for(size_t i = 0; i < y_mat; i++){
        for(size_t j = 0; j < x_mat; j++) {
            if (mat[i][j].key_is()) key_counter++;
        }
    }
    if (key_counter < 1 and player.get_money() >= 5) mat[key_pos / x_size][key_pos % x_size].event_new(new Event_Bonus_Key);
}

void Field::action_event(){
    if(!mat[player_position_y][player_position_x].none_is()){
        mat[player_position_y][player_position_x].event_effect();
        mat[player_position_y][player_position_x].event_new(new Event_ELse_None);
    }
}

bool Field::is_event(){
    if(mat[player_position_y][player_position_x].none_is() or mat[player_position_y][player_position_x].player_is()){
        return false;
    }
    return true;
}

void Field::player_moved(){
    mat[player_position_y][player_position_x].event_new(new Event_Else_Player);
}

void Field::none_moved(){
    mat[player_position_y][player_position_x].event_new(new Event_ELse_None);
}


