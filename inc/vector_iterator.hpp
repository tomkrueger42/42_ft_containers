#pragma once

namespace ft {

template < class it >
class vector_iterator
{
	public:
		typename ft::iterator<ft::random_access_iterator_tag, it>::value_type			value_type;
		typename ft::iterator<ft::random_access_iterator_tag, it>::difference_type		difference_type;
		typename ft::iterator<ft::random_access_iterator_tag, it>::pointer				pointer;
		typename ft::iterator<ft::random_access_iterator_tag, it>::reference			reference;
		typename ft::iterator<ft::random_access_iterator_tag, it>::iterator_category	iterator_category;

	private:
		pointer	_ptr;

	public:
		vector_iterator( void ) : _ptr(nullptr) {}

		vector_iterator( const vector_iterator &vi )
		{
			*this = vi;
		}

		vector_iterator( pointer ptr ) : _ptr(ptr) {}

		~vector_iterator( void ) {}

		vector_iterator	&operator=( const vector_iterator &vi )
		{
			if (this != &vi)
			{
				this->pointer = vi.pointer;
			}
			return (*this);
		}

		pointer	base( void ) const
		{
			return (_ptr);
		}

		reference	operator*( void ) const
		{
			return (*_ptr);
		}

		pointer		operator->(void) const
		{
			return (&(*_ptr));
		}

		reference	operator[]( difference_type dt ) const
		{
			return (*(_ptr + dt));
		}
};

} // namespace ft
