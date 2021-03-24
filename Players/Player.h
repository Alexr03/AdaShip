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
    bool salvoMode = false;
    bool bombsMode = false;
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

    bool isSalvoMode() const;

    void setSalvoMode(bool salvoMode);

    bool isBombsMode() const;

    void setBombsMode(bool bombsMode);
};

#endif //ADASHIP2_PLAYER_H
