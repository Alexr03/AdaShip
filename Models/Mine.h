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
    Mine(int id) : MapEntity(stringhelper::numberToLetters(id)) {}

    void hit();

    PlayerBoard *getPlayerBoard() const;

    void setPlayerBoard(PlayerBoard *playerBoard);
};


#endif //ADASHIP2_MINE_H
