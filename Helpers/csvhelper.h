//
// Created by alexr on 13/01/2021.
//

#ifndef PRIMERS_PORTFOLIO_ALEXR03_CSVHELPER_H
#define PRIMERS_PORTFOLIO_ALEXR03_CSVHELPER_H

#include "string"
#include "vector"

using namespace std;

class csvhelper {
public:
    static vector<string> getHeaders(const string& fileName);
    static vector<vector<string>> getContents(const string& fileName);

    static void writeCsvRow(string fileName, vector<string> values);

    static vector<string> getAllContents(const string &fileName);

    static void writeCsvRow(string fileName, string value);

    static void writeCsv(string fileName, string value);

    static void removeLine(string fileName, int lineNum);
};


#endif //PRIMERS_PORTFOLIO_ALEXR03_CSVHELPER_H
