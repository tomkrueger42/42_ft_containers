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
	LOGI(vec.size());
	LOGI(vec.capacity());
	std::cout << "-------------------------" << std::endl;
}

void	insert_test(int overload)
{
	if (overload == 1)
	{
		{
			ft::vector<int>	vec;
			vec.insert(vec.begin(), 3);
			vec.insert(vec.end(), 5);
			printVector(vec);

			ft::vector<int> vec2;
			vec2.insert(vec2.end(), 3);
			vec2.insert(vec2.begin(), 5);
			vec2.insert(vec2.end() - 1, 4);
			printVector(vec2);
		}
	}
	else if (overload == 3)
	{
		{
			ft::vector<int>	vec;
			vec.insert(vec.begin(), 2, 27);
			vec.insert(vec.end(), 2, 29);
			LOGI(vec.insert(vec.begin() + 2, 2, 28).base());
			LOGI(vec.data());
			printVector(vec);
		}
	}
	else if (overload == 4)
	{
		{
			ft::vector<int>	vec(3, 4);
			ft::vector<int>	vec2;
			vec2.insert(vec2.begin(), vec.begin(), vec.end());
			
			ft::vector<int>	vec3(2, 7);
			vec2.insert(vec2.end(), vec3.begin(), vec3.end());
			printVector(vec2);
		}
	}
}

int	main(void)
{
	{
		insert_test(4);
	}
	return (0);
}