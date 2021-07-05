#ifndef C_HPP
#define C_HPP

#include <iostream>
#include <string>
#include "Base.hpp"

class C : public Base
{

public:
	C(void) {}
	C(C const &src) { *this = src; }
	~C() {}

	C &operator=(C const &rhs)
	{
		static_cast<void>(rhs);
		return *this;
	}
};

std::ostream &operator<<(std::ostream &o, C const &i)
{
	static_cast<void>(i);
	o << "Instance of class C";
	return (o);
}

#endif /* *************************************************************** C_H */