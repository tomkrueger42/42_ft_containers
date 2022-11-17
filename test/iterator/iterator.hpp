#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include "iterator_traits.hpp"

namespace ft {

	template<typename Category, typename T, typename Difference = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
	struct iterator {
		typedef T			value_type;
		typedef Difference	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

}

#endif