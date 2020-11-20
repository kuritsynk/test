#pragma once

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
