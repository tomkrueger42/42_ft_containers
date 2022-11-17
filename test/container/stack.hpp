#ifndef STACK_HPP
# define STACK_HPP

# include "../utils/log_colors.hpp"
# include "vector.hpp"

namespace ft {

	template <class T, class Container = ft::vector<T> >
	class stack {
		public:
			typedef 	T			value_type;
			typedef 	Container	container_type;
			typedef 	size_t		size_type;

		protected:
			container_type	c;

		public:
			explicit stack( const container_type& ctnr = container_type() ) : c(ctnr) {}

			bool				empty() const { return (size() == 0); }

			size_type			size() const { return c.size(); }

			void				push( const value_type& val ) { c.push_back(val); }

			void				pop() { if (size()) {c.pop_back(); } }

			value_type &		top() { return c.back(); }

			const value_type &	top() const { return c.back(); }

			template <class X, class TContainer>
			friend bool	operator==( const stack<X,TContainer>& lhs, const stack<X,TContainer>& rhs );

			template <class X, class TContainer>
			friend bool	operator!=( const stack<X,TContainer>& lhs, const stack<X,TContainer>& rhs );

			template <class X, class TContainer>
			friend bool	operator<( const stack<X,TContainer>& lhs, const stack<X,TContainer>& rhs );

			template <class X, class TContainer>
			friend bool	operator<=( const stack<X,TContainer>& lhs, const stack<X,TContainer>& rhs );

			template <class X, class TContainer>
			friend bool	operator>( const stack<X,TContainer>& lhs, const stack<X,TContainer>& rhs );

			template <class X, class TContainer>
			friend bool	operator>=( const stack<X,TContainer>& lhs, const stack<X,TContainer>& rhs );
	}; /* class stack */

	template <class T, class Container>
	bool	operator==( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
		return (lhs.c == rhs.c);
	}

	template <class T, class Container>
	bool	operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
		return (lhs.c != rhs.c);
	}

	template <class T, class Container>
	bool	operator<( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
		return (lhs.c < rhs.c);
	}

	template <class T, class Container>
	bool	operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
		return (lhs.c <= rhs.c);
	}

	template <class T, class Container>
	bool	operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
		return (lhs.c > rhs.c);
	}

	template <class T, class Container>
	bool	operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
		return (lhs.c >= rhs.c);
	}
} /* namespace ft */

#endif