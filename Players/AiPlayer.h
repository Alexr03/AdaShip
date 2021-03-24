//
// Created by alexr on 23/03/2021.
//

#ifndef ADASHIP2_AIPLAYER_H
#define ADASHIP2_AIPLAYER_H


#include "Player.h"

class AiPlayer : public Player {
public:
    AiPlayer();

    AiPlayer(bool bombMode);

    void init() override;

    void takeTurn() override;

    PlayerType type() override;

    void shoot() const;
};


#endif //ADASHIP2_AIPLAYER_H
