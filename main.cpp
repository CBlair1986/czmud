#include "libtcod.hpp"

int main()
{   
    /*
     * This will be a bit of a test. To see if it works, and such.
     */
    TCODConsole::initRoot(80,50,"CZGame",false);
    bool endGame;
    while ( ! endGame && ! TCODConsole::isWindowClosed() )
    {
        // Draw functions go here...
        TCODConsole::flush();
        TCOD_key_t key=TCODConsole::waitForKeypress(true);
        // Updating functions go here...
    }
    // Cleanup goes here...
}
