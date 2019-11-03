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
    Game();
    ~Game();

    void run();

private:
    void initSystem();
    BoardImage selectImageBoard(sf::Vector2u monitorDim);

    sf::Vector2u screenDimensions;

    bool doQuit;

    // Number of times the board has been displayed
    uint redrawCount;
    uint keyDisplayCountDown;
};

#endif //PACRU_GAME_HPP
