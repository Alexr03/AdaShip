//
// Created by alexr on 01/03/2021.
//

#include <iostream>
#include "PlayerBoard.h"
#include "../Settings.h"
#include "../Helpers/mathshelper.h"
#include "../Helpers/stringhelper.h"

const std::vector<Ship> &PlayerBoard::getShips() const {
    return ships;
}

PlayerBoard::PlayerBoard() : ships(Settings::getShips()) {
    for (auto &c : ships) {
        vector<string> coords;
        int posOrientation = mathshelper::generatePickedNumber(2); // 1 = Horizontal, 2 = Vertical
//        if(posOrientation == 1){ // Debug for vertical
//            posOrientation = 2;
//        }
        int posX = mathshelper::generatePickedNumber(Settings::getBoard().getSizeX());
        int posY = mathshelper::generatePickedNumber(Settings::getBoard().getSizeY());

        cout << "[D] pos orgin: " << posOrientation << " (" << c.getName() << ")" << endl;
        if (posOrientation == 1) {
            cout << "[D] horz";
            coords.push_back(to_string(posY));
            // If the ship will overrun the map.
            cout << "[D] posX = " << posX << endl;
            cout << "[D] add = " << c.getLength() + posX << endl;
            cout << (c.getLength() + posX <= Settings::getBoard().getSizeX()) << endl;
            if (c.getLength() + posX <= Settings::getBoard().getSizeX()) {
                cout << "[D] Entered loop" << endl;
                for (int i = posX; i < posX + c.getLength(); ++i) {
                    cout << "[D] Ship: " << c.getName() << " | adding coord: " << i << " ("
                         << stringhelper::numberToLetters(i) << ") | PosX=" << posX << endl;
                    coords.push_back(stringhelper::numberToLetters(i));
                }
                for (const auto &coord : coords) {
                    cout << "Coord::" << coord << endl;
                }
                c.setCoordinates(coords);
            } else {
                cout << "[D] needs to flip" << endl;
                cout << "[D] Entered loop" << endl;
                for (int i = posX; i > posX - c.getLength(); --i) {
                    cout << "[D] Ship: " << c.getName() << " | adding coord: " << i << " ("
                         << stringhelper::numberToLetters(i) << ") | PosX=" << posX << endl;
                    coords.push_back(stringhelper::numberToLetters(i));
                }
                for (const auto &coord : coords) {
                    cout << "[D] Coord::" << coord << endl;
                }
                c.setCoordinates(coords);
            }
        } else {
            coords.push_back(stringhelper::numberToLetters(posX));
            cout << "[D] vert";
            if (c.getLength() + posY <= Settings::getBoard().getSizeY()) {
                cout << "[D] Entered loop" << endl;
                for (int i = posY; i < posY + c.getLength(); ++i) {
                    cout << "[D] Ship: " << c.getName() << " | adding coord: " << i << " ("
                         << stringhelper::numberToLetters(i) << ") | PosY=" << posY << endl;
                    coords.push_back(to_string(i));
                }
                for (const auto &coord : coords) {
                    cout << "Coord::" << coord << endl;
                }
                c.setCoordinates(coords);
            } else{
                cout << "[D] needs to flip" << endl;
                cout << "[D] Entered loop" << endl;
                for (int i = posY; i > posY - c.getLength(); --i) {
                    cout << "[D] Ship: " << c.getName() << " | adding coord: " << i << " ("
                         << stringhelper::numberToLetters(i) << ") | PosY=" << posY << endl;
                    coords.push_back(to_string(i));
                }
                for (const auto &coord : coords) {
                    cout << "[D] Coord::" << coord << endl;
                }
                c.setCoordinates(coords);
            }
        }
        cout << "--------------" << endl;
    }
}