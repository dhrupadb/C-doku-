#pragma once

#include "grid.hpp"
#include "utils.hpp"

#include <cassert>
#include <vector>

#define EASY 1
#define MEDIUM 2
#define HARD 3
#define EASY_NUM 24
#define MEDIUM_NUM 30
#define HARD_NUM 40

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

		// TODO: Add actual logic to populate the board. 
		setRow(g, getRandom(), 0);
		setRow(g, getRandom(), 1);
		setRow(g, getRandom(), 2);
		setRow(g, getRandom(), 3);
		setRow(g, getRandom(), 4);
		setRow(g, getRandom(), 5);
		setRow(g, getRandom(), 6);
		setRow(g, getRandom(), 7);
		setRow(g, getRandom(), 8);

		// Removes random spots on the grid based on difficulty rating
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

