#pragma once
#include <iostream>
#include <memory>
#include <stdexcept>

#include "vector_iterator.hpp"
#include "iterator.hpp"
#include "algorithm.hpp"
#include "type_traits.hpp"

#define LOG(msg) std::cout << msg
#define LOGN(msg) std::cout << msg << std::endl;
#define LOGI(...) std::cout << #__VA_ARGS__ << ": " << __VA_ARGS__ << std::endl;

namespace ft {
template < class T, class Allocator = std::allocator<T> >
class vector
{

/* ************************************************************************** */
/*	Member types															  */
/* ************************************************************************** */

	public:
		typedef T												value_type;
		typedef Allocator										allocator_type;
		typedef typename Allocator::size_type					size_type;
		typedef typename Allocator::difference_type				difference_type;
		typedef typename Allocator::reference					reference;
		typedef typename Allocator::const_reference				const_reference;
		typedef typename Allocator::pointer						pointer;
		typedef typename Allocator::const_pointer				const_pointer;
		typedef typename ft::vector_iterator<value_type>		iterator;
		typedef typename ft::vector_iterator<const value_type>	const_iterator;
		// typedef typename ft::reverse_iterator<value_type>		reverse_iterator;
		// typedef typename ft::reverse_iterator<const value_type>	const_reverse_iterator;

	private:
		size_type		_size;
		size_type		_capacity;
		pointer			_ptr;
		allocator_type	_alloc;

	public:

/* ************************************************************************** */
/*	Public member functions													  */
/* ************************************************************************** */

/* =================	Constructors						================= */

		// (1)	Default constructor. Constructs an empty container with a default-constructed allocator.
		vector( void ) : _size(0), _capacity(0), _ptr(NULL)
		{
			LOGN("\033[32mDefault Constructor called for Vector\033[0m");
			this->realloc(0);
		}

		// (2)	Constructs an empty container with the given allocator alloc.
		explicit vector( const Allocator& alloc ) : _size(0), _capacity(0),
													_ptr(NULL), _alloc(alloc)
		{
			LOGN("\033[32mAlloc Constructor called for Vector\033[0m");
			this->realloc(0);
		}

		// (3)	Constructs the container with count copies of elements with value value.
		explicit vector( size_type count, const T& value = T(),
							const Allocator& alloc = Allocator() ) : _size(0), _capacity(0), _ptr(NULL), _alloc(alloc)
		{
			LOGN("\033[32mValue initializer Constructor called for Vector\033[0m");
			this->realloc(count);
			for (size_type i = 0; i < count; i++)
				this->_alloc.construct(&(this->_ptr[i]), value);
			this->_size = count;
		}

		// (5)	Constructs the container with the contents of the range [first, last).
		//		This constructor has the same effect as vector(static_cast<size_type>(first), static_cast<value_type>(last), a) if InputIt is an integral type.
		template < class InputIt >
		vector( InputIt first, InputIt last, const Allocator& alloc = Allocator(),
				 typename ft::enable_if<!ft::is_integral<InputIt>::value, bool>::type = true) : _size(0), _capacity(0), _ptr(NULL), _alloc(alloc)
		{
			LOGN("\033[32mRange Constructor called for Vector\033[0m");
			this->realloc(distance(first, last));
			for (size_type i = 0; first != last; i++, first++)
				this->_alloc.construct(&(this->_ptr[i]), *first);
			this->_size = distance(first, last);
		}

		// (6)	Copy constructor. Constructs the container with the copy of the contents of other.
		vector( const vector& other ) : _size(0), _capacity(0), _ptr(NULL)
		{
			LOGN("\033[32mCopy Constructor called for Vector\033[0m");
			*this = other;
		}

		//		Destructs the vector. The destructors of the elements are called and the used storage is deallocated.
		//		Note, that if the elements are pointers, the pointed-to objects are not destroyed.
		~vector( void )
		{
			LOGN("\033[31mDestructor called for Vector\033[0m");
			this->_alloc.deallocate(this->_ptr, this->_capacity);
		}

		// (1)	Copy assignment operator. Replaces the contents with a copy of the contents of other.
		vector	&operator=( const vector& other )
		{
			LOGN("\033[34mAssignment Operator called for Vector\033[0m");
			if (this != &other)
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.destroy(&(this->_ptr[i]));
				this->_alloc.deallocate(this->_ptr, this->_capacity);
				this->_ptr = this->_alloc.allocate(other._capacity);
				this->_capacity = other._capacity;
				for (size_type i = 0; i < other._size; i++)
					this->_alloc.construct(&(this->_ptr[i]), other._ptr[i]);
				this->_size = other._size;
			}
			return (*this);
		}

		// (1)	Replaces the contents with count copies of value value
		void	assign( size_type count, const T& value )
		{
			reserve(count);
			for (size_type i = 0; i < count; i++)
			{
				this->_alloc.destroy(&(this->_ptr[i]));
				this->_alloc.construct(&(this->_ptr[i]), value);
			}
			this->_size = count;
		}

		// (2)	Replaces the contents with copies of those in the range [first, last). The behavior is undefined if either argument is an iterator into *this. 
		// 		This overload has the same effect as overload (1) if InputIt is an integral type.
		template< class InputIt >
		void	assign( InputIt first, InputIt last,
						typename ft::enable_if<!ft::is_integral<InputIt>::value, bool>::type = true)
		{
			if ((first >= this->begin() && first <= this->end())
				|| (last >= this->begin() && last <= this->end()))
				return ;
			reserve(distance(first, last));
			this->_size = distance(first, last);
			if (this->_size == static_cast<size_type>(-1))						// protection for when first == last
				this->_size = 0;
			for (size_type i = 0; first != last; i++, first++)
			{
				this->_alloc.destroy(&(this->_ptr[i]));
				this->_alloc.construct(&(this->_ptr[i], *first));
			}
		}

		//		Returns the allocator associated with the container.
		allocator_type	get_allocator() const
		{
			return (this->_alloc);
		}


/* =================	Element access						================= */

		//		Returns a reference to the element at specified location pos, with bounds checking.
		//		If pos is not within the range of the container, an exception of type std::out_of_range is thrown.
		reference	at( size_type pos )
		{
			if (pos >= this->_size)
				throw std::out_of_range("pos is out of vector bounds");
			return (this->_ptr[pos]);
		}

		const_reference	at( size_type pos ) const
		{
			if (pos >= this->_size)
				throw std::out_of_range("pos is out of vector bounds");
			return (this->_ptr[pos]);
		}

		//		Returns a reference to the element at specified location pos. No bounds checking is performed.
		T	&operator[]( size_type pos )
		{
			return (this->_ptr[pos]);
		}

		const T	&operator[]( size_type pos ) const
		{
			return (this->_ptr[pos]);
		}

		//		Returns a reference to the first element in the container.
		//		Calling front on an empty container is undefined.
		reference	front()
		{
			return (this->_ptr[0]);
		}

		const_reference	front() const
		{
			return (this->_ptr[0]);
		}

		//		Returns a reference to the last element in the container.
		//		Calling back on an empty container causes undefined behavior.
		reference	back()
		{
			return (this->_ptr[this->_size - 1]);
		}

		const_reference	back() const
		{
			return (this->_ptr[this->_size - 1]);
		}

		//		Returns pointer to the underlying array serving as element storage.
		//		The pointer is such that range [data(); data()+size()) is always a valid range,
		//		even if the container is empty (data() is not dereferenceable in that case).
		T*	data()
		{
			return (this->_ptr);
		}

		const T*	data() const
		{
			return (this->_ptr);
		}


/* =================	Iterators								================= */

		//		Returns an iterator to the first element of the vector.
		//		If the vector is empty, the returned iterator will be equal to end().
		iterator	begin( void )
		{
			return (iterator(this->_ptr));
		}

		const_iterator	begin( void ) const
		{
			return (const_iterator(this->_ptr));
		}

		//		Returns an iterator to the element following the last element of the vector.
		//		This element acts as a placeholder; attempting to access it results in undefined behavior.
		iterator	end( void )
		{
			return (iterator(this->_ptr + this->_size));
		}

		const_iterator	end( void ) const
		{
			return (const_iterator(this->_ptr + this->_size));
		}

		// //		Returns a reverse iterator to the first element of the reversed vector.
		// //		It corresponds to the last element of the non-reversed vector.
		// //		If the vector is empty, the returned iterator is equal to rend().
		// reverse_iterator	rbegin( void )
		// {
		// 	return (ft::reverse_iterator<value_type>(this->end()));
		// }
		
		// const_reverse_iterator	rbegin( void ) const
		// {
		// 	return (ft::reverse_iterator<const value_type>(this->end()));
		// }

		// //		Returns a reverse iterator to the element following the last element of the reversed vector.
		// //		It corresponds to the element preceding the first element of the non-reversed vector.
		// //		This element acts as a placeholder, attempting to access it results in undefined behavior.
		// reverse_iterator	rend( void )
		// {
		// 	return (ft::reverse_iterator<value_type>(this->begin()));
		// }

		// const_reverse_iterator	rend( void ) const
		// {
		// 	return (ft::reverse_iterator<const value_type>(this->begin()));
		// }

		//	Capacity:

		//		Checks if the container has no elements, i.e. whether begin() == end().
		bool	empty( void ) const
		{
			return (this->_size == 0);
		}

		//		Returns the number of elements in the container, i.e. std::distance(begin(), end()).
		size_type	size( void ) const
		{
			return (this->_size);
		}

		//		Returns the maximum number of elements the container is able to hold due to system
		//		or library implementation limitations, i.e. std::distance(begin(), end()) for the largest container.
		size_type	max_size() const
		{
			return (this->_alloc.max_size());
		}

		//		Increase the capacity of the vector to a value that's greater or equal to new_cap.
		//		If new_cap is greater than the current capacity(), new storage is allocated, otherwise the function does nothing.
		void	reserve( size_type newCapacity )
		{
			if (newCapacity > this->_capacity)
				realloc(newCapacity);
		}

		size_t	capacity( void ) const
		{
			return (this->_capacity);
		}


/* =================	Modifiers							================= */

		//		Erases all elements from the container. After this call, size() returns zero.
		void	clear( void )
		{
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.destroy(&(this->_ptr[i]));
			this->_alloc.deallocate(this->_ptr, this->_capacity);
			this->_ptr = this->_alloc.allocate(this->_capacity);
			this->_size = 0;
		}

		//		Inserts elements at the specified location in the container.
		//		(1)	inserts value before pos.
		iterator	insert( iterator pos, const T& value )						// pos needs to be fucking const_iterator!!!
		{
			size_type	position = distance(begin(), pos);
			this->reserve(1);
			if (this->_size == this->_capacity)
				this->realloc(this->_capacity * 2);
			for (size_type i = this->_size; i > position; i--)
				this->_ptr[i] = this->_ptr[i - 1];
			this->_alloc.construct(&(this->_ptr[position]), value);
			++this->_size;
			return (iterator(&(this->_ptr[position])));
		}

		//		(3)	inserts count copies of the value before pos.
		iterator	insert( iterator pos, size_type count, const T& value )		// pos needs to be fucking const_iterator!!!
		{
			size_type	position = distance(begin(), pos);
			this->reserve(this->_size + count);
			for (size_type i = this->_size; i > position; i--)
			{
				this->_ptr[i + count - 1] = this->_ptr[i - 1];
			}
			for (size_type i = 0; i < count; i++)
			{
				this->_alloc.construct(&(this->_ptr[position + i]), value);
				++this->_size;
			}
			return (iterator(&(this->_ptr[position])));
		}

		//		(4)	inserts elements from range [first, last) before pos.
		//		This overload has the same effect as overload (3) if InputIt is an integral type.
		template< class InputIt >
		iterator	insert( iterator pos, InputIt first, InputIt last,			// pos needs to be fucking const_iterator!!!
							typename ft::enable_if<!ft::is_integral<InputIt>::value, bool>::type = true )
		{
			size_type	position = distance(begin(), pos);
			this->reserve(this->_size + distance(first, last));
			for (size_type i = this->_size; i > position; i--)
			{
				this->_ptr[i + distance(first, last) - 1] = this->_ptr[i - 1];
			}
			for ( ; first != last; position++, first++)
			{
				this->_alloc.construct(&(this->_ptr[position]), *first);
				++this->_size;
			}
			return (iterator(&(this->_ptr[position])));
		}

		//		Erases the specified elements from the container.
		//		(1) Removes the element at pos.
		iterator	erase( iterator pos )
		{
			iterator	end = this->end();
			while (pos != end)
			{
				*pos = *(pos + 1);
				++pos;
			}
			this->_size--;
			return (pos);
		}

		//		(2) Removes the elements in the range [first, last).
		iterator	erase( iterator first, iterator last )
		{
			iterator	end = this->end();
			iterator	f	= first;
			while (last <= end)
			{
				*first = *last;
				++first;
				++last;
			}
			this->_size -= (last - first);
			return (f);
		}

		//		Appends the given element value to the end of the container.
		//		The new element is initialized as a copy of value.
		void	push_back( const T& value )
		{
			if (this->_capacity == 0)
				realloc(1);
			if (this->_size >= this->_capacity)
				realloc(_capacity * 2);
			this->_ptr[this->_size] = value;
			this->_size++;
		}

		//		Removes the last element of the container. 
		void	pop_back( void )
		{
			*(this->end() - 1) = *(this->end());
			this->_size--;
		}

		//		Resizes the container to contain count elements. If the current
		//		size is greater than count, the container is reduced to its first count elements.
		//		If the current size is less than count, additional copies of value are appended.
		void	resize( size_type count, T value = T() )
		{
			while (this->_size < count)
			{
				this->push_back(value);
			}
			this->erase(this->begin() + count, this->end());
		}

		//		Exchanges the contents of the container with those of other.
		//		Does not invoke any move, copy, or swap operations on individual elements.
		//		All iterators and references remain valid. The past-the-end iterator is invalidated. 
		void swap( vector& other )
		{
			size_type		tmp_size = this->_size;
			size_type		tmp_capacity = this->_capacity;
			pointer			tmp_ptr = this->_ptr;
			allocator_type	tmp_alloc = this->_alloc;
			this->_size = other._size;
			this->_capacity = other._capacity;
			this->_ptr = other._ptr;
			this->_alloc = other._alloc;
			other._size = tmp_size;
			other._capacity = tmp_capacity;
			other._ptr = tmp_ptr;
			other._alloc = tmp_alloc;
		}

	private:
		void	realloc( size_type newCapacity )
		{
			if (this->max_size() < newCapacity)									// does not increase _capacity to max_size()
				throw std::length_error("maximum capacity has been reached");
			// if (this->_capacity == this->max_size() && newCapacity > this->_capacity)
			// 	throw std::length_error("maximum capacity has been reached");
			// if (newCapacity > this->max_size())
			// 	newCapacity = this->max_size();
			T	*newVector = new T[newCapacity];
			if (newCapacity < this->_size)
				this->_size = newCapacity;
			std::memmove(newVector, _ptr, this->_size * sizeof(T));		// memmove or just plain copying??
			// for (size_type i = 0; i < this->_size; i++)
			// 	NewVector[i] = _ptr[i];
			delete []_ptr;
			_ptr = newVector;
			_capacity = newCapacity;
			LOG("\033[34mrealloc with ");
			LOG(newCapacity);
			LOGN(" memory slots\033[0m");
		}

}; // class Vector

/* ************************************************************************** */
/*	Non-member functions													  */
/* ************************************************************************** */

template< class T, class Alloc >
bool	operator==( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	if (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
		return (true);
	return (false);
}

template< class T, class Alloc >
bool	operator!=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	return (!(lhs == rhs));
}

template< class T, class Alloc >
bool	operator<( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
}

template< class T, class Alloc >
bool	operator<=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	if (lhs == rhs || lhs < rhs)
		return (true);
	return (false);
}

template< class T, class Alloc >
bool	operator>( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template< class T, class Alloc >
bool	operator>=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	if (lhs == rhs || lhs > rhs)
		return (true);
	return (false);
}

//		Specializes the ft::swap algorithm for ft::vector. Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
template< class T, class Alloc >
void	swap( ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs )
{
	lhs.swap(rhs);
}

} // namespace ft
