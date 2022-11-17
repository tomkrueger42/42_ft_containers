#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft {

	template<typename Iterator>
	class reverse_iterator {
		public:
			typedef typename Iterator::iterator_category		iterator_category;
			typedef typename Iterator::value_type				value_type;
			typedef typename Iterator::pointer					pointer;
			typedef typename Iterator::reference				reference;
			typedef typename Iterator::difference_type			difference_type;

		private:
			Iterator	_it;

		public:
			reverse_iterator() : _it() {}
			explicit reverse_iterator( Iterator it ) : _it(it) {}
			template<class Iter>
			reverse_iterator( const reverse_iterator<Iter> &in ) : _it(in.base()) {}
			~reverse_iterator() {}

			Iterator			base() const { return this->_it; }

			/* references */
			reference			operator*() { Iterator temp(_it); --temp; return (*temp); } 
			reference			operator[]( int pos ) { return *(operator+(pos)); }

			/* pointer */ /* when tested type is a class --> access members through iterator */
			pointer				operator->() { Iterator temp(_it); --temp; return temp.operator->(); }

			/* increments */
			reverse_iterator &	operator++() { --_it; return (*this); }
			reverse_iterator	operator++(int) { reverse_iterator	temp(*this); --_it; return (temp); }
			reverse_iterator &	operator+=( int offset ) { _it -= offset; return (*this); }

			/* decrements */
			reverse_iterator &	operator--() { ++_it; return (*this); }
			reverse_iterator	operator--(int) { reverse_iterator	temp(*this); ++_it; return (temp); }
			reverse_iterator &	operator-=( int offset ) { _it += offset; return (*this); }

			/* assign */
			template<class Iter>
			reverse_iterator &	operator=( const reverse_iterator<Iter> & in ) { _it = in.base(); return (*this); }

			/* addition */
			reverse_iterator	operator+( int offset ) { return reverse_iterator(_it - offset); }
	};

	template <class T, class U>
	bool	operator!=( const reverse_iterator<T>& lhs, const reverse_iterator<U>& rhs ) { return (lhs.base() != rhs.base()); }

	template <class T, class U>
	bool	operator==( const reverse_iterator<T>& lhs, const reverse_iterator<U>& rhs ) { return (lhs.base() == rhs.base()); }

	template <class T, class U>
	bool	operator<=( const reverse_iterator<T>& lhs, const reverse_iterator<U>& rhs ) { return (lhs.base() >= rhs.base()); }

	template <class T, class U>
	bool	operator>=( const reverse_iterator<T>& lhs, const reverse_iterator<U>& rhs ) { return (lhs.base() <= rhs.base()); }

	template <class T, class U>
	bool	operator<( const reverse_iterator<T>& lhs, const reverse_iterator<U>& rhs ) { return (lhs.base() > rhs.base()); }

	template <class T, class U>
	bool	operator>( const reverse_iterator<T>& lhs, const reverse_iterator<U>& rhs ) { return (lhs.base() < rhs.base()); }

	template < class T, class U >
	typename ft::reverse_iterator<T>::difference_type	operator-( const ft::reverse_iterator<T>& first, const ft::reverse_iterator<U>& second )
	{
		return (second.base() - first.base());
	}

	template < class T >
	ft::reverse_iterator<T>	operator-( const ft::reverse_iterator<T>& rit, const typename ft::reverse_iterator<T>::difference_type offset )
	{
		return ft::reverse_iterator<T>(rit.base() + offset);
	}

	template < class T>
	ft::reverse_iterator<T>	operator+( const typename ft::reverse_iterator<T>::difference_type offset, const ft::reverse_iterator<T>& rit )
	{
		return ft::reverse_iterator<T>(rit.base() - offset);
	}
}

#endif