//
// Created by alexr on 03/03/2021.
//

#include "Grid.h"
#include "Helpers/iohelper.h"
#include "Constants.h"

void Grid::print() const {
//    for (int i = 0; i < rows; i++) {    /* output labeled grid rows */
//        for (int j = 0; j < cols; j++) {
//            bool hit = coordHit(i + 1, stringhelper::numberToLetters(j + 1));
//        }
//    }

    std::cout << "\n";                  /* output new line before grid */
    for (int i = 0; i < cols; i++) { /* output column headings */
        auto colLetter = stringhelper::numberToLetters(i + 1);
        if (!i) {
            std::cout << "       " << stringhelper::numberToLetters(i + 1);
        } else {
            if (colLetter.size() == 1) {
                std::cout << "     " << stringhelper::numberToLetters(i + 1);
            } else {
                std::cout << "    " << stringhelper::numberToLetters(i + 1);
            }
        }
    }
    std::cout << "\n";
    for (int i = 0; i < cols; i++)      /* output header separators */
        if (!i)
            std::cout << "     -----";
        else
            std::cout << " -----";
    std::cout << "\n";
    std::string shipId = " ";
    for (int i = 0; i < rows; i++) {    /* output labeled grid rows */
        for (int j = 0; j < cols; j++) {
            bool hit = coordHit(i + 1, stringhelper::numberToLetters(j + 1));
            auto ship = shipForCoord(i + 1, stringhelper::numberToLetters(j + 1));
            shipId = shipIdForCoord(i + 1, stringhelper::numberToLetters(j + 1));
            if(hit){
                iohelper::setFontColor(FOREGROUND_RED);
                shipId = "*";
//                cout << ship.getName() << " des: " << to_string(ship.isDestroyed());
                if (ship.isInvalid()) {
                    iohelper::setFontColor(FOREGROUND_YELLOW);
                    shipId = "Ø";
                } else if (ship.isDestroyed()) {
                    shipId = "▓";
                }
            }

            if (!j) {
                std::cout << std::setw(3) << i + 1 << " |  ";
                cout << shipId;
                iohelper::setDefaultFontColor();
                cout << "  |";
            } else {
                std::cout << "  ";
                cout << shipId;
                iohelper::setDefaultFontColor();
                cout << "  |";
            }
            iohelper::setDefaultFontColor();
        }
        std::cout << " " << i + 1 << "\n";
    }
    for (int i = 0; i < cols; i++)      /* output footer separators */
        if (!i)
            std::cout << "     -----";
        else
            std::cout << "------";
    std::cout << "\n";
    for (int i = 0; i < cols; i++) {      /* output column footer */
        auto colLetter = stringhelper::numberToLetters(i + 1);
        if (!i)
            std::cout << "       " << stringhelper::numberToLetters(i + 1);
        else {
            if (colLetter.size() == 1) {
                std::cout << "     " << stringhelper::numberToLetters(i + 1);
            } else {
                std::cout << "    " << stringhelper::numberToLetters(i + 1);
            }
        }
    }

    std::cout << "\n";                  /* tidy up with new line */
}

void Grid::setPlayer(Player *&player) {
    Grid::player = player;
}

Player *Grid::getPlayer() const {
    return player;
}

Ship Grid::shipForCoord(int row, const std::string &col) const {
    for (const auto &ship : getPlayer()->getBoard()->getShips()) {
        if (ship.getCoordinates().empty()) {
            continue;
        }

        for (const auto &coords : ship.getCoordinates()) {
            if (coords.getRow() == row && coords.getCol() == col) {
                return ship;
            }
        }
    }
    return Constants::GetInvalidShip();
}

std::string Grid::shipIdForCoord(int row, const std::string &col) const {
    if (Settings::getSettingsFile()["Settings"]["ShowBombsOnGrid"] == "1") {
        for (const auto &mine : getPlayer()->getBoard()->getMines()) {
            if (mine.getCoordinates().empty()) {
                continue;
            }

            for (const auto &coords : mine.getCoordinates()) {
                if (coords.getRow() == row && coords.getCol() == col) {
                    return "+";
                }
            }
        }
    }

    if (Settings::getSettingsFile()["Settings"]["ShowShipsOnGrid"] == "1") {
        for (const auto &ship : getPlayer()->getBoard()->getShips()) {
            if (ship.getCoordinates().empty()) {
                continue;
            }

            for (const auto &coords : ship.getCoordinates()) {
                if (coords.getRow() == row && coords.getCol() == col) {
                    return ship.getId();
                }
            }
        }
    }
    return " ";
}

bool Grid::coordHit(int row, const std::string &col) const {
    auto hitSpots = getPlayer()->getBoard()->getHitSpots();
    for (const auto &hitSpot : hitSpots) {
        if (hitSpot.getRow() == row && hitSpot.getCol() == col) {
            return true;
        }
    }
    return false;
}

Game *Grid::getGame() const {
    return game;
}

void Grid::setGame(Game *game) {
    Grid::game = game;
}
