#ifndef REGION_H
#define REGION_H
#include "libtcod.hpp"

class Region
{
    /*
     * This represents a single 'room' in the game, and holds references to the
     * rooms that this room links to.
     *
     * Gonna be interesting...
     */
    uint32 seed;

    public:
    Region(uint32);
    Region(int);
    int getSeed() { return seed; }
};

#endif
