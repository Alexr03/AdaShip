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
public:
    Player *getPlayer() const;

    void setPlayer(Player* &player);

    void print() const;

    std::string shipIdForCoord(int row, const std::string& col) const;

    Ship shipForCoord(int row, const std::string &col) const;

    bool coordHit(int row, const std::string &col) const;
};

#endif //ADASHIP2_GRID_H
