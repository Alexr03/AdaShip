//
// Created by alexr on 22/03/2021.
//

#include <iostream>
#include "Menu.h"
#include "Settings.h"
#include "Helpers/iohelper.h"
#include "Game.h"
#include "Helpers/Logger.h"
#include "Players/RealPlayer.h"
#include "Players/AiPlayer.h"

using namespace std;

void Menu::start() {
    while (true) {
        Logger::Divider();
        Logger::Game("1) Player v Computer Game");
        Logger::Game("2) Player v Player Game");
        Logger::Game("3) Player v Computer (Salvo) Game");
        Logger::Game("9) Quit");
        auto input = iohelper::getInputBetweenRange("Enter a option", 1, 9);
        switch (input) {
            case 1: {
                iohelper::setDefaultFontColor();
                std::cout << "Starting Game..." << std::endl;
                Game game{};
                game.setPlayer1(new RealPlayer);
                game.setPlayer2(new AiPlayer);
                game.Start();
                break;
            }
            case 2:{
                iohelper::setDefaultFontColor();
                std::cout << "Starting Game..." << std::endl;
                Game game{};
                game.setPlayer1(new RealPlayer);
                game.setPlayer2(new RealPlayer);
                game.Start();
                break;
            }
            case 3:{
                iohelper::setDefaultFontColor();
                std::cout << "Starting Game..." << std::endl;
                Game game{};
                auto* player1 = new RealPlayer;
                player1->setSalvoMode(true);
                game.setPlayer1(player1);
                auto* player2 = new AiPlayer;
                player2->setSalvoMode(true);
                game.setPlayer2(player2);
                game.Start();
                break;
            }
            case 9: {
                cout << "Quitting" << endl;
                exit(0);
            }
            default: {
                cout << "Invalid option" << endl;
                break;
            }
        }
    }
}

void Menu::settingsMenu() {
}