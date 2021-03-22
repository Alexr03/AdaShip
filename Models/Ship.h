//
// Created by alexr on 01/03/2021.
//

#ifndef ADASHIP2_SHIP_H
#define ADASHIP2_SHIP_H


#include <string>
#include <list>
#include <vector>
#include "Coord.h"
#include "MapEntity.h"

class PlayerBoard;
class Ship : public MapEntity {

private:
    std::string id;
    std::string name;
    int length{};
    PlayerBoard *playerBoard;
public:
    explicit Ship(int id);

    const std::string &getId() const;

    bool isInvalid();

    const std::string &getName() const;

    void setName(const std::string &name);

    int getLength() const;

    void setLength(int length);

    bool isDestroyed() const;

    PlayerBoard *getPlayerBoard() const;

    void setPlayerBoard(PlayerBoard *playerBoard);
};


#endif //ADASHIP2_SHIP_H
