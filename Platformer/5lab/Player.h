#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H
class Player {
private:
    int health = 3;
    int money = 0;
    int moves = 10;
public:
    Player(int n_health);

    void damage();

    void heal();

    void plus_money();

    int get_health();

    int get_money();

    void death();
};
#endif //UNTITLED_PLAYER_H
