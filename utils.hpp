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

void tokenize(const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters = " ")
{
    std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    std::string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (std::string::npos != pos || std::string::npos != lastPos)
    {
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        lastPos = str.find_first_not_of(delimiters, pos);
        pos = str.find_first_of(delimiters, lastPos);
    }
}

