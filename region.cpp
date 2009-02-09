#include "region.h"

Region::Region(uint32 a_seed)
{
    seed = a_seed;
}

Region::Region(int a_seed)
{
    seed = (uint32)a_seed;
}
