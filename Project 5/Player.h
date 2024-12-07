#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Player {
private:
    string _name;
    string _character;
    string _advisor;
    int _boardIndex; // NEW: Index of the board assigned to the player

    int _strength, _stamina, _wisdom, _pride_points, _age;
    int _track; // Track selection (0 for Path 1, 1 for Path 2)

public:
    Player();
    Player(string, int);

    string getName();
    string getCharacter();
    string getAdvisor();
    int getStrength();
    int getStamina();
    int getWisdom();
    int getPridePoints();
    int getAge();
void setTrack(int track) { _track = track; }
    int getTrack() const { return _track; }
    void setName(string name);
    void setCharacter(string character);
    void setAdvisor(string advisor);
    void setStrength(int strength);
    void setStamina(int stamina);
    void setWisdom(int wisdom);
    void setPridePoints(int pride_points);
    void setAge(int age);

    void trainCub(int strength, int stamina, int wisdom);
    void toPrideLands();
    void printStats();
    void setBoardIndex(int boardIndex); // Set the board index
    int getBoardIndex() const;         // Get the board index
};

#endif
