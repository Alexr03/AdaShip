//
// Created by alexr on 01/03/2021.
//

#include "Ship.h"
#include "../Helpers/stringhelper.h"
#include "../Settings.h"
#include "../Models/PlayerBoard.h"
#include <algorithm>

bool Ship::isInvalid() {
    return Ship::name == "invalid";
}

const std::string &Ship::getName() const {
    return name;
}

void Ship::setName(const std::string &name) {
    Ship::name = name;
}

int Ship::getLength() const {
    return length;
}

void Ship::setLength(int length) {
    Ship::length = length;
}

bool Ship::isDestroyed() const {
    auto hitSpots = playerBoard->getHitSpots();
    int hit = 0;
    for (const auto &hitSpot : hitSpots) {
        for (const auto &coord : getCoordinates()){
            if(hitSpot.getCol() == coord.getCol() && hitSpot.getRow() == coord.getRow()){
                hit++;
            }
        }
    }
    return hit == getLength();
}

Ship::Ship(int id) : MapEntity(stringhelper::numberToLetters(id)) {}

PlayerBoard *Ship::getPlayerBoard() const {
    return playerBoard;
}

void Ship::setPlayerBoard(PlayerBoard *playerBoard) {
    Ship::playerBoard = playerBoard;
}