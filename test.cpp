#include <iostream>
#include <vector>

#define LOG(msg) std::cout << msg << std::endl
#define LOGN(msg) std::cout << msg << std::endl

int	main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(1);
	LOGN(vec.capacity());
	return (0);
}