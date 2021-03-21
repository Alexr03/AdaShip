//
// Created by alexr on 13/01/2021.
//

#include "stringhelper.h"

#include <algorithm>
#include <cctype>
#include <locale>
#define MAX 50

// trim from start (in place)
void stringhelper::ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
void stringhelper::rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
void stringhelper::trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

// trim from start (copying)
std::string stringhelper::ltrim_copy(std::string s) {
    ltrim(s);
    return s;
}

// trim from end (copying)
std::string stringhelper::rtrim_copy(std::string s) {
    rtrim(s);
    return s;
}

// trim from both ends (copying)
std::string stringhelper::trim_copy(std::string s) {
    trim(s);
    return s;
}

std::string stringhelper::numberToLetters(int num) {
    char str[MAX]; // To store result (Excel column name)
    int i = 0; // To store current index in str which is result

    while (num > 0) {
        // Find remainder
        int rem = num % 26;

        // If remainder is 0, then a 'Z' must be there in output
        if (rem == 0) {
            str[i++] = 'Z';
            num = (num / 26) - 1;
        }
        else // If remainder is non-zero
        {
            str[i++] = (rem - 1) + 'A';
            num = num / 26;
        }
    }
    str[i] = '\0';

    // Reverse the string and print result
    std::reverse(str, str + strlen(str));

    return str;
}
