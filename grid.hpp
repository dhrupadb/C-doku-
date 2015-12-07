#pragma once

#include <cassert>
#include <iostream>
#include <vector>

class Grid{
  std::vector< std::vector<int> > _data;

  Grid(std::vector< std::vector<int> > data) : _data(data) {}
public:
  Grid() : _data() {
    _data.resize(9, std::vector<int>(9,0));
  }

  Grid(const Grid &g) {
    if (g._data.size() != 9 && g._data[0].size() != 9) {
      return;
    }
    _data.resize(9, std::vector<int>(9,0));
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        _data[i][j] = g._data[i][j];
      }
    }
  }

  void operator= (const Grid &g) {
    if (g._data.size() != 9 && g._data[0].size() != 9) {
      return;
    }
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        _data[i][j] = g._data[i][j];
      }
    }
    return;
  }

  bool operator== (const Grid &g) {
    if (g._data.size() != 9 && g._data[0].size() != 9) {
      return false;
    }
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if(_data[i][j] != g._data[i][j]) {
          return false;
        }
      }
    }
    return true;
  }

  bool operator!= (const Grid &g) {
    if (g._data.size() != 9 && g._data[0].size() != 9) {
      return false;
    }
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if(_data[i][j] != g._data[i][j]) {
          return true;
        }
      }
    }
    return false;
  }

  /**
  * Print function for the grid. -10 is a blank grid value. A negative number is a preset value of
  * the original solution. A positive number is a user set value.
  **/
  void print() {
    for(int i = -1; i < 9; i++) {
      if (i == -1) {
        printLetters();
      } else {
        for(int j = -1; j < 9; j++) {
          if (j == -1) {
            printNumber(i);
            continue;
          }
          if (_data[i][j] == -10) {
            std::cout << "x \t";
          } else if (_data[i][j] < 0) {
            printGreen(_data[i][j]*-1);
          } else {
            std::cout << _data[i][j] << "\t";
          }
        }
      }
      std::cout << "\n";
    }
  }

  std::vector<int> operator[](int i) {
    assert(i < 9 && i >= 0);
    return _data[i];
  }

  void set(int i, int j, int val) {
    assert(i < 9 && i >= 0 && j < 9 && j >= 0);
    _data[i][j] = val;
  }

private:
  void printLetters() {
    std::cout << "\t";
    for (int j = 65; j < 74; j++ ) {
      printRed(j);
    }
    std::cout << "\n";
  }

  void printNumber(int i) {
    printRed(i);
  }

  void printGreen(int data) {
    std::cout << "\33[32;40m" << data << "\33[0m" << "\t";
  }

  void printRed(int data) {
    if (data > 10) {
      std::cout << "\33[0;31m" << char(data) << "\33[0m" << "\t";
    } else {
      std::cout << "\33[0;31m" << data << "\33[0m" << "\t";
    }
  }
};
