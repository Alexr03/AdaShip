//
// Created by alexr on 01/03/2021.
//

#ifndef ADASHIP2_GAME_H
#define ADASHIP2_GAME_H


#include "Players/Player.h"
#include "Grid.h"

class Game {
private:
    Player* player1{};
    Player* player2{};
    Player* activePlayer{};
    Grid gameGrid{};
    bool salvoMode = false;

public:
    /// Initialize new instance of the game
    Game();

    /// Code to execute when the game starts
    void Start();

    /// Sets the active player
    /// \param player
    void SetActivePlayer(Player* player);

    /// Switches the active player to the next player
    void NextPlayer();

    /// Displays the opponents grid
    void DisplayOpponentGrid();

    /// Displays all players grids
    void DisplayAllGrids();

    /// Sets a hitspot on the opponent
    void HitOpponent(int row, std::string col);

    /// Prints the icon definitions
    static void printIconDef() ;

    /// Gets player 1
    /// \return
    Player *getPlayer1() const;

    /// Sets player 1
    /// \param player1
    void setPlayer1(Player *player1);

    /// Gets player 2
    /// \return
    Player *getPlayer2() const;

    /// Sets player 2
    /// \param player2
    void setPlayer2(Player *player2);

    /// Gets the current active player
    /// \return
    Player *getActivePlayer() const;

    /// Sets the current active player
    /// \param activePlayer
    void setActivePlayer(Player *activePlayer);

    /// Gets the games gamegrid
    /// \return
    const Grid &getGameGrid() const;

    /// Sets the games gamegrid
    /// \param gameGrid
    void setGameGrid(const Grid &gameGrid);

    /// Get the opponent player
    /// \return
    Player *getOpponentPlayer() const;
};


#endif //ADASHIP2_GAME_H
