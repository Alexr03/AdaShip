//
// Created by alexr on 22/03/2021.
//

#ifndef ADASHIP2_LOGGER_H
#define ADASHIP2_LOGGER_H

#include <iostream>

class Logger {
public:
    static void Debug(std::string msg){
        iohelper::setFontColor(FOREGROUND_RED);
        if(Settings::getSettingsFile()["Settings"]["Debug"] == "1"){
            cout << "[DEBUG] " << msg << std::endl;
        }
    }

    static void Divider(){
        cout << "---------------------------------------------------" << std::endl;
    }
};


#endif //ADASHIP2_LOGGER_H
