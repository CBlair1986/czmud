#ifndef PLAYER_H
#define PLAYER_H
#include "vector.h"
#include "libtcod.hpp"

class Player
{
    Vector pos;
    char symbol;
    TCODColor fgcolor, bgcolor;
    public:
    Player (int, int, char);
    Player (int, int, char, TCODColor, TCODColor);
    void moveSouth(int);
    void moveNorth(int);
    void moveEast(int);
    void moveWest(int);
    void draw();
};
#endif
