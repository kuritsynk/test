#include <iostream>
#include <string>

// #include "Listener.cpp"
#include "A.cpp"
#include "B.cpp"
#include "C.cpp"
//#include "AFactory.cpp"

A* createA(int x, float y, int c) {

	return new C(x, y, c);

}



std::string ask_user_name() {
	std::cout << "Enter user name:";
	std::string user_name;
	std::cin >> user_name;
	return user_name;
}

class OnCreateListener : public Listener<const char*> {

public:

	void execute(const char* event) {
		std::cout << "Event created: " << event << endl;
	}

};


class OnCreateListenerA : public Listener<const char*> {

public:

	void execute(const char* event) {
		std::cout << "Event created A fdfkdjfk: " << event << endl;
	}

};



int main() {
	std::cout << "Hello, " << ask_user_name() << "!" << std::endl;

	OnCreateListener onCreateListener;
	onCreateEvent.registerListener(&onCreateListener);
	
	OnCreateListenerA onCreateListenerA;
	onCreateEvent.registerListener(&onCreateListenerA);

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


	/*
	std::cout << "Constructor example" << std::endl;

	C c = C(2, 2.76, 5);

	A* p = &a;
	p->print(); // x=1;y=3.14

	std::cout << std::endl;

	p = &c;
	p->print(); // x=2;y=2.76;c=5

	*/

	std::cout << std::endl << "Factory example" << std::endl;

	A* p = createA(2, 2.76, 5);
	p->print();


	std::cin.get();
}