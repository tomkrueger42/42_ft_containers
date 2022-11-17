#ifndef ENABLE_IF
# define ENABLE_IF

namespace ft {
	/* passed condition gets evaluated to either true or false */
	template <bool Cond>
	struct enable_if {};

	/* if the ft::enable_if<Cond> is true, type exists --> function gets executed */
	/* else --> type doesnt exists --> other function gets executed, or error if nop matching function is found */
	template <>
	struct enable_if<true> { typedef int type; };

	/* classes are false, any integrals are true */
	template <class T>
	struct is_integral { static const bool value = false; };

	template <>
	struct is_integral<bool> { static const bool value = true; };

	template <>
	struct is_integral<char> { static const bool value = true; };

	template <>
	struct is_integral<unsigned char> { static const bool value = true; };

	template <>
	struct is_integral<int> { static const bool value = true; };

	template <>
	struct is_integral<unsigned int> { static const bool value = true; };

	template <>
	struct is_integral<long> { static const bool value = true; };

	template <>
	struct is_integral<long long> { static const bool value = true; };

	template <>
	struct is_integral<unsigned long> { static const bool value = true; };

	template <>
	struct is_integral<unsigned long long> { static const bool value = true; };
}

#endif