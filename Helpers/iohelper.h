//
// Created by alexr on 11/01/2021.
//

#ifndef ADAADVANCEDPROGRAMMING_1_IOHELPER_H
#define ADAADVANCEDPROGRAMMING_1_IOHELPER_H


#include <string>
#include <iostream>
#include <iomanip>
#include "ConsoleColor.h"

using namespace std;

class iohelper {
public:
    /// Get input from the user
    /// \param question Question to ask the user
    /// \param regex Regex (if any) to validate against the user input
    /// \return The user input that was validated against the regex.
    static std::string getInput(string question = "", const string& regex = "");

    /// Set the font color of the console back to default
    static void setDefaultFontColor();

    ///Clear the screen on a supported terminal
    static void clearScreen();

    /// Take user input of an integer between a range
    /// \param question Question to ask user
    /// \param lowerRange Lower range (inclusive)
    /// \param higherRange Higher range (inclusive)
    /// \return
    static int getInputBetweenRange(string question, int lowerRange, int higherRange);

    /// Set the font color of the console
    /// \param code Color
    static void setFontColor(ConsoleColor code);
};


#endif //ADAADVANCEDPROGRAMMING_1_IOHELPER_H
