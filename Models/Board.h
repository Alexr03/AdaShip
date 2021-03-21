//
// Created by alexr on 01/03/2021.
//

#ifndef ADASHIP2_BOARD_H
#define ADASHIP2_BOARD_H


#include <vector>
#include "Ship.h"

class Board {
private:
    int sizeX = 10;
    int sizeY = 10;
public:
    int getSizeX() const;
    void setSizeX(int sizeX);
    int getSizeY() const;
    void setSizeY(int sizeY);
};


#endif //ADASHIP2_BOARD_H
