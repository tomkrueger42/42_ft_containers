#include "vector_tests.hpp"
#include "map_tests.hpp"
#include "stack.hpp"
#include "set.hpp"
#include "map.hpp"
#include "log.hpp"
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
// #define NAMESPACE ft
#include <list>
#include <set>
template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "value: " << *iterator;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}
#define T1 std::string

static int iter = 0;

template <typename SET, typename U>
void	ft_erase(SET &st, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	st.erase(param);
	printSize(st);
}

template <typename SET, typename U, typename V>
void	ft_erase(SET &st, U param, V param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	st.erase(param, param2);
	printSize(st);
}

int		main(void)
{
	std::list<T1> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(std::string((lst_size - i), i + 65));
	TESTED_NAMESPACE::set<T1> st(lst.begin(), lst.end());
	printSize(st);

	ft_erase(st, ++st.begin());

	ft_erase(st, st.begin());
	ft_erase(st, --st.end());

	ft_erase(st, st.begin(), ++(++(++st.begin())));
	ft_erase(st, --(--(--st.end())), --st.end());

	st.insert("Hello");
	st.insert("Hi there");
	printSize(st);
	ft_erase(st, --(--(--st.end())), st.end());

	st.insert("ONE");
	st.insert("TWO");
	st.insert("THREE");
	st.insert("FOUR");
	printSize(st);
	ft_erase(st, st.begin(), st.end());

	return (0);
}