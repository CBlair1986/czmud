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
    Player (int x, int y, char a_symbol)
    {
        pos.x = x;
        pos.y = y;
        symbol = a_symbol;
        fgcolor = TCODColor::white;
        bgcolor = TCODColor::black;
    }
    Player (int x, int y, char a_symbol, TCODColor fg, TCODColor bg = TCODColor::black)
    {
        Player(x,y,a_symbol);
        fgcolor = fg;
        bgcolor = bg;
    }
    void moveSouth(int distance) { pos.y += distance; }
    void moveNorth(int distance) { pos.y -= distance; }
    void moveEast(int distance) { pos.x += distance; }
    void moveWest(int distance) { pos.x -= distance; }
    void draw() { TCODConsole::root->putChar(pos.x,pos.y,(int)symbol,TCOD_BKGND_NONE); }
};

class NonPlayer: public Player
{
    public:
        NonPlayer (int a,int b, char c): Player (a,b,c) {}
        NonPlayer (int a,int b, char c, TCODColor fg, TCODColor bg = TCODColor::black): Player (a,b,c) {}
        void update()
        {
            TCODRandom * gen = TCODRandom::getInstance();
            int choice = gen->getInt(0,7);
            switch (choice) {
                case 0:
                    moveSouth(1);
                    break;
                case 1:
                    moveNorth(1);
                    break;
                case 2:
                    moveEast(1);
                    break;
                case 3:
                    moveWest(1);
                    break;
                case 4:
                    moveSouth(1);
                    moveEast(1);
                    break;
                case 5:
                    moveSouth(1);
                    moveWest(1);
                    break;
                case 6:
                    moveNorth(1);
                    moveEast(1);
                    break;
                case 7:
                    moveNorth(1);
                    moveWest(1);
                    break;
            }
        }
};
#endif
