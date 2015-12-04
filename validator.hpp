#pragma once

class Validator {
public:
    static int gridIsValid(Grid &g) {
        int sq_index [3] = {0,3,6};

        for (int i = 0; i < 9; i++) {
            // check for each row and each column
            if (!checkRow(g,i) || !checkColumn(g,i)) return 0;
            // check for each square 
            if (i%3==0) {
                for (int col : sq_index) {
                    if (!checkSquare(g, i, col)) return 0;
                }
            }
        }
        return 1;
    }

private: 
    static int checkRow(Grid &g, int row) {
        int check [9] = { };
        int sum = 0;
        for (int i = 0; i < 9; i++) {
            if (sum > 45) return 0;
            int curr = g[row][i];
            if (curr < 1 || curr > 9) return 0;
            if (check[curr-1] == 1) return 0;
            if (check[curr-1] == 0) {
                check[curr-1]++;
                sum += curr;
            }
        }
        return sum == 45;
    }

    static int checkColumn(Grid &g, int col) {
        int check [9] = { };
        int sum = 0; 
        for (int i = 0; i < 9; i++) {
            if (sum > 45) return 0; 
            int curr = g[i][col];
            if (curr < 1 || curr > 9) return 0;
            if (check[curr-1] == 1) return 0;
            if (check[curr-1] == 0) {
                check[curr-1]++;
                sum += curr;
            }
        }
        return sum == 45; 
    }

    // row and col specifies the top left cell of the square
    static int checkSquare(Grid &g, int row, int col) {
        int check [9] = { };
        int sum = 0; 
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                int curr = g[i][j];
                if (curr < 1 || curr > 9) return 0;
                if (check[curr-1] == 1) return 0;
                if (check[curr-1] == 0) {
                    check[curr-1]++;
                    sum += curr;
                }
            }
        }
        return sum == 45; 
    }
};
