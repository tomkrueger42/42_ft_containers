#pragma once

#include "log.hpp"

#include "iterator.hpp"
#include "iterator_traits.hpp"

namespace ft {

template < class T_node, class T_node_value, class it >
class red_black_tree_iterator
{

	public:

/* =================	Member types						================= */

		typedef T_node					value_type;
		typedef value_type&				reference;
		typedef value_type*				pointer;
		typedef T_node_value			node_value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, it>::difference_type		difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, it>::iterator_category	iterator_category;


	private:

/* =================	Member objects						================= */

		pointer	_current;


	public:

/* =================	Constructors						================= */

		red_black_tree_iterator( void ) : _current(pointer()) {}								// STL initializes the _current pointer differently but it is not dereferencable

		red_black_tree_iterator( const red_black_tree_iterator &other )
		{
			*this = other;
		}

		// THIS CONSTRUCTOR MIGHT SHOULD BE PRIVATE (MAYBE)
		red_black_tree_iterator( pointer ptr ) : _current(ptr) {}


/* =================	Destructor							================= */

		~red_black_tree_iterator( void ) {}


/* =================	Accessors							================= */

		pointer	base( void ) const
		{
			return (_current);
		}


/* =================	Operator overloads					================= */

		red_black_tree_iterator	&operator=( const red_black_tree_iterator &other )
		{
			if (this != &other)
				this->_current = other._current;
			return (*this);
		}

		node_value_type&	operator*( void )
		{
			return (_current->value_pair);
		}

		node_value_type&	operator*( void ) const
		{
			return (_current->value_pair);
		}

		node_value_type*	operator->( void )
		{
			return (&(_current->value_pair));
		}

		node_value_type*	operator->( void ) const
		{
			return (&(_current->value_pair));
		}

		red_black_tree_iterator	&operator++( void )
		{
			pointer	n = _current;
			// LOG1N("iterator: operator++(void)");
			if (n->right != NULL)												//	minimum of right subtree
			{
				n = n->right;
				while (n->left != NULL)
					n = n->left;
			}
			else if (n->parent != NULL && n->parent->left == _current)					//	left child of parent
			{
				n = n->parent;
			}
			else
			{
				while (n->parent != NULL && n->parent->right == _current)				//	right child of parent
					n = n->parent;
				if (n->parent == NULL)											//	end iterator has already been reached
					return (*this);
				n = n->parent;
			}
			_current = n;
			return (*this);
		}

		red_black_tree_iterator	operator++( int )
		{
			red_black_tree_iterator	tmp(_current);
			++*this;
			return (tmp);
		}

		red_black_tree_iterator	&operator--( void )
		{
			pointer	n = _current;
			if (n->left != NULL)												//	maximum of left subtree
			{
				n = n->left;
				while (n->right != NULL)
					n = n->right;
			}
			else if (n->parent != NULL && n->parent->right == _current)					//	right child of parent
			{
				n = n->parent;
			}
			else
			{
				while (n->parent != NULL && n->parent->left == _current)				//	left child of parent
					n = n->parent;
				if (n->parent == NULL)											//	begin iterator has already been reached
					return (*this);
				n = n->parent;
			}
			_current = n;
			return (*this);
		}

		red_black_tree_iterator	operator--( int )
		{
			red_black_tree_iterator	tmp(_current);
			--(*this);
			return (tmp);
		}

		bool	operator==( const red_black_tree_iterator& other )
		{
			return (base() == other.base());
		}

		bool	operator!=( const red_black_tree_iterator& other)
		{
			return (base() != other.base());
		}
	private:

		//		This constructor overload is priva
};

/* =================	Non-member functions				================= */



/* =================	Operations							================= */

// template < class InputIt, class Distance >
// void	advance( InputIt& it, Distance n )										// is this needed for the bidirectional_iterator??
// {
// 	it += n;
// }

// template < class InputIt >
// typename ft::iterator_traits<InputIt>::difference_type
// 			distance( InputIt first, InputIt last )								// is this needed for the bidirectional_iterator??
// {
// 	typename ft::iterator_traits<InputIt>::difference_type	hops = 0;
// 	for ( ; first > last; --first, --hops)
// 		;
// 	for ( ; first < last; ++first, ++hops)
// 		;
// 	return (hops);
// }

//	Specializes the ft::swap algorithm for ft::vector_iterator. Swaps the contents of lhs and rhs.
// template < class InputIt >
// void	swap( InputIt& lhs, InputIt& rhs )
// {
// 	lhs.swap(rhs);
// }

} // namespace ft
