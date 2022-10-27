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
	> class red_black_tree
	{
		public:
			typedef Allocator												allocator_type;
			typedef rb_node<value_type>										node;
			typedef typename ft::red_black_tree_iterator<value_type>		iterator;		// they will need to be red_black_tree iterators
			typedef typename ft::red_black_tree_iterator<const value_type>	const_iterator;
			typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		
		
		private:
			node*	_root;

		public:
			red_black_tree( void ) : _root(NULL) {}

			red_black_tree( const red_black_tree& other ) : _root(NULL)
			{
				*this = other;
			}

			~red_black_tree( void ) {}

			red_black_tree&	operator=( const red_black_tree& other )
			{
				if (this != &other)
				{
					_root = other._root;
				}
			}

			//	Finds an element with key equivalent to key.
			iterator	find( const Key& key )
			{
				for (node *n = _root; n != NULL; )
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
				for (node *n = _root; n != NULL; )
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

			//	Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
			//	(1) Returns a pair consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool denoting whether the insertion took place.
			ft::pair<map_iterator, bool>	insert( const T& value )
			{
				return (_insert(_root, value));
			}


		private:

			ft::pair<map_iterator, bool>	_insert( node *root, const T& value )
			{
				if (root == NULL)
				{
					return ()
				}
			}


	}; //	class red_black_tree

} //	namespace ft
