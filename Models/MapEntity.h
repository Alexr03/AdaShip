//
// Created by alexr on 22/03/2021.
//

#ifndef ADASHIP2_MAPENTITY_H
#define ADASHIP2_MAPENTITY_H


#include <vector>
#include "Coord.h"

class MapEntity {
private:
    std::string id;
    std::vector<Coord> coordinates;
public:
    MapEntity();

    MapEntity(std::string id);

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::vector<Coord> &getCoordinates() const;

    void setCoordinates(const std::vector<Coord> &coordinates);
};


#endif //ADASHIP2_MAPENTITY_H
