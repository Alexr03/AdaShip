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

    /// Code to execute when initializing the object (or derived object)
    virtual void init();

    /// Set the board for this player
    /// \param board
    void setBoard(PlayerBoard *board);

    /// Get the board from this player
    /// \return
    PlayerBoard *getBoard() const;

    /// Code to execute when this players turn is available.
    virtual void takeTurn();

    /// The type of player this is (Computer, Real, etc)
    /// \return
    virtual PlayerType type();

    /// Get the game this player is attached to
    /// \return
    Game *getGame() const;

    /// Set the game this player is attached to
    /// \param game
    void setGame(Game *game);

    /// Determines if salvo mode is set for this player
    /// \return
    bool isSalvoMode() const;

    /// Set salvo mode for this player
    /// \param salvoMode
    void setSalvoMode(bool salvoMode);

    /// Determines if bomb mode is set for this player
    /// \return
    bool isBombsMode() const;

    /// Set bomb mode for this player
    /// \param bombsMode
    void setBombsMode(bool bombsMode);
};

#endif //ADASHIP2_PLAYER_H
