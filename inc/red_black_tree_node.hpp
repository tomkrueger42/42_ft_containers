#pragma once

#include <memory>
#include "utility.hpp"

namespace ft {

	enum COLOR {
		BLACK,
		RED
	};

	template< 
		class value_type
	> class red_black_tree_node
	{
		public:

			typename red_black_tree_node	node;
			typename node&					reference;
			typename node*					pointer;

			pointer	parent;
			pointer	left;
			pointer	right;
			value_type	value_pair;
			bool		color;

			rb_node( void ) : parent(NULL), left(NULL), right(NULL), value_pair(), color(RED) {}

			rb_node( const value_type& value ) : parent(NULL), left(NULL), right(NULL), value_pair(value), color(RED) {}

			rb_node( const pointer parent, const pointer left, const pointer right, const value_type& value, bool color )
				: parent(parent), left(left), right(right), value_pair(value), color(color) {}

			rb_node( const reference other )
			{
				*this = other;
			}

			~rb_node( void ) {}

			reference	operator=( const reference other )
			{
				if (this != &other )
				{
					parent = other.parent;
					left = other.left;
					right = other.right;
					value_pair = other.value_pair;
					color = other.color;
				}
				return (*this);
			}
	};

/* =================	Non-member functions				================= */

//	Compares the contents of two maps.
template< class value_type >
bool	operator==( const ft::red_black_tree_node< value_type >& lhs,
					const ft::red_black_tree_node< value_type >& rhs )
{
	return (lhs.value_pair == rhs.value_pair);
}

template< class value_type >
bool	operator!=( const ft::red_black_tree_node< value_type >& lhs,
					const ft::red_black_tree_node< value_type >& rhs )
{
	return (!(lhs == rhs));
}

template< class value_type >
bool	operator<( const ft::red_black_tree_node< value_type >& lhs,
					const ft::red_black_tree_node< value_type >& rhs )
{
	return (lhs.value_pair < rhs.value_pair);
}

template< class value_type >
bool	operator<=( const ft::red_black_tree_node< value_type >& lhs,
					const ft::red_black_tree_node< value_type >& rhs )
{
	return (!(rhs < lhs));
}

template< class value_type >
bool	operator>( const ft::red_black_tree_node< value_type >& lhs,
					const ft::red_black_tree_node< value_type >& rhs )
{
	return (rhs < lhs);
}

template< class value_type >
bool	operator>=( const ft::red_black_tree_node< value_type >& lhs,
					const ft::red_black_tree_node< value_type >& rhs )
{
	return (!(lhs < rhs));
}

} //	namespace ft
