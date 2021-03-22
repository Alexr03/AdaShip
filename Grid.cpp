//
// Created by alexr on 03/03/2021.
//

#include "Grid.h"
#include "Helpers/iohelper.h"
#include "Constants.h"

void Grid::print() const {
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
            shipId = shipIdForCoord(i + 1, stringhelper::numberToLetters(j + 1));
            if (!j) {
                std::cout << std::setw(3) << i + 1 << " |  " << shipId << "  |";
            } else {
                std::cout << "  " << shipId << "  |";
            }
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
//    std::cout << "Ships: " << getPlayer()->getBoard()->getShips().size();
    for (const auto &ship : getPlayer()->getBoard()->getShips()) {
        if (ship.getCoordinates().empty()) {
            continue;
        }
        if (ship.getCoordinates().front() == to_string(row)) {
            for (auto it = std::next(ship.getCoordinates().begin()); it != ship.getCoordinates().end(); ++it) {
                if (*it == col) {
                    return ship;
                }
            }
        }
        if (ship.getCoordinates().front() == col) {
            for (auto it = std::next(ship.getCoordinates().begin()); it != ship.getCoordinates().end(); ++it) {
                if (*it == to_string(row)) {
                    return ship;
                }
            }
        }
    }
    return Constants::GetInvalidShip();
}

std::string Grid::shipIdForCoord(int row, const std::string &col) const {
//    std::cout << "Ships: " << getPlayer()->getBoard()->getShips().size();
    for (const auto &ship : getPlayer()->getBoard()->getShips()) {
        if (ship.getCoordinates().empty()) {
            continue;
        }
        if (ship.getCoordinates().front() == to_string(row)) {
            for (auto it = std::next(ship.getCoordinates().begin()); it != ship.getCoordinates().end(); ++it) {
                if (*it == col) {
                    return ship.getId();
                }
            }
        }
        if (ship.getCoordinates().front() == col) {
            for (auto it = std::next(ship.getCoordinates().begin()); it != ship.getCoordinates().end(); ++it) {
                if (*it == to_string(row)) {
                    return ship.getId();
                }
            }
        }
    }
    return " ";
}