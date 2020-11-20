#pragma once

#include <iostream>

class A {

	int x;

	float y;

public:

	A(int x, float y) : x(x), y(y) {}

	int getX() { return x; }

	float getY() { return y; }

	virtual void print() {
		std::cout << "x=" << x
			<< "; y=" << y;
	}

};
