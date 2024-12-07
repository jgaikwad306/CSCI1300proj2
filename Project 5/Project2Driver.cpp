#include "Game.h"
#include "Board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void displayMenu() {
    cout << "Game Menu:\n";
    cout << "1. Check Player Progress\n";
    cout << "2. Review Character\n";
    cout << "3. Check Position\n";
    cout << "4. Review Your Advisor\n";
    cout << "5. Move Forward\n";
    cout << "6. Switch Player\n";
    cout << "7. View Leaderboard\n";
    cout << "8. Exit Game\n";
    cout << "Enter your choice: ";
}

void bubbleSort(Player players[], int numPlayers, const string &stat) {
    for (int i = 0; i < numPlayers - 1; i++) {
        for (int j = 0; j < numPlayers - i - 1; j++) {
            bool swapCondition = false;

            if (stat == "Pride Points" && players[j].getPridePoints() < players[j + 1].getPridePoints()) {
                swapCondition = true;
            } else if (stat == "Strength" && players[j].getStrength() < players[j + 1].getStrength()) {
                swapCondition = true;
            } else if (stat == "Stamina" && players[j].getStamina() < players[j + 1].getStamina()) {
                swapCondition = true;
            } else if (stat == "Wisdom" && players[j].getWisdom() < players[j + 1].getWisdom()) {
                swapCondition = true;
            }

            if (swapCondition) {
                Player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }
}

void displayLeaderboard(Player players[], int numPlayers) {
    cout << "Choose a stat to rank players by:\n";
    cout << "1. Pride Points\n";
    cout << "2. Strength\n";
    cout << "3. Stamina\n";
    cout << "4. Wisdom\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    string stat;
    switch (choice) {
        case 1:
            stat = "Pride Points";
            break;
        case 2:
            stat = "Strength";
            break;
        case 3:
            stat = "Stamina";
            break;
        case 4:
            stat = "Wisdom";
            break;
        default:
            cout << "Invalid choice. Returning to menu.\n";
            return;
    }

    Player sortedPlayers[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        sortedPlayers[i] = players[i];
    }

    bubbleSort(sortedPlayers, numPlayers, stat);

    cout << "\nLeaderboard (Ranked by " << stat << "):\n";
    for (int i = 0; i < numPlayers; i++) {
        cout << i + 1 << ". " << sortedPlayers[i].getName() << " - " << stat << ": ";

        if (stat == "Pride Points") {
            cout << sortedPlayers[i].getPridePoints();
        } else if (stat == "Strength") {
            cout << sortedPlayers[i].getStrength();
        } else if (stat == "Stamina") {
            cout << sortedPlayers[i].getStamina();
        } else if (stat == "Wisdom") {
            cout << sortedPlayers[i].getWisdom();
        }

        cout << endl;
    }
}

void handleMenuOption(int option, Game &gameInstance, Board &gameBoard, Player players[], int &currentPlayer, int numPlayers) {
    switch (option) {
        case 1: {
            players[currentPlayer].printStats();
            break;
        }
        case 2: {
            cout << "1. Display Character Name\n";
            cout << "2. Display Character Age\n";
            int subOption;
            cin >> subOption;
            switch (subOption) {
                case 1:
                    cout << "Player " << currentPlayer + 1 << " Character Name: "
                         << players[currentPlayer].getName() << endl;
                    break;
                case 2:
                    cout << "Player " << currentPlayer + 1 << " Character Age: "
                         << players[currentPlayer].getAge() << endl;
                    break;
                default:
                    cout << "Invalid choice for Character menu.\n";
            }
            break;
        }
        case 3:
            cout << "Player " << currentPlayer + 1 << " is at position: "
                 << gameBoard.getPlayerPosition(currentPlayer) << endl;
            break;

        case 4: {
            cout << "Player " << currentPlayer + 1 << " Advisor: "
                 << players[currentPlayer].getAdvisor() << endl;
            break;
        }

        case 5: {
            int steps = rand() % 6 + 1; // Roll dice (1-6)
            cout << "Player " << currentPlayer + 1 << " rolls a " << steps << " and moves forward." << endl;

            int previousPosition = gameBoard.getPlayerPosition(currentPlayer);
            for (int i = 0; i < steps; i++) {
                bool reachedEnd = gameBoard.movePlayer(currentPlayer);
                if (reachedEnd) {
                    cout << "Player " << currentPlayer + 1 << " has reached the end of the board!" << endl;
                    return;
                }
            }

            int newPosition = gameBoard.getPlayerPosition(currentPlayer);
            string tileColor = gameBoard.getTileColor(currentPlayer);
            int eventNumber = gameBoard.getEventForTile(newPosition);

            cout << "Player " << currentPlayer + 1 << " landed on a " << tileColor << " tile." << endl;
            players[currentPlayer] = gameBoard.executeEvent(eventNumber + 1, tileColor[0], players[currentPlayer], newPosition, previousPosition);
            break;
        }

        case 6:
            currentPlayer = (currentPlayer + 1) % numPlayers;
            cout << "Switching to Player " << currentPlayer + 1 << "\n";
            break;

        case 7:
            displayLeaderboard(players, numPlayers);
            break;

        case 8:
            cout << "Exiting game. Goodbye!" << endl;
            exit(0);

        default:
            cout << "Invalid option. Please try again.\n";
    }
}

int main() {
    srand(time(0)); // Seed the random number generator

    Game gameInstance; // Create a game instance
    gameInstance.welcome();

    // Create players and game board
    const int numPlayers = gameInstance.getNumPlayers();
    Player players[numPlayers];

    for (int i = 0; i < numPlayers; i++) {
        players[i] = gameInstance.getPlayer(i);
    }

    Board gameBoard(numPlayers);
    gameBoard.assignEventsToTiles();

    int currentPlayer = 0;

    while (true) {
        cout << "\nPlayer " << currentPlayer + 1 << "'s Turn:\n";
        displayMenu();
        int option;
        cin >> option;
        handleMenuOption(option, gameInstance, gameBoard, players, currentPlayer, numPlayers);
    }

    return 0;
}
