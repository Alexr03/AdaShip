//
// Created by alexr on 01/03/2021.
//

#include <iostream>
#include "Settings.h"
#include "Models/Mine.h"

Board Settings::getBoard() {
    Board board{};
    auto config = getSettingsFile();
    board.setSizeX(std::stoi(config["Board"]["SizeY"]));
    board.setSizeY(std::stoi(config["Board"]["SizeX"]));

    return board;
}

std::vector<Ship> Settings::getShips() {
    std::vector<Ship> ships;
    auto config = getSettingsFile();
    int id = 1;
    for (auto const &i : config["Ships"]) {
        Ship ship(id);
        ship.setName(i.first);
        ship.setLength(std::stoi(i.second));
        ships.push_back(ship);
        id++;
    }
    return ships;
}

std::vector<Mine> Settings::getMines() {
    std::vector<Mine> mines;
    auto config = getSettingsFile();
    int id = 1000;
    for (int i = 0; i < stoi(getSettingsFile()["Board"]["Bombs"]); ++i) {
        Mine mine(id);
        mines.push_back(mine);
        id++;
    }
    return mines;
}

mINI::INIStructure Settings::getSettingsFile() {
    mINI::INIFile file("adaship_config.ini");
    mINI::INIStructure ini;
    file.read(ini);
    return ini;
}
