//
// Created by Jake on 27/12/2018.
//

#ifndef OOPCASSIGNMENT_COMMANDS_H
#define OOPCASSIGNMENT_COMMANDS_H

#define DEFAULT_TEST_FILE "defaulttest.txt"
#define DEFAULT_LINES 32

#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct FileNotFoundException : public std::exception {
    const char *message () const throw () {
        return "Unable to find or open file.";
    }
};

struct MalformedCommandException : public std::exception {
    MalformedCommandException(string reason){
        this->reason = "Malformed command: " + reason;
    }

    virtual const string message () const throw () {
        return this->reason;
    }

private:
    string reason;
};

struct ArgumentNumberException : public MalformedCommandException{
    ArgumentNumberException(string reason, int argnum)
    : MalformedCommandException(reason){
        this->argnum = argnum;
    }

    const string message () const throw () {
        return MalformedCommandException::message() + to_string(argnum);
    }

private:
    int argnum;
};



vector<string> lineReader(string fileName){
    vector<string> lines;
    ifstream file(fileName);

    if (file.is_open())
    {
        string line;
        while (getline(file, line)){
                line[line.size()-1] = '\0';
            lines.push_back(line);
        }
        file.close();
    } else {
        throw new FileNotFoundException();
    }

    return lines;
}

vector<string> lineTokenizer(string line){
    vector<string> tokenizedLine;

    char *commands = strtok(&line[0], " ");
    while (commands != NULL) {
        tokenizedLine.push_back(commands);
        commands = strtok(NULL, " ");
    }

    return tokenizedLine;
}

#endif //OOPCASSIGNMENT_COMMANDS_H
