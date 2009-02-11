// TODO: Reorganize, get things settled into a sensible, understandable flow.
#include "libtcod.hpp"
#include "region.h"
#include "defines.h"
#include "input.h"
#include "player.h"
#include "nonplayer.h"

bool endGame;

int main()
{   
    /*
     * This will be a bit of a test. To see if it works, and such.
     */
    endGame = false;
    TCODConsole::initRoot(80,50,"CZGame",false);
    Region * r = new Region(1);
    Player * player = new Player (0,0,'@',r);
    TCODList<NonPlayer *> monst;
    char * symbols = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    TCODRandom * gen = new TCODRandom();
    for (int i = 0; i < 50000; i++)
    {
        int red = gen->getInt(0,255);
        int green = gen->getInt(0,255);
        int blue = gen->getInt(0,255);
        TCODColor fgcolor (red,green,blue);
        monst.push(new NonPlayer (i % 80,25,symbols[i % 52],r,fgcolor));
    }
    delete gen;
    while ( ! endGame && ! TCODConsole::isWindowClosed() )
    {
        // Draw functions go here...
        TCODConsole::root->clear();
        for (NonPlayer * * i = monst.begin(); i != monst.end(); i++)
        {
            NonPlayer * monst = *i;
            monst->update();
            monst->draw();
        }
        player->draw();
        TCODConsole::flush();
        TCOD_key_t * key=&TCODConsole::waitForKeypress(true);
        // Updating functions go here...
        handleInput(key,player);
    }
    // Cleanup goes here...
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
