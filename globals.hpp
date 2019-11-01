//*****************************************************************************
// Globals
// 
// sivshani@gmail.com
//*****************************************************************************

#ifndef PACRU_GLOBALS_HPP
#define PACRU_GLOBALS_HPP

enum GAME_TYPE
{
    PACRU,
    AZACRU,
    SHACRU
};

enum NUMBER_OF_PLAYERS
{
    TWO_PLAYERS = 2,
    THREE_PLAYERS,
    FOUR_PLAYERS
};

/*
 * Board
 * three sizes: 100%, 75% and 50%
 * all measurments are in pixels
 */

enum BOARD_SIZE
{
    _100_PC,
    _75_PC,
    _50_PC
};

// size 100%
std::string PacruBoardTransparent_100 = "../resources/PacruBoardTransparent_100.png";

const unsigned int BoardWidth_100 = 753;
const unsigned int BoardHeight_100 = 753;
const unsigned int BorderlandWidth_100 = 248;
const unsigned int BorderlandHeight_100 = 248;
const unsigned int FieldWidth_100 = 50;
const unsigned int FieldHeight_100 = 50;
const unsigned int SeparationLine_100 = 3;

// size 75%
std::string PacruBoardTransparent_75 = "../resources/PacruBoardTransparent_75.png";

const unsigned int BoardWidth_75 = 565;
const unsigned int BoardHeight_75 = 565;
const unsigned int BorderlandWidth_75 = 188;
const unsigned int BorderlandHeight_75 = 188;
const unsigned int FieldWidth_75 = 37;
const unsigned int FieldHeight_75 = 37;
const unsigned int SeparationLine_75 = 2;

// size 50%
std::string PacruBoardTransparent_50 = "../resources/PacruBoardTransparent_50.png";

const unsigned int BoardWidth_50 = 377;
const unsigned int BoardHeight_50 = 377;
const unsigned int BorderlandWidth_50 = 124;
const unsigned int BorderlandHeight_50 = 124;
const unsigned int FieldWidth_50 = 24;
const unsigned int FieldHeight_50 = 24;
const unsigned int SeparationLine_50 = 2;

#endif //PACRU_GLOBALS_HPP
