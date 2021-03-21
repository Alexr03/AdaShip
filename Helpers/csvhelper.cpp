//
// Created by alexr on 13/01/2021.
//

#include "iostream"
#include "fstream"
#include <sstream>
#include "csvhelper.h"
#include "stringhelper.h"

using namespace std;

vector<string> csvhelper::getHeaders(const string &fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "File does not exist.";
        throw;
    }

    vector<string> headers;
    string line;
    getline(file, line);
    stringstream ss(line);

    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        headers.push_back(stringhelper::trim_copy(substr));
    }

    return headers;
}

vector<vector<string>> csvhelper::getContents(const string &fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "File does not exist.";
        throw;
    }

    vector<vector<string>> contents;
    string line;
    bool header = true;
    while (getline(file, line)) {
        // Skips the header
        if (header) {
            header = false;
            continue;
        }
        vector<string> contentFromLine;
        stringstream ss(line);

        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            contentFromLine.push_back(stringhelper::trim_copy(substr));
        }
        contents.push_back(contentFromLine);
    }

    return contents;
}

vector<string> csvhelper::getAllContents(const string &fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "File does not exist.";
        throw;
    }

    vector<string> contents;
    string line;
    while (getline(file, line)) {
        contents.push_back(line);
    }

    return contents;
}

void csvhelper::writeCsvRow(string fileName, vector<string> values) {
    ofstream file(fileName, std::ios_base::app);
    if (!file.is_open()) {
        cout << "File does not exist.";
        throw;
    }

    for (auto & value : values) {
        if(value.back() != ','){
            value += ",";
        }
        file << value;
    }
    file << endl;
    file.close();
}

void csvhelper::writeCsvRow(string fileName, string value) {
    ofstream file(fileName, std::ios_base::app);
    if (!file.is_open()) {
        cout << "File does not exist.";
        throw;
    }

    if(value.back() != ','){
        value += ",";
    }
    file << value;
    file << endl;
    file.close();
}

void csvhelper::writeCsv(string fileName, string value) {
    ofstream file(fileName, std::ios_base::out);
    if (!file.is_open()) {
        cout << "File does not exist.";
        throw;
    }

    if(value.back() != ','){
        value += ",";
    }
    file << value;
    file << endl;
    file.close();
}