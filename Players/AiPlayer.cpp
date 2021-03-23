//
// Created by alexr on 23/03/2021.
//

#include "string"
#include "AiPlayer.h"
#include "../Helpers/stringhelper.h"
#include "../Helpers/mathshelper.h"
#include "../Settings.h"
#include "../Game.h"
#include <chrono>
#include <thread>

using namespace std;

void AiPlayer::init() {
    auto *playerBoard = new PlayerBoard(this);
    setBoard(playerBoard);
}

void AiPlayer::takeTurn() {
    string col = stringhelper::numberToLetters(mathshelper::generatePickedNumber(Settings::getBoard().getSizeX()));
    int row = mathshelper::generatePickedNumber(Settings::getBoard().getSizeY());
    cout << "I choose to fire at Position: " << col << to_string(row) << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    getGame()->HitOpponent(row, col);
}

PlayerType AiPlayer::type() {
    return Computer;
}

AiPlayer::AiPlayer() : Player() {
    Player::init();
    init();
}
