CXXFLAGS=-std=c++11 -g -fPIC

TARGETS = test_grid test_utils test_gen test_valid cdokupp
OBJS=test_grid.o test_utils.o test_gen.o test_valid.o driver.o

all: $(TARGETS)

cdokupp: driver.o
	g++ -o cdokupp driver.o $(CXXFLAGS)

test_grid: test_grid.o
	g++ -o test_grid test_grid.o $(CXXFLAGS)

test_utils: test_utils.o
	g++ -o test_utils test_utils.o $(CXXFLAGS)

test_gen: test_gen.o
	g++ -o test_gen test_gen.o $(CXXFLAGS)

test_valid: test_valid.o
	g++ -o test_valid test_valid.o $(CXXFLAGS)

%.o: %.cpp generator.hpp grid.hpp utils.hpp solver.hpp validator.hpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm $(OBJS) $(TARGETS)
