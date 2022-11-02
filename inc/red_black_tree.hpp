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

/* =================	Member types						================= */

			typedef Allocator												allocator_type;
			typedef rb_node<value_type>										node;
			typedef typename ft::red_black_tree_iterator<node>		iterator;		// they will need to be red_black_tree iterators
			typedef typename ft::red_black_tree_iterator<const node>	const_iterator;
			typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef	node*													node_pointer;


		private:

/* =================	Member objects						================= */

			node_pointer	_root;


		public:

/* =================	Member classes						================= */

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


/* =================	Iterators							================= */

			iterator	begin( void )
			{
				node_pointer	n = _root;
				while (n != NULL && n.left != NULL)
					n = n.left;
				return (n);
			}

			const_iterator	begin( void ) const
			{
				node_pointer	n = _root;
				while (n != NULL && n.left != NULL)
					n = n.left;
				return (n);
			}

			iterator	end( void )
			{
				node_pointer	n = _root;
				while (n != NULL && n.right != NULL)
					n = n.right;
				return (n);
			}

			const_iterator	end( void ) const
			{
				node_pointer	n = _root;
				while (n != NULL && n.right != NULL)
					n = n.right;
				return (n);
			}


/* =================	Modifiers							================= */

			void	clear( void )
			{
				for (iterator it = begin(); it != end(); it++)
					deleteNode(it);
			}

			//	Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
			//	(1) Returns a pair consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool denoting whether the insertion took place.
			ft::pair<map_iterator, bool>	insert( const value_type& value )
			{
				for (node_pointer n = _root; n != NULL; )
				{
					if (n.value_pair.first == value.first)
					{
						return (ft::pair<iterator, bool>(iterator(n), false));
					}
					else if (n.value_pair.first < value.first && n.left == NULL)
					{
						n.left = newNode(value, n)
						return (ft::pair<iterator, bool>(iterator(n.left), true));
					}
					else if (n.value_pair.first < value.first)
					{
						n = n.left;
					}
					else if (n.right == NULL)
					{
						n.right = newNode(value, n);
						return (ft::pair<iterator, bool>(iterator(n.right), true));
					}
					else
					{
						n = n.right;
					}
				}
				_root = newNode(value, NULL);
				return (ft::pair<iterator, bool>(iterator(_root), true));
			}

			void	erase( iterator pos )
			{
				node_pointer	left_sub_tree = pos->left;
				while (left_sub_tree != NULL && left_sub_tree.right != NULL)
					left_sub_tree = left_sub_tree.right;

				if (pos->left == NULL)
				{
					pos->left = pos->right;
				}
				else
				{
					left_sub_tree.right = pos->right;
					if (pos->right != NULL)
						pos->right->parent = left_sub_tree;
				}

				if (pos->parent->left == this)
					pos->parent->left = left;
				else
					pos->parent->right = left;
				if (pos->left != NULL)
					pos->left->parent = parent;

				deleteNode(pos);
			}


/* =================	Lookup								================= */

			//	Finds an element with key equivalent to key.
			iterator	find( const Key& key )
			{
				for (node_pointer n = _root; n != NULL; )
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
				for (node_pointer n = _root; n != NULL; )
				{
					if (n.value_pair.first == key)
						return (const_iterator(n));
					else if (n.value_pair.first < key)
						n = n.left;
					else
						n = n.right;
				}
				return (end());
			}

		private:

			node_pointer	newNode( value_type value_pair, node_pointer parent )
			{
				LOGI(size_type(1));
				node_pointer	n = _alloc.allocate(size_type(1));
				_alloc.construct(n, value_pair);
				n->parent = parent;
				return (n);
			}

			void	deleteNode( iterator it )
			{
				_alloc.destroy(it.base(), size_type(1));
				_alloc.deallocate(it.base(), size_type(1));
			}

	}; //	class red_black_tree

} //	namespace ft
