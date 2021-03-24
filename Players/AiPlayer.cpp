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
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    getGame()->HitOpponent(row, col);

    iohelper::getInput("Press any key to end computers turn");
}

PlayerType AiPlayer::type() {
    return Computer;
}

AiPlayer::AiPlayer() : Player() {
    Player::init();
    init();
}
