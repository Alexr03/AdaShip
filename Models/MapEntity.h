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
    /// Initialize entity without an ID
    MapEntity();

    /// Initialize entity with an ID
    /// \param id
    MapEntity(std::string id);

    /// Get ID
    /// \return ID
    const std::string &getId() const;

    /// Set ID
    /// \param id ID to set
    void setId(const std::string &id);

    /// Get Coordinates
    /// \return Coordinates
    const std::vector<Coord> &getCoordinates() const;

    /// Set Coordinates
    /// \param coordinates Coordinates
    void setCoordinates(const std::vector<Coord> &coordinates);
};


#endif //ADASHIP2_MAPENTITY_H
