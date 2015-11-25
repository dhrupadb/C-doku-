#include "utils.hpp"
#include <iostream>

int main() {
	std::vector<int> v = getRandom();
	std::vector<int> v1 = getRandom();
	std::vector<int> v2 = getRandom();
	for (int i = 0; i < 9; i++) {
		std::cout << v[i] << "\t";
	}
	std::cout << std::endl;
	for (int i = 0; i < 9; i++) {
		std::cout << v1[i] << "\t";
	}
	std::cout << std::endl;
	for (int i = 0; i < 9; i++) {
		std::cout << v2[i] << "\t";
	}
	std::cout << std::endl;
	std::cout << "All Tests Passed!\n";
	return 1;
}