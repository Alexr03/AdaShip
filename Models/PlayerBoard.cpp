//
// Created by alexr on 01/03/2021.
//

#include <string>
#include "PlayerBoard.h"
#include "../Settings.h"
#include "../Helpers/mathshelper.h"
#include "../Helpers/stringhelper.h"
#include "../Players/Player.h"
#include "../Helpers/iohelper.h"
#include "../Helpers/Logger.h"

const std::vector<Ship> &PlayerBoard::getShips() const {
    return ships;
}

PlayerBoard::PlayerBoard(Player *player1) : ships(Settings::getShips()), player(player1) {
    for (auto &ship : ships) {
        ship.setPlayerBoard(this);
    }
    bool autoPlaceAll = false;
    if (player->type() == Real) {
        auto option = iohelper::getInputBetweenRange("Press 1 to autoplace ships.\nPress 2 to place ships manually.", 1,
                                                     2);
        autoPlaceAll = option == 1;
    } else if (player->type() == Computer) {
        autoPlaceAll = true;
    }
    for (auto &c : ships) {
        vector<Coord> coords;
        int posOrientation = 1;
        int posX = 1;
        int posY = 1;
        if (autoPlaceAll) {
            posOrientation = mathshelper::generatePickedNumber(2); // 1 = Horizontal, 2 = Vertical
            posX = mathshelper::generatePickedNumber(Settings::getBoard().getSizeX());
            posY = mathshelper::generatePickedNumber(Settings::getBoard().getSizeY());
        } else {
            auto option = iohelper::getInputBetweenRange(
                    "Ship: " + c.getName() + "\nPress 1 to autoplace the ship.\nPress 2 to place the ship manually", 1,
                    2);
            if (option == 1) {
                posOrientation = mathshelper::generatePickedNumber(2); // 1 = Horizontal, 2 = Vertical
                posX = mathshelper::generatePickedNumber(Settings::getBoard().getSizeX());
                posY = mathshelper::generatePickedNumber(Settings::getBoard().getSizeY());
            } else {
                posOrientation = iohelper::getInputBetweenRange("Orientation - 1 for Horizontal, 2 for Vertical", 1, 2);
                posX = stringhelper::lettersToNumber(iohelper::getInput(
                        "Position X, enter a letter between A-" +
                        stringhelper::numberToLetters(Settings::getBoard().getSizeX()), ""));
                posY = iohelper::getInputBetweenRange(
                        "Position Y, enter a number between 1-" + to_string(Settings::getBoard().getSizeY()), 1,
                        Settings::getBoard().getSizeY());
            }
        }

        bool overlapped = true;
        Logger::Debug("Pos Orientation: " + (to_string(posOrientation)) + " (" + c.getName() + ")");
        while (overlapped) {
            if (posOrientation == 1) {
                coords.clear();
                Logger::Debug("Horizontal");
                // If the ship will overrun the map.
                Logger::Debug("PosX: " + to_string(posX));
                Logger::Debug("PosY: " + to_string(posY));
                Logger::Debug("Length: " + to_string(c.getLength()));
                if (c.getLength() + posX <= Settings::getBoard().getSizeX()) {
                    for (int i = posX; i < posX + c.getLength(); ++i) {
                        Logger::Debug("Ship: " + c.getName() + " | adding coord: " + to_string(i) + " (" +
                                      stringhelper::numberToLetters(i) + ")");
                        coords.emplace_back(posX, stringhelper::numberToLetters(i));
                    }
                    c.setCoordinates(coords);
                } else { // Flip, because it doesn't fit.
                    for (int i = posX; i > posX - c.getLength(); --i) {
                        Logger::Debug("Ship: " + c.getName() + " | adding coord: " + to_string(i) + " (" +
                                      stringhelper::numberToLetters(i) + ")");
                        coords.emplace_back(posX, stringhelper::numberToLetters(i));
                    }
                    c.setCoordinates(coords);
                }
            } else {
                coords.clear();
                Logger::Debug("Vertical");
                if (c.getLength() + posY <= Settings::getBoard().getSizeY()) {
                    for (int i = posY; i < posY + c.getLength(); ++i) {
                        Logger::Debug("Ship: " + c.getName() + " | adding coord: " + to_string(i) + " (" +
                                      stringhelper::numberToLetters(i) + ")");
                        coords.emplace_back(i, stringhelper::numberToLetters(posX));
                    }
                    c.setCoordinates(coords);
                } else { // Flip, because it doesn't fit.
                    for (int i = posY; i > posY - c.getLength(); --i) {
                        Logger::Debug("Ship: " + c.getName() + " | adding coord: " + to_string(i) + " (" +
                                      stringhelper::numberToLetters(i) + ")");
                        coords.emplace_back(i, stringhelper::numberToLetters(posX));
                    }
                    c.setCoordinates(coords);
                }
            }
            overlapped = isShipOverlapping(c);
            if (overlapped && autoPlaceAll) {
                posOrientation = mathshelper::generatePickedNumber(2); // 1 = Horizontal, 2 = Vertical
                posX = mathshelper::generatePickedNumber(Settings::getBoard().getSizeX());
                posY = mathshelper::generatePickedNumber(Settings::getBoard().getSizeY());
            }
            Logger::DebugDivider();
        }
    }
}

void PlayerBoard::hitSpot(int row, string col) {
    hitSpots.emplace_back(row, col);
}

const vector<Coord> &PlayerBoard::getHitSpots() const {
    return hitSpots;
}

bool PlayerBoard::isShipOverlapping(const Ship& ship) {
    for (const auto &s : ships) {
        for (const auto& coord : ship.getCoordinates()) {
            if (ship.getId() == s.getId()) continue;
            for(const auto &coord2 : s.getCoordinates()){
                if(coord.getCol() == coord2.getCol() && coord.getRow() == coord2.getRow()){
                    Logger::Debug("Ship - " + ship.getName() + " is overlapping with ship - " + s.getName());
                    return true;
                }
            }
        }
    }
    return false;
}

bool PlayerBoard::isHitSpot(int row, std::string col) {
    for(auto &hitSpot : hitSpots){
        if(hitSpot.getRow() == row && hitSpot.getCol() == col){
            return true;
        }
    }

    return false;
}
