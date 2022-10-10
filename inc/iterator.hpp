#pragma once
#include <cstddef>																// for std::ptrdiff_t

namespace ft {
template <
		class Category,
		class T,
		class Distance = std::ptrdiff_t,
		class Pointer = T*,
		class Reference = T&
		> struct iterator
{
	public:
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
}; // struct iterator
} // namespace ft
