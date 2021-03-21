//
// Created by alexr on 02/03/2021.
//

#ifndef ADASHIP2_PLAYER_H
#define ADASHIP2_PLAYER_H


#include <vector>
#include "../Models/Ship.h"
#include "../Models/PlayerBoard.h"

struct Player {
private:
    PlayerBoard* board{};
public:
    Player() {
        auto *playerBoard = new PlayerBoard;
        board = playerBoard;
    }

    PlayerBoard *getBoard() const;

    void setBoard(PlayerBoard *board);

    /// Code to takeTurn for this exercise.
    virtual void takeTurn();
};

#endif //ADASHIP2_PLAYER_H
