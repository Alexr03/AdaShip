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
        if (std::find(coordinates.begin(), coordinates.end(), hitSpot.getCol()) != coordinates.end()) {
            if(std::find(coordinates.begin(), coordinates.end(), std::to_string(hitSpot.getRow())) != coordinates.end()){
                //            Logger::Debug("Found hitspot @ " + std::to_string(hitSpot.getRow()) + " | " + hitSpot.getCol());
                hit++;
            }
        }
    }
//    Logger::Debug(std::to_string(hit == getLength()));
    return hit == getLength();
}

const std::vector<std::string> &Ship::getCoordinates() const {
    return coordinates;
}

void Ship::setCoordinates(const std::vector<std::string> &coords) {
    Ship::coordinates = coords;
}

Ship::Ship(int id) : id(stringhelper::numberToLetters(id)) {}

const std::string &Ship::getId() const {
    return id;
}

PlayerBoard *Ship::getPlayerBoard() const {
    return playerBoard;
}

void Ship::setPlayerBoard(PlayerBoard *playerBoard) {
    Ship::playerBoard = playerBoard;
}
