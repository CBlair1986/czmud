#include "player.h"
#include "libtcod.hpp"

Player::Player (int x, int y, char a_symbol)
{
    pos.x = x;
    pos.y = y;
    symbol = a_symbol;
}
