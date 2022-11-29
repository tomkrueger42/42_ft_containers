#include "vector_tests.hpp"
#include "map_tests.hpp"
#include <sys/time.h>

// int		main(void)
// {
// 	struct timeval	tval_start;
// 	struct timeval	tval_end;
// 	gettimeofday(&tval_start, NULL);
	
// 	std::map<int, int> const stdm;
// 	std::map<int, int>::iterator stdit = stdm.begin();
// 	(void)stdit;
// 	// ft::map<int, int> const ftm;
// 	// ft::map<int, int>::iterator ftit = ftm.begin();
// 	// (void)ftit;
	
// 	gettimeofday(&tval_end, NULL);
// 	LOG("Time: ");
// 	LOG((tval_end.tv_sec * 1000000 + tval_end.tv_usec) - (tval_start.tv_sec * 1000000 + tval_start.tv_usec));
// 	LOGN(" usec");
// 	return (0);
// }



#define TESTED_TYPE int

#define T_SIZE_TYPE typename NAMESPACE::vector<T>::size_type

template <typename T>
void	printSize(NAMESPACE::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

void	prepost_incdec(NAMESPACE::vector<TESTED_TYPE> &vct)
{
	NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
	NAMESPACE::vector<TESTED_TYPE>::iterator it_tmp;

	std::cout << "Pre inc" << std::endl;
	it_tmp = ++it;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Pre dec" << std::endl;
	it_tmp = --it;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Post inc" << std::endl;
	it_tmp = it++;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Post dec" << std::endl;
	it_tmp = it--;
	std::cout << *it_tmp << " | " << *it << std::endl;
	std::cout << "###############################################" << std::endl;
}

int		main(void)
{
	const int size = 5;
	NAMESPACE::vector<TESTED_TYPE> vct(size);
	NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
	NAMESPACE::vector<TESTED_TYPE>::const_iterator ite = vct.begin();

	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;
	prepost_incdec(vct);

	it = it + 5;
	it = 1 + it;
	it = it - 4;
	std::cout << *(it += 2) << std::endl;
	std::cout << *(it -= 1) << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

	std::cout << "const_ite +=: " << *(ite += 2) << std::endl;
	std::cout << "const_ite -=: " << *(ite -= 2) << std::endl;

	std::cout << "(it == const_it): " << (ite == it) << std::endl;
	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	printSize(vct, true);
	return (0);
}