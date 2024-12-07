//Partner Joel Gaikwad

//pulled from last week submission for rec
//logic for the iostream
#include "Board.h"
#include "tile.h"
#include "Player.h"
#include "game.h"
Player::Player(){
_name = "";
_age = 1;
_strength = 100;
_stamina = 100;
_wisdom =100;
_pride_points = 0;
}
// Player::Player(string name, int strength, int stamina, int wisdom ){

// }
string Player::getName(){
    return _name;

}

string Player::getCharacter () {
    return _character; 
}


int Player::getStrength(){
    return _strength;

}
int Player::getStamina(){
    return _stamina;

}
int Player::getWisdom(){
    return _wisdom;

}
int Player::getPridePoints(){
    return _pride_points;

}
int Player::getAge(){
    return _age;

}
void Player::setName(string name){
    _name = name;


}
void Player::setStrength(int strength){
    if(strength >= 100 && strength <= 1000){
_strength = strength;
     }
}
void Player::setStamina(int stamina){
    if(stamina >= 100 && stamina <= 1000){
        _stamina = stamina;
     }

}
void Player::setWisdom(int wisdom){
if(wisdom >= 100 && wisdom <= 1000){
        _wisdom = wisdom;
     }
}
void Player::setPridePoints(int pride_points){
    _pride_points = pride_points;

}
void Player::setAge(int age){
    if(age >= 1 && age <= 20){
        _age = age;
    }

}
void Player::setCharacter(string character) {
    _character = character;
}
void Player::trainCub(int strength, int stamina, int wisdom){
    if(strength >= 100 && strength <= 1000){
_strength = strength;
     }

     if(stamina >= 100 && stamina <= 1000){
        _stamina = stamina;
     }
if(wisdom >= 100 && wisdom <= 1000){
        _wisdom = wisdom;
     }
_pride_points = -5000;

    

}
void Player::toPrideLands(){
    _strength = -2000;
    _wisdom = -2000;
    _stamina = -1000;
    _pride_points = 5000;

}


void Player::printStats(){
    cout<< _name<<", age "<<_age<<endl;
    cout<<"Strength: "<<_strength<<endl;
    cout<<"Stamina: "<<_stamina<<endl;
    cout<<"Wisdom: "<<_wisdom<<endl;
    cout<<"Pride Points: "<<_pride_points<<endl;

}
