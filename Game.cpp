//*****************************************************************************
// 
// 
// sivshani@gmail.com
//*****************************************************************************

#include "Game.hpp"
#include "globals.hpp"

BoardDimensions getBoardDimensions()
{
    unsigned int monitor_width = sf::VideoMode::getDesktopMode().width;
    unsigned int monitor_height = sf::VideoMode::getDesktopMode().height;

    // in case 100% board fits in monitor
    if(monitor_width > BoardWidth_100 && monitor_height > BoardHeight_100)
    {
        return BoardDimensions(PacruBoardTransparent_100, BoardWidth_100, BoardHeight_100,
                               BorderlandWidth_100, BorderlandHeight_100,
                               FieldWidth_100, FieldHeight_100, SeparationLine_100);
    }
    if(monitor_width > BoardWidth_75 && monitor_height > BoardHeight_75)
    {
        return BoardDimensions(PacruBoardTransparent_75, BoardWidth_75, BoardHeight_75,
                               BorderlandWidth_75, BorderlandHeight_75,
                               FieldWidth_75, FieldHeight_75, SeparationLine_75);
    }
    return BoardDimensions(PacruBoardTransparent_50, BoardWidth_50, BoardHeight_50,
                           BorderlandWidth_50, BorderlandHeight_50,
                           FieldWidth_50, FieldHeight_50, SeparationLine_50);
}

void Game::run()
{

}