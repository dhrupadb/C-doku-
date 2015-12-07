#pragma once

class Solver {
public:
    // Check whether a half-filled grid has valid solution(s)
    static int hasSolution(Grid &g) {
        Grid dup(g);
        return solve(dup, 0, 0);
    }

    // Assuming g is solvable, get a valid solution 
    static Grid getSolution(Grid &g) {
        Grid dup(g);
        solve(dup, 0, 0); 
        return dup;
    }

    static int isValidMove(int number, Grid &g, int row, int col) {
        int sqRow = 3*(row/3);
        int sqCol = 3*(col/3);
        int row1 = (row+2)%3;
        int row2 = (row+4)%3;
        int col1 = (col+2)%3;
        int col2 = (col+4)%3;

        for (int i = 0; i < 9; i++) {
	  if (i != col && abs(g[row][i]) == number) return 0;
	  if (i != row && abs(g[i][col]) == number) return 0; 
        }

        if (abs(g[sqRow+row1][sqCol+col1]) == number) return 0;
        if (abs(g[sqRow+row2][sqCol+col1]) == number) return 0;
        if (abs(g[sqRow+row1][sqCol+col2]) == number) return 0;
        if (abs(g[sqRow+row2][sqCol+col2]) == number) return 0;
        
	return 1;
    }

private:

    // Given a half-filled grid, solve the grid and return 0 if it is solvable.
    // If not solvable, return 0.
    static int solve(Grid &g, int row, int col) {
        if (row == 9) return 1;

        // if cell has already been set
        if (g[row][col] != -10) {
            if (col == 8) {
                if (solve(g, row+1, 0)) return 1;
            } else {
                if (solve(g, row, col+1)) return 1; 
            }
            return 0;
        }

        // find a valid value to fill the cell
        for (int i = 1; i < 10; i++) {
            if(isValidMove(i, g, row, col)) {
                g.set(row, col, i);
                if (col == 8) {
                    if (solve(g, row+1, 0)) return 1;
                } else {
                    if (solve(g, row, col+1)) return 1;
                }
                g.set(row, col, -10);
            }
        }
        return 0;
    }
};
