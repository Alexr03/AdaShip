//
// Created by alexr on 03/03/2021.
//

#include "Grid.h"
#include "Helpers/iohelper.h"

void Grid::print() const {
    std::cout << "\n";                  /* output new line before grid */
    for (int i = 0; i < cols; i++)      /* output column headings */
        if (!i)
            std::cout << "       " << stringhelper::numberToLetters(i + 1);
        else
            std::cout << "     " << stringhelper::numberToLetters(i + 1);
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
    for (int i = 0; i < cols; i++)      /* output column footer */
        if (!i)
            std::cout << "       " << stringhelper::numberToLetters(i + 1);
        else
            std::cout << "     " << stringhelper::numberToLetters(i + 1);
    std::cout << "\n";                  /* tidy up with new line */
}

void Grid::setPlayer(Player *&player) {
    Grid::player = player;
}

Player *Grid::getPlayer() const {
    return player;
}

std::string Grid::shipIdForCoord(int row, std::string col) const {
//    std::cout << "Ships: " << getPlayer()->getBoard()->getShips().size();
    for (const auto& ship : getPlayer()->getBoard()->getShips()) {
        if (ship.getCoordinates().empty()) {
//            std::cout << "coords for ship " << ship.getName() << " is empty." << std::endl;
            continue;
        }
        if (std::stoi(ship.getCoordinates().front()) == row){
            for (auto it = std::next(ship.getCoordinates().begin()); it != ship.getCoordinates().end(); ++it) {
                if(*it == col){
                    return ship.getId();
                }
            }
        }
    }
    return " ";
}