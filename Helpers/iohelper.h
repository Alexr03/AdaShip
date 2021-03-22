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

    /// Print formatted text to the screen where spacing is defined
    /// \tparam T Text to print
    /// \param t Text to print
    /// \param width The width to give the text
    static void printElement(const string& t, const int &width);

    static void setDefaultFontColor();

    static void clearScreen();

    static int getInputBetweenRange(string question, int lowerRange, int higherRange);

    static void setFontColor(ConsoleColor code);
};


#endif //ADAADVANCEDPROGRAMMING_1_IOHELPER_H
