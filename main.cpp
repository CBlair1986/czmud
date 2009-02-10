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
    Player * player = new Player (0,0,'@');
    TCODList<NonPlayer *> monst;
    char * symbols = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 50000; i++)
    {
        monst.push(new NonPlayer (i % 80,25,symbols[i % 52]));
    }
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
