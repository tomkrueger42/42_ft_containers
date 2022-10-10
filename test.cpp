#include <iostream>
#include <vector>

#define LOG(msg) std::cout << msg << std::endl
#define LOGN(msg) std::cout << msg << std::endl

int	main(void)
{
	std::vector<int> vec;
	std::vector<int> vec2;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.swap(vec2);
	LOGN(vec.size());
	LOGN(vec.capacity());
	LOGN(vec2.size());
	LOGN(vec2.capacity());
	return (0);
}