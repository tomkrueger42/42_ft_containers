#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "iterator.hpp"

namespace ft {

	template<typename T>
	class vector_iterator {
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
	
		private:
			pointer	_ptr;

		public:
			vector_iterator( pointer ptr = nullptr ) : _ptr(ptr) {}
			vector_iterator( const vector_iterator &in ) : _ptr(in._ptr) {}
			~vector_iterator() {}

			pointer				base() const { return this->_ptr; }

			/* convert non-const to const */
			operator			vector_iterator<const T>() const { return (vector_iterator<const T>(base())); }

			/* references */
			reference			operator*() { return (*_ptr); }
			reference			operator[]( int pos ) { return *(operator+(pos)); }

			/* pointer */ /* when tested type is a class --> access members through iterator */
			pointer				operator->() { return &(operator*()); }

			/* increments */
			vector_iterator &	operator++() { ++this->_ptr; return (*this); }
			vector_iterator		operator++( int ) { vector_iterator	temp(this->_ptr); ++this->_ptr; return (temp); }
			vector_iterator &	operator+=( int offset ) { this->_ptr += offset; return *this; }

			/* decrements */
			vector_iterator &	operator--() { --this->_ptr; return (*this); }
			vector_iterator		operator--( int ) { vector_iterator temp(this->_ptr); --this->_ptr; return (temp); }
			vector_iterator &	operator-=( int offset ) { this->_ptr -= offset; return *this; }

			/* assign */
			vector_iterator &	operator=( const vector_iterator & in ) { this->_ptr = in.base(); return *this; }

			/* addition / subtraction */
			vector_iterator		operator-( int offset ) { return (vector_iterator(_ptr - offset)); }
			vector_iterator		operator+( int offset ) { return (vector_iterator(_ptr + offset)); }
	};
	
	template <class T, class U>
	bool	operator!=( const vector_iterator<T>& lhs, const vector_iterator<U>& rhs ) { return (lhs.base() != rhs.base()); }

	template <class T, class U>
	bool	operator==( const vector_iterator<T>& lhs, const vector_iterator<U>& rhs ) { return (lhs.base() == rhs.base()); }

	template <class T, class U>
	bool	operator<=( const vector_iterator<T>& lhs, const vector_iterator<U>& rhs ) { return (lhs.base() <= rhs.base()); }

	template <class T, class U>
	bool	operator>=( const vector_iterator<T>& lhs, const vector_iterator<U>& rhs ) { return (lhs.base() >= rhs.base()); }

	template <class T, class U>
	bool	operator<( const vector_iterator<T>& lhs, const vector_iterator<U>& rhs ) { return (lhs.base() < rhs.base()); }

	template <class T, class U>
	bool	operator>( const vector_iterator<T>& lhs, const vector_iterator<U>& rhs ) { return (lhs.base() > rhs.base()); }

	template <class T, class U>
	typename ft::vector_iterator<T>::difference_type	operator-( const vector_iterator<T>& lhs, const vector_iterator<U>& rhs ) { return (lhs.base() - rhs.base()); }
	
	template < typename T>
	ft::vector_iterator<T>	operator+( typename ft::vector_iterator<T>::difference_type n, const vector_iterator<T> &in ) { return ft::vector_iterator<T>(in.base() + n); }
	
	template <class Iterator>
	typename ft::iterator_traits<Iterator>::difference_type	difference( Iterator first, Iterator second ) {
		typename ft::iterator_traits<Iterator>::difference_type	diff = 0;
		while (first != second) {
			first++;
			diff++;
		}
		return diff;
	}
}

#endif