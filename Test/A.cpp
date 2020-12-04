#pragma once
#ifndef _A_CPP_

#define _A_CPP_



#include <iostream>
#include "Listener.cpp"

Event<const char*> onCreateEvent;

class A {

	int x;

	float y;


public:

	A(int x, float y) : x(x), y(y) {
		onCreateEvent.notifyAll("A created");
	}

	int getX() { return x; }

	float getY() { return y; }

	virtual void print() {
		std::cout << "x=" << x
			<< "; y=" << y;
	}

};

#endif // !_A_CPP_

