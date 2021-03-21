//
// Created by alexr on 01/03/2021.
//

#include <iostream>
#include "Settings.h"

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

mINI::INIStructure Settings::getSettingsFile() {
    mINI::INIFile file("adaship_config.ini");
    mINI::INIStructure ini;
    file.read(ini);
    return ini;
}
