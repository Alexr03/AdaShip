//
// Created by alexr on 02/03/2021.
//

#ifndef ADASHIP2_GRID_H
#define ADASHIP2_GRID_H

#include <iostream>
#include <iomanip>
#include "Helpers/stringhelper.h"
#include "Settings.h"
#include "Players/Player.h"

class Grid {
    int rows = Settings::getBoard().getSizeX(), cols = Settings::getBoard().getSizeY();
    Player* player;
    Game* game;
public:
    /// Get the player this grid is set to
    /// \return
    Player *getPlayer() const;

    /// Set the player this grid is for
    /// \param player
    void setPlayer(Player* &player);

    /// Print the grid
    void print() const;

    /// Get the ShipId/MineId for the coordinate
    /// \param row Row to check
    /// \param col Col to check
    /// \return " " if empty or the ID of the entity
    std::string shipIdForCoord(int row, const std::string& col) const;

    /// Gets the ship on a coordinate
    /// \param row Row to check
    /// \param col Col to check
    /// \return Ship if present on coordinate or Constants::InvalidShip
    Ship shipForCoord(int row, const std::string &col) const;

    /// Check if a coordinate has been hit on the players hitspot
    /// \param row Row to check
    /// \param col Col to check
    /// \return true if coordinate has been hit
    bool coordHit(int row, const std::string &col) const;

    /// Gets the game the grid is attached to
    /// \return
    Game *getGame() const;

    /// Set the game the grid is attached to
    /// \param game
    void setGame(Game *game);
};

#endif //ADASHIP2_GRID_H
