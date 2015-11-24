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

  Grid(const Grid &g);

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

  void print() {
    for(int i = 0; i < 9; i++) {
      for(int j = 0; j < 9; j++) {
        if (_data[i][j] < 0) {
          std::cout << "_\t";
        } else {
          std::cout << "\33[32;40m" << _data[i][j] << "\33[0m" << "\t";
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
};
