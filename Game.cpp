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
#include "Players/AiPlayer.h"

int currentPlayer = 1;

Game::Game() {

}

void Game::Start() {
    player1->setGame(this);
    player2->setGame(this);
    activePlayer = player1;
    iohelper::clearScreen();

    gameGrid.setPlayer(activePlayer);
//    gameGrid.print();
    bool state = true;
    while(state){
        iohelper::clearScreen();
        printIconDef();
        DisplayAllGrids();
        Logger::Game("Player " + to_string(currentPlayer) + " its your turn!");
        activePlayer->takeTurn();
        NextPlayer();
    }
//    std::cout << "ree" << std::endl;
//    std::cout << "Player1 = " << typeid(player1).name() << std::endl;
}

void Game::printIconDef() const {
    cout << "Icon Meanings" << endl;
    iohelper::setFontColor(FOREGROUND_YELLOW);
    cout << "Ø = Fired shot that missed." << endl;
    iohelper::setFontColor(FOREGROUND_RED);
    cout << "* = Fired shot that hit a ship" << endl;
    cout << "▓ = Destroyed Ship" << endl;
    iohelper::setDefaultFontColor();
    Logger::Divider();
}

Player *Game::GeneratePlayer() {
//    auto *realPlayer = new RealPlayer();
//    realPlayer->setGame(this);
//    return realPlayer;
    std::string choice = iohelper::getInput("Press 1 for you to play or 2 for the computer to play");
    if (choice == "1") {
        auto *realPlayer = new RealPlayer();
        realPlayer->setGame(this);
        return realPlayer;
    } else {
        //todo Actually do AI.
        auto *aiPlayer = new AiPlayer();
        aiPlayer->setGame(this);
        return aiPlayer;
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

Player *Game::getPlayer1() const {
    return player1;
}

void Game::setPlayer1(Player *player1) {
    Game::player1 = player1;
}

Player *Game::getPlayer2() const {
    return player2;
}

void Game::setPlayer2(Player *player2) {
    Game::player2 = player2;
}

Player *Game::getActivePlayer() const {
    return activePlayer;
}

void Game::setActivePlayer(Player *activePlayer) {
    Game::activePlayer = activePlayer;
}

const Grid &Game::getGameGrid() const {
    return gameGrid;
}

void Game::setGameGrid(const Grid &gameGrid) {
    Game::gameGrid = gameGrid;
}
