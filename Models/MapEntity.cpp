//
// Created by alexr on 22/03/2021.
//

#include "MapEntity.h"

#include <utility>

const std::vector<Coord> &MapEntity::getCoordinates() const {
    return coordinates;
}

void MapEntity::setCoordinates(const std::vector<Coord> &coordinates) {
    MapEntity::coordinates = coordinates;
}

const std::string &MapEntity::getId() const {
    return id;
}

void MapEntity::setId(const std::string &id) {
    MapEntity::id = id;
}

MapEntity::MapEntity(std::string id) : id(std::move(id)) {}

MapEntity::MapEntity() {}
