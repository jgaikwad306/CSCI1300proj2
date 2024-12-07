// With Joel Gaikwad 

#include "Board.h"
#include "Tile.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>

#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m"  /* Grassy Green (34,139,34) */
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0) */
#define GREY "\033[48;2;128;128;128m" /* Grey (128,128,128) */
#define RESET "\033[0m"

#include <iostream>

using namespace std;




#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

void Board::initializeBoard()
{
    srand(time(0));  // Seed the random number generator once in the main function
    for (int i = 0; i < 2; i++)
    {
        initializeTiles(i);  // This ensures each lane has a unique tile distribution
    }
}

void Board::initializeTiles(int player_index) {
    Tile temp;
    int green_count = 0;
    int max_green_tiles = 35;  // Default value for Track 1
    int total_tiles = _BOARD_SIZE;

    // If player_index is 0 (Track 2), we want 35 green tiles
    if (player_index == 0) {
        max_green_tiles = 30;  // Track 2 gets 35 green tiles
    }

    for (int i = 0; i < total_tiles; i++) {
        if (i == total_tiles - 1) {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'O';
        } 
        else if (i == 0) {
            // Set the first tile as Yellow for the starting point
            temp.color = 'Y';
        } 
        else if (green_count < max_green_tiles && (rand() % (total_tiles - i) < max_green_tiles - green_count)) {
            // Ensure the specified number of green tiles
            temp.color = 'G';
            green_count++;
        } 
        else {
            // Generate a random number for tile type
            int random_value = rand() % 100 + 1; // Random number between 1 and 100

          if (player_index == 0) {  // Track 2 (player_index == 0) Grasslands Path
                // First half of the lane (first 50% of tiles)
                if (i <= total_tiles / 2) {
                    if (random_value <= 25) {
                        temp.color = 'R'; // Graveyard (25%)
                    } 
                    else if (random_value <= 50) {
                        temp.color = 'N'; // Hyena (25%)
                    } 
                    else if (random_value <= 70) {
                        temp.color = 'P'; // Advisor (20%)
                    } 
                    else if (random_value <= 75) {
                        temp.color = 'B'; // Oasis (5%)
                    } 
                    else {
                        temp.color = 'U'; // Challenge (remaining 25%)
                    }
                }
                // Second half of the lane (second 50% of tiles)
                else {
                    if (random_value <= 15) {
                        temp.color = 'R'; // Graveyard (15%)
                    } 
                    else if (random_value <= 30) {
                        temp.color = 'N'; // Hyena (15%)
                    } 
                    else if (random_value <= 50) {
                        temp.color = 'P'; // Advisor (20%)
                    } 
                    else if (random_value <= 75) {
                        temp.color = 'B'; // Oasis (25%)
                    } 
                    else {
                        temp.color = 'U'; // Challenge (remaining 25%)
                    }
                }
            } 
            else if (player_index == 1) {  // Track 1 (player_index == 1)
                // Assign tile types based on custom probability ranges for Track 1
                if (i <= 25) { // First half of the board
                    if (random_value <= 20) {
                        temp.color = 'R'; // Graveyard (20%)
                    } 
                    else if (random_value <= 40) {
                        temp.color = 'N'; // Hyena (next 20%)
                    } 
                    else if (random_value <= 55) {
                        temp.color = 'P'; // Advisor (15%)
                    } 
                    else if (random_value <= 80) {
                        temp.color = 'B'; // Oasis (25%)
                    } 
                    else {
                        temp.color = 'U'; // Challenge (remaining 20%)
                    }
                } 
                else { // Second half of the board
                    if (random_value <= 20) {
                        temp.color = 'R'; // Graveyard (20%)
                    } 
                    else if (random_value <= 40) {
                        temp.color = 'N'; // Hyena (next 20%)
                    } 
                    else if (random_value <= 55) {
                        temp.color = 'P'; // Advisor (15%)
                    } 
                    else if (random_value <= 70) {
                        temp.color = 'B'; // Oasis (15%)
                    } 
                    else {
                        temp.color = 'U'; // Challenge (remaining 30%)
                    }
                }
            }
        }

        // Assign the tile to the board for the specified player
        _tiles[player_index][i] = temp;
    }
}

 Board::Board()
 {
     _player_count = 1;

     // Initialize player position
     _player_position[0] = 0;

     // Initialize tiles
     //initializeTiles();
 }

Board::Board(int player_count)
{
    if (player_count > _MAX_PLAYERS)
    {
        _player_count = _MAX_PLAYERS;
    }
    else
    {
        _player_count = player_count;
    }

    // Initialize player position
    for (int i = 0; i < _player_count; i++)
    {
        _player_position[i] = 0;
    }

    // Initialize tiles

    initializeBoard();
}

bool Board::isPlayerOnTile(int player_index, int pos)
{
    if (_player_position[player_index] == pos)
    {
        return true;
    }
    return false;
}

void Board::displayTile(int player_index, int pos)
{
    string space = "                                       ";
    string color = "";
    int player = isPlayerOnTile(player_index, pos);

    // Template for displaying a tile: <line filler space> <color start> |<player symbol or blank space>| <reset color> <line filler space> <endl>

    // Determine color to display
    if (_tiles[player_index][pos].color == 'R')
    {
        color = RED;
    }
    else if (_tiles[player_index][pos].color == 'G')
    {
        color = GREEN;
    }
    else if (_tiles[player_index][pos].color == 'B')
    {
        color = BLUE;
    }
    else if (_tiles[player_index][pos].color == 'U')
    {
        color = PURPLE;
    }
    else if (_tiles[player_index][pos].color == 'N')
    {
        color = BROWN;
    }
    else if (_tiles[player_index][pos].color == 'P')
    {
        color = PINK;
    }
    else if (_tiles[player_index][pos].color == 'O')
    {
        color = ORANGE;
    }
    else if (_tiles[player_index][pos].color == 'Y')
    {
        color = GREY;
    }

     if (player == true)
    {
        cout << color << "|" << (player_index + 1) << "|" << RESET;
    }
    else
    {
        cout << color << "| |" << RESET;
    }
}

void Board::displayTrack(int player_index)
{
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        displayTile(player_index, i);
    }
    cout << endl;
}

void Board::displayBoard()
{
    for (int i = 0; i < 2; i++)
    {
        displayTrack(i);
        if (i == 0) {
            cout << endl;  // Add an extra line between the two lanes
        }
    }
}

bool Board::movePlayer(int player_index)
{
    // Increment player position
    _player_position[player_index]++;
    if (_player_position[player_index] == _BOARD_SIZE - 1)
    {
        // Player reached last tile
        return true;
    }
    return false;
}

int Board::getPlayerPosition(int player_index) const
{
    if (player_index >= 0 && player_index <= _player_count)
    {
        return _player_position[player_index];
    }
    return -1;
}
string Board::getTileColor(int player_index) const {
    int position = _player_position[player_index];
    
    if (player_index >= 0 && player_index < _player_count && position >= 0 && position < _BOARD_SIZE) {
        return string(1, _tiles[player_index][position].color);  
    }
    return "Invalid";  // Return "Invalid" if player index or position is out of bounds
}
void Board::printTileColor(string color) {
    if (color == "O") {
        cout << "Player is on an Orange tile." << endl;
    }
    else if (color == "B") {
        cout << "Player is on a Blue tile." << endl;
    }
    else if (color == "G") {
        cout << "Player is on a Green tile." << endl;
    }
    else if (color == "R") {
        cout << "Player is on a Red tile." << endl;
    }
    else if (color == "Y") {
        cout << "Player is on a Yellow tile." << endl;
    }
    else {
        cout << "Player is on an Unknown tile." << endl;
    }
}

void Board::displayEvents() {
    cout << "List of Events on Green Tiles:" << endl;

    // Define the list of possible events
    string events[] = {
        "1. Nothing Happens",
        "2. Desert storm sweeps through the territory | Damage: -500",
        "3. Fatigue from intense training with pride warriors | Damage: -200",
        "4. Challenging night watch duty under pitch-black conditions | Damage: -400",
        "5. Extra energy from bountiful season | Bonus: +800",
        "6. Observed a rare natural phenomenon | Bonus: +600",
        "7. Gained wisdom from observing Rafiki's rituals | Bonus: +500"
    };

    // Display all events
    for (int i = 0; i < 7; i++) {
        cout << "Event " << i << ": " << events[i] << endl;
    }
}

int Board::getEventForTile(int tileIndex) {
    // Assuming tileIndex is valid and represents a green tile
    // Return a specific event based on the tileIndex using modulo to cycle through events
    return tileIndex % 7;
}

void Board::assignEventsToTiles() {
    for (int i = 0; i < _BOARD_SIZE; i++) {
        if (_tiles[0][i].color == 'G') {  // Assuming player 0's tiles are being updated
            int eventIndex = getEventForTile(i);
            _tileEvents[0][i] = eventIndex;
        }
        if (_tiles[1][i].color == 'G') {  // Assuming player 1's tiles are being updated
            int eventIndex = getEventForTile(i);
            _tileEvents[1][i] = eventIndex;
        }
    }
}

void Board::executeEvent(int eventNumber, char tileColor) {
    switch (tileColor) {
        case 'G': // Green tile events
            switch (eventNumber) {
                case 1:
                    cout << "Nothing happens." << endl;
                    break;
                case 2:
                    cout << "A desert storm sweeps through the territory. You lose 500 points." << endl;
                    break;
                case 3:
                    cout << "Fatigue from intense training with pride warriors. You lose 200 points." << endl;
                    break;
                case 4:
                    cout << "Challenging night watch duty under pitch-black conditions. You lose 400 points." << endl;
                    break;
                case 5:
                    cout << "Extra energy from bountiful season. You gain 800 points." << endl;
                    break;
                case 6:
                    cout << "Observed a rare natural phenomenon. You gain 600 points." << endl;
                    break;
                case 7:
                    cout << "Gained wisdom from observing Rafiki's rituals. You gain 500 points." << endl;
                    break;
                default:
                    cout << "Invalid event number." << endl;
                    break;
            }
            break;
       case 'U':
            cout << "u effects" << endl;
            break;
        case 'B':
            cout << "B effect" << endl;
            break;
        case 'P':
            cout << "p effects" << endl;
            break;
        case 'N':
            cout << "N effect" << endl;
            break;
        case 'R':
            cout << "R effect" << endl;
            break;
        default:
            cout << "Invalid tile color." << endl;
            break;
    }
}