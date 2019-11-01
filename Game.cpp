//*****************************************************************************
// 
// 
// sivshani@gmail.com
//*****************************************************************************

#include <iostream>

#include "Game.hpp"
#include "globals.hpp"

// calculates which board image is fitting the monitor
BoardImage Game::selectImageBoard(sf::Vector2u monitorDim)
{
    // in case 100% board fits in monitor
    if(monitorDim.x > BoardWidth_100 && monitorDim.y > BoardHeight_100)
    {
        return BoardImage(PacruBoardTransparent_100, BoardWidth_100, BoardHeight_100,
                               BorderlandWidth_100, BorderlandHeight_100,
                               FieldWidth_100, FieldHeight_100, SeparationLine_100);
    }
    // in case only 75% board fits in monitor
    if(monitorDim.x > BoardWidth_75 && monitorDim.y > BoardHeight_75)
    {
        return BoardImage(PacruBoardTransparent_75, BoardWidth_75, BoardHeight_75,
                               BorderlandWidth_75, BorderlandHeight_75,
                               FieldWidth_75, FieldHeight_75, SeparationLine_75);
    }
    // in case only 50% board fits in monitor
    return BoardImage(PacruBoardTransparent_50, BoardWidth_50, BoardHeight_50,
                           BorderlandWidth_50, BorderlandHeight_50,
                           FieldWidth_50, FieldHeight_50, SeparationLine_50);
}
//----------------------------------------------------------------------------------------------------------------------

// gets requested middle point boardPosition and object size,
// return required upper left boardPosition
sf::Vector2f upperLeftPosFromMiddlePos(sf::Vector2f middlePos, sf::Vector2f size)
{
    return sf::Vector2f(middlePos.x - (size.x)/2, middlePos.y - (size.y)/2);
}

//----------------------------------------------------------------------------------------------------------------------

void Game::run()
{
    /*
     * setting a window and the board
     */
    // get monitor dimensions
    sf::Vector2u monitorDim(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
    // create a window
    sf::RenderWindow window(sf::VideoMode(int(monitorDim.x), int(monitorDim.y)), "Pacru");

    // get the fitting board
    BoardImage BD = selectImageBoard(monitorDim);
    // get upper left corner boardPosition
    sf::Vector2f position = upperLeftPosFromMiddlePos(sf::Vector2f(monitorDim.x/2, monitorDim.y/2), BD.BoardDim);
    // create the board
    Board board(window, position, BD);

    std::cout << position.x << " " << position.y << std::endl;

    // run and handle events
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    board.~Board();
                    return;
                default:
                    break;
            }
        }

        window.clear();
        board.draw();
        window.display();
    }
}
//----------------------------------------------------------------------------------------------------------------------