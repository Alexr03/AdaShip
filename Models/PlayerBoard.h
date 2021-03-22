//
// Created by alexr on 02/03/2021.
//

#ifndef ADASHIP2_PLAYERBOARD_H
#define ADASHIP2_PLAYERBOARD_H

#include "Board.h"

class Player;
class PlayerBoard : public Board {
private:
    Player *player{};
    std::vector<Ship> ships{};

public:
    explicit PlayerBoard(Player *player1);

    const std::vector<Ship> & getShips() const;
};

#endif //ADASHIP2_PLAYERBOARD_H
