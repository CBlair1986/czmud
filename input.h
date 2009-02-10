#ifndef INPUT_H
#define INPUT_H
#include "libtcod.hpp"
#include "player.h"
#include "defines.h"

void handleCharacter (TCOD_key_t *, Player *);
void handleInput (TCOD_key_t *, Player *);

#endif
