//
// Created by alexr on 01/03/2021.
//

#include <iostream>
#include "RealPlayer.h"
#include "../Helpers/iohelper.h"
#include "../Game.h"
#include "../Helpers/mathshelper.h"

void RealPlayer::init() {
    auto *playerBoard = new PlayerBoard(this);
    setBoard(playerBoard);
}

void RealPlayer::takeTurn() {
    auto coord = iohelper::getInput("Enter a coordinate (e.g. F2 or auto)", "");
    string col;
    int row;
    if (coord != "auto") {
        for (char &c : coord) {
            if (isalpha(c)) {
                col += c;
            }
        }
        std::transform(col.begin(), col.end(), col.begin(), ::toupper);
        row = stoi(coord.substr(col.size(), coord.size()));
    } else {
        col = stringhelper::numberToLetters(mathshelper::generatePickedNumber(Settings::getBoard().getSizeX()));
        row = mathshelper::generatePickedNumber(Settings::getBoard().getSizeY());
    }

    getGame()->HitOpponent(row, col);

//    if(row > Settings::getBoard().getSizeX()){
//
//    }
}

RealPlayer::RealPlayer() : Player() {
    Player::init();
    init();
}

PlayerType RealPlayer::type() {
    return Real;
}
