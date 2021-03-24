//
// Created by alexr on 24/03/2021.
//

#include <iostream>
#include "PlayerBoard.h"

PlayerBoard *Mine::getPlayerBoard() const {
    return playerBoard;
}

void Mine::setPlayerBoard(PlayerBoard *playerBoard) {
    Mine::playerBoard = playerBoard;
}

void Mine::hit() {
    if(!exploded){
        exploded = true;
        auto baseCoord = getCoordinates().front();
        playerBoard->hitSpot(baseCoord.getRow(), stringhelper::numberToLetters(stringhelper::lettersToNumber(baseCoord.getCol()) - 1));
        playerBoard->hitSpot(baseCoord.getRow(), stringhelper::numberToLetters(stringhelper::lettersToNumber(baseCoord.getCol()) + 1));
        playerBoard->hitSpot(baseCoord.getRow() - 1, stringhelper::numberToLetters(stringhelper::lettersToNumber(baseCoord.getCol())));
        playerBoard->hitSpot(baseCoord.getRow() + 1, stringhelper::numberToLetters(stringhelper::lettersToNumber(baseCoord.getCol())));
    }
}
