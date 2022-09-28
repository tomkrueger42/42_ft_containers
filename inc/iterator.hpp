#pragma once
#include <iterator>
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
		typedef typename Category	iterator_category;
		typedef typename T			value_type;
		typedef typename Distance	difference_type;
		typedef typename Pointer	pointer;
		typedef typename Reference	reference;
}; // struct Iterator
} // namespace ft
