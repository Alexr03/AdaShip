//
// Created by alexr on 02/03/2021.
//

#ifndef ADASHIP2_PLAYERBOARD_H
#define ADASHIP2_PLAYERBOARD_H

#include "Board.h"

class PlayerBoard : public Board {
private:
    std::vector<Ship> ships{};

public:
    PlayerBoard();

    const std::vector<Ship> & getShips() const;
};

#endif //ADASHIP2_PLAYERBOARD_H
