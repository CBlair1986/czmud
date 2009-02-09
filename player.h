#ifndef PLAYER_H
#define PLAYER_H
#include "vector.h"
#include "libtcod.hpp"

class Player
{
    Vector pos;
    char symbol;
    public:
    Player(int,int,char);
    void moveSouth(int distance) { pos.y += distance; }
    void moveNorth(int distance) { pos.y -= distance; }
    void moveEast(int distance) { pos.x += distance; }
    void moveWest(int distance) { pos.x -= distance; }
    void draw() { TCODConsole::root->putChar(pos.x,pos.y,(int)symbol,TCOD_BKGND_NONE); }
};
#endif
