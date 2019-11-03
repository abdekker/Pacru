//*****************************************************************************
//
//
// sivshani@gmail.com
//*****************************************************************************

#include <iostream>

#include "Game.hpp"
#include "GameState.hpp"
#include "globals.hpp"

void Game::initSystem()
{
    // Get monitor dimensions
    #ifdef DEBUG
        screenDimensions = sf::Vector2u(50, 50);
    #else
        screenDimensions = sf::Vector2u(
            sf::VideoMode::getDesktopMode().width,
            sf::VideoMode::getDesktopMode().height);
    #endif
}

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
/*
 * Note: this methid results in insufficient board position, hence setting static position for now
 */
sf::Vector2f upperLeftPosFromMiddlePos(sf::Vector2f middlePos, sf::Vector2f size)
{
    return sf::Vector2f(middlePos.x - (size.x)/2, middlePos.y - (size.y)/2);
}

//----------------------------------------------------------------------------------------------------------------------

Game::Game()
{
    // Constructor

    // Initialise the game
    doQuit = false;
    redrawCount = 0;
    initSystem();
}

Game::~Game()
{
    // Destructor...clean up?
}

void Game::run()
{
    // Create a window
    sf::RenderWindow window(
        // Video mode: Width, height and depth
        sf::VideoMode(screenDimensions.x, screenDimensions.y),
        "Pacru",                                    // Title
        sf::Style::Titlebar | sf::Style::Close);    // Window style (note "Fullscreen" removes title bar)

    // Get the fitting board
    BoardImage imgBoard = selectImageBoard(screenDimensions);

    // get upper left corner boardPosition
    // sf::Vector2f position = upperLeftPosFromMiddlePos(sf::Vector2f(monitorDim.x/2, monitorDim.y/2), BD.BoardDim);
    sf::Vector2f position(25.0f, 15.0f);
    // create the board
    Board board(window, position, imgBoard);
    board.setScreenDimensions(screenDimensions);

    GameState gameState;

    // Diagnostics
    std::cout << "Board X = " << position.x << " Board Y = " << position.y << std::endl;

    // run and handle events
    while (window.isOpen() && !doQuit)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    board.~Board();
                    return;

                case sf::Event::KeyPressed:
                    // A key has been pressed!
                    keyDisplayCountDown = 1000;
                    if (event.key.code == sf::Keyboard::Q)
                    {
                        // We should quit!
                        doQuit = true;
                    }
                    else if (event.key.code == sf::Keyboard::S)
                    {
                        // Start/stop game
                        gameState.setRunning(!gameState.getRunning());
                    }
                    else if (event.key.code == sf::Keyboard::D)
                    {
                        // Start/stop game
                        gameState.dbgDraw();
                    }
                    break;

                default:
                    break;
            }
        }

        //board.updatePosition(1,-2);
        redrawCount++;
        //window.clear();
        //board.draw(&gameState);
        window.display();
    }
}
//----------------------------------------------------------------------------------------------------------------------
