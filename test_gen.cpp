#include "generator.hpp"
#include "grid.hpp"

#include <iostream>

int main(){
    // Generates a grid for each difficulty level
	Grid sample = Generator::getGrid(1);
	sample.print();
	sample = Generator::getGrid(2);
	sample.print();
	sample = Generator::getGrid(3);
	sample.print();
	std::cout << "All Tests Pass!" << std::endl;
	return 0;
}
