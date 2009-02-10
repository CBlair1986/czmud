#include "player.h"
#include "nonplayer.h"
/**
 * Moves a NonPlayer according to a random choice.
 */
void NonPlayer::update()
{
    TCODRandom * gen = TCODRandom::getInstance();
    int choice = gen->getInt(0,7);
    switch (choice) {
        case 0:
            moveSouth(1);
            break;
        case 1:
            moveNorth(1);
            break;
        case 2:
            moveEast(1);
            break;
        case 3:
            moveWest(1);
            break;
        case 4:
            moveSouth(1);
            moveEast(1);
            break;
        case 5:
            moveSouth(1);
            moveWest(1);
            break;
        case 6:
            moveNorth(1);
            moveEast(1);
            break;
        case 7:
            moveNorth(1);
            moveWest(1);
            break;
    }
}
