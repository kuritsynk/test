#include <iostream>
#include <string>

class A {

	int x;

	float y;

public:

	A(int x, float y) : x(x), y(y) {}

	int getX() { return x; }

	float getY() { return y; }


};

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






std::string ask_user_name() {
	std::cout << "Enter user name:";
	std::string user_name;
	std::cin >> user_name;
	return user_name;
}

int main() {
	std::cout << "Hello, " << ask_user_name() << "!" << std::endl;
	
	A a(1, 3.14);

	int x = a.getX();  // x = 1;

//	B b(1, 2, 3, 4, A(1, 3.14));
//	b.setCh(&x);

	B b = B::builder()
		.withX(1)
		.withY(2)
		.withZ(3)
		.withZ1(4)
		.withA(A(1, 3.14))
		.withCh(&x)
		.build();


	std::cout << "b.y=" << b.getY() << std::endl; // 2

	std::cin.get();
}