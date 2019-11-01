//*****************************************************************************
// Run and control the game and the IO
// 
// sivshani@gmail.com
//*****************************************************************************

#ifndef PACRU_GAME_HPP
#define PACRU_GAME_HPP

#include "Board.hpp"

class Game
{
public:
    void run();

private:
    BoardImage selectImageBoard(sf::Vector2u monitorDim);
};

#endif //PACRU_GAME_HPP
