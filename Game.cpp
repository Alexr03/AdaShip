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
    while(true){
        iohelper::clearScreen();
        printIconDef();
        DisplayAllGrids();
        Logger::Game("Player " + to_string(currentPlayer) + " its your turn!");
        activePlayer->takeTurn();
        int shipsDestroyed = 0;
        for(auto &ship : getOpponentPlayer()->getBoard()->getShips()){
            if(ship.isDestroyed()){
                ++shipsDestroyed;
            }
        }

        if(shipsDestroyed >= Settings::getShips().size()){
            break;
        }
        NextPlayer();
    }

    // Show end game
    DisplayAllGrids();
    Logger::Divider();
    Logger::Game("Player " + to_string(currentPlayer) + " has won!");
}

void Game::printIconDef() {
    cout << "Icon Meanings" << endl;
    iohelper::setFontColor(FOREGROUND_YELLOW);
    cout << "Ø = Fired shot that missed." << endl;
    iohelper::setFontColor(FOREGROUND_RED);
    cout << "* = Fired shot that hit a ship" << endl;
    cout << "▓ = Destroyed Ship" << endl;
    iohelper::setDefaultFontColor();
    Logger::Divider();
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

Player *Game::getOpponentPlayer() const {
    if (currentPlayer == 1) {
        return player2;
    } else {
        return player1;
    }
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
