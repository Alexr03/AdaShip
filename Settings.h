//
// Created by alexr on 01/03/2021.
//

#ifndef ADASHIP2_SETTINGS_H
#define ADASHIP2_SETTINGS_H

#include "mini.h"
#include "Models/Board.h"
#include "Models/Mine.h"

class Settings {
public:
    static mINI::INIStructure getSettingsFile();
    static Board getBoard();
    static std::vector<Ship> getShips();
    static std::vector<Mine> getMines();
};


#endif //ADASHIP2_SETTINGS_H
