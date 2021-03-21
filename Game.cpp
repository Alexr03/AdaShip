//
// Created by alexr on 01/03/2021.
//

#include <iostream>
#include "Game.h"
#include "Players/RealPlayer.h"
#include "Helpers/iohelper.h"
#include "Grid.h"

int currentPlayer = 1;

Game::Game() {
    player1 = GeneratePlayer();
    player2 = GeneratePlayer();
    activePlayer = player1;

    gameGrid.setPlayer(activePlayer);
}

void Game::Start() {
    gameGrid.setPlayer(activePlayer);
    gameGrid.print();
//    while(state){
//        activePlayer->takeTurn();
//    }
//    std::cout << "ree" << std::endl;
//    std::cout << "Player1 = " << typeid(player1).name() << std::endl;
}

Player *Game::GeneratePlayer() {
    std::string choice = iohelper::getInput("Press 1 for you to play or 2 for the computer to play");
    if (choice == "1") {
        auto *realPlayer = new RealPlayer();
        return realPlayer;
    } else {
        //todo Actually do AI.
        auto *realPlayer = new RealPlayer();
        return realPlayer;
    }
}

void Game::SetActivePlayer(Player *player) {
    this->activePlayer = player;
    gameGrid.setPlayer(activePlayer);
}

void Game::NextPlayer() {
    if (currentPlayer == 1) {
        SetActivePlayer(player2);
        currentPlayer = 2;
    } else {
        SetActivePlayer(player1);
        currentPlayer = 1;
    }
}
