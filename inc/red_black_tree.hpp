#pragma once

#include <memory>
#include "red_black_tree_node.hpp"
#include "red_black_tree_iterator.hpp"
#include "reverse_iterator.hpp"
#include "utility.hpp"

namespace ft {

	template< 
		class Key,
		class T,
		class value_type = ft::pair< const Key, T >,
		class Allocator = std::allocator< value_type >
	> class rb_tree
	{
		public:
			typedef Allocator												allocator_type;
			typedef rb_node<value_type>										node;
			typedef typename ft::red_black_tree_iterator<value_type>		iterator;		// they will need to be rb_tree iterators
			typedef typename ft::red_black_tree_iterator<const value_type>	const_iterator;
			typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		
		
		private:
			node*	_root;

		public:
			rb_tree( void ) : _root(NULL) {}

			rb_tree( const rb_tree& other ) : _root(NULL)
			{
				*this = other;
			}

			~rb_tree( void ) {}

			rb_tree&	operator=( const rb_tree& other )
			{
				if (this != &other)
				{
					_root = other._root;
				}
			}

			//	Finds an element with key equivalent to key.
			iterator	find( const Key& key )
			{
				for (iterator it = _root; n != NULL; )
				{
					if (n.value_pair.first == key)
						return (iterator(n));
					else if (n.value_pair.first < key)
						n = n.left;
					else
						n = n.right;
				}
				return (end());
			}

			const_iterator find( const Key& key ) const
			{
				for (node n = _root; n != NULL; )
				{
					if (n.value_pair.first == key)
						return (iterator(n));
					else if (n.value_pair.first < key)
						n = n.left;
					else
						n = n.right;
				}
				return (end());
			}

			ft::pair<map_iterator, bool>	insert( const T& value )
			{
				if (find())
			}


	}; //	class rb_tree

} //	namespace ft
