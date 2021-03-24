//
// Created by alexr on 21/03/2021.
//

#ifndef ADASHIP2_CONSTANTS_H
#define ADASHIP2_CONSTANTS_H

#include "Models/Ship.h"

class Constants {
public:
    /// Creates an instance of an invalid ship, that we can test against if a coordinate returns a invalid ship
    /// \return
    static Ship GetInvalidShip(){
        Ship ship(999);
        ship.setName("invalid");
        return ship;
    }

    /// Creates an instance of an invalid mine, that we can test against if a coordinate returns a invalid mine
    static Mine GetInvalidMine(){
        Mine mine(10000);
        mine.setId("invalid");
        return mine;
    }
};


#endif //ADASHIP2_CONSTANTS_H
