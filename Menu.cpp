//
// Created by alexr on 22/03/2021.
//

#include <iostream>
#include "Menu.h"
#include "Settings.h"
#include "Helpers/iohelper.h"
#include "Game.h"
#include "Helpers/Logger.h"

using namespace std;

void Menu::start() {
    Logger::Game("1) One Player v Computer Game");
    Logger::Game("9) Quit");

    while (true) {
        auto input = iohelper::getInputBetweenRange("Enter a option", 1, 9);
        switch (input) {
            case 1: {
                iohelper::setDefaultFontColor();
                std::cout << "Starting Game..." << std::endl;
                Game game{};
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