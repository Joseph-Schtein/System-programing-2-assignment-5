#include <iostream>
#include <vector>

#include "range.hpp"
#include "accumulator.hpp"
#include "filterfalse.hpp"
#include "compress.hpp"

struct lessThan3 {
    bool operator()(int i) const { return i < 3; }
};

int main() {
    
    std::cout << "####  range:  ####";
    std::cout << std::endl;
	for (int i: range(5,9))
		std::cout << i << " ";
    

    std::vector<int> vecInt = {1,2,3,4};
    std::vector<std::string> vecString = {"Hello", "Bye", "Adam"};
    std::vector<float> vecFloat = {-1, 0.3, 5.2, -8.3};


    std::cout << std::endl << "####  accumulate:  ####";
    std::cout << std::endl << "accumulate of range: " << std::endl;
	for (int i: accumulate(range(5,9)))
		std::cout << i << " ";      // 5 11 18 26
    
    std::cout << std::endl << "accumulate of vector<string>: " << std::endl;
    for (auto i: accumulate(vecString) )
        std::cout << i << " ";  // Hello HelloBye HelloByeAdam
    std::cout << std::endl << std::endl;
    
    std::cout << std::endl << "accumulate of range with binary operator: " << std::endl;
	for (int i: accumulate(range(5,9), [](int x, int y){return x*y;}))
		std::cout << i << " ";      // 5 30 210 1680
    


    std::cout << "####  Filter False:  ####";
    std::cout << std::endl << "Filter out all numbers less than 3 in vector{1,2,3,4}: " << std::endl;
    for (auto i: filterfalse(lessThan3{}, vecInt))
        std::cout << i << " ";   // 3 4
    std::cout << std::endl << "Filter out all even numbers in range(5,9): " << std::endl;
    for (auto i: filterfalse([](int i){return i%2==0;}, range(5,9)))
        std::cout << i << " ";   // 5 7
    std::cout << std::endl << std::endl;


    std::cout << "####  compress:  ####";
    std::vector<bool> ttft {true,true,false,true};

    std::cout << std::endl << "compress a string" << std::endl;
    for (auto i: compress(std::string("abcd"), ttft))
        std::cout << i << " ";  // a b d

    std::cout << std::endl << "compress a range" << std::endl;
    for (auto i: compress(range(5,9), ttft))
        std::cout << i << " ";  // 5 6 8
    std::cout << std::endl << std::endl;
    

    std::cout << std::endl;


    return 0;
}        