//
// Created by alexr on 01/03/2021.
//

#include "Board.h"

int Board::getSizeX() const {
    return sizeX;
}

void Board::setSizeX(int sizeX) {
    Board::sizeX = sizeX;
}

int Board::getSizeY() const {
    return sizeY;
}

void Board::setSizeY(int sizeY) {
    Board::sizeY = sizeY;
}
