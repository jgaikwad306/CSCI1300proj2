// With Joel Gaikwad 

#ifndef BOARD_H
#define BOARD_H
#include "tile.h"


/* board h from workbook/canvas. Will implement the advisor here. */

class Board
{
private:
   static const int _BOARD_SIZE = 52;
   Tile _tiles[2][_BOARD_SIZE];
   static const int _MAX_PLAYERS = 2;
   int _player_count;
   int _player_position[_MAX_PLAYERS];
   void displayTile(int player_index, int pos);
   void initializeTiles(int player_index);
   bool isPlayerOnTile(int player_index, int pos);
int _tileEvents[2][_BOARD_SIZE];

public:
   Board();
   Board(int player_count);
   void displayTrack(int player_index);
   void initializeBoard();
   void displayBoard();
   bool movePlayer(int player_index);
   int getPlayerPosition(int player_index) const;
   string getTileColor(int player_index) const; 
    void printTileColor(string color);
    void displayEvents();
    int getEventForTile(int tileIndex);
    void assignEventsToTiles();
    void executeEvent (int eventNumber, char tileColor);
};




#endif
