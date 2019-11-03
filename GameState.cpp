#include <iostream>
#ifdef DEBUG
    #include <iomanip>
    #include <sstream>
#endif

#include "GameState.hpp"

using namespace std;

// ### FieldState ###
FieldState::FieldState()
{
    // Constructor
    coordinate = sf::Vector2u(0, 0);
    chevron = PLAYER_NUMBER::PLAYER_NONE;
    chevronDirection = CHEVRON_DIRECTION::DIRECTION_NONE;
    marker = PLAYER_NUMBER::PLAYER_NONE;
    borderPower = 1;
}

FieldState::~FieldState()
{
    // Destructor...clean up?
}

void FieldState::setCoord(const sf::Vector2u coord)
{
    coordinate = coord;
}

void FieldState::setChevron(const PLAYER_NUMBER player, const CHEVRON_DIRECTION direction)
{
    chevron = player;
    chevronDirection = direction;
}

void FieldState::setMarker(const PLAYER_NUMBER player)
{
    marker = player;
}

void FieldState::setBorderPower(const uint power)
{
    if (power <= 9)
    {
        borderPower = power;
    }
    else
    {
        cout << "Error: Field (" << coordinate.x << "," << coordinate.y << ") set to power " << power << endl;
    }
}

string FieldState::getChevronDirectionAsString()
{
    switch (chevronDirection)
    {
        case CHEVRON_DIRECTION::DIRECTION_N:
            return "_N";
        case CHEVRON_DIRECTION::DIRECTION_NE:
            return "NE";
        case CHEVRON_DIRECTION::DIRECTION_E:
            return "_E";
        case CHEVRON_DIRECTION::DIRECTION_SE:
            return "SE";
        case CHEVRON_DIRECTION::DIRECTION_S:
            return "_S";
        case CHEVRON_DIRECTION::DIRECTION_SW:
            return "SW";
        case CHEVRON_DIRECTION::DIRECTION_W:
            return "_W";
        case CHEVRON_DIRECTION::DIRECTION_NW:
            return "NW";

        case CHEVRON_DIRECTION::DIRECTION_NONE:
        default:    // Deliberate fall-through
            return "??";
    }

    return "??";
}

// ### GameState ###
GameState::GameState()
{
    // Constructor
    isRunning = false;

    // Create initial board
    InitialiseGame();
}

GameState::~GameState()
{
    // Destructor...clean up?
}

void GameState::InitialiseGame()
{
    // Set up board
    for (uint col=0; col < BOARD_SIZE; col++)
    {
        vector<unique_ptr<FieldState>> vecRow;
        for (uint row=0; row < BOARD_SIZE; row++)
        {
            unique_ptr<FieldState> field(new FieldState());
            (*field).setCoord(sf::Vector2u(row, col));
            vecRow.push_back(move(field));
        }

        fields.push_back(move(vecRow));
    }

    // Add initial chevrons

    // Player 1
    (*fields[0][0]).setChevron(PLAYER_NUMBER::PLAYER_1, CHEVRON_DIRECTION::DIRECTION_NE);
    (*fields[6][0]).setChevron(PLAYER_NUMBER::PLAYER_1, CHEVRON_DIRECTION::DIRECTION_E);
    (*fields[8][4]).setChevron(PLAYER_NUMBER::PLAYER_1, CHEVRON_DIRECTION::DIRECTION_S);
    (*fields[6][8]).setChevron(PLAYER_NUMBER::PLAYER_1, CHEVRON_DIRECTION::DIRECTION_W);

    // Player 2
    (*fields[2][0]).setChevron(PLAYER_NUMBER::PLAYER_2, CHEVRON_DIRECTION::DIRECTION_E);
    (*fields[0][4]).setChevron(PLAYER_NUMBER::PLAYER_2, CHEVRON_DIRECTION::DIRECTION_N);
    (*fields[2][8]).setChevron(PLAYER_NUMBER::PLAYER_2, CHEVRON_DIRECTION::DIRECTION_W);
    (*fields[8][8]).setChevron(PLAYER_NUMBER::PLAYER_2, CHEVRON_DIRECTION::DIRECTION_SW);
}

void GameState::dbgDraw()
{
    // Draw the current state of the game
    uint col = 0;
    uint row = BOARD_SIZE_1;
    bool complete = false;
    do
    {
        cout << (*fields[row][col]).getChevronPlayer();
        cout << (*fields[row][col]).getChevronDirectionAsString() << ",";
        cout << (*fields[row][col]).getMarker() << " ";
        if (col == BOARD_SIZE_1)
        {
            cout << endl;
            if (row == 0)
            {
                // Complete!
                complete = true;
            }
            else
            {
                // Next row...
                col = 0;
                row--;
            }
        }
        else
        {
            col++;
        }
    } while (!complete);

    // Final line for Sivan
    cout << endl;
}

void GameState::updateFields()
{
    // Update the state of the fields
}

void GameState::updateBorders()
{
    // Update the state of the borders
}
