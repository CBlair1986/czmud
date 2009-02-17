// TODO: Reorganize, get things settled into a sensible, understandable flow.
#include "main.h"

int main()
{   
    /*
     * This will be a bit of a test. To see if it works, and such.
     */
    endGame = false;
    TCODConsole::initRoot(80, 50, "CZGame", false);
    Region * region = new Region(1);
    Player * player = new Player (0, 0, '@', region);
    while ( ! endGame && ! TCODConsole::isWindowClosed() )
    {
        // Draw functions go here...
        TCODConsole::root->clear();
        player->drawRegion();
        TCODConsole::flush();
        TCOD_key_t * key=&TCODConsole::waitForKeypress(true);
        // Updating functions go here...
        handleInput(key, player);
    }
    // Cleanup goes here...
    delete region;
    delete player;
    return 0;
}


/*
 * Ideally, I want to have something with entry points, like this pseudo-code:
 *
 * main( arguments )
 * {
 * initial setup ( arguments )
 * startup stuff () <- Where we get the information from player.
 * begin mainloop ()
 * on exit functions () <- cleanup, saving, etc.
 * exit ()
 * }
 */
