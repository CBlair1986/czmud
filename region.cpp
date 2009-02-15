#include "main.h"

Region::Region(uint32 a_seed)
{
    seed = a_seed;
    makeRegion();
}

Region::Region(int a_seed)
{
    seed = (uint32)a_seed;
    makeRegion();
}

// This is mainly for testing purposes; I can define a set floor pattern, to
// see if it displays correctly.
Region::Region(vector<vector<int > > a_floor)
{
    floor = a_floor;
}

// TODO: This will set the region up, storing the neccessary data for the room
// for later use.
void Region::makeRegion()
{
}

// TODO: This will draw the region to the screen, proceeding to neighboring
// regions when neccessary.
void Region::drawRegion()
{
}
