//with Aaron Duong
#include "Player.h"
Player::Player(){
_name = "";
_character = "";
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
string Player::getCharacter(){
    return _character;
}
string Player::getAdvisor(){
    return _advisor;
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
void Player::setCharacter(string character){
    _character = character;


}
void Player::setAdvisor(string advisor){
    _advisor = advisor;

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
    cout<< _character<<", age "<<_age<<endl;
    cout<<"Strength: "<<_strength<<endl;
    cout<<"Stamina: "<<_stamina<<endl;
    cout<<"Wisdom: "<<_wisdom<<endl;
    cout<<"Pride Points: "<<_pride_points<<endl;
    cout<<"**************************"<<endl;

}


// //this gets all the characters 
// void Player::loadCharacters(){
//     ifstream players("characters.txt");
//     if(players.fail()){
//         cout<<"this shit does not work!!!"<<endl;
//     }
//     Player player[5];
//     string line;
//     string name;
//     string ageS;
//     string staminaS;
//     string wisdomS;
//     string pridePointsS;
//     int  age;
//     int stamina;
//     int wisdom;
//     int pridePoints;
//     int idx = 0;

//     while(getline(players,line) && idx < 5){
//         stringstream ss(line);
//         getline(ss,name,'|');
//         getline(ss, ageS, '|');
//         getline(ss, staminaS, '|');
//         getline(ss, wisdomS, '|');
//         getline(ss, pridePointsS,'|');

//         age = stoi(ageS);
//         stamina = stoi(staminaS);
//         wisdom = stoi(wisdomS);
//         pridePoints = stoi(pridePointsS);

//         // cout<<"Name: "<<name<<", Age: "<<age<<endl;
//         // cout<<"Stamina: "<<stamina<<endl;
//         // cout<<"Wisdom: "<<wisdom<<endl;
//         // cout<<"Pride Points: "<<pridePoints<<endl;
//         // cout<<"******************************"<<endl;

//         player[idx].setCharacter(name);
//         player[idx].setAge(age);
//         player[idx].setStamina(stamina);
//         player[idx].setWisdom(wisdom);
//         player[idx].setPridePoints(pridePoints);
//         player[idx].printStats();


//         idx++;



        
//     }
//      players.close();

// }

// void Player::welcome(){
//     string name;
//     string character;

//     cout<<"Welcome to the Game of Life! Please enter your name and choose a character."<<endl;
//     cout<<"    "<<endl;
//     loadCharacters();
//     cout<<"Enter your name: ";
//     cin>>name;
//     cout<<"Choose a Character: ";
//     cin>>character;

// if(character == "Apollo"){

    
// }

    
    



// }








