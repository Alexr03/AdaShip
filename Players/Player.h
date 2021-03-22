//
// Created by alexr on 02/03/2021.
//

#ifndef ADASHIP2_PLAYER_H
#define ADASHIP2_PLAYER_H


#include <vector>
#include "../Models/Ship.h"
#include "../Models/PlayerBoard.h"
#include "PlayerType.h"

struct Player {
private:
    PlayerBoard* board{};
public:
    Player() {}

    virtual void init();

    void setBoard(PlayerBoard *board);

    PlayerBoard *getBoard() const;

    /// Code to takeTurn for this exercise.
    virtual void takeTurn();

    virtual PlayerType type();
};

#endif //ADASHIP2_PLAYER_H
