// With Joel Gaikwad 

#include "Board.h"
#include "tile.h"
#include "player.h"
#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



int main() {
    srand(time(0));
    Board game(2); // Initialize the board for 2 players

    // Assign events to green tiles after initializing the board
    game.assignEventsToTiles();

    while (true) {
        for (int i = 0; i < 2; i++) {
            game.displayBoard();

            int steps;
            cout << "Player " << i + 1 << ", enter the number of tiles to move: ";
            while (!(cin >> steps) || steps < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a positive integer: ";
            }

            for (int j = 0; j < steps; j++) {
                bool reachedEnd = game.movePlayer(i);
                string tileColor = game.getTileColor(i);

                cout << "Player " << i + 1 << " is now on a " << tileColor << " tile." << endl;

                // If the player is on a green, purple, or blue tile, execute the event
               
                    int currentPosition = game.getPlayerPosition(i);
                    int eventIndex = game.getEventForTile(currentPosition);
                    game.executeEvent(eventIndex + 1, tileColor[0]);  // Execute the event for the player based on tile color
            

                if (reachedEnd) {
                    cout << "Player " << i + 1 << " has reached the end of the board! Game over." << endl;
                    return 0; // End the game
                }
            }

            cout << endl;
        }
    }

    return 0;
}


//cout char list from if stream
//have them choose which char they want with a switch or if statement then enter name
//have them choose if they want pridelands or cubtraining which determines the board to use
// all values must be ran through constructor
//if they choose cubtraining, they must choose an advisor from ifstream list, which can be done with a switch
//use a dice function to determine how far they go
//button that allows to open menu
//cout menu and code to run menu  
/*1. Check Player Progress: Review Pride Point and Leadership Trait stats.
2. Review Character: Check your character name and age.
3. Check Position: Display board to view current position.
4. Review your Advisor: Check who your current advisor is on the game.
5. Move Forward: For each player’s turn, access this option to spin the virtual spinner.*/
//


