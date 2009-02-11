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
