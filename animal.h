//
// Created by Jake on 11/12/2018.
//

#ifndef OOPCASSIGNMENT_ANIMAL_H
#define OOPCASSIGNMENT_ANIMAL_H

#include "comparable.h"

class Animal: public Comparable<Animal>{
public:
    Animal(std::string name, double length){
        this->name = name;
        this->length = length;
    }

    bool operator==(const Animal& that){
        std::cout << "Equals?" << std::endl;
        return this->length == that.length;
    }

    bool operator<(const Animal& that){
        std::cout << "Less Than?" << std::endl;
        return this->length < that.length;
    }

    bool operator>(const Animal& that){
        std::cout << "Greater Than?" << std::endl;
        return this->length > that.length;
    }

    friend std::ostream& operator<<(std::ostream &out, const Animal& toPrint){
        out << toPrint.getName();
        return out;
    }

    std::string getName() const{
        return this->name;
    }

private:
    std::string name;
    double length;
};

class Mammal: public Animal{
public:
    Mammal(std::string name, double length, int averageLitterSize)
    : Animal(name, length){
        this->averageLitterSize = averageLitterSize;
    }

private:
    int averageLitterSize;
};

class Reptile: public Animal{
public:
    Reptile(std::string name, double length, bool venomous)
    : Animal(name, length){
        this->venomous = venomous;
    }

private:
    bool venomous;
};

class Bird: public Animal{
public:
    Bird(std::string name, double length, bool canFly)
            : Animal(name, length){
        this->canFly = canFly;
    }

private:
    bool canFly;
};


#endif //OOPCASSIGNMENT_ANIMAL_H
