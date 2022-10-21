#pragma once

#include "iterator.hpp"
#include "iterator_traits.hpp"

namespace ft {

template < class it >
class vector_iterator
{
	public:
		typedef typename ft::iterator<ft::random_access_iterator_tag, it>::value_type			value_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, it>::difference_type		difference_type;
		typedef typename ft::iterator<ft::random_access_iterator_tag, it>::reference			reference;
		typedef typename ft::iterator<ft::random_access_iterator_tag, it>::pointer				pointer;
		typedef typename ft::iterator<ft::random_access_iterator_tag, it>::iterator_category	iterator_category;

	private:
		pointer	_current;

	public:

/* =================	Constructors						================= */

		vector_iterator( void ) : _current(pointer()) {}								// STL initializes the _current pointer differently but it is not dereferencable

		vector_iterator( const vector_iterator &other )
		{
			*this = other;
		}

		// THIS CONSTRUCTOR SHOULD BE PRIVATE!!1!
		vector_iterator( pointer ptr ) : _current(ptr) {}

/* =================	Destructor							================= */

		~vector_iterator( void ) {}


/* =================	Accessors							================= */

		pointer	base( void ) const
		{
			return (_current);
		}

/* =================	Operator overloads					================= */

		vector_iterator	&operator=( const vector_iterator &other )
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

		reference	operator[]( difference_type n ) const
		{
			return (*(_current + n));
		}

		vector_iterator	&operator++( void )
		{
			++_current;
			return (*this);
		}

		vector_iterator	operator++( int )
		{
			vector_iterator	tmp(_current);
			++_current;
			return (tmp);
		}

		vector_iterator	&operator+=( difference_type n )
		{
			_current += n;
			return (*this);
		}

		vector_iterator	&operator--( void )
		{
			--_current;
			return (*this);
		}

		vector_iterator	operator--( int )
		{
			vector_iterator	tmp(_current);
			--_current;
			return (tmp);
		}

		vector_iterator	&operator-=( difference_type n )
		{
			_current -= n;
			return (*this);
		}
		
		vector_iterator	operator+( difference_type n ) const
		{
			return (vector_iterator(_current + n));
		}
		
		vector_iterator	operator-( difference_type n ) const
		{
			return (vector_iterator(_current - n));
		}

		void	swap( vector_iterator& other )
		{
			pointer	tmp = this->_current;
			this->_current = other._current;
			other._current = tmp;
		}

	private:

		//		This constructor overload is priva
};

/* ************************************************************************** */
/*	Non-member functions													  */
/* ************************************************************************** */

template < class It1, class It2 >
bool	operator==( const ft::vector_iterator<It1> &lhs,
					const ft::vector_iterator<It2> &rhs )
{
	return (lhs.base() == rhs.base());
}

template < class It1, class It2 >
bool	operator!=( const ft::vector_iterator<It1> &lhs,
					const ft::vector_iterator<It2> &rhs )
{
	return (!(lhs == rhs));
}

template < class It1, class It2 >
bool	operator<( const ft::vector_iterator<It1> &lhs,
					const ft::vector_iterator<It2> &rhs )
{
	return (lhs.base() < rhs.base());
}

template < class It1, class It2 >
bool	operator<=( const ft::vector_iterator<It1> &lhs,
					const ft::vector_iterator<It2> &rhs )
{
	return (!(rhs < lhs));
}

template < class It1, class It2 >
bool	operator>( const ft::vector_iterator<It1> &lhs,
					const ft::vector_iterator<It2> &rhs )
{
	return (rhs > lhs);
}

template < class It1, class It2 >
bool	operator>=( const ft::vector_iterator<It1> &lhs,
					const ft::vector_iterator<It2> &rhs )
{
	return (!(lhs < rhs));
}

template < class It >
vector_iterator<It>	operator+( typename vector_iterator<It>::difference_type n,
								const vector_iterator<It>& it )
{
	return (vector_iterator<It>(it.base() + n));
}

template < class It >
typename vector_iterator<It>::difference_type
	operator-( const vector_iterator<It>& lhs, const vector_iterator<It>& rhs )
{
	return (lhs.base() - rhs.base());
}

/* =================	Operations							================= */

template < class InputIt, class Distance >
void	advance( InputIt& it, Distance n )
{
	it += n;
}

template < class InputIt >
typename ft::iterator_traits<InputIt>::difference_type
			distance( InputIt first, InputIt last )
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
