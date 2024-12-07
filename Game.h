#ifndef GAME_H
#define GAME_H
#include "Player.h"

class Game
{
private:
    Player _player[5];
    Player _advisor[5];
    int _num_players;

public:
    Game();
    Game(Player[], int);
    void loadCharacters();
    void loadAdvisors();
    void welcome();
    void menu();
    
};

#endif