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
    string col;
    int row;
    bool validCoord = false;
    while(!validCoord){
        col = "";
        auto coord = iohelper::getInput("Enter a coordinate (e.g. F2 or auto)", "");
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

        validCoord = !getGame()->getOpponentPlayer()->getBoard()->isHitSpot(row, col);
        if(!validCoord){
            cout << "That is an invalid/already hit coordinate" << endl;
        }
    }
    getGame()->HitOpponent(row, col);
}

RealPlayer::RealPlayer() : Player() {
    Player::init();
    init();
}

PlayerType RealPlayer::type() {
    return Real;
}
