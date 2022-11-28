#include "vector_tests.hpp"
#include "map_tests.hpp"
#include <sys/time.h>

int		main(void)
{
	struct timeval	tval_start;
	struct timeval	tval_end;
	gettimeofday(&tval_start, NULL);
	
	std::map<int, int> const stdm;
	std::map<int, int>::iterator stdit = stdm.begin();
	(void)stdit;
	// ft::map<int, int> const ftm;
	// ft::map<int, int>::iterator ftit = ftm.begin();
	// (void)ftit;
	
	gettimeofday(&tval_end, NULL);
	LOG("Time: ");
	LOG((tval_end.tv_sec * 1000000 + tval_end.tv_usec) - (tval_start.tv_sec * 1000000 + tval_start.tv_usec));
	LOGN(" usec");
	return (0);
}
