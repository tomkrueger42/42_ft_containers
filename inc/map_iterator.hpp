#pragma once

#include "iterator.hpp"
#include "iterator_traits.hpp"

namespace ft {

template < class it >
class map_iterator
{

	public:

/* =================	Member types						================= */

		typedef typename ft::iterator<ft::bidirectional_iterator_tag, it>::value_type			value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, it>::difference_type		difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, it>::reference			reference;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, it>::pointer				pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, it>::iterator_category	iterator_category;


	private:

/* =================	Member objects						================= */

		pointer	_current;


	public:

/* =================	Constructors						================= */

		map_iterator( void ) : _current(pointer()) {}								// STL initializes the _current pointer differently but it is not dereferencable

		map_iterator( const map_iterator &other )
		{
			*this = other;
		}

		// THIS CONSTRUCTOR MIGHT SHOULD BE PRIVATE (MAYBE)
		map_iterator( pointer ptr ) : _current(ptr) {}


/* =================	Destructor							================= */

		~map_iterator( void ) {}


/* =================	Accessors							================= */

		pointer	base( void ) const
		{
			return (_current);
		}


/* =================	Operator overloads					================= */

		map_iterator	&operator=( const map_iterator &other )
		{
			if (this != &other)
				this->_current = other._current;
			return (*this);
		}

		reference	operator*( void ) const
		{
			return (*_current);
		}

		pointer	operator->( void ) const
		{
			return (&(*_current));
		}

		reference	operator[]( difference_type n ) const						// is this needed for the bidirectional_iterator??
		{
			return (*(_current + n));
		}

		map_iterator	&operator++( void )
		{
			++_current;
			return (*this);
		}

		map_iterator	operator++( int )
		{
			map_iterator	tmp(_current);
			++_current;
			return (tmp);
		}

		map_iterator	&operator--( void )
		{
			--_current;
			return (*this);
		}

		map_iterator	operator--( int )
		{
			map_iterator	tmp(_current);
			--_current;
			return (tmp);
		}

	private:

		//		This constructor overload is priva
};

/* =================	Non-member functions				================= */


template < class It1, class It2 >
bool	operator==( const ft::map_iterator<It1> &lhs,
					const ft::map_iterator<It2> &rhs )
{
	return (lhs.base() == rhs.base());
}

template < class It1, class It2 >
bool	operator!=( const ft::map_iterator<It1> &lhs,
					const ft::map_iterator<It2> &rhs )
{
	return (!(lhs == rhs));
}

/* =================	Operations							================= */

template < class InputIt, class Distance >
void	advance( InputIt& it, Distance n )										// is this needed for the bidirectional_iterator??
{
	it += n;
}

template < class InputIt >
typename ft::iterator_traits<InputIt>::difference_type
			distance( InputIt first, InputIt last )								// is this needed for the bidirectional_iterator??
{
	typename ft::iterator_traits<InputIt>::difference_type	hops = 0;
	for ( ; first > last; --first, --hops)
		;
	for ( ; first < last; ++first, ++hops)
		;
	return (hops);
}

//	Specializes the ft::swap algorithm for ft::vector_iterator. Swaps the contents of lhs and rhs.
template < class InputIt >
void	swap( InputIt& lhs, InputIt& rhs )
{
	lhs.swap(rhs);
}

} // namespace ft
