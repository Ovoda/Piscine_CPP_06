#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

class Data {
   public:
    // Constructors
    Data(void) : _value(42) {}
    Data(Data &src) { *this = src; }

    // Destructor
    ~Data() {}

    // Overload
    Data &operator=(Data &rhs) {
        if (this != &rhs) _value = rhs._value;
        return (*this);
    }

    // Getters
    int getValue(void) const { return _value; }

   private:
    int _value;
};

std::ostream &operator<<(std::ostream &o, Data const &i) {
    o << i.getValue();
    return (o);
}

#endif /* ************************************************************ DATA_H \
        */