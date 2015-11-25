#include <algorithm> 
#include <iostream>
#include <vector>
#include <thread>
#include <chrono> 

int myrandom (int i) { 
	return std::rand()%i;
}

std::vector<int> getRandom() {
	std::vector<int> v;
	for (int i=1; i<10; i++) {
		v.push_back(i);
	}
	std::random_shuffle (v.begin(), v.end(), myrandom);
	return v;
}

