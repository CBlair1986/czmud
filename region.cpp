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
Region::Region(VMap a_floor, int cx, int cy)
{
    floor = a_floor;
    cornerx = cx;
    cornery = cy;
}

// TODO: This will set the region up, storing the neccessary data for the room
// for later use.
void Region::makeRegion()
{
    TCODRandom *gen = TCODRandom::getInstance();
    int width = gen->getInt(5,15);
    int height = gen->getInt(5,15);
    floor = VMap(width,height);
    // TODO: I'm going to use the 'glue it on' method of making irregular rooms
    // I suppose.
    TCODConsole::root->printLeft(0,0,TCOD_BKGND_NONE,"%d,%d",width,height);
}

// TODO: This will draw the region to the screen, proceeding to neighboring
// regions when neccessary.
void Region::drawRegion()
{
    // I need to draw the appropriate region using the appropriate symbols.
    // 0 -> ' '
    // 1 -> '#'
    // Should be easy.
    // TODO Make this sensible. You should reference the number you get to some
    // sort of table of types, one per number possible.

    // TODO: I'll do some conditional rotation things here, eventually.

    // Draw the map.
    floor.drawMap(cornerx,cornery);
    // Draw the objects.
    // for key in objects
    // key is (x,y) position in the region
    // key points to value, which will be a list of item objects.
    // item.symbol is what we want.

    // Draw the creatures (this includes the player)
}
