#ifndef VMAP_H
#define VMAP_H

#include "main.h"

class VMap
{
    TVecVecInt map;
    unsigned int map_width, map_height;
    public:
    VMap();
    VMap(int,int);
    void drawMap(int,int);
    void drawTerrain(int,int,int);
    void insertRect(int,int,int,int,int);
    void setCell(int,int,int);
    int getWidth();
    int getHeight();
};

#endif
