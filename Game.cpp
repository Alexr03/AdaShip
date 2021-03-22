//
// Created by alexr on 01/03/2021.
//

#include <iostream>
#include <utility>
#include "Game.h"
#include "Players/RealPlayer.h"
#include "Helpers/iohelper.h"
#include "Grid.h"
#include "Helpers/Logger.h"

int currentPlayer = 1;

Game::Game() {
    player1 = GeneratePlayer();

    player2 = GeneratePlayer();
    activePlayer = player1;

    gameGrid.setPlayer(activePlayer);
}

void Game::Start() {
    iohelper::clearScreen();

    cout << "Icon Meanings" << endl;
    iohelper::setFontColor(FOREGROUND_YELLOW);
    cout << "Ø = Fired shot that missed." << endl;
    iohelper::setFontColor(FOREGROUND_RED);
    cout << "* = Fired shot that hit a ship" << endl;
    cout << "▓ = Destroyed Ship" << endl;
    iohelper::setDefaultFontColor();
    Logger::Divider();

    gameGrid.setPlayer(activePlayer);
//    gameGrid.print();
    bool state = true;
    while(state){
        iohelper::clearScreen();
        DisplayAllGrids();
        Logger::Game("Player " + to_string(currentPlayer) + " its your turn!");
        activePlayer->takeTurn();
        NextPlayer();
    }
//    std::cout << "ree" << std::endl;
//    std::cout << "Player1 = " << typeid(player1).name() << std::endl;
}

Player *Game::GeneratePlayer() {
    auto *realPlayer = new RealPlayer();
    realPlayer->setGame(this);
    return realPlayer;
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

void Game::DisplayOpponentGrid() {
    NextPlayer();
    cout << "Player " << currentPlayer << " Grid:";
    gameGrid.print();
    NextPlayer();
}

void Game::DisplayAllGrids() {
    cout << "Player 1 Grid:";
    gameGrid.setPlayer(player1);
    gameGrid.print();
    Logger::Divider();
    cout << "Player 2 Grid:";
    gameGrid.setPlayer(player2);
    gameGrid.print();
    gameGrid.setPlayer(activePlayer);
    Logger::Divider();
}

void Game::HitOpponent(int row, string col){
    NextPlayer();
    activePlayer->getBoard()->hitSpot(row, std::move(col));
    NextPlayer();
}
