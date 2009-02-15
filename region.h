#ifndef REGION_H
#define REGION_H
#include "main.h"

class Region
{
    /*
     * This represents a single 'room' in the game, and holds references to the
     * rooms that this room links to.
     *
     * Gonna be interesting...
     *
     * What does a region need?
     * * a place to store things that it contains.
     *   most probably gonna be a simple list structure, with push/pop, etc. TCODList?
     * * a place to store its floor tiles, so it knows its shape.
     *   this would probably be an array, since I'm always gonna need the whole thing...
     */
    uint32 seed;
    int centerx, centery;
    vector<vector<int > > floor;
    public:
    Region(uint32);
    Region(int);
    Region(vector<vector<int > >);
    int getSeed() { return seed; }
    void makeRegion();
    void drawRegion();
};

#endif
