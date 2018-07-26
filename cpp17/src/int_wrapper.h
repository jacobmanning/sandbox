#pragma once
#ifndef INT_WRAPPER_H_
#define INT_WRAPPER_H_

#include <iostream>

class IntWrapper {
public:
    int value_;
    IntWrapper() : IntWrapper(0) {};
    IntWrapper(int val) : value_{val} {};

    void print(std::ostream& os = std::cout) const {
        os << value_;
    }

    friend std::ostream& operator << (std::ostream& os, const IntWrapper& x) {
        x.print(os);
        return os;
    }

    friend IntWrapper operator * (const IntWrapper& x, const int y) {
        return IntWrapper(x.value_ * y);
    }

    friend void operator *= (IntWrapper& x, const int y) {
        x.value_ *= y;
    }
};

#endif // INT_WRAPPER_H_
