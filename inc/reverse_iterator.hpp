#pragma once

#include "iterator_traits.hpp"

namespace ft {

template< class Iter >
class reverse_iterator
{

/* ************************************************************************** */
/*	Member types															  */
/* ************************************************************************** */

	public:
		typedef Iter													iterator_type;
		typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type			value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer				pointer;
		typedef typename ft::iterator_traits<Iter>::reference			reference;
	
	private:
		iterator_type	_current;


/* ************************************************************************** */
/*	Public member functions													  */
/* ************************************************************************** */

	public:

/* =================	Constructors						================= */

		//		Constructs a new iterator adaptor.
		// (1)	Default constructor. The underlying iterator is value-initialized.
		//		Operations on the resulting iterator have defined behavior if and only if
		//		the corresponding operations on a value-initialized Iter also have defined behavior.
		reverse_iterator()
		{
			this->_current = /* iterator_type() */ NULL;
		}

		// (2)	The underlying iterator is initialized with x.
		explicit reverse_iterator( iterator_type x )
		{
			this->_current = x;
		}

		// (3)	The underlying iterator is initialized with that of other.
		template< class U >
		reverse_iterator( const reverse_iterator<U>& other )
		{
			*this = other;
		}

		//		The underlying iterator is assigned the value of the underlying
		//		iterator of other, i.e. other.base().
		template< class U >
		reverse_iterator&	operator=( const reverse_iterator<U>& other )
		{
			*this->_current = other.base();
			return (*this);
		}

		//		Returns the underlying base iterator. That is ft::reverse_iterator(it).base() == it.
		iterator_type	base() const
		{
			return (this->_current);
		}

/* =================	Operator overloads					================= */

		//		Returns a reference or pointer to the element previous to current.
		// (1)	Equivalent to Iter tmp = current; return *--tmp;
		reference	operator*() const
		{
			return (*(this->_current - 1));
		}

		// (2) Equivalent to return std::addressof(operator*());
		pointer	operator->() const
		{
			return (&(operator*()));
		}

		//		Returns a reference to the element at specified relative location.
		reference	operator[]( difference_type n ) const
		{
			return (base()[- n - 1]);
		}

		//		Increments or decrements the iterator. Inverse operations are
		//		applied to the underlying operator because of the reverse order.
		reverse_iterator&	operator++()
		{
			--this->_current;
			return (*this);
		}

		reverse_iterator&	operator--()
		{
			++this->_current;
			return (*this);
		}

		reverse_iterator	operator++( int )
		{
			reverse_iterator	tmp(*this);
			--this->_current;
			return (tmp);
		}

		reverse_iterator operator--( int )
		{
			reverse_iterator	tmp(*this);
			++this->_current;
			return (tmp);
		}

		reverse_iterator operator+( difference_type n ) const
		{
			return (reverse_iterator(this->base() - n));
		}

		reverse_iterator operator-( difference_type n ) const
		{
			return (reverse_iterator(this->base() + n));
		}

		reverse_iterator& operator+=( difference_type n )
		{
			this->_current -= n;
			return (*this);
		}

		reverse_iterator& operator-=( difference_type n )
		{
			this->_current += n;
			return (*this);
		}
};

/* ************************************************************************** */
/*	Non-member functions													  */
/* ************************************************************************** */

//		Compares the underlying iterators. Inverse comparisons are applied
//		in order to take into account that the iterator order is reversed.
template< class Iterator1, class Iterator2 >
bool operator==( const ft::reverse_iterator<Iterator1>& lhs,
				 const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() == rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator!=( const ft::reverse_iterator<Iterator1>& lhs,
				 const ft::reverse_iterator<Iterator2>& rhs )
{
	return (!(lhs == rhs));
}

template< class Iterator1, class Iterator2 >
bool operator<( const ft::reverse_iterator<Iterator1>& lhs,
				const ft::reverse_iterator<Iterator2>& rhs )
{
	return (lhs.base() > rhs.base());
}

template< class Iterator1, class Iterator2 >
bool operator<=( const ft::reverse_iterator<Iterator1>& lhs,
				 const ft::reverse_iterator<Iterator2>& rhs )
{
	return (!(rhs < lhs));
}

template< class Iterator1, class Iterator2 >
bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
				const ft::reverse_iterator<Iterator2>& rhs )
{
	return (rhs < lhs);
}

template< class Iterator1, class Iterator2 >
bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
				 const ft::reverse_iterator<Iterator2>& rhs )
{
	return (!(lhs < rhs));
}

//		Returns the iterator it incremented by n.
template< class Iter >
reverse_iterator<Iter>
	operator+( typename reverse_iterator<Iter>::difference_type n,
				const reverse_iterator<Iter>& it )
{
	return (reverse_iterator<Iter>(it.base() - n));
}

//		Returns the distance between two iterator adaptors.
template< class Iterator >
typename reverse_iterator<Iterator>::difference_type
	operator-( const reverse_iterator<Iterator>& lhs,
				const reverse_iterator<Iterator>& rhs )
{
	return (rhs.base() - lhs.base());
}

} // namespace ft
