//
// Created by Jake on 11/12/2018.
//

#ifndef OOPCASSIGNMENT_ANIMAL_H
#define OOPCASSIGNMENT_ANIMAL_H

#include <string>
#include <sstream>

#include "comparable.h"

using namespace std;

class Animal: public Comparable<Animal>{
public:
    Animal(string name, double length){
        this->name = name;
        this->length = length;
    }

    Animal(string name){
        this->name = name;
    }

    // Needs to be virtual so that the derived classes' destructor is called first.
    virtual ~Animal(){
    }

    bool operator==(const Animal& that){
        return this->name.compare(that.name) == 0;
    }

    bool operator<(const Animal& that){
        return this->name.compare(that.name) < 0;
    }

    bool operator>(const Animal& that){
        return this->name.compare(that.name) > 0;
    }

    friend ostream& operator<<(ostream &out, const Animal& toPrint){
        out << toPrint.toString() << endl;
        return out;
    }

    virtual string toString() const {
        ostringstream strs;
        strs << "Animal: " << this->getName() << " " << this->getLength();
        return strs.str();
    }

    string getName() const{
        return this->name;
    }

    double getLength() const{
        return this->length;
    }

private:
    string name;
    double length;
};

class Mammal: public Animal{
public:
    Mammal(string name, double length, int averageLitterSize)
    : Animal(name, length){
        this->averageLitterSize = averageLitterSize;
    }

    ~Mammal(){
        cout << "Mammal dead" << endl;
    }

    int getAverageLitterSize() const{
        return this->averageLitterSize;
    }

    string toString() const {
        ostringstream strs;
        strs << "Mammal: " << this->getName() << " " << this->getLength() << " " << this->getAverageLitterSize();
        return strs.str();
    }

private:
    int averageLitterSize;
};

class Reptile: public Animal{
public:
    Reptile(string name, double length, bool venomous)
    : Animal(name, length){
        this->venomous = venomous;
    }

    ~Reptile(){
        cout << "Reptile dead" << endl;
    }


    bool getVenomous() const{
        return this->venomous;
    }

    string toString() const {
        string venomousString = this->getVenomous() ? "venomous" : "non-venomous";
        ostringstream strs;
        strs << "Reptile: " << this->getName() << " " << this->getLength() << " " << venomousString;
        return strs.str();
    }

private:
    bool venomous;
};

class Bird: public Animal{
public:
    Bird(string name, double length, bool canFly)
            : Animal(name, length){
        this->canFly = canFly;
    }

    ~Bird(){
        cout << "Bird dead" << endl;
    }


    bool getCanFly() const{
        return this->canFly;
    }

    string toString() const {
        string canFlyString = this->getCanFly() ? "can-fly" : "cannot-fly";
        ostringstream strs;
        strs << "Bird: " << this->getName() << " " << this->getLength() << " " << canFlyString;
        return strs.str();
    }

private:
    bool canFly;
};


#endif //OOPCASSIGNMENT_ANIMAL_H
