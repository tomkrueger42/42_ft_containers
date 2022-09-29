#pragma once
#include <vector>

#define	GROWTH_FACTOR 2															// needs to be larger than 1!

namespace ft {
template < class T, class Allocator = std::allocator<T> >
class vector
{
	public:		// Member functions:

		vector( void ) : _ptr(nullptr), _size(0), _capacity(0)					// Default constructor. Constructs an empty container with a default-constructed allocator.
		{
			
		}

		explicit vector( const Allocator& alloc )								// Constructs an empty container with the given allocator alloc.
		{

		}

		explicit vector( size_type count, const T& value = T(),
							const Allocator& alloc = Allocator())				// Constructs the container with count copies of elements with value value.
		{

		}

		template < class InputIt >
		vector( InputIt first, InputIt last,
				const Allocator& alloc = Allocator() )							// Constructs the container with the contents of the range [first, last).
		{

		}

		vector( const vector& other )											// Copy constructor. Constructs the container with the copy of the contents of other.
		{

		}

		~vector( void )
		{
			delete []_value_type;
		}

		vector	&operator=( const vector& other )
		{
			if (this != &other)
			{
				delete []_value_type;											// not sure about wether or not to delete contents of vector that is about to be overwritten
				reserve(other.capacity());										// should I only reserve for capacity items or size items?
				_size_type = other._size_type;
				_capacity = other._capacity;
				for (size_t i = 0; i < _size_type; i++)
				{
					_value_type[i] = other._value_type[i];						// maybe also possible with insert()
				}
			}
			return (*this);
		}

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
			if ((first >= begin() && first <= end())
				|| (last >= begin() && last <= end()))
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
			return (&_value_type[pos]);											// do I need to multiply pos with the size of each element??
		}

		const_reference at( size_type pos ) const
		{
			if (pos >= _size_type || pos < 0)
			{
				throw std::out_of_range;
			}
			return (&_value_type[pos]);											// do I need to multiply pos with the size of each element??
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
			return (_begin);													// is this already a nullpointer when size_type == 0??
		}

		const T* data() const
		{
			return (_begin);													// is this already a nullpointer when size_type == 0??
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
			T	*newVector = new T[newCapacity]; // malloc protection??
			if (newCapacity < _size_type)
				_size_type = newCapacity;
			std::memmove(newVector, _value_type, _size_type * sizeof(T));		// memmove or just plain copying??
			// for (size_t i = 0; i < _size_type; i++)
			// 	NewVector[i] = _value_type[i];
			delete []_value_type;
			_value_type = newVector;
			_capacity = newCapacity;
		}

	public:
		typedef T										value_type;
		typedef Allocator								allocator_type;
		typedef size_t									size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef Allocator::pointer						pointer;
		typedef Allocator::const_pointer				const_pointer;
		typedef ft::vector_iterator<value_type>			iterator;
		typedef ft::vector_iterator<const value_type>	const_iterator;
		// typedef ft::reverse_iterator<value_type>		reverse_iterator;		// reverse_iterator is still missing
		// typedef ft::reverse_iterator<const value_type>	const_reverse_iterator;

	private:
		size_type		_size;
		size_type		_capacity;												// is this also in STL??
		pointer			_ptr;													// not needed so far
		allocator_type	_alloc;

}; // class Vector

//	Non-member functions:

//		operator==()

//		operator!=()

//		operator<()

//		operator<=()

//		operator>()

//		operator>=()

//		std::swap(std::vector)

} // namespace ft
