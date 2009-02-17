#include "main.h"

/**
 * Initializes a player, setting the foreground and background colors to the
 * default white and black, respectively.
 * 
 * \param x The initial x position of the Player.
 * \param y The initial y position of the Player.
 * \param a_symbol The character used to represent the Player.
 */
Player::Player (int x, int y, char a_symbol, Region * a_region)
{
    pos.v.x = x;
    pos.v.y = y;
    symbol = a_symbol;
    fgcolor = TCODColor::white;
    bgcolor = TCODColor::black;
    pos.r = a_region;
}

/**
 * Initializes a player, as Player (int, int, char), but also specifies the
 * foreground and background colors to use.
 * 
 * \param fg The foreground color to use.
 * \param bg The background color to use.
 */
Player::Player (int x, int y, char a_symbol, Region * a_region, TCODColor fg, TCODColor bg = TCODColor::black)
{
    pos.v.x = x;
    pos.v.y = y;
    symbol = a_symbol;
    fgcolor = fg;
    bgcolor = bg;
    pos.r = a_region;
}

/**
 * Moves a Player object south by distance.
 * \param distance The number of spaces to move.
 */
void Player::moveSouth(int distance) { pos.v.y += distance; }

/**
 * Moves a Player object north by distance.
 * \param distance The number of spaces to move.
 */
void Player::moveNorth(int distance) { pos.v.y -= distance; }

/**
 * Moves a Player object east by distance.
 * \param distance The number of spaces to move.
 */
void Player::moveEast(int distance) { pos.v.x += distance; }

/**
 * Moves a Player object west by distance.
 * \param distance The number of spaces to move.
 */
void Player::moveWest(int distance) { pos.v.x -= distance; }

/**
 * Draws the Player object, using the symbol, foreground, and background color
 * options
 */
void Player::draw()
{
    // Store old values:
    TCODColor oldfg, oldbg;
    oldfg = TCODConsole::root->getForegroundColor();
    oldbg = TCODConsole::root->getBackgroundColor();
    // Set the new colors:
    TCODConsole::root->setBackgroundColor(bgcolor);
    TCODConsole::root->setForegroundColor(fgcolor);
    // Draw character:
    TCODConsole::root->putChar(pos.v.x,pos.v.y,(int)symbol,TCOD_BKGND_SET);
    // Reset colors:
    TCODConsole::root->setForegroundColor(oldfg);
    TCODConsole::root->setBackgroundColor(oldbg);
}

void Player::drawRegion()
{
    pos.r->drawRegion();
}
