#ifndef VECTOR_H
#define VECTOR_H

#include "main.h"

struct Vector
{
    int x,y;
};

// I think I will use this, to keep track of player position and such.
struct Position
{
    Vector v;
    Region * r;
};
#endif
