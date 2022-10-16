#include "vector.hpp"
#include <vector>
#include <iostream>

// #define LOG(msg) std::cout << msg
// #define LOGN(msg) std::cout << msg << std::endl

template<typename T>
void	printVector(const T& vec)
{
	for (typename T::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		LOGI(*it);
	}
	std::cout << "-------------------------" << std::endl;
}

int	main(void)
{
	{
		ft::vector<int> vec;

		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		ft::vector<int> vec2;

		vec2.assign(vec.begin(), vec.end());
		printVector(vec2);
		LOGI(vec.max_size());
	}
	{
		std::vector<int> vec;

		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		std::vector<int> vec2;

		vec2.assign(vec.begin(), vec.end());
		printVector(vec2);
		LOGI(vec.max_size());
	}
	return (0);
}