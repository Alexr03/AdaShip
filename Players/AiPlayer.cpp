//
// Created by alexr on 23/03/2021.
//

#include "string"
#include "AiPlayer.h"
#include "../Helpers/stringhelper.h"
#include "../Helpers/mathshelper.h"
#include "../Settings.h"
#include "../Game.h"
#include "../Helpers/iohelper.h"
#include <chrono>
#include <thread>

using namespace std;

void AiPlayer::init() {
    auto *playerBoard = new PlayerBoard(this);
    setBoard(playerBoard);
}

void AiPlayer::takeTurn() {
    if(isSalvoMode()){
        cout << "[Salvo mode] Grid of the hit ships will show after you fired all missiles.";
        for(auto &ship : getBoard()->getShips()){
            if(ship.isDestroyed()) continue;

            cout << "[Salvo mode] You are shooting from ship: " << ship.getName() << endl;
            shoot();
        }
    } else{
        shoot();
    }

    iohelper::getInput("Press any key to end computers turn");
}

void AiPlayer::shoot() const {
    bool validCoord = false;
    string col;
    int row;
    while(!validCoord){
        col = stringhelper::numberToLetters(mathshelper::generatePickedNumber(Settings::getBoard().getSizeX()));
        row = mathshelper::generatePickedNumber(Settings::getBoard().getSizeY());
        cout << "I choose to fire at Position: " << col << to_string(row) << endl;
        validCoord = !getGame()->getOpponentPlayer()->getBoard()->isHitSpot(row, col);
        if(!validCoord){
            cout << "That is an invalid/already hit coordinate" << endl;
        }
    }
//    this_thread::sleep_for(chrono::milliseconds(1000));
    getGame()->HitOpponent(row, col);
    auto opponent = getGame()->getOpponentPlayer();
    for(const Mine& mine : opponent->getBoard()->getMines()){
        if(opponent->getBoard()->isHitSpot(mine.getCoordinates().front().getRow(), mine.getCoordinates().front().getCol())){
            auto baseCoord = mine.getCoordinates().front();
            getGame()->HitOpponent(baseCoord.getRow(), stringhelper::numberToLetters(stringhelper::lettersToNumber(baseCoord.getCol()) - 1));
            getGame()->HitOpponent(baseCoord.getRow(), stringhelper::numberToLetters(stringhelper::lettersToNumber(baseCoord.getCol()) + 1));
            getGame()->HitOpponent(baseCoord.getRow() - 1, stringhelper::numberToLetters(stringhelper::lettersToNumber(baseCoord.getCol())));
            getGame()->HitOpponent(baseCoord.getRow() + 1, stringhelper::numberToLetters(stringhelper::lettersToNumber(baseCoord.getCol())));
            getGame()->HitOpponent(baseCoord.getRow() - 1, stringhelper::numberToLetters(stringhelper::lettersToNumber(baseCoord.getCol()) - 1));
            getGame()->HitOpponent(baseCoord.getRow() + 1, stringhelper::numberToLetters(stringhelper::lettersToNumber(baseCoord.getCol()) + 1));
            getGame()->HitOpponent(baseCoord.getRow() - 1, stringhelper::numberToLetters(stringhelper::lettersToNumber(baseCoord.getCol()) + 1));
            getGame()->HitOpponent(baseCoord.getRow() + 1, stringhelper::numberToLetters(stringhelper::lettersToNumber(baseCoord.getCol()) - 1));
        }
    }
}

PlayerType AiPlayer::type() {
    return Computer;
}

AiPlayer::AiPlayer() : Player() {
    Player::init();
    init();
}

AiPlayer::AiPlayer(bool bombMode) : Player() {
    setBombsMode(bombMode);
    Player::init();
    init();
}