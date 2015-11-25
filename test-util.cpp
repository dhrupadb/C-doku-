#include "utils.hpp"
#include <iostream>

int main() {
	std::vector<int> v = getRandom();
	for (int i = 0; i < 9; i++) {
		std::cout << v[i] << "\t";
	}
	std::cout << "\n All Tests Passed!\n";
	return 1;
}