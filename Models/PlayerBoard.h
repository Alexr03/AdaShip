//
// Created by alexr on 02/03/2021.
//

#ifndef ADASHIP2_PLAYERBOARD_H
#define ADASHIP2_PLAYERBOARD_H

#include "Board.h"
#include "Coord.h"

class Player;
class PlayerBoard : public Board {
private:
    Player *player{};
    std::vector<Ship> ships{};
    std::vector<Coord> hitSpots;

public:
    explicit PlayerBoard(Player *player1);

    const std::vector<Ship> & getShips() const;

    const std::vector<Coord> &getHitSpots() const;

    void hitSpot(int row, std::string col);

    bool isHitSpot(int row, std::string col);

    bool isShipOverlapping(const Ship& ship);
};

#endif //ADASHIP2_PLAYERBOARD_H
