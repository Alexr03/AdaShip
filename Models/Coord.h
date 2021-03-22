//
// Created by alexr on 22/03/2021.
//

#ifndef ADASHIP2_COORD_H
#define ADASHIP2_COORD_H

#include "string"

class Coord {
private:
    int row;
    std::string col;
public:
    Coord(int row, const std::string &col) : row(row), col(col) {}

    int getRow() const {
        return row;
    }

    const std::string &getCol() const {
        return col;
    }
};


#endif //ADASHIP2_COORD_H
