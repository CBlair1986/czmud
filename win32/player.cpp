#include "player.h"
#include "libtcod.hpp"

/**
 * Initializes a player, setting the foreground and background colors to the
 * default white and black, respectively.
 * 
 * \param x The initial x position of the Player.
 * \param y The initial y position of the Player.
 * \param a_symbol The character used to represent the Player.
 */
Player::Player (int x, int y, char a_symbol)
{
    pos.x = x;
    pos.y = y;
    symbol = a_symbol;
    fgcolor = TCODColor::white;
    bgcolor = TCODColor::black;
}

/**
 * Initializes a player, as Player (int, int, char), but also specifies the
 * foreground and background colors to use.
 * 
 * \param fg The foreground color to use.
 * \param bg The background color to use.
 */
Player::Player (int x, int y, char a_symbol, TCODColor fg, TCODColor bg = TCODColor::black)
{
    Player(x,y,a_symbol);
    fgcolor = fg;
    bgcolor = bg;
}

/**
 * Moves a Player object south by distance.
 * \param distance The number of spaces to move.
 */
void Player::moveSouth(int distance) { pos.y += distance; }

/**
 * Moves a Player object north by distance.
 * \param distance The number of spaces to move.
 */
void Player::moveNorth(int distance) { pos.y -= distance; }

/**
 * Moves a Player object east by distance.
 * \param distance The number of spaces to move.
 */
void Player::moveEast(int distance) { pos.x += distance; }

/**
 * Moves a Player object west by distance.
 * \param distance The number of spaces to move.
 */
void Player::moveWest(int distance) { pos.x -= distance; }

/**
 * Draws the Player object, using the symbol, foreground, and background color
 * options
 */
void Player::draw() { TCODConsole::root->putChar(pos.x,pos.y,(int)symbol,TCOD_BKGND_NONE); }
