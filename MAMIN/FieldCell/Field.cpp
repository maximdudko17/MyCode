#include "Field.h"


Field::Field(Player& player, int Xsize, int Ysize): player(player){
    x_size = Xsize;
    y_size = Ysize;
    window_height = cell_size * y_size;
    window_width = cell_size * x_size;
    x_mat = x_size;
    y_mat = y_size;
    player_position_x = (x_size-2)/2;
    player_position_y = (y_size-2)/2;
}


Field::Field(const Field& obj): x_size(obj.x_size), y_size(obj.y_size), player(obj.player){
    window_height = cell_size * y_size;
    window_width = cell_size * x_size;
    x_mat = x_size;
    y_mat = y_size;
    player_position_x = (x_size-2)/2;
    player_position_y = (y_size-2)/2;
}

Field& Field::operator=(const Field& obj){
    if(this != &obj){
        x_size = obj.x_size;
        y_size = obj.y_size;
        window_height = cell_size * obj.y_size;
        window_width = cell_size * obj.x_size;
        x_mat = obj.x_size;
        y_mat = obj.y_size;
        player_position_x = (obj.x_size-2)/2;
        player_position_y = (obj.y_size-2)/2;

    }
    return *this;
}

Field::Field(Field&& obj){
    std::swap(this->x_size, obj.x_size);
    std::swap(this->y_size, obj.y_size);
}

Field& Field::operator=(Field&& obj){
    if(this != &obj){
        std::swap(x_size, obj.x_size);
        std::swap(y_size, obj.y_size);
    }
    return *this;
}


int Field::get_window_width(){
    return window_width;
}

int Field::get_window_height(){
    return window_height;
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

void Field::create_map(){
    for(size_t i = 0; i < y_mat; i++){
        mat.push_back(std::vector<Cell>());
        for(size_t j = 0; j < x_mat; j++){
            mat.back().emplace_back(0,player);
            mat[i][j].none_new();
        }
    }
    mat[player_position_y][player_position_x].player_new();

}


Cell Field::get_mat(int I, int J){
    for(size_t i = 0; i < y_mat; i++) {
        for (size_t j = 0; j < x_mat; j++) {
            if (i==I and j == J){
                return mat[i][j];
            }
        }
    }
}

int Field::random_pos(){
    int none_counter = 0;
    for(size_t i = 1; i < y_mat-1; i++){
        for(size_t j = 1; j < x_mat-1; j++) {
            if (mat[i][j].none_is()){
                none_counter++;
            }
        }
    }
    int rand_cell = rand() % none_counter;
    int ind_counter = 0;
    int pos;

    for(size_t i = 1; i < y_mat-1; i++){
        for(size_t j = 1; j < x_mat-1; j++) {
            if (ind_counter == rand_cell){
                pos =  i * x_size + j;
            }
            ind_counter++;
        }
    }

    return pos;
}

void Field::add_arrow(Field& field){
    int arrow_pos = field.random_pos();
    int arrow_counter = 0;
    for(size_t i = 0; i < y_mat; i++){
        for(size_t j = 0; j < x_mat; j++) {
            if (mat[i][j].arrow_is()){
                arrow_counter++;
            }
        }
    }
    if (arrow_counter < 10) mat[arrow_pos / x_size][arrow_pos % x_size].arrow_new();
}

void Field::add_coin(Field& field){
    int coin_pos = field.random_pos();
    int coin_counter = 0;
    for(size_t i = 0; i < y_mat; i++){
        for(size_t j = 0; j < x_mat; j++) {
            if (mat[i][j].coin_is()){
                coin_counter++;
            }
        }
    }
    if (coin_counter < 3) mat[coin_pos / x_size][coin_pos % x_size].coin_new();
}

void Field::add_skull(Field& field){
    int skull_pos = field.random_pos();
    int skull_counter = 0;
    for(size_t i = 0; i < y_mat; i++){
        for(size_t j = 0; j < x_mat; j++) {
            if (mat[i][j].skull_is()){
                skull_counter++;
            }
        }
    }
    if (skull_counter < 3) mat[skull_pos / x_size][skull_pos % x_size].skull_new();
}

void Field::add_potion(Field& field){
    int potion_pos = field.random_pos();
    int potion_counter = 0;
    for(size_t i = 0; i < y_mat; i++){
        for(size_t j = 0; j < x_mat; j++) {
            if (mat[i][j].potion_is()){
                potion_counter++;
            }
        }
    }
    if (potion_counter < 3) mat[potion_pos / x_size][potion_pos % x_size].potion_new();
}

void Field::add_wall(Field& field){
    int wall_pos = field.random_pos();
    int wall_counter = 0;
    for(size_t i = 0; i < y_mat; i++){
        for(size_t j = 0; j < x_mat; j++) {
            if (mat[i][j].wall_is()){
                wall_counter++;
            }
        }
    }
    if (wall_counter < 15) mat[wall_pos / x_size][wall_pos % x_size].wall_new();
}

void Field::add_key(Field& field, Player& player){
    int key_pos = field.random_pos();
    int key_counter = 0;
    for(size_t i = 0; i < y_mat; i++){
        for(size_t j = 0; j < x_mat; j++) {
            if (mat[i][j].key_is()){
                key_counter++;
            }
        }
    }
    if (key_counter < 1 and player.get_money() >= 5) mat[key_pos / x_size][key_pos % x_size].key_new();
}

void Field::action_event(){
    if(mat[player_position_y][player_position_x].coin_is()){
        mat[player_position_y][player_position_x].coin_effect();
        mat[player_position_y][player_position_x].none_new();
    }
    if(mat[player_position_y][player_position_x].arrow_is()){
        mat[player_position_y][player_position_x].arrow_effect();
        mat[player_position_y][player_position_x].none_new();
    }
    if(mat[player_position_y][player_position_x].skull_is()){
        mat[player_position_y][player_position_x].skull_effect();
        mat[player_position_y][player_position_x].none_new();
    }
    if(mat[player_position_y][player_position_x].potion_is()){
        mat[player_position_y][player_position_x].potion_effect();
        mat[player_position_y][player_position_x].none_new();
    }
    if(mat[player_position_y][player_position_x].key_is()){
        mat[player_position_y][player_position_x].key_effect();
        mat[player_position_y][player_position_x].none_new();
    }
}

void Field::player_moved(){
    mat[player_position_y][player_position_x].player_new();
}

void Field::none_moved(){
    mat[player_position_y][player_position_x].none_new();
}


