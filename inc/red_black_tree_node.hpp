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
	> class rb_node
	{
		public:
			rb_node*	parent;
			rb_node*	left;
			rb_node*	right;
			value_type	value_pair;
			bool		color;

			rb_node( void ) : parent(NULL), left(NULL), right(NULL), value_pair(), color(RED) {}

			rb_node( const value_type& value ) : parent(NULL), left(NULL), right(NULL), value_pair(value), color(RED) {}

			rb_node( const rb_node* parent, const rb_node* left, const rb_node* right, const value_type& value, bool color )
				: parent(parent), left(left), right(right), value_pair(value), color(color) {}

			rb_node( const rb_node& other )
			{
				*this = other;
			}

			~rb_node( void ) {}

			rb_node&	operator=( const rb_node& other )
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

} //	namespace ft
