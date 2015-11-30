#pragma once

#include "grid.hpp"
#include "utils.hpp"
#include "solver.hpp"

#include <cassert>
#include <vector>

#define EASY 1
#define MEDIUM 2
#define HARD 3
#define EASY_NUM 24
#define MEDIUM_NUM 30
#define HARD_NUM 40
#define PRESETS 10

class Generator{

public:
	static Grid getGrid(int diff) {
		Grid g = Grid();
		initializeGrid(g, diff);
		return g;
	}

private:
	static void initializeGrid(Grid &g, int diff) {
		setBlanks(g);
		srand(time(NULL));
        createValidGrid(g, PRESETS);
        
        /* TODO: find a way to store the solution
        Grid solution = g;
        std::cout << "Default solution: \n";
        solution.print();
        */
        eraseCells(g, diff);
	}

    // Removes random spots on the grid based on difficulty rating
    static void eraseCells(Grid &g, int diff) {
		int count = 0;
		if (diff == EASY) {
			count = EASY_NUM;
		} else if (diff == MEDIUM) {
			count = MEDIUM_NUM;
		} else {
			count = HARD_NUM;
		}

		while (count > 0) {
			int x = std::rand()%9;
			int y = std::rand()%9;
			if (g[x][y] != -10) {
				g.set(x,y, -10);
				count--;
			}
		}
    }

    // fill the grid will a full, valid sudoku
    static void createValidGrid(Grid &g, int presets) {
        while (presets > 0) {
            int x = std::rand()%9;
            int y = std::rand()%9;
            if (g[x][y] != -10) continue;
            // choose an empty cell to set
            std::vector<int> vec = getRandom();
            for (int i = 0; i < 9; i++) {
                if (Solver::isValidMove(vec[i], g, x, y)) {
                    g.set(x,y,vec[i]);
                    if (Solver::hasSolution(g)) {
                        presets--;
                        break;
                    }
                    g.set(x,y,-10);
                }
            }
        }
        g = Solver::getSolution(g);
    }

	static void setBlanks(Grid &g) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				g.set(i,j,-10);
			}
		}
	}

	static void setRow(Grid &g, std::vector<int> vec, int index) {
		for (int i = 0; i < 9; i++) {
			g.set(index,i,vec[i]*-1);
		}
	}
};

