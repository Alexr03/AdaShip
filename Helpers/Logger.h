//
// Created by alexr on 22/03/2021.
//

#ifndef ADASHIP2_LOGGER_H
#define ADASHIP2_LOGGER_H

#include <iostream>
#include <string>

using namespace std;

class Logger {
public:
    static void Debug(std::string msg){
        iohelper::setFontColor(FOREGROUND_RED);
        if(Settings::getSettingsFile()["Settings"]["Debug"] == "1"){
            cout << "[DEBUG] " << msg << std::endl;
        }
        iohelper::setDefaultFontColor();
    }

    static void Game(std::string msg){
        iohelper::setDefaultFontColor();
        cout << "[GAME] " << msg << std::endl;
    }

    static void Divider(){
        std::cout << "---------------------------------------------------------------------" << std::endl;
    }

    static void DebugDivider(){
        if(Settings::getSettingsFile()["Settings"]["Debug"] == "1"){
            std::cout << "---------------------------------------------------------------------" << std::endl;
        }
    }
};


#endif //ADASHIP2_LOGGER_H
