#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H
class Player {
public:
    Player(int n_health){
        health = n_health;
    }
    void damage(){
        health--;
    }

    void heal(){
        health++;
    }

    int get_health(){
        return health;
    }

    void death(){
        health = 0;
    }


private:
    int health = 3;
    int armor = 3;
    int moves = 10;

};
#endif //UNTITLED_PLAYER_H
