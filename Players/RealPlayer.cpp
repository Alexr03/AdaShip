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
    if(isSalvoMode()){
        for(auto &ship : getBoard()->getShips()){
            if(ship.isDestroyed()) continue;

            cout << "[Salvo mode] You are shooting from ship: " << ship.getName() << endl;
            shoot();
        }
    } else{
        shoot();
    }
}

void RealPlayer::shoot() const {
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
            transform(col.begin(), col.end(), col.begin(), toupper);
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
    auto opponent = getGame()->getOpponentPlayer();
    for(const Mine& mine : opponent->getBoard()->getMines()){
        if(opponent->getBoard()->isHitSpot(mine.getCoordinates().front().getRow(), mine.getCoordinates().front().getCol())){
            auto baseCoord = mine.getCoordinates().front();
            getGame()->HitOpponent(baseCoord.getRow(), stringhelper::numberToLetters(stringhelper::lettersToNumber(baseCoord.getCol()) - 1));
            getGame()->HitOpponent(baseCoord.getRow(), stringhelper::numberToLetters(stringhelper::lettersToNumber(baseCoord.getCol()) + 1));
            getGame()->HitOpponent(baseCoord.getRow() - 1, stringhelper::numberToLetters(stringhelper::lettersToNumber(baseCoord.getCol())));
            getGame()->HitOpponent(baseCoord.getRow() + 1, stringhelper::numberToLetters(stringhelper::lettersToNumber(baseCoord.getCol())));
        }
    }
}

RealPlayer::RealPlayer() : Player() {
    Player::init();
    init();
}

PlayerType RealPlayer::type() {
    return Real;
}
