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
};


#endif //ADASHIP2_GAME_H
