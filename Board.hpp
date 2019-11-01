//*****************************************************************************
// Pacru Board
// 
// sivshani@gmail.com
//*****************************************************************************

#ifndef PACRU_BOARD_HPP
#define PACRU_BOARD_HPP

#include <SFML/Graphics.hpp>
#include "globals.hpp"

struct BoardDimensions
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

    BoardDimensions(std::string file, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};

class PacruBoard
{
public:
    PacruBoard(sf::RenderWindow& window, sf::Vector2f position);
    ~PacruBoard();

    void draw();

private:

    sf::RenderWindow& window;
    sf::Vector2f position;

    sf::Texture* boardImage;
};

#endif //PACRU_BOARD_HPP
