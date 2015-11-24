#include "grid.hpp"

#include <iostream>
#include <cassert>

int main(){
  Grid g = Grid();

  Grid g2 = Grid();

  assert(g == g2);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      g2.set(i,j,(i-1)*(j+1));
    }
  }

  assert(g != g2);

  g = g2;

  assert (g == g2);

  g.print();

  std::cout << "All tests passed!\n";

  return 0;
}