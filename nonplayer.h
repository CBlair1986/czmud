#ifndef NONPLAYER_H
#define NONPLAYER_H
#include "libtcod.hpp"
#include "vector.h"

class NonPlayer: public Player
{
    public:
        NonPlayer (int a,int b, char c, Region * r): Player (a,b,c,r) {}
        NonPlayer (int a,int b, char c, Region * r, TCODColor fg, TCODColor bg = TCODColor::black): Player (a,b,c,r,fg,bg) {}
        void update();
};
#endif
