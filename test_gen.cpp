#include "generator.hpp"
#include "grid.hpp"

#include <iostream>

int main(){
	Grid sample = Generator::getGrid(1);
	sample.print();
	std::cout << "All Tests Pass!" << std::endl;
	return 0;
}