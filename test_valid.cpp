#include "generator.hpp"
#include "grid.hpp"
#include "solver.hpp"
#include "validator.hpp"
#include <iostream>
#include <cassert>

int main() {
    // Generates a grid for each difficulty level
	Grid g = Generator::getGrid(2);
    Grid solved = Solver::getSolution(g);
	solved.print();
    int result = Validator::gridIsValid(solved);
    assert(result);
    
    solved.set(2,6,0);
    result = Validator::gridIsValid(solved);
    assert(!result);
    
    solved.set(2,6,8);
    result = Validator::gridIsValid(solved);
    assert(!result);

    solved.set(2,6,11);
    result = Validator::gridIsValid(solved);
    assert(!result);

    std::cout << "All Tests Pass!" << std::endl;
	return 0;
}
