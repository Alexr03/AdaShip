//
// Created by alexr on 22/03/2021.
//

#ifndef ADASHIP2_MAPENTITY_H
#define ADASHIP2_MAPENTITY_H


#include <vector>
#include "Coord.h"

class MapEntity {
private:
    std::vector<Coord> coordinates;
public:
    const std::vector<Coord> &getCoordinates() const;

    void setCoordinates(const std::vector<Coord> &coordinates);
};


#endif //ADASHIP2_MAPENTITY_H
