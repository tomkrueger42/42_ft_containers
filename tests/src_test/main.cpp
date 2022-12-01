#include "tests.hpp"

#include <iostream>
#include <iomanip>
#include <ctime>

#define XSTR(x) STR(x)
#define STR(x) #x

double  benchmark( void(*test_container)(void) )
{
    std::clock_t begin = std::clock();
    test_container();
    std::clock_t end = std::clock();

    return (double(end - begin) / CLOCKS_PER_SEC);
}

int	main( void )
{
    std::cerr << "Using namespace " << XSTR(NAMESPACE) << std::endl;

    double  duration;

    duration = benchmark(&vector_test);
    std::cerr << "Vector:\t" << std::setprecision(3) << duration << "s" << std::endl;

    duration = benchmark(&stack_test);
    std::cerr << "Stack:\t" << std::setprecision(3) << duration << "s" << std::endl;

    duration = benchmark(&map_test);
    std::cerr << "Map:\t" << std::setprecision(3) << duration << "s" << std::endl;

    duration = benchmark(&set_test);
    std::cerr << "Set:\t" << std::setprecision(3) << duration << "s" << std::endl << std::endl;;

	return (0);
}
