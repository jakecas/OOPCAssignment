//
// Created by Jake on 12/01/2019.
//

#ifndef OOPCASSIGNMENT_PRINTABLE_H
#define OOPCASSIGNMENT_PRINTABLE_H

// Printable is an abstract class which has a default overloading of the << operator
// that uses a pure virtual toString method.
// This forces the class to implement toString() and at the same time
// hides complexity.
class Printable {
    friend std::ostream& operator<<(std::ostream &out, const Printable& toPrint){
        out << toPrint.toString();
        return out;
    }

    virtual std::string toString() const = 0;
};

#endif //OOPCASSIGNMENT_PRINTABLE_H
