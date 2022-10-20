#pragma once

#include <functional>															// for std::less<>
#include "utility.hpp"

namespace ft {

template<
	class Key,
	class T,
	class Compare = std::less<Key>,
	class Allocator = std::allocator<ft::pair<const Key, T>>
> class map
{
	
}; // class map

} // namespace ft
