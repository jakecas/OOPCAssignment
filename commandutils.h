//
// Created by Jake on 12/01/2019.
//

#ifndef OOPCASSIGNMENT_COMMANDUTILS_H
#define OOPCASSIGNMENT_COMMANDUTILS_H

#include <iostream>
#include <vector>

#include "binstree.h"
#include "animal.h"

using namespace std;


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

// switch
void lineRunner(vector<string> line, Node<Animal*> *root);

// commands
void insertAnimal(vector<string> line, Node<Animal*> *root);
void findAnimal(vector<string> line, Node<Animal*> *root);
void removeAnimal(vector<string> line, Node<Animal*> *root);
void printAll(vector<string> line, Node<Animal*> *root);

// internal functions
Animal* constructAnimal(vector<string> line, Node<Animal*> *root);
bool venomousToBool(string venomous);
bool canflyToBool(string canfly);
void checkArgumentNumber(int actual, int expected, string action);

#endif //OOPCASSIGNMENT_COMMANDUTILS_H
