#pragma once

#include "log.hpp"
#include "iterator.hpp"

namespace ft {

template <
	class T_node,
	class T_value
> class red_black_tree_iterator
{

public:

/* =================	Member types						================= */

	typedef T_node							node_pointer;
	typedef T_value							value_type;
	typedef value_type&						reference;
	typedef const value_type&				const_reference;
	typedef value_type*						pointer;
	typedef const value_type*				const_pointer;
	typedef std::ptrdiff_t					difference_type;
	typedef ft::bidirectional_iterator_tag	iterator_category;


private:

/* =================	Member objects						================= */

	node_pointer	_current;


public:

/* =================	Constructors / Destructor			================= */

	red_black_tree_iterator( const node_pointer& ptr = NULL ) : _current(ptr) {}

	template< typename NodePtr2, typename T2 >
	red_black_tree_iterator( const red_black_tree_iterator< NodePtr2, T2 >& rhs )
							: _current(rhs.base()) {}

	//	const to non-const constructor
	operator red_black_tree_iterator< const node_pointer, const T_value >() const
	{
		return (_current);
	}

	~red_black_tree_iterator( void ) {}


/* =================	Accessors							================= */

	node_pointer	base( void ) const
	{
		return (_current);
	}


/* =================	Operator overloads					================= */

	template< typename NodePtr2, typename T2 >
	red_black_tree_iterator	&operator=( const red_black_tree_iterator< NodePtr2, T2 >& other )
	{
		this->_current = other.base();
		return (*this);
	}

	reference	operator*( void )
	{
		return (_current->value_pair);
	}

	reference	operator*( void ) const
	{
		return (_current->value_pair);
	}

	pointer	operator->( void )
	{
		return (&(_current->value_pair));
	}

	pointer	operator->( void ) const
	{
		return (&(_current->value_pair));
	}

	red_black_tree_iterator	&operator++( void )
	{
		node_pointer	n = _current;

		if (n->right != NULL)												//	minimum of right subtree
		{
			n = n->right;
			while (n->left != NULL)
				n = n->left;
		}
		else if (n->parent != NULL && n->parent->left == _current)			//	left child of parent
		{
			n = n->parent;
		}
		else
		{
			while (n->parent != NULL && n->parent->right == n)				//	right child of parent
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
		node_pointer	n = _current;
		if (n->left != NULL)												//	maximum of left subtree
		{
			n = n->left;
			while (n->right != NULL)
				n = n->right;
		}
		else if (n->parent != NULL && n->parent->right == _current)			//	right child of parent
		{
			n = n->parent;
		}
		else
		{
			while (n->parent != NULL && n->parent->left == n)				//	left child of parent
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
};

/* =================	Non-member functions				================= */

template< typename NodePtr, typename T >
bool	operator==( const red_black_tree_iterator< NodePtr, T >& lhs,
					const red_black_tree_iterator< NodePtr, T >& rhs )
{
	return (lhs.base() == rhs.base());
}

template< typename NodePtr1, typename T1, typename NodePtr2, typename T2 >
bool	operator==( const red_black_tree_iterator< NodePtr1, T1 >& lhs,
					const red_black_tree_iterator< NodePtr2, T2 >& rhs )
{
	return (lhs.base() == rhs.base());
}

template< typename NodePtr, typename T >
bool	operator!=( const red_black_tree_iterator< NodePtr, T >& lhs,
					const red_black_tree_iterator< NodePtr, T >& rhs )
{
	return (lhs.base() != rhs.base());
}

template< typename NodePtr1, typename T1, typename NodePtr2, typename T2 >
bool	operator!=( const red_black_tree_iterator< NodePtr1, T1 >& lhs,
					const red_black_tree_iterator< NodePtr2, T2 >& rhs )
{
	return (lhs.base() != rhs.base());
}

} // namespace ft
