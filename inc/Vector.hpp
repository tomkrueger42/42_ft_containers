#pragma once
#include <vector>

#define	GROWING_FACTOR 2 // needs to be larger than 1!

namespace ft {
template < class T, class Allocator = std::allocator<T> >
class Vector
{
	public:			// member functions:

		Vector( void ) : _value_type(nullptr), _size_type(0), _capacity(0)
		{
			realloc(2);
		}

		~Vector( void )
		{
			delete []_value_type;
		}

		Vector	&operator=( const vector& other )
		{
			if (this != &other)
			{
				delete []_value_type;							// not sure about wether or not to delete contents of vector that is about to be overwritten
				reserve(other.capacity());				// should I only reserve for capacity items or size items?
				_size_type = other._size_type;
				_capacity = other._capacity;
				for (size_t i = 0; i < _size_type; i++)
				{
					_value_type[i] = other._value_type[i];			// maybe also possible with insert()
				}
			}
			return (*this);
		}

		//		assign()

		void assign( size_type count, const T& value )
		{
			delete []_value_type;
			reserve(count);
			_size_type = count;
			_capacity = count;
			for (size_t i = 0; i < _size_type; i ++)
			{
				_value_type[i] = value;
			}
		}

		template< class InputIt >
		void	assign( InputIt first, InputIt last )
		{
			if ((first >= begin() && first <= end()) || (last >= begin() && last <= end()))
				return ;
			delete []_value_type;
			reserve(last - first);
			_size_type = last - first;
			_capacity = last - first;
			for (size_t i = 0; first != last; first++)
			{
				_size_type[i++] = first;
			}
		}

		allocator_type	get_allocator() const
		{
			return (allocator_type);
		}

		//	Element access:

		reference at( size_type pos )
		{
			if (pos >= _size_type || pos < 0)
			{
				throw std::out_of_range;
			}
			return (&_value_type[pos]);						// do I need to multiply pos with the size of each element??
		}

		const_reference at( size_type pos ) const
		{
			if (pos >= _size_type || pos < 0)
			{
				throw std::out_of_range;
			}
			return (&_value_type[pos]);						// do I need to multiply pos with the size of each element??
		}

		const T	&operator[]( size_t index ) const
		{
			return (_value_type[index]);
		}

		T	&operator[]( size_t index )
		{
			return (_value_type[index]);
		}

		reference front()
		{
			return (*_begin);
		}

		const_reference front() const
		{
			return (*_begin);
		}

		reference back()
		{
			return (*(_end - 1));
		}

		const_reference back() const
		{
			return (*(_end - 1));
		}

		T* data()
		{
			return (_begin);								// is this already a nullpointer when size_type == 0??
		}

		const T* data() const
		{
			return (_begin);								// is this already a nullpointer when size_type == 0??
		}

		//	Iterators:

		//		begin()

		//		end()

		//		rbegin()

		//		rend()

		//	Capacity:

		//		empty()

		size_t	size( void ) const
		{
			return (_size_type);
		}

		//		max_size()

		void reserve( size_type newCapacity )
		{
			if (newCapacity > _capacity)
				realloc(newCapacity);
		}

		size_t	capacity( void ) const
		{
			return (_capacity);
		}

		//	Modifiers:

		//		clear()

		//		insert()

		//		erase()

		void	push_back( const T& value )
		{
			if (_size_type >= _capacity)
				realloc(_capacity * GROWING_FACTOR);
			_value_type[_size_type] = value;
			_size_type++;
		}

		//		pop_back()

		//		resize()

		//		swap()

	private:
		void	realloc( size_t newCapacity )
		{
			T	*NewVector = new T[newCapacity];
			if (newCapacity < _size_type)
				_size_type = newCapacity;
			std::memmove(NewVector, _value_type, _size_type * sizeof(T));		// memmove or just plain copying??
			// for (size_t i = 0; i < _size_type; i++)
			// 	NewVector[i] = _value_type[i];
			delete []_value_type;
			_value_type = NewVector;
			_capacity = newCapacity;
		}

	public:
		typedef Allocator				allocator_type;

	protected:
		typedef T						_value_type;
		// typedef value_type				&reference;
		// typedef const value_type		&const_reference;
		allocator_type::pointer			pointer;
		allocator_type::pointer			iterator;
		allocator_type::const_pointer	const_iterator;

		size_t		_size_type;
		ptrdiff_t	_difference_type;
		T			&reference
		size_t		_capacity;
};
}

//	Non-member functions:

//		operator==()

//		operator!=()

//		operator<()

//		operator<=()

//		operator>()

//		operator>=()

//		std::swap(std::vector)
