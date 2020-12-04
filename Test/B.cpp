#pragma once
#ifndef _B_CPP_
#define _B_CPP_

#include "A.cpp"

class B {

	int x;

	float y;

	int z;

	float z1;

	int* ch;

	A a;

	B(int x, float y, int z, float z1, A a, int* ch)
		: x(x), y(y), z(z), z1(z1), a(a), ch(ch) {	}


public:

	int getX() { return x; }

	float getY() { return y; }

	A& getA() { return a; }

	class Builder {

		int x;

		float y;

		int z;

		float z1;

		int* ch;

		A a;

	public:
		Builder() : a(A(0, 0)) {
		}

		Builder& withX(int x) {
			this->x = x;
			return *this;
		}

		Builder& withY(float y) {
			this->y = y;
			return *this;
		}

		Builder& withZ(int z) {
			this->z = z;
			return *this;
		}

		Builder& withZ1(float z1) {
			this->z1 = z1;
			return *this;
		}

		Builder& withCh(int* ch) {
			this->ch = ch;
			return *this;
		}

		Builder& withA(A a) {
			this->a = a;
			return *this;
		}

		B build() {
			return B(x, y, z, z1, a, ch);
		}


	};

	static Builder builder() {
		return Builder();
	}

};

#endif _B_CPP_