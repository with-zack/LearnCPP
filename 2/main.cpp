#include <iostream>
#include <vector>
#include <chrono>
#include "prime_numbers_smaller_than_x.hpp"

int main()
{
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	unsigned int x = 0x00FFFFFF;
	std::vector<unsigned int> P = prime_numbers_smaller_than_x(x);
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> span = t2 - t1;
	std::cout << "Took " << span.count() << " ms to find all "<< P.size()<<" prime numbers smaller than or equal to " << x << std::endl;
	/*for (auto i : P)
	{
		std::cout << i << std::endl;
	}*/
}