//
// Created by alexr on 13/01/2021.
//

#ifndef PRIMERS_PORTFOLIO_ALEXR03_STRINGHELPER_H
#define PRIMERS_PORTFOLIO_ALEXR03_STRINGHELPER_H


#include <string>

class stringhelper {
public:
    /// Convert a number to an excel-like column name
    /// \param num Number to convert
    /// \return Letter(s) that the number corresponds to.
    static std::string numberToLetters(int num);

    /// Convert excel column name to number equivalent.
    /// \param s Letter(s) to convert
    /// \return Number that the letter(s) correspond to.
    static int lettersToNumber(std::string s);
};


#endif //PRIMERS_PORTFOLIO_ALEXR03_STRINGHELPER_H
