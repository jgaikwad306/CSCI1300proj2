#include "Game.h"
#include "Player.h"
#include "Board.h"
#include "Tile.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Game::Game() {
    _num_players = 2;
}

int Game::getNumPlayers() const {
    return _num_players;
}

Game::Game(Player character[], int num_players) {
    if (num_players > 5 || num_players < 2) {
        _num_players = 2;
    } else {
        _num_players = num_players;
    }
}

Player Game::getPlayer(int playerIndex) {
    return _player[playerIndex]; // Return a copy of the player object
}

void Game::loadCharacters() {
    ifstream players("characters.txt");
    if (players.fail()) {
        cout << "Error: Failed to load characters file." << endl;
        return;
    }

    string line;
    string name, ageS,strengthS, staminaS, wisdomS, pridePointsS;
    int age, stamina, strength, wisdom, pridePoints;
    int idx = 0;

    while (getline(players, line) && idx < 5) {
        stringstream ss(line);
        getline(ss, name, '|');
        getline(ss, ageS, '|');
        getline(ss, strengthS, '|');

        getline(ss, staminaS, '|');
        getline(ss, wisdomS, '|');
        getline(ss, pridePointsS, '|');


        age = stoi(ageS);
                strength = stoi(strengthS);

        stamina = stoi(staminaS);
        wisdom = stoi(wisdomS);
        pridePoints = stoi(pridePointsS);
        _player[idx].setCharacter(name);
        _player[idx].setAge(age);
                _player[idx].setStrength(strength);

        _player[idx].setStamina(stamina);
        _player[idx].setWisdom(wisdom);
        _player[idx].setPridePoints(pridePoints);
        idx++;
    }

    players.close();

    // Debugging: Print player stats after loading
    for (int i = 0; i < 5; i++) {
        _player[i].printStats();
    }
}

void Game::loadAdvisors() {
    ifstream advisors("Advisors.txt");
    if (advisors.fail()) {
        cout << "Error: Failed to load advisors file." << endl;
        return;
    }

    string line;
    int num = 0;

    while (getline(advisors, line) && num < 5) {
        _advisor[num].setAdvisor(line);
        num++;
    }

    advisors.close();

    // Debugging: Print advisor names after loading
    for (int i = 0; i < 5; i++) {
        cout << "Advisor " << i + 1 << ": " << _advisor[i].getAdvisor() << endl;
    }
}

void Game::welcome() {
    string name;
    int num_players;
    string character;
    int path = 0;
    int advisor;

    cout << "Welcome to the Game of Life! Please enter how many people are playing and your name!" << endl;
    cout << "Number of People playing: ";
    cin >> num_players;

    if (num_players <= 5 && num_players >= 2) {
        _num_players = num_players; // Update the number of players

        loadCharacters(); // Load characters only once

        for (int i = 0; i < num_players; i++) {
            cout << "\nEnter your name: ";
            cin >> name;

            cout << "Choose a Character: ";
            cin >> character;

            bool validCharacter = false;
            for (int j = 0; j < 5; j++) { // Check against loaded characters
                if (_player[j].getCharacter() == character) {
                    validCharacter = true;
                    _player[i] = _player[j];  // Assign the selected character to the current player
                    _player[i].setName(name); // Set the player's name
                    break;
                }
            }

            if (!validCharacter) {
                cout << "Invalid character. Please restart and choose a valid character." << endl;
                return;
            }

            cout << "\nChoose a path:" << endl;
            cout << "1. Straight to Pride Lands" << endl;
            cout << "2. Cub Training" << endl;
            cin >> path;

            switch (path) {
                case 1:
                    cout << "Before `toPrideLands`: ";
                    _player[i].printStats();
                    _player[i].toPrideLands();
                    cout << "After `toPrideLands`: ";
                    _player[i].printStats();
                    break;
                case 2:
                    cout << "Before `trainCub`: ";
                    _player[i].printStats();
                    _player[i].trainCub(_player[i].getStrength(), _player[i].getStamina(), _player[i].getWisdom());
                    cout << "After `trainCub`: ";
                    _player[i].printStats();

                    cout << "Choose an Advisor!" << endl;
                    loadAdvisors();
                    cin >> advisor;

                    if (advisor >= 0 && advisor < 5) {
                        _player[i].setAdvisor(_advisor[advisor].getAdvisor());
                    } else {
                        cout << "Invalid advisor choice. Defaulting to first advisor." << endl;
                        _player[i].setAdvisor(_advisor[0].getAdvisor());
                    }
                    break;
                default:
                    cout << "Invalid path choice." << endl;
                    break;
            }

            cout << "\nPlayer setup complete for " << name << "!" << endl;
        }
    } else {
        cout << "Invalid number of players. Please restart the game." << endl;
    }
}
void Game::showPlayerStats(int playerIndex) {
    if (playerIndex >= 0 && playerIndex < _num_players) {
        cout << "Stats for Player " << playerIndex + 1 << ":" << endl;
        _player[playerIndex].printStats();
    } else {
        cout << "Invalid player index. Please choose a valid player." << endl;
    }
}

// //void Game::menu()
// {
//     Board board;
//     int choice;
//     int i;
//     cout << "Main Menu: Select an option to continue" << endl;
//     cout << "1. Check Player Progress (1)" << endl;
//     cout << "2. Review Character (2)" << endl;
//     cout << "3. Check Position (3)" << endl;
//     cout << "4. Review your Advisor (4)" << endl;
//     cout << "5. Move Forward (5)" << endl;

//     cin >> choice;
//     switch (choice)
//     {
//     case 1:
//         _player[i].printStats();

//         break;
//     case 2:

//     case 3:
//        //board.getPlayerPosition();
//     case 4:

//     case 5:
//     }
// }

// int main()
// {
//     Game game;
//     game.welcome();
// }
