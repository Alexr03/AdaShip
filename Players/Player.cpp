//
// Created by alexr on 01/03/2021.
//

#include "Player.h"
#include "../Settings.h"

void Player::takeTurn() {

}

PlayerBoard *Player::getBoard() const {
    return board;
}

void Player::setBoard(PlayerBoard *board) {
    Player::board = board;
}


