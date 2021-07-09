#ifndef B_HPP
#define B_HPP

#include <iostream>
#include <string>

#include "Base.hpp"

class B : public Base {
   public:
    B(void) {}
    B(B const &src) { *this = src; }
    ~B() {}

    B &operator=(B const &rhs) {
        static_cast<void>(rhs);
        return *this;
    }
};

std::ostream &operator<<(std::ostream &o, B const &i) {
    static_cast<void>(i);
    o << "Instance of class B";
    return (o);
}

#endif /* *************************************************************** B_H \
        */