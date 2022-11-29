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


template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
{
	std::cout << (first < second) << std::endl;
	std::cout << (first <= second) << std::endl;
	std::cout << (first > second) << std::endl;
	std::cout << (first >= second) << std::endl;
	if (redo)
		ft_eq_ope(second, first, 0);
}

int		main(void)
{
	const int size = 5;
	NAMESPACE::vector<int> vct(size);
	NAMESPACE::vector<int>::reverse_iterator it_0(vct.rbegin());
	NAMESPACE::vector<int>::reverse_iterator it_1(vct.rend());
	NAMESPACE::vector<int>::reverse_iterator it_mid;

	NAMESPACE::vector<int>::const_reverse_iterator cit_0 = vct.rbegin();
	NAMESPACE::vector<int>::const_reverse_iterator cit_1;
	NAMESPACE::vector<int>::const_reverse_iterator cit_mid;

	for (int i = size; it_0 != it_1; --i)
		*it_0++ = i;
	printSize(vct, 1);
	it_0 = vct.rbegin();
	cit_1 = vct.rend();
	it_mid = it_0 + 3;
	cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;

	std::cout << std::boolalpha;
	std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

	std::cout << "\t\tft_eq_ope:" << std::endl;
	// regular it
	ft_eq_ope(it_0 + 3, it_mid);
	std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << std::endl;
	ft_eq_ope(it_0, it_1);
	ft_eq_ope(it_1 - 3, it_mid);
	// const it
	ft_eq_ope(cit_0 + 3, cit_mid);
	ft_eq_ope(cit_0, cit_1);
	ft_eq_ope(cit_1 - 3, cit_mid);
	// both it
	ft_eq_ope(it_0 + 3, cit_mid);
	ft_eq_ope(it_mid, cit_0 + 3);
	ft_eq_ope(it_0, cit_1);
	ft_eq_ope(it_1, cit_0);
	ft_eq_ope(it_1 - 3, cit_mid);
	ft_eq_ope(it_mid, cit_1 - 3);

	return (0);
}
