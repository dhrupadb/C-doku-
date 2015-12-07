#include <iostream>
#include <cstdlib>
#include <string>
#include <map>

#include "generator.hpp"
#include "solver.hpp"

#define EASY 1
#define MEDIUM 2
#define HARD 3

#define EASY_NUM 24
#define MEDIUM_NUM 30
#define HARD_NUM 40


static std::vector<int> moveParser(std::string command) {
  std::vector<int> retVal = std::vector<int>(3); //three parts
  std::string firstChar = command.substr(0,1);
  std::transform(firstChar.begin(), firstChar.end(), firstChar.begin(), tolower);
  std::string secondChar = command.substr(2,1);
  int firstNum = stoi(secondChar);
  std::string thirdChar = command.substr(4,1);
  int secondNum = stoi(thirdChar);
  
  std::map<std::string,int> comparator;
  comparator["a"] = 0;
  comparator["b"] = 1;
  comparator["c"] = 2;
  comparator["d"] = 3;
  comparator["e"] = 4;
  comparator["f"] = 5;
  comparator["g"] = 6;
  comparator["h"] = 7;
  comparator["i"] = 8;

  retVal[0] = comparator[firstChar];
  retVal[1] = firstNum;
  retVal[2] = secondNum;
  return retVal;
}

static bool canUpdate(Grid &g, int row, int col) {
  if(Solver::isValidMove) {
    if(g[row][col] > 0) {
      return true;
    }
  }
  return false;
}

static bool validCmd(std::string command) {
  //convert to lowercase
  std::transform(command.begin(), command.end(),command.begin(), ::tolower);
  if(command.compare("quit")==0 || command.compare("solve") == 0) {
    return true;
  }
  //command format "column row number"
  std::string firstChar = command.substr(0,1);
  std::transform(firstChar.begin(), firstChar.end(), firstChar.begin(), tolower);
  std::string secondChar = command.substr(2,1);
  int firstNum = stoi(secondChar);
  std::string thirdChar = command.substr(4,1);
  int secondNum = stoi(thirdChar);
  if(firstChar > "i" || firstNum > 9 || firstNum < 0 || secondNum > 9 || secondNum < 0){
    return false;
  } else {
    return true;
  }
}

int main() {
	std::cout << " Welcome to C-Doku++ ! An interactive terminal based Sudoku Game" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Please select a difficulty level. \n 1. Easy \n 2. Medium \n 3. Hard\n\n";
	std::string s1;
	int difficulty;
	//int move_count;
	while(true) {
	  std::getline(std::cin, s1);
	  difficulty = stoi(s1);
		if (difficulty == EASY) {
			std::cout << "\nYou have selected level 1 (Easy)\n" << std::endl;
			//move_count = EASY_NUM;
			break;
		} else if (difficulty == MEDIUM) {
			std::cout << "\nYou have selected level 2 (Medium)\n" << std::endl;
			//move_count = MEDIUM_NUM;
			break;
		} else if (difficulty == HARD){
			std::cout << "\nYou have selected level 3 (Hard)\n" << std::endl;
			//move_count = HARD_NUM;
			break;
		} else {
			std::cout << "\nInvalid Choice. Try Again.\n" << std::endl;
			std::cout << "Please select a difficulty level. \n 1. Easy \n 2. Medium \n 3. Hard\n\n";
		}
      	}
	std::cout << "Loading Grid \n\n";

	Grid g = Generator::getGrid(difficulty);
	Grid solved = Solver::getSolution(g);
	// Command needs to be parsed and a valid move made if command is valid
	// move_count decremented when valid move is made
	// Valid move is also a move which doesn't break Sudoku invariant
	  while(true) {
	    g.print();
	    std::cout << "\nEnter a move (or 'quit' to quit the game; 'solve' to get the solution) \n";
	    std::string cmd;
	    std::getline(std::cin, cmd);
	    if(!validCmd(cmd)) {
	      continue;
	    }
	    if (cmd == "quit" || cmd == "Quit" || cmd == "QUIT") return 0;
	    if (cmd == "Solve" || cmd == "solve" || cmd == "SOLVE") {
	      std::cout << "Are you sure ? \" Y / N \"" << std::endl;
	      std::string ans;
	      std::cin >> ans;
	      std::cout << std::endl;
	      if (ans == "Y" || ans == "y") {
		solved.print();
		std::cout << std::endl;
		return 0;
	      } else {
		continue;
	      }
	    }
		  //parsedCmd is column,row,number to update
	      std::vector<int> parsedCmd = moveParser(cmd);
	      if(canUpdate) {
		g.set(parsedCmd[1],parsedCmd[0], parsedCmd[2]);
		if(solved == g) {
		  std::cout << "You win!";
		  solved.print();
		  std::cout << std::endl;
		  return 0;
		}
		//go back to the beginning and keep playing
		continue;
	      }
	  }
}
