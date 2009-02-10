#ifndef NONPLAYER_H
#define NONPLAYER_H
#include "libtcod.hpp"
#include "vector.h"

class NonPlayer: public Player
{
    public:
        NonPlayer (int a,int b, char c): Player (a,b,c) {}
        NonPlayer (int a,int b, char c, TCODColor fg, TCODColor bg = TCODColor::black): Player (a,b,c) {}
        void update();
};
#endif
