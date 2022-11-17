#ifndef PAIR_HPP
# define PAIR_HPP

# include <memory>

namespace ft {

	template <class T1, class T2>
	struct pair {
		public:
			typedef T1	first_type;
			typedef T2	second_type;

		private:
			typedef std::allocator<first_type>	alloctor_first;
			typedef std::allocator<second_type>	alloctor_second;

			alloctor_first	_alloc_first;
			alloctor_second	_alloc_second;

		public:
			first_type	first;
			second_type	second;

			/* default */
			pair() : first(), second() {}

			/* copy */
			template<class U, class V>
			pair( const pair<U, V>& pr) : first(pr.first), second(pr.second) {}

			/* initialization */
			pair( const first_type& a, const second_type& b ) : first(a), second(b) {}

			/* destructor */
			~pair() {}

			/* assign */
			pair &	operator=( const pair& pr ) {
				_alloc_first.construct(&this->first, pr.first);
				_alloc_second.construct(&this->second, pr.second);
				return *this;
			}
	};

	template <class T1, class T2>
	ft::pair<T1, T2>	make_pair( T1 x, T2 y ) {
		return	ft::pair<T1, T2>(x, y);
	}

	template <class T1, class T2>
	bool	operator==( ft::pair<T1, T2> lhs, ft::pair<T1, T2> rhs ) {
		return ((lhs.first == rhs.first) && (lhs.second == rhs.second));
	}

	template <class T1, class T2>
	bool	operator!=( ft::pair<T1, T2> lhs, ft::pair<T1, T2> rhs ) {
		return (!(lhs == rhs));
	}

	template <class T1, class T2>
	bool operator<( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <class T1, class T2>
	bool operator<=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		return (rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) {
		return !(lhs < rhs);
	}
} /* namespace ft */

#endif