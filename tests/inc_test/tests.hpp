#pragma once

#include "map.hpp"
#include "set.hpp"
#include "stack.hpp"
#include "vector.hpp"

#include <iostream>

#ifdef USING_STD
	#define NAMESPACE std
#else
	#define NAMESPACE ft
#endif

#define PRINT_SEPERATOR()                                                                          \
    std::cout << "\n#############################################################################" \
              << "############\n"

#define PRINT_TEST_FUNC() \
    std::cout << "file: " << __FILE__ << "\nfunction: " << __PRETTY_FUNCTION__ << "\n"

void    vector_test( void );
void    stack_test( void );
void    map_test( void );
void    set_test( void );
