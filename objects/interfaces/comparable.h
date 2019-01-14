//
// Created by Jake on 10/12/2018.
//

#ifndef OOPCASSIGNMENT_COMPARABLE_H
#define OOPCASSIGNMENT_COMPARABLE_H

// This pure virtual class is to be used as an interface that enforces the object to implement relational operators.
// The type would be set when a class inherits the Comparable class, and should be set to the child class itself.
template <typename T>
class Comparable {
public:
    virtual bool operator==(const T& that) = 0;
    virtual bool operator<(const T& that) = 0;
    virtual bool operator>(const T& that) = 0;
};


#endif //OOPCASSIGNMENT_COMPARABLE_H
