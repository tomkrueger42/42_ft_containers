#pragma once

namespace ft {
	//		Exchanges the given values.
	template< class T >
	void	swap( T& a, T& b )
	{
		T	tmp = a;
		a = b;
		b = tmp;
	}
} // namespace ft
