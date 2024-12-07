// With Joel Gaikwad 

#include "tile.h"

Tile::Tile(){
    _color = ' '; 
    _effect = 0;
}
Tile::Tile(string color, int effect)  {
    _color = color;
    _effect = effect;
}

string Tile::getColor()  { 
    return _color; }

int Tile::getEffect()  { 
    return _effect; }

// Setters
void Tile::setColor(string color) {
     _color = color; }
void Tile::setEffect(int effect) {
     _effect = effect; }

void applyEffect(); /*This would use if statements based off the color tile the character lands on, 
matching the description/requirements given from the workbook. It would then change numbers for player. Maybe use switch statements
1. Check the tile's color.
2. Use if statements to determine the effect based on the color.
3. Apply the corresponding effect to the player by using effect with a number.
4. Output a message indicating the effect applied.*/