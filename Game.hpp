//*****************************************************************************
// Run and control the game and the IO
// 
// sivshani@gmail.com
//*****************************************************************************

#ifndef PACRU_GAME_HPP
#define PACRU_GAME_HPP

#include "Board.hpp"

/*
 * helper functions
 */
// calculate board dimensions and return structure with those dimensions
BoardDimensions getBoardDimensions();

class Game
{
public:
    void run();

private:

};

#endif //PACRU_GAME_HPP
