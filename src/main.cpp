#include "vector.hpp"
#include <iostream>

// #define LOG(msg) std::cout << msg
// #define LOGN(msg) std::cout << msg << std::endl

template<typename T>
void	printVector(const T& vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << std::endl;
	}
	std::cout << "-------------------------" << std::endl;
}

int	main(void)
{
	ft::vector<int>	vec;

	// vec.push_back(2);
	// LOGN(vec.size());
	// LOGN(vec.capacity());
	// LOGN(vec.max_size());
	// LOGN(vec.empty());
	LOGN(vec.front());
	// LOGN(vec.back());
	printVector(vec);

	return (0);
}