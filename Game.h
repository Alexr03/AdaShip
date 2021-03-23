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

public:
    Game();

    Player* GeneratePlayer();

    void Start();

    void SetActivePlayer(Player* player);

    void NextPlayer();

    void DisplayOpponentGrid();

    void DisplayAllGrids();

    void HitOpponent(int row, std::string col);

    void printIconDef() const;

    Player *getPlayer1() const;

    void setPlayer1(Player *player1);

    Player *getPlayer2() const;

    void setPlayer2(Player *player2);

    Player *getActivePlayer() const;

    void setActivePlayer(Player *activePlayer);

    const Grid &getGameGrid() const;

    void setGameGrid(const Grid &gameGrid);
};


#endif //ADASHIP2_GAME_H
