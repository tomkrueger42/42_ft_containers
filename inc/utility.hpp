#pragma once

namespace ft {

template< class T1, class T2 >
struct pair
{
	public:
		typedef T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;

			// 		Constructs a new pair.
		// (1)	Default constructor. Value-initializes both elements of the pair, first and second.
		pair( void ) : first(first_type()), second(second_type()) {}

		// (2)	Initializes first with x and second with y.
		pair( const T1& x, const T2& y ) : first(x), second(y) {}

		// (5)	Initializes first with p.first and second with p.second.
		template< class U1, class U2 >
		pair( const pair<U1, U2>& p ) : first(p.first), second(p.second) {}

		// 		Replaces the contents of the pair.
		// (1)	Copy assignment operator. Replaces the contents with a copy of the contents of other.
		pair&	operator=( const pair& other )
		{
			if (this != &other)
			{
				first = other.first;
				second = other.second;
			}
			return (*this);
		}

}; // struct pair

//		Creates an ft::pair object, deducing the target type from the types of arguments.
template< class T1, class T2 >
ft::pair<T1, T2>	make_pair( T1 t, T2 u )
{
	ft::pair<T1, T2>	pair(t, u);
	return (pair);
}

template< class T1, class T2 >
bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
{
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template< class T1, class T2 >
bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
{
	return (!(lhs == rhs));
}

template< class T1, class T2 >
bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
{
	if (lhs.first < rhs.first)
		return (true);
	else if (lhs.first > rhs.first)
		return (false);
	else if (lhs.second < rhs.second)
		return (true);
	else
		return (false);
}

template< class T1, class T2 >
bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
{
	return (!(rhs < lhs));
}

template< class T1, class T2 >
bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
{
	return (rhs < lhs);
}

template< class T1, class T2 >
bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
{
	return (!(lhs < rhs));
}

} // namespace ft
