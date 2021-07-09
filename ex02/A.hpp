#ifndef A_HPP
#define A_HPP

#include <iostream>
#include <string>

#include "Base.hpp"

class A : public Base {
   public:
    A(void) {}
    A(A const &src) { *this = src; }
    ~A() {}

    A &operator=(A const &rhs) {
        static_cast<void>(rhs);
        return *this;
    }
};

std::ostream &operator<<(std::ostream &o, A const &i) {
    static_cast<void>(i);
    o << "Instance of class A";
    return (o);
}

#endif /* *************************************************************** A_H \
        */