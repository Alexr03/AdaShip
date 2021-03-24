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
    /// Get SizeX of the board
    /// \return SizeX
    int getSizeX() const;

    /// Set SizeX of the board
    void setSizeX(int sizeX);

    /// Get SizeY of the board
    /// \return SizeY
    int getSizeY() const;

    /// Set SizeY of the board
    void setSizeY(int sizeY);
};


#endif //ADASHIP2_BOARD_H
