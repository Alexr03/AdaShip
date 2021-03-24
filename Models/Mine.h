//
// Created by alexr on 24/03/2021.
//

#ifndef ADASHIP2_MINE_H
#define ADASHIP2_MINE_H


#include "MapEntity.h"
#include "../Helpers/stringhelper.h"

class PlayerBoard;
class Mine : public MapEntity {
private:
    bool exploded = false;
    PlayerBoard *playerBoard;

public:
    /// Initialize mine with integer ID and convert to excel-like column ID
    /// \param id
    Mine(int id) : MapEntity(stringhelper::numberToLetters(id)) {}

    /// Get Player board this mine is on.
    /// \return
    PlayerBoard *getPlayerBoard() const;

    /// Set playerboard this mine is on
    /// \param playerBoard
    void setPlayerBoard(PlayerBoard *playerBoard);
};


#endif //ADASHIP2_MINE_H
