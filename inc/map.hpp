#pragma once

#include <map>

#include <functional>															// for std::less<> and maybe also std::binary_function
#include "utility.hpp"
#include "map_iterator.hpp"

namespace ft {

template<
	class Key,
	class T,
	class Compare = std::less< Key >,
	class Allocator = std::allocator< ft::pair< const Key, T > >
> class map
{

	public:

/* =================	Member types						================= */

		typedef Key												key_type;
		typedef T												mapped_type;
		typedef ft::pair<const Key, T>							value_type;
		typedef typename Allocator::size_type					size_type;
		typedef typename Allocator::difference_type				difference_type;
		typedef Compare											key_compare;
		typedef Allocator										allocator_type;
		typedef typename Allocator::reference					reference;
		typedef typename Allocator::const_reference				const_reference;
		typedef typename Allocator::pointer						pointer;
		typedef typename Allocator::const_pointer				const_pointer;
		typedef typename ft::map_iterator<value_type>			iterator;		// they will need to be rb_tree iterators
		typedef typename ft::map_iterator<const value_type>		const_iterator;
		typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;


	private:

/* =================	Member objects						================= */

		Allocator	_alloc;
		rb_tree		*_root;
		size_type	_size;


	public:

/* =================	Member classes						================= */

		class value_compare : public std::binary_function< value_type, value_type, bool >
		{
			protected:
				Compare	comp;

				//	Initializes the internal instance of the comparator to c.
				value_compare( Compare c ) : comp(c) {}

			public:
				//	Compares lhs.first and rhs.first by calling the stored comparator.
				bool	operator()( const value_type& lhs, const value_type& rhs ) const
				{
					return (comp(lhs.first, rhs.first));
				}
		}


/* =================	Constructors						================= */

		//	(1) Constructs an empty container.
		map( void );

		//	(2) Constructs an empty container.
		explicit map( const Compare& comp, const Allocator& alloc = Allocator() );

		//	(4) Constructs the container with the contents of the range [first, last). If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted.
		template< class InputIt >
		map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );

		//	(6) Copy constructor. Constructs the container with the copy of the contents of other.
		map( const map& other );

		//	Destructs the map. The destructors of the elements are called and the used storage is deallocated. Note, that if the elements are pointers, the pointed-to objects are not destroyed.
		~map( void );

		//	Copy assignment operator. Replaces the contents with a copy of the contents of other.
		map&	operator=( const map& other );

		//	Returns the allocator associated with the container.
		allocator_type	get_allocator( void ) const
		{
			return (this->_alloc);
		}


/* =================	Element access						================= */

		//	Returns a reference to the mapped value of the element with key equivalent to key. If no such element exists, an exception of type std::out_of_range is thrown.
		T&	at( const Key& key );

		//	Returns a reference to the value that is mapped to a key equivalent to key, performing an insertion if such key does not already exist.
		//	More information is on cppreference!!
		T&	operator[]( const Key& key );


/* =================	Iterators							================= */

		//	Returns an iterator to the first element of the map. If the map is empty, the returned iterator will be equal to end().
		iterator	begin( void );

		iterator	begin( void ) const;

		//	Returns an iterator to the element following the last element of the map. This element acts as a placeholder; attempting to access it results in undefined behavior.
		iterator	end( void );

		iterator	end( void ) const;

		//	Returns a reverse iterator to the first element of the reversed map. It corresponds to the last element of the non-reversed map. If the map is empty, the returned iterator is equal to rend().
		reverse_iterator	rbegin( void );

		reverse_iterator	rbegin( void ) const;

		//	Returns a reverse iterator to the element following the last element of the reversed map. It corresponds to the element preceding the first element of the non-reversed map. This element acts as a placeholder, attempting to access it results in undefined behavior.
		reverse_iterator	rend( void );

		reverse_iterator	rend( void ) const;


/* =================	Capacity							================= */

		//	Checks if the container has no elements.
		bool	empty( void ) const
		{
			return (this->begin() == this->end());
		}

		//	Returns the number of elements in the container.
		size_type	size( void ) const
		{
			ft::distance(this->begin(), this->end());
		}

		//	Returns the maximum number of elements the container is able to hold due to system or library implementation limitations.
		size_type	max_size( void ) const
		{
			return (this->_alloc.max_size());
		}


/* =================	Modifiers							================= */

		//	Erases all elements from the container. After this call, size() returns zero.
		void	clear( void );

		//	Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
		//	(1) Inserts value.
		ft::pair<iterator, bool>	insert( const value_type& value );

		//	Inserts value in the position as close as possible to the position just prior to pos.
		iterator	insert( iterator pos, const value_type& value );

		//	(1) Removes the element at pos.
		iterator	erase( iterator pos );

		//	(2) Removes the elements in the range [first; last), which must be a valid range in *this.
		iterator	erase( iterator first, iterator last );

		//	Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on individual elements.
		void	swap( map& other );


/* =================	Lookup								================= */

		//	(1) Returns the number of elements with key key. This is either 1 or 0 since this container does not allow duplicates.
		size_type	count( const Key& key ) const;

		//	Finds an element with key equivalent to key.
		iterator	find( const Key& key );
		
		const_iterator	find( const Key& key ) const;

		//	Returns a range containing all elements with the given key in the container. The range is defined by two iterators, one pointing to the first element that is not less than key and another pointing to the first element greater than key. Alternatively, the first iterator may be obtained with lower_bound(), and the second with upper_bound().
		ft::pair<iterator,iterator>	equal_range( const Key& key );
		
		ft::pair<const_iterator,const_iterator>	equal_range( const Key& key ) const;

		//	Returns an iterator pointing to the first element that is not less than (i.e. greater or equal to) key.
		iterator	lower_bound( const Key& key );

		const_iterator	lower_bound( const Key& key ) const;

		//	Returns an iterator pointing to the first element that is greater than key.
		iterator	upper_bound( const Key& key );

		const_iterator	upper_bound( const Key& key ) const;


/* =================	Observers							================= */

		//	Returns the function object that compares the keys, which is a copy of this container's constructor argument comp.
		key_compare	key_comp() const;

		//	Returns a function object that compares objects of type ft::map::value_type (key-value pairs) by using key_comp to compare the first components of the pairs.
		ft::map::value_compare	value_comp() const;

}; // class map

/* =================	Non-member functions				================= */

//	Compares the contents of two maps.
template< class Key, class T, class Compare, class Alloc >
bool	operator==( const ft::map< Key, T, Compare, Alloc >& lhs,
					const ft::map< Key, T, Compare, Alloc >& rhs );

template< class Key, class T, class Compare, class Alloc >
bool	operator!=( const ft::map< Key, T, Compare, Alloc >& lhs,
					const ft::map< Key, T, Compare, Alloc >& rhs );

template< class Key, class T, class Compare, class Alloc >
bool	operator<( const ft::map< Key, T, Compare, Alloc >& lhs,
					const ft::map< Key, T, Compare, Alloc >& rhs );

template< class Key, class T, class Compare, class Alloc >
bool	operator<=( const ft::map< Key, T, Compare, Alloc >& lhs,
					const ft::map< Key, T, Compare, Alloc >& rhs );

template< class Key, class T, class Compare, class Alloc >
bool	operator>( const ft::map< Key, T, Compare, Alloc >& lhs,
					const ft::map< Key, T, Compare, Alloc >& rhs );

template< class Key, class T, class Compare, class Alloc >
bool	operator>=( const ft::map< Key, T, Compare, Alloc >& lhs,
					const ft::map< Key, T, Compare, Alloc >& rhs );

//	Specializes the ft::swap algorithm for ft::map. Swaps the contents of lhs and rhs.
template< class Key, class T, class Compare, class Alloc >
void	swap( ft::map< Key, T, Compare, Alloc >& lhs,
				ft::map< Key, T, Compare, Alloc >& rhs )
{
	lhs.swap(rhs);
}

} // namespace ft
