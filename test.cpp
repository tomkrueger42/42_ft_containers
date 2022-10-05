#include <iostream>
#include <vector>

#define LOG(msg) std::cout << msg << std::endl
#define LOGN(msg) std::cout << msg << std::endl

int	main(void)
{
	std::vector<int> vec;
	LOGN(vec.max_size());
	LOGN(std::numeric_limits<difference_type>::max());
	return (0);
}