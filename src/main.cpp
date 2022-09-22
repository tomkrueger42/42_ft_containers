#include "Vector.hpp"
#include <iostream>

#define LOG(msg) std::cout << msg
#define LOGN(msg) std::cout << msg << std::endl

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
	ft::Vector<int>	vec;

	vec.push_back(12);
	vec.push_back(13);
	vec.push_back(14);
	printVector(vec);

	return (0);
}