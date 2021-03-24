//
// Created by alexr on 13/01/2021.
//

#include "stringhelper.h"

#include <algorithm>
#include <cctype>
#include <string.h>
#define MAX 50

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

int stringhelper::lettersToNumber(std::string s) {
    int number = 0;
    for (const auto& c : s) {
        number *= 26;
        number += c  - 'A' + 1;
    }
    return number;
}
