//
// Created by alexr on 13/01/2021.
//

#ifndef PRIMERS_PORTFOLIO_ALEXR03_STRINGHELPER_H
#define PRIMERS_PORTFOLIO_ALEXR03_STRINGHELPER_H


#include <string>

class stringhelper {
public:
    static void ltrim(std::string &s);

    static void rtrim(std::string &s);

    static void trim(std::string &s);

    static std::string ltrim_copy(std::string s);

    static std::string rtrim_copy(std::string s);

    static std::string trim_copy(std::string s);

    static std::string numberToLetters(int num);
};


#endif //PRIMERS_PORTFOLIO_ALEXR03_STRINGHELPER_H
