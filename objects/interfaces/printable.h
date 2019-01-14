//
// Created by Jake on 12/01/2019.
//

#ifndef OOPCASSIGNMENT_PRINTABLE_H
#define OOPCASSIGNMENT_PRINTABLE_H

class Printable {
    friend std::ostream& operator<<(std::ostream &out, const Printable& toPrint){
        out << toPrint.toString();
        return out;
    }

    virtual std::string toString() const = 0;
};

#endif //OOPCASSIGNMENT_PRINTABLE_H
