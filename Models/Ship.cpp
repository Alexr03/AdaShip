//
// Created by alexr on 01/03/2021.
//

#include "Ship.h"
#include "../Helpers/mathshelper.h"
#include "../Helpers/stringhelper.h"
#include "../Settings.h"

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
    return destroyed;
}

const std::vector<std::string> &Ship::getCoordinates() const {
    return coordinates;
}

void Ship::setCoordinates(const std::vector<std::string> &coords) {
    Ship::coordinates = coords;
}

Ship::Ship(int id) : id(stringhelper::numberToLetters(id)) {}

const string &Ship::getId() const {
    return id;
}
