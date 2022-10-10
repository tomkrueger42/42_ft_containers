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
		typedef typename ft::iterator<ft::random_access_iterator_tag, it>::pointer				pointer;
		typedef typename ft::iterator<ft::random_access_iterator_tag, it>::reference			reference;
		typedef typename ft::iterator<ft::random_access_iterator_tag, it>::iterator_category	iterator_category;

	private:
		pointer	_ptr;

	public:

		/* constructors */

		vector_iterator( void ) : _ptr(nullptr) {}

		vector_iterator( const vector_iterator &vi )
		{
			*this = vi;
		}

		vector_iterator( pointer ptr ) : _ptr(ptr) {}

		/* destructors */

		~vector_iterator( void ) {}

		vector_iterator	&operator=( const vector_iterator &vi )
		{
			if (this != &vi)
			{
				this->_ptr = vi._ptr;
			}
			return (*this);
		}

		pointer	base( void ) const
		{
			return (_ptr);
		}

		reference	operator*( void ) const
		{
			return (*_ptr);
		}

		pointer			operator->( void ) const
		{
			return (&(*_ptr));
		}

		reference	operator[]( difference_type n ) const					// does this need to return the reference or a new iterator at position n??
		{
			return (*(_ptr + n));
		}

		vector_iterator	&operator++( void )
		{
			_ptr++;
			return (*this);
		}

		vector_iterator	operator++( int )
		{
			vector_iterator	tmp(_ptr);
			_ptr++;
			return (tmp);
		}

		vector_iterator	&operator+=( difference_type n )
		{
			_ptr += n;
			return (*this);
		}

		vector_iterator	&operator--( void )
		{
			--_ptr;
			return (*this);
		}

		vector_iterator	operator--( int )
		{
			vector_iterator	tmp(_ptr);
			--_ptr;
			return (tmp);
		}

		vector_iterator	&operator-=( difference_type n )
		{
			_ptr -= n;
			return (*this);
		}
		
		vector_iterator	operator+( difference_type n ) const
		{
			return (vector_iterator(_ptr + n));
		}
		
		vector_iterator	operator-( difference_type n ) const
		{
			return (vector_iterator(_ptr - n));
		}
};

// Non-member operators

template < class It1, class It2 >
bool	operator==( ft::vector_iterator<It1> &lhs,
					ft::vector_iterator<It2> &rhs )
{
	if (lhs.base() == rhs.base())
		return (true);
	return (false);
}
 
template < class It1, class It2 >
bool	operator!=( ft::vector_iterator<It1> &lhs,
					ft::vector_iterator<It2> &rhs )
{
	if (lhs.base() != rhs.base())
		return (true);
	return (false);
}

template < class It1, class It2 >
bool	operator<( ft::vector_iterator<It1> &lhs,
					ft::vector_iterator<It2> &rhs )
{
	if (lhs.base() < rhs.base())
		return (true);
	return (false);
}

template < class It1, class It2 >
bool	operator<=( ft::vector_iterator<It1> &lhs,
					ft::vector_iterator<It2> &rhs )
{
	if (lhs.base() <= rhs.base())
		return (true);
	return (false);
}

template < class It1, class It2 >
bool	operator>( ft::vector_iterator<It1> &lhs,
					ft::vector_iterator<It2> &rhs )
{
	if (lhs.base() > rhs.base())
		return (true);
	return (false);
}

template < class It1, class It2 >
bool	operator>=( ft::vector_iterator<It1> &lhs,
					ft::vector_iterator<It2> &rhs )
{
	if (lhs.base() >= rhs.base())
		return (true);
	return (false);
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
	return (rhs.base() - lhs.base());
}

// Operations

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
	while (first < last)														// first can only be greater than last for random_access_iterators in c++11 and later
	{
		++hops;
		++first;
	}
	return (hops);
}

} // namespace ft
