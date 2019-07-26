#include <iostream>
#include <string>

std::string ask_user_name() {
	std::cout << "Enter user name:";
	std::string user_name;
	std::cin >> user_name;
	return user_name;
}

int main() {
	std::cout << "Hello, " << ask_user_name() << "!" << std::endl;
}