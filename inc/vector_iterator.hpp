#pragma once
#include "iterator.hpp"

namespace ft {

template < class T >
class vector_iterator
{
public:
	typedef typename ft::iterator<ft::random_access_iterator_tag, T >::value_type			value_type;
	typedef typename ft::iterator<ft::random_access_iterator_tag, T >::difference_type		difference_type;
	typedef typename ft::iterator<ft::random_access_iterator_tag, T >::reference			reference;
	typedef typename ft::iterator<ft::random_access_iterator_tag, T >::pointer				pointer;
	typedef typename ft::iterator<ft::random_access_iterator_tag, T >::iterator_category	iterator_category;

private:
	pointer	_current;

public:

/* =================	Constructors						================= */

	vector_iterator( pointer ptr = NULL ) : _current(ptr) {}

	vector_iterator( const vector_iterator &other )
	{
		*this = other;
	}
	
/* =================	Destructor							================= */

	~vector_iterator( void ) {}

/* =================	Accessors							================= */

	pointer	base( void ) const
	{
		return (_current);
	}

	/* =================	Operator overloads					================= */

	operator	vector_iterator< const T >( void ) const
	{
		return (vector_iterator< const T >(_current));
	}

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
};

/* =================	Operations							================= */

template< typename T >
bool	operator==(const vector_iterator< T >& lhs, const vector_iterator< T >& rhs)
{
	return (lhs.base() == rhs.base());
}

template< typename T1, typename T2 >
bool	operator==(const vector_iterator< T1 >& lhs, const vector_iterator< T2 >& rhs)
{
	return (lhs.base() == rhs.base());
}

template< typename T >
bool	operator!=(const vector_iterator< T >& lhs, const vector_iterator< T >& rhs)
{
	return (!(lhs == rhs));
}

template< typename T1, typename T2 >
bool	operator!=(const vector_iterator< T1 >& lhs, const vector_iterator< T2 >& rhs)
{
	return (!(lhs == rhs));
}

template< typename T >
bool	operator<(const vector_iterator< T >& lhs, const vector_iterator< T >& rhs)
{
	return (lhs.base() < rhs.base());
}

template< typename T1, typename T2 >
bool	operator<(const vector_iterator< T1 >& lhs, const vector_iterator< T2 >& rhs)
{
	return (lhs.base() < rhs.base());
}

template< typename T >
bool	operator<=(const vector_iterator< T >& lhs, const vector_iterator< T >& rhs)
{
	return (!(rhs < lhs));
}

template< typename T1, typename T2 >
bool	operator<=(const vector_iterator< T1 >& lhs, const vector_iterator< T2 >& rhs)
{
	return (!(rhs < lhs));
}

template< typename T >
bool	operator>(const vector_iterator< T >& lhs, const vector_iterator< T >& rhs)
{
	return (rhs < lhs);
}

template< typename T1, typename T2 >
bool	operator>(const vector_iterator< T1 >& lhs, const vector_iterator< T2 >& rhs)
{
	return (rhs < lhs);
}

template< typename T >
bool	operator>=(const vector_iterator< T >& lhs, const vector_iterator< T >& rhs)
{
	return (!(lhs < rhs));
}

template< typename T1, typename T2 >
bool	operator>=(const vector_iterator< T1 >& lhs, const vector_iterator< T2 >& rhs)
{
	return (!(lhs < rhs));
}

template< typename T >
vector_iterator< T >	operator+(const typename vector_iterator< T >::difference_type& i, const vector_iterator< T >& iter)
{
	return (vector_iterator< T >(iter.base() + i));
}

template< typename T >
vector_iterator< T >	operator-(const typename vector_iterator< T >::difference_type& i, const vector_iterator< T >& iter)
{
	return (vector_iterator< T >(iter.base() - i));
}

template< typename T >
typename vector_iterator< T >::difference_type	operator+(const vector_iterator< T >& rhs, const vector_iterator< T >& lhs)
{
	return (rhs.base() + lhs.base());
}

template< typename T >
typename vector_iterator< T >::difference_type	operator-(const vector_iterator< T >& rhs, const vector_iterator< T >& lhs)
{
	return (rhs.base() - lhs.base());
}

template< typename T1, typename T2 >
typename vector_iterator< T1 >::difference_type	operator+(const vector_iterator< T1 >& rhs, const vector_iterator< T2 >& lhs)
{
	return (rhs.base() + lhs.base());
}

template< typename T1, typename T2 >
typename vector_iterator< T1 >::difference_type	operator-(const vector_iterator< T1 >& rhs, const vector_iterator< T2 >& lhs)
{
	return (rhs.base() - lhs.base());
}

} // namespace ft
