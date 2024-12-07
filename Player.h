// With Joel Gaikwad 

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;
//Taken from last weeks rec for player
//Add the advisor and character list here
//use if streams

class Player{
    private:
        string _name;
        int _strength, _stamina, _wisdom, _pride_points, _age;
        string _character;
    public:
    Player();
    Player(string, int);
    string getName();
    string getCharacter();
    int getStrength();
    int getStamina();
    int getWisdom();
    int getPridePoints();
    int getAge();
    void setName(string name);
    void setCharacter (string character); 
    void setStrength(int strength); 
    void setStamina(int stamina); 
    void setWisdom(int wisdom);
    void setPridePoints(int pride_points); 
    void setAge(int age);
    void trainCub (int strength,int stamina,int wisdom);
    void printStats();
    void toPrideLands() ; 
    
};
#endif