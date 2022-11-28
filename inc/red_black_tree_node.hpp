#pragma once

#include <memory>
#include "utility.hpp"
#include <iostream>

namespace ft {

	enum COLOR {
		BLACK,
		RED
	};

	template <
		class T
	> class red_black_tree_node
	{
	public:

		typedef T									value_type;
		typedef red_black_tree_node< value_type >	node_type;
		typedef node_type*							node_pointer;
		typedef const node_type*					node_const_pointer;

		node_pointer	parent;
		node_pointer	left;
		node_pointer	right;
		value_type		value_pair;
		COLOR			color;

		red_black_tree_node( void ) : parent(NULL), left(NULL), right(NULL), value_pair(value_type()), color(RED) {}

		red_black_tree_node( const node_type& other )
		{
			*this = other;
		}

		~red_black_tree_node( void ) {}

		node_type&	operator=( const node_type& other )
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
	}; //	class red_black_tree_node

	template< class value_type >
	std::ostream	&operator <<(std::ostream &out, ft::red_black_tree_node< value_type > &n)
	{
		out << "val: " << n.value_pair.first << std::endl;
		if (n.parent != NULL)
			out << "par: " << n.parent->value_pair.first << std::endl;
		else
			out << "par: NULL" << std::endl;
		if (n.left != NULL)
			out << "lef: " << n.left->value_pair.first << std::endl;
		else
			out << "lef: NULL" << std::endl;
		if (n.right != NULL)
			out << "rig: " << n.right->value_pair.first << std::endl;
		else
			out << "rig: NULL" << std::endl;
		out << "col: " << n.color << std::endl;
		return (out);
	}

} //	namespace ft
