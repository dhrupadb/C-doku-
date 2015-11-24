CXXFLAGS=-std=c++11 -g -fPIC

TARGETS = generator test_grid
OBJS=generator.o test_grid.o

all: $(TARGETS)

generator: generator.o
	g++ -o generator generator.o $(CXXFLAGS)

test_grid: test_grid.o
	g++ -o test_grid test_grid.o $(CXXFLAGS)

%.o: %.cpp generator.hpp grid.hpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm $(OBJS) $(TARGETS)
