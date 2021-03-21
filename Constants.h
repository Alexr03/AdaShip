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
};


#endif //ADASHIP2_CONSTANTS_H
