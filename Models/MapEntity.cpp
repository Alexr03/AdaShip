//
// Created by alexr on 22/03/2021.
//

#include "MapEntity.h"

const std::vector<Coord> &MapEntity::getCoordinates() const {
    return coordinates;
}

void MapEntity::setCoordinates(const std::vector<Coord> &coordinates) {
    MapEntity::coordinates = coordinates;
}
