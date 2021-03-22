//
// Created by alexr on 11/01/2021.
//

#include "iohelper.h"
#include <regex>

std::string iohelper::getInput(string question, const string &regex) {
    string answer;
    question += ":";
    cout << question;
    if (!regex.empty()) {
        while (true) {
            std::regex r(regex);
            getline(cin, answer);
            if (!std::regex_match(answer, r)) {
                cout << "Invalid value, please try again: ";
                continue;
            }
            return answer;
        }
    } else {
        getline(cin, answer);
        return answer;
    }
}

void iohelper::printElement(const string &t, const int &width) {
    const char separator = ' ';
    cout << left << setw(width) << setfill(separator) << t;
}

void iohelper::setFontColor(ConsoleColor code) {
    switch (code) {
        case FOREGROUND_BLACK:
            printf("\033[30m");
            break;
        case FOREGROUND_RED:
            printf("\033[31m");
            break;
        case FOREGROUND_GREEN:
            printf("\033[32m");
            break;
        case FOREGROUND_YELLOW:
            printf("\033[33m");
            break;
        case FOREGROUND_BLUE:
            printf("\033[34m");
            break;
        case FOREGROUND_PURPLE:
            printf("\033[35m");
            break;
        case FOREGROUND_CYAN:
            printf("\033[36m");
            break;
        case FOREGROUND_WHITE:
            printf("\033[37m");
            break;
    }
}

void iohelper::setDefaultFontColor() {
    iohelper::setFontColor(FOREGROUND_WHITE);
}

void iohelper::clearScreen() {
    std::cout<< u8"\033[2J\033[1;1H";
}

int iohelper::getInputBetweenRange(string question, int lowerRange, int higherRange) {
    string answer;
    while(answer.empty()){
        answer = getInput(question, "");
        try {
            int ans = stoi(answer);
            if(ans >= lowerRange && ans <= higherRange){
                return ans;
            }
            answer = "";
        } catch (...) {
            // Ignore
        }
    }
    return 0;
}
