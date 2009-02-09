#include "libtcod.hpp"
#include "region.h"
#include "defines.h"
#include "player.h"

bool endGame;

void handleCharacter (TCOD_key_t * key, Player * player)
{
    switch (key->c) {
        case 'h':
            player->moveWest(1);
            break;
        case 'k':
            player->moveNorth(1);
            break;
        case 'j':
            player->moveSouth(1);
            break;
        case 'l':
            player->moveEast(1);
            break;
        case 'y':
            player->moveNorth(1);
            player->moveWest(1);
            break;
        case 'u':
            player->moveNorth(1);
            player->moveEast(1);
            break;
        case 'b':
            player->moveSouth(1);
            player->moveWest(1);
            break;
        case 'n':
            player->moveSouth(1);
            player->moveEast(1);
            break;
    }
}

void handleInput (TCOD_key_t * key, Player * player)
{
    switch (key->vk) {
        case TCODK_ESCAPE:
            endGame = true;
            break;
        case TCODK_UP:
            player->moveNorth(1);
            break;
        case TCODK_DOWN:
            player->moveSouth(1);
            break;
        case TCODK_LEFT:
            player->moveWest(1);
            break;
        case TCODK_RIGHT:
            player->moveEast(1);
            break;
        case TCODK_CHAR:
            handleCharacter(key, player);
            break;
    }
}

int main()
{   
    /*
     * This will be a bit of a test. To see if it works, and such.
     */
    TCODConsole::initRoot(80,50,"CZGame",false);
    Player * player = new Player (0,0,'@');
    while ( ! endGame && ! TCODConsole::isWindowClosed() )
    {
        // Draw functions go here...
        TCODConsole::root->clear();
        player->draw();
        TCODConsole::flush();
        TCOD_key_t * key=&TCODConsole::waitForKeypress(true);
        // Updating functions go here...
        handleInput(key,player);
    }
    // Cleanup goes here...
    return 0;
}
