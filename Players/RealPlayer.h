//
// Created by alexr on 01/03/2021.
//

#ifndef ADASHIP2_REALPLAYER_H
#define ADASHIP2_REALPLAYER_H


#include "Player.h"

class RealPlayer : public Player {
public:
    RealPlayer();

    PlayerType type() override;

    void init() override;

private:
    void takeTurn() override;
};


#endif //ADASHIP2_REALPLAYER_H
