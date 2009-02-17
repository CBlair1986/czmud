#include "main.h"

VMap::VMap(int width, int height)
{
    for (unsigned int y = 0; y < height; y++)
    {
        map.push_back(vector<int>(width));
    }
    map_width = width;
    map_height = height;
}

VMap::VMap()
{
    // Let's do something sensible...
    for (unsigned int y = 0; y < 10; y++)
    {
        map.push_back(vector<int>(10));
    }
    map_width = map[0].size();
    map_height = map.size();
}

void VMap::drawMap(int cornerx, int cornery)
{
    int x, y;
    for (y = 0; y < map_height; y++ )
    {
        for (x = 0; x < map_width; x++)
        {
            int t = map[y][x];
            drawTerrain(x+cornerx,y+cornery,t);
        }
    }
}

void VMap::setCell(int x, int y, int terrain)
{
    if ( x < map_width && y < map_height )
    {
        map[y][x] = terrain;
    }
}

void VMap::drawTerrain(int x, int y, int terrain)
{
    char symbol;
    switch (terrain)
    {
        case 0:
            symbol = ' ';
            break;
        case 1:
            symbol = '#';
            break;
        case 2:
            symbol = '.';
            break;
    }
    TCODConsole::root->putChar(x,y,symbol);
}
