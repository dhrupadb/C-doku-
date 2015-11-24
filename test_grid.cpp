#include "grid.hpp"

#include <iostream>
#include <cassert>

int main(){
  Grid g = Grid();

  Grid g2 = Grid();

  assert(g == g2);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if ((i+j)%7 == 0) {
        g2.set(i,j,-1*(i+1)*(j+1));
      } else {
        g2.set(i,j,(i-1)*(j+1));
      }
    }
  }

  assert(g != g2);

  g = g2;

  assert (g == g2);

  g.set(8,8, -10);
  g.set(4,8, -10);
  g.set(3,8, -10);
  g.set(8,5, -10);
  g.set(1,3, -10);

  g.print();

  std::cout << "All tests passed!\n";

  return 0;
}