#ifndef PLAYER_H
#define PLAYER_H
#include "vector.h"
#include "libtcod.hpp"

class Player
{
    Position pos;
    char symbol;
    TCODColor fgcolor, bgcolor;
    public:
    Player (int, int, char, Region*);
    Player (int, int, char, Region*, TCODColor, TCODColor);
    void moveSouth(int);
    void moveNorth(int);
    void moveEast(int);
    void moveWest(int);
    void draw();
    void drawRegion();
};
#endif
