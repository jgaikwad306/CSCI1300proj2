//with Aaron Duong

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <fstream>
#include<sstream>
using namespace std;

//add advisor and character name

class Player{
    private:
        string _name;
        string _character;
        string _advisor;

        int _strength, _stamina, _wisdom, _pride_points, _age;
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
};
#endif