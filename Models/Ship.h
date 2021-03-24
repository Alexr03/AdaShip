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
    std::string name;
    int length{};
    PlayerBoard *playerBoard{};
public:
    /// Initialize ship with integer ID then convert to excel-like column ID.
    /// \param id
    explicit Ship(int id);

    /// If the current ship is invalid
    /// \return True if invalid
    bool isInvalid();

    /// Get name of ship
    /// \return
    const std::string &getName() const;

    /// Set name of ship
    /// \param name
    void setName(const std::string &name);

    /// Get length of ship
    /// \return
    int getLength() const;

    /// Set length of ship
    /// \param length
    void setLength(int length);

    /// Determines if the ship is destroyed by checking hit spots on the playerboard
    /// \return
    bool isDestroyed() const;

    /// Get player board this ship is attached to
    /// \return
    PlayerBoard *getPlayerBoard() const;

    /// Set playerboard this ship is attached to
    /// \param playerBoard
    void setPlayerBoard(PlayerBoard *playerBoard);
};


#endif //ADASHIP2_SHIP_H
