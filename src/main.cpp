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
	ft::vector<int>	vec;

	vec.push_back(1);
	vec.push_back(10);
	LOGN(stdvec.size());
	LOGN(stdvec.capacity());
	// vec.push_back(2);
	// for (std::vector<int>::reverse_iterator it = stdvec.rbegin(); it != stdvec.rend(); it++)
	// {
	// 	LOGI(*it);
	// }
	// vec.push_back(3);
	// vec2.assign(4, 6);
	// LOGI(vec2.size());
	// stdvec.assign((int)2, 45);


	// LOGI(vec.front());
	// LOGI(vec.back());
	printVector(vec);
	// system("leaks ft_containers");
	return (0);
}