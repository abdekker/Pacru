//*****************************************************************************
// 
// 
// sivshani@gmail.com
//*****************************************************************************

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.hpp"

BoardImage::BoardImage() {}

BoardImage::BoardImage(std::string file, unsigned int BW, unsigned int BH,
                                 unsigned int BLW, unsigned int BLH,
                                 unsigned int FW, unsigned int FH, unsigned int SL)
                                 : fileName(file), BoardWidth(BW), BoardHeight(BH),
                                   BorderlandWidth(BLW), BorderlandHeight(BLH),
                                   FieldWidth(FW), FieldHeight(FH), SeparationLine(SL),
                                   BoardDim(BW, BH), BorderlandDim(BLW, BLH), FieldDim(FH, FH){}
//----------------------------------------------------------------------------------------------------------------------

Board::Board(sf::RenderWindow& window, sf::Vector2f boardPosition, BoardImage BD)
            : window(window), boardPosition(boardPosition), boardImage(BD)
{
    if(!boardTexture.loadFromFile(boardImage.fileName))
    {
        std::cout << "Error, could not load " << boardImage.fileName << std::endl;
    }
    boardSprite.setTexture(boardTexture);
    boardSprite.setPosition(boardPosition);
}

Board::~Board() {}
//----------------------------------------------------------------------------------------------------------------------

void Board::draw()
{
    window.draw(boardSprite);
}
//----------------------------------------------------------------------------------------------------------------------