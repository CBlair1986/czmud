// TODO: Reorganize, get things settled into a sensible, understandable flow.
#include "main.h"

int main()
{   
    /*
     * This will be a bit of a test. To see if it works, and such.
     */
    endGame = false;
    TCODConsole::initRoot(80, 50, "CZGame", false);
    char *field[] =
    { "    ####",
      "    #..#",
      "    #..#",
      "#####..#",
      "#......#",
      "#......#",
      "########" };
    VMap vfield (8,8);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (field[i][j] == '#')
            {
                vfield.setCell(j,i,1);
            } else if (field[i][j] == '.')
            {
                vfield.setCell(j,i,2);
            } else
            {
                vfield.setCell(j,i,0);
            }
        }
    }
    Region * region = new Region(vfield, 40, 25);
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
