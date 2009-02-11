#ifndef VECTOR_H
#define VECTOR_H
#include "region.h"

struct Vector
{
    int x,y;
};

struct Position
{
    Vector v;
    Region * r;
};
#endif
