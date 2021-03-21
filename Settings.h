//
// Created by alexr on 01/03/2021.
//

#ifndef ADASHIP2_SETTINGS_H
#define ADASHIP2_SETTINGS_H

#include "mini.h"
#include "Models/Board.h"

class Settings {
public:
    static mINI::INIStructure getSettingsFile();

public:
    static Board getBoard();
    static std::vector<Ship> getShips();
};


#endif //ADASHIP2_SETTINGS_H
