//
// Created by alexr on 01/03/2021.
//

#include "Player.h"
#include "../Helpers/iohelper.h"
#include "../Game.h"

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

Game *Player::getGame() const {
    return game;
}

void Player::setGame(Game *game) {
    Player::game = game;
}

bool Player::isSalvoMode() const {
    return salvoMode;
}

void Player::setSalvoMode(bool salvoMode) {
    Player::salvoMode = salvoMode;
}
