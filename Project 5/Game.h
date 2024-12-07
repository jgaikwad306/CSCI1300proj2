#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Board.h"
#include "Tile.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Game {
private:
    Player _player[5];
    Player _advisor[5];
    int _num_players;

public:
    Game();
    Game(Player character[], int num_players);
    int getNumPlayers() const;
    Player getPlayer(int playerIndex);
    void loadCharacters();
    void loadAdvisors();
    void welcome();
    void showPlayerStats(int playerIndex); // Function to display stats for a player
};

#endif
