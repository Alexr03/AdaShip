//
// Created by alexr on 24/03/2021.
//

#include <iostream>
#include "PlayerBoard.h"

PlayerBoard *Mine::getPlayerBoard() const {
    return playerBoard;
}

void Mine::setPlayerBoard(PlayerBoard *playerBoard) {
    Mine::playerBoard = playerBoard;
}
