#ifndef INCLUDES_HPP
# define INCLUDES_HPP

#include <iostream>

#ifdef USING_STD
	#define TESTED_NAMESPACE std
	#include <vector>
	#include <set>
	#include <map>
	#include <stack>
#else
	#define TESTED_NAMESPACE ft
	#include "../container/vector.hpp"
	#include "../container/map.hpp"
	#include "../container/stack.hpp"
	#include "../container/set.hpp"
#endif

template <typename T>
void	printVectorContent( TESTED_NAMESPACE::vector<T> & vector ) {
	std::cout << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~ START vector" << std::endl;
	typename TESTED_NAMESPACE::vector<T>::iterator	it;
	for (it = vector.begin(); it != vector.end(); it++)
		std::cout << (*it) << std::endl;
	std::cout << "----- size: " << vector.size() << " -----" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ END vector" << std::endl;
	std::cout << std::endl;
}

#endif