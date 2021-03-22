//
// Created by alexr on 02/03/2021.
//

#ifndef ADASHIP2_PLAYER_H
#define ADASHIP2_PLAYER_H


#include <vector>
#include "../Models/Ship.h"
#include "../Models/PlayerBoard.h"
#include "PlayerType.h"

class Game;
struct Player {
private:
    PlayerBoard* board{};
    Game* game;
public:
    Player() {}

    virtual void init();

    void setBoard(PlayerBoard *board);

    PlayerBoard *getBoard() const;

    /// Code to takeTurn for this exercise.
    virtual void takeTurn();

    virtual PlayerType type();

    Game *getGame() const;

    void setGame(Game *game);
};

#endif //ADASHIP2_PLAYER_H
