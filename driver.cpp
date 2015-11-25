#include <iostream>
#include <cstdlib>
#include <string>

#include "generator.hpp"

#define EASY 1
#define MEDIUM 2
#define HARD 3

#define EASY_NUM 24
#define MEDIUM_NUM 30
#define HARD_NUM 40

int main() {
	std::cout << " Welcome to C-Doku++ ! An interactive terminal based Sudoku Game" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Please select a difficulty level. \n 1. Easy \n 2. Medium \n 3. Hard\n\n";
	int difficulty;
	int move_count;
	while(true) {
		std::cin >> difficulty;
		if (difficulty == EASY) {
			std::cout << "\nYou have selected level 1 (Easy)\n" << std::endl;
			move_count = EASY_NUM;
			break;
		} else if (difficulty == MEDIUM) {
			std::cout << "\nYou have selected level 2 (Medium)\n" << std::endl;
			move_count = MEDIUM_NUM;
			break;
		} else if (difficulty == HARD){
			std::cout << "\nYou have selected level 3 (Hard)\n" << std::endl;
			move_count = HARD_NUM;
			break;
		} else {
			std::cout << "\nInvalid Choice. Try Again.\n" << std::endl;
			std::cout << "Please select a difficulty level. \n 1. Easy \n 2. Medium \n 3. Hard\n\n";
		}
	}
	std::cout << "Loading Grid \n\n";

	Grid g = Generator::getGrid(difficulty);
	g.print();
	while (move_count > 0) {
		std::cout << "\nEnter a move \n";
		std::string cmd;
		std::cin >> cmd; 
		// Command needs to be parsed and a valid move made if command is valid
		// move_count decremented when valid move is made
		// Valid move is also a move which doesn't break Sudoku invariant
		std::cout << std::endl;
		g.print();
		std::cout << std::endl;
	}
	return 0;
}