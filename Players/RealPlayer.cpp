//
// Created by alexr on 01/03/2021.
//

#include <iostream>
#include "RealPlayer.h"

void RealPlayer::init() {
    auto *playerBoard = new PlayerBoard(this);
    setBoard(playerBoard);
}

void RealPlayer::takeTurn() {
    Player::takeTurn();
}

RealPlayer::RealPlayer() : Player() {
    Player::init();
    init();
}

PlayerType RealPlayer::type() {
    return Real;
}
