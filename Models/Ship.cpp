//
// Created by alexr on 01/03/2021.
//

#include "Ship.h"
#include "../Helpers/stringhelper.h"
#include "../Settings.h"
#include "../Models/PlayerBoard.h"

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
    for (const auto &coord : getCoordinates()){
        for (const auto &hitSpot : hitSpots) {
            if(hitSpot.getCol() == coord.getCol() && hitSpot.getRow() == coord.getRow()){
                ++hit;
            }
        }
    }
//    std::cout << getName() << ":" << std::to_string(hit) << "-" << std::to_string(getLength()) << std::endl;
    return hit >= getLength();
}

Ship::Ship(int id) : MapEntity(stringhelper::numberToLetters(id)) {}

PlayerBoard *Ship::getPlayerBoard() const {
    return playerBoard;
}

void Ship::setPlayerBoard(PlayerBoard *playerBoard) {
    Ship::playerBoard = playerBoard;
}