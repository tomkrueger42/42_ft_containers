#pragma once

namespace ft {
	//		Returns true if the range [first1, last1) is equal to the range
	//		[first2, first2 + (last1 - first1)), and false otherwise.
	template< class InputIt1, class InputIt2 >
	bool	equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 )
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!(*first1 == *first2)) {
				return false;
			}
		}
		return true;
	}

	template< class InputIt1, class InputIt2, class BinaryPredicate >
	bool	equal( InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p )
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!p(*first1, *first2)) {
				return false;
			}
		}
		return true;
	}
} // namespace ft
