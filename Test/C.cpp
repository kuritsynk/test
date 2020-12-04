#pragma once
#ifndef _C_CPP_
#define _C_CPP_

#include "A.cpp"

class C : public A {

	int c;

public:

	C(int x, float y, int c) : A(x, y), c(c) {}

	int getC() {
		return c;
	}

	void print() {
		A::print();
		std::cout << " ;c=" << c;
	}
};

#endif _C_CPP_
