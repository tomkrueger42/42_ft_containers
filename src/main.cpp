#include "vector_tests.hpp"
// #include "map_tests.hpp"
#include "../inc/stack.hpp"
#include "../inc/set.hpp"
#include "../inc/map.hpp"
#include "../inc/log.hpp"
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
#define NAMESPACE ft
template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
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

#define T1 char
#define T2 float
typedef NAMESPACE::map<T1, T2> _map;
typedef _map::const_iterator const_it;

static unsigned int i = 0;

void	ft_comp(const _map &mp, const const_it &it1, const const_it &it2)
{
	bool res[2];

	std::cout << "\t-- [" << ++i << "] --" << std::endl;
	res[0] = mp.key_comp()(it1->first, it2->first);
	res[1] = mp.value_comp()(*it1, *it2);
	std::cout << "with [" << it1->first << " and " << it2->first << "]: ";
	std::cout << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << std::endl;
}

int		main(void)
{
	_map	mp;

	mp['a'] = 2.3;
	mp['b'] = 1.4;
	mp['c'] = 0.3;
	mp['d'] = 4.2;
	printSize(mp);

	for (const_it it1 = mp.begin(); it1 != mp.end(); ++it1)
		for (const_it it2 = mp.begin(); it2 != mp.end(); ++it2)
			ft_comp(mp, it1, it2);

	printSize(mp);
	return (0);
}
