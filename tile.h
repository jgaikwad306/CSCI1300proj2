// With Joel Gaikwad 

#ifndef Tile_H
#define Tile_H
#include <iostream>
#include <string>
using namespace std;


class Tile {
    
   
   private: 
    string _color; 
    int _effect; 
            int event;

    public: 
    char color; 
    Tile();
    Tile(string color , int effect );

    // Getters
    string getColor() ;
    int getEffect() ;

    // Setters
    void setColor(string color);
    void setEffect(int effect);
};

#endif