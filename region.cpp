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
Region::Region(vector<vector<int > > a_floor, int cx, int cy)
{
    floor = a_floor;
    centerx = cx;
    centery = cy;
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
    // I need to draw the appropriate region using the appropriate symbols.
    // 0 -> ' '
    // 1 -> '#'
    // Should be easy.
    // TODO Make this sensible. You should reference the number you get to some
    // sort of table of types, one per number possible.
    int width = floor[0].size();
    int height = floor.size();
    int half_width = width / 2;
    int half_height = height / 2;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            char symbol;
            if (floor[i][j] == 1)
            {
                symbol = '#';
            } else if (floor[i][j] == 2)
            {
                symbol = '.';
            } else
            {
                symbol = ' ';
            }
            int x = j + (centerx - half_width);
            int y = i + (centery - half_height);
            TCODConsole::root->putChar(x,y,symbol,TCOD_BKGND_NONE);
        }
    }
}
