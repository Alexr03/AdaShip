//
// Created by alexr on 21/03/2021.
//

#ifndef ADASHIP2_CONSTANTS_H
#define ADASHIP2_CONSTANTS_H

#include "Models/Ship.h"

class Constants {
public:
    static Ship GetInvalidShip(){
        Ship ship(999);
        ship.setName("invalid");
        return ship;
    }

    static Mine GetInvalidMine(){
        Mine mine(10000);
        mine.setId("invalid");
        return mine;
    }
};


#endif //ADASHIP2_CONSTANTS_H
