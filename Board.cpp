//*****************************************************************************
// 
// 
// sivshani@gmail.com
//*****************************************************************************

#include <SFML/Graphics.hpp>
#include "Board.hpp"

BoardDimensions::BoardDimensions(std::string file, unsigned int BW, unsigned int BH,
                                 unsigned int BLW, unsigned int BLH,
                                 unsigned int FW, unsigned int FH, unsigned int SL)
                                 : fileName(file), BoardWidth(BW), BoardHeight(BH),
                                   BorderlandWidth(BLW), BorderlandHeight(BLH),
                                   FieldWidth(FW), FieldHeight(FH), SeparationLine(SL) {}

PacruBoard::PacruBoard(sf::RenderWindow& window, sf::Vector2f position)
                        : window(window), position(position)
{

}