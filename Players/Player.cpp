//
// Created by alexr on 01/03/2021.
//

#include "Player.h"

void Player::takeTurn() {

}

PlayerBoard *Player::getBoard() const {
    return board;
}

PlayerType Player::type() {
    return Generic;
}

void Player::setBoard(PlayerBoard *board) {
    Player::board = board;
}

void Player::init() {
    // Do init here.
}
