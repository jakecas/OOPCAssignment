//
// Created by Jake on 10/12/2018.
//

#ifndef OOPCASSIGNMENT_COMPARABLE_H
#define OOPCASSIGNMENT_COMPARABLE_H

template <typename T>
class Comparable {
public:
    virtual bool operator==(const T& that) = 0;
    virtual bool operator<(const T& that) = 0;
    virtual bool operator>(const T& that) = 0;
};


#endif //OOPCASSIGNMENT_COMPARABLE_H
