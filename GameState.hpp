#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

#include "globals.hpp"

using namespace std;
class FieldState
{
    public:
        FieldState();
        ~FieldState();

        void setCoord(const sf::Vector2u coord);
        //void setChevron(CHEVRON* )
        void setChevron(const PLAYER_NUMBER player, const CHEVRON_DIRECTION direction);
        void setMarker(const PLAYER_NUMBER player);
        void setBorderPower(const uint power);

        sf::Vector2u getCoord() { return coordinate; }
        PLAYER_NUMBER getChevronPlayer() { return chevron; }
        CHEVRON_DIRECTION getChevronDirection() { return chevronDirection; }
        string getChevronDirectionAsString();
        PLAYER_NUMBER getMarker() { return marker; }
        uint getBorderPower() { return borderPower; }

    private:
        sf::Vector2u coordinate;
        PLAYER_NUMBER chevron;
        CHEVRON_DIRECTION chevronDirection;
        PLAYER_NUMBER marker;
        uint borderPower;
};

class GameState
{
    public:
        GameState();
        ~GameState();
        void InitialiseGame();

        void setRunning(const bool gameStarted) { isRunning = gameStarted; }
        bool getRunning() { return isRunning; }
        //vector<vector<unique_ptr<FieldState>>> getFields() { return fields; }

        // Debug functions
        void dbgDraw();

    private:
        bool isRunning;
        vector<vector<unique_ptr<FieldState>>> fields;

        void updateFields();
        void updateBorders();
};
