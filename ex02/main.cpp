#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base *generate(void) {
    int i = rand() % 3;
    Base *ret;

    switch (i) {
        case 0:
            ret = new A;
            std::cout << "Instance of class A generated" << std::endl;
            break;
        case 1:
            ret = new B;
            std::cout << "Instance of class B generated" << std::endl;
            break;
        case 2:
            ret = new C;
            std::cout << "Instance of class C generated" << std::endl;
            break;
    }
    return (ret);
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << *(dynamic_cast<A *>(p)) << " identified by pointer"
                  << std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << *(dynamic_cast<B *>(p)) << " identified by pointer"
                  << std::endl;
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout << *(dynamic_cast<C *>(p)) << " identified by pointer"
                  << std::endl;
    else
        std::cout << "Couldn't identify class" << std::endl;
}

void identify(Base &p) {
    try {
        Base &tmp = dynamic_cast<A &>(p);
        static_cast<void>(tmp);
        std::cout << (dynamic_cast<A &>(p)) << " identified by reference"
                  << std::endl;
    } catch (std::exception) {
    }

    try {
        Base &tmp = dynamic_cast<B &>(p);
        static_cast<void>(tmp);
        std::cout << (dynamic_cast<B &>(p)) << " identified by reference"
                  << std::endl;
    } catch (std::exception) {
    }
    try {
        Base &tmp = dynamic_cast<C &>(p);
        static_cast<void>(tmp);
        std::cout << (dynamic_cast<C &>(p)) << " identified by reference"
                  << std::endl;
    } catch (std::exception) {
    }
}

int main(void) {
    Base *base;
    srand(time(NULL));

    base = generate();
    identify(base);
    identify(*base);
    return (0);
}