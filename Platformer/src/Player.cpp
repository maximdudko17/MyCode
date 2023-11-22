#include "Player.h"

Player::Player(int n_health){
    health = n_health;
}

void Player::damage(){
    health--;
}

void Player::heal(){
    health++;
}

void Player::plus_money(){
    money++;
}

int Player::get_health(){
    return health;
}

int Player::get_money(){
    return money;
}

void Player::death(){
    health = 0;
}