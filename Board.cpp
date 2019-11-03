//*****************************************************************************
//
//
// sivshani@gmail.com
//*****************************************************************************

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.hpp"

BoardImage::BoardImage() {}

BoardImage::BoardImage(std::string file, unsigned int BW, unsigned int BH,
                                 unsigned int BLW, unsigned int BLH,
                                 unsigned int FW, unsigned int FH, unsigned int SL)
                                 : fileName(file), BoardWidth(BW), BoardHeight(BH),
                                   BorderlandWidth(BLW), BorderlandHeight(BLH),
                                   FieldWidth(FW), FieldHeight(FH), SeparationLine(SL),
                                   BoardDim(BW, BH), BorderlandDim(BLW, BLH), FieldDim(FH, FH)
{
}
//----------------------------------------------------------------------------------------------------------------------

Board::Board(sf::RenderWindow& window, sf::Vector2f boardPosition, BoardImage BD)
            : window(window), boardPosition(boardPosition), boardImage(BD)
{
    if (!boardTexture.loadFromFile(boardImage.fileName))
    {
        std::cout << "Error, could not load " << boardImage.fileName << std::endl;
    }

    boardSprite.setTexture(boardTexture);
    boardSprite.setPosition(boardPosition);
}

void Board::updatePosition(int xDelta, int yDelta)
{
    drawCount = 0;
    boardPosition.x += xDelta;
    boardPosition.y += yDelta;
    boardSprite.setPosition(boardPosition);
}

Board::~Board() {}
//----------------------------------------------------------------------------------------------------------------------

void Board::draw()
{
    window.draw(boardSprite);

    // Try draw some text
    drawCount++;
    outputText.clear();
    sf::Font myFont;
    myFont.loadFromFile(FontCourier);
    sf::Text txt1("hello Sivan", myFont, FontSize);
    txt1.setFillColor(sf::Color::White);
    txt1.setPosition(25, 0);
    outputText.push_back(txt1);

    sf::Text txt2("Pacru!", myFont, FontSize);
    txt2.setFillColor(sf::Color::Red);
    txt2.setPosition(250, 10);
    outputText.push_back(txt2);
    window.draw(outputText[0]);
    window.draw(outputText[1]);
}

void Board::draw(GameState* pState)
{
    window.draw(boardSprite);

    //vector<vector<unique_ptr<FieldState>>> localFields = pState->getFields();

    // Try draw some text
    drawCount++;
    outputText.clear();
    sf::Font myFont;
    myFont.loadFromFile(FontCourier);
    sf::Text txt1(
        pState->getRunning() ? "Running!" : "Stopped...", myFont, FontSize);

    txt1.setFillColor(sf::Color::Yellow);
    txt1.setPosition(25, 0);
    outputText.push_back(txt1);

    sf::Text txt2("Pacru!!", myFont, FontSize);
    txt2.setFillColor(sf::Color::Blue);
    txt2.setPosition(250, 10);
    outputText.push_back(txt2);
    window.draw(outputText[0]);
    window.draw(outputText[1]);
}
//----------------------------------------------------------------------------------------------------------------------
