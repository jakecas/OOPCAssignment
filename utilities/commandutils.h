//
// Created by Jake on 12/01/2019.
//

#ifndef OOPCASSIGNMENT_COMMANDUTILS_H
#define OOPCASSIGNMENT_COMMANDUTILS_H

#include <iostream>
#include <vector>

#include "../objects/binstree.h"
#include "../objects/animal.h"

using namespace std;

// Throwwn when a generic command error occurs.
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

// Thrown when a command is malformed due to insufficient/too many arguments.
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

// Maps each command to a method.
void lineRunner(vector<string> line, Node<Animal*> *root);

// commands
// Constructs and inserts an animal into the tree.
void insertAnimal(vector<string> line, Node<Animal*> *root);
// Searches the tree for an animal of the given name.
void findAnimal(vector<string> line, Node<Animal*> *root);
// Removes the chosen animal from the tree, if it exists.
void removeAnimal(vector<string> line, Node<Animal*> *root);
// Prints the tree in the given traversal order.
void printAll(vector<string> line, Node<Animal*> *root);

// internal functions
// Constructs an Animal object from the arguments.
Animal* constructAnimal(vector<string> line, Node<Animal*> *root);
// Converts a string describing venomous/non-venomous to a boolean.
bool venomousToBool(string venomous);
// Converts a string describing can-fly/cannot-fly to a boolean.
bool canflyToBool(string canfly);
// Ascertains that the number of arguments is as expected, or throws an ArgumentNumberException.
void checkArgumentNumber(int actual, int expected, string action);

#endif //OOPCASSIGNMENT_COMMANDUTILS_H
