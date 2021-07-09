#include <iostream>
#include <string>
#include <stdint.h>

#include "Data.hpp"

uintptr_t serialize(Data *ptr) {
    uintptr_t casted_ptr;

    casted_ptr = reinterpret_cast<uintptr_t>(ptr);
    return (casted_ptr);
}

Data *deserialize(uintptr_t raw) {
    Data *ret;

    ret = reinterpret_cast<Data *>(raw);
    return (ret);
}

int main(void) {
    Data *data = new Data;
    uintptr_t intptr;
    Data *new_data;

    std::cout << "Before cast :	" << data << ", _value = " << data->getValue()
              << std::endl;

    intptr = serialize(data);
    std::cout << intptr << std::endl;
    new_data = deserialize(intptr);

    std::cout << "After cast :	" << new_data
              << ", _value = " << new_data->getValue() << std::endl;

    return (0);
}