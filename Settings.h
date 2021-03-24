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
    /// Gets the mINI intance of the settings file
    /// \return IniStructure instance
    static mINI::INIStructure getSettingsFile();

    /// Gets board settings
    /// \return
    static Board getBoard();

    /// Gets ships defined in the settings file
    /// \return
    static std::vector<Ship> getShips();

    /// Gets mines defined in the settings file
    /// \return
    static std::vector<Mine> getMines();
};


#endif //ADASHIP2_SETTINGS_H
