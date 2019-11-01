//*****************************************************************************
// Pacru Board
// 
// sivshani@gmail.com
//*****************************************************************************

#ifndef PACRU_BOARD_HPP
#define PACRU_BOARD_HPP

#include <SFML/Graphics.hpp>
#include "globals.hpp"

//
struct BoardImage
{
public:
    std::string fileName;
    unsigned int BoardWidth;
    unsigned int BoardHeight;
    unsigned int BorderlandWidth;
    unsigned int BorderlandHeight;
    unsigned int FieldWidth;
    unsigned int FieldHeight;
    unsigned int SeparationLine;

    sf::Vector2f BoardDim;
    sf::Vector2f BorderlandDim;
    sf::Vector2f FieldDim;

    BoardImage();
    BoardImage(std::string file, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};

class Board
{
public:
    Board(sf::RenderWindow& window, sf::Vector2f boardPosition , BoardImage BD);
    ~Board();

    void draw();

private:

    sf::RenderWindow& window;
    sf::Vector2f boardPosition;
    BoardImage boardImage;
    sf::Texture boardTexture;
    sf::Sprite boardSprite;
};

#endif //PACRU_BOARD_HPP
