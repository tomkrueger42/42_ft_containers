#include <iostream>
#include <vector>

#define LOG(msg) std::cout << msg << std::endl
#define LOGN(msg) std::cout << msg << std::endl

int	main(void)
{
	std::vector<int> vec;
	LOGN(vec.front());
	return (0);
}