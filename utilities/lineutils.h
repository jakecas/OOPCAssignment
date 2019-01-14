//
// Created by Jake on 27/12/2018.
//

#ifndef OOPCASSIGNMENT_LINEUTILS_H
#define OOPCASSIGNMENT_LINEUTILS_H

#define DEFAULT_TEST_FILE "defaulttest.txt"
#define DEFAULT_LINES 32

#include <algorithm>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Thrown if the file could not be opened.
struct FileNotFoundException : public std::exception {
    const char *message () const throw () {
        return "Unable to find or open file.";
    }
};

// Splits the file into a vector of lines.
vector<string> lineReader(string fileName){
    vector<string> lines;
    ifstream file(fileName);

    if (file.is_open())
    {
        string line;
        while (getline(file, line)){
            if(line.size() > 0)
                // Removing line endings for both linux and windows systems just in case.
                line.erase(remove(line.begin(), line.end(), '\n'), line.end());
                line.erase(remove(line.begin(), line.end(), '\r'), line.end());
                lines.push_back(line);
        }
        file.close();
    } else {
        throw new FileNotFoundException();
    }

    return lines;
}

// Splits the string into a vector of words.
vector<string> lineTokenizer(string line){
    vector<string> tokenizedLine;

    char *commands = strtok(&line[0], " ");
    while (commands != NULL) {
        tokenizedLine.push_back(commands);
        commands = strtok(NULL, " ");
    }

    return tokenizedLine;
}

#endif //OOPCASSIGNMENT_LINEUTILS_H
