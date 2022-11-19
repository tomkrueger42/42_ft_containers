#pragma once

#include <map>

#include "algorithm.hpp"
#include <functional>															// for std::less<> and maybe also std::binary_function
#include "utility.hpp"
#include "red_black_tree.hpp"
#include "red_black_tree_iterator.hpp"
#include "reverse_iterator.hpp"

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
		typedef ft::pair<const key_type, mapped_type>			value_type;
		typedef Compare											key_compare;
		typedef Allocator										allocator_type;
		typedef typename allocator_type::size_type				size_type;
		typedef typename allocator_type::difference_type		difference_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;


/* =================	Member classes						================= */

		class value_compare : public std::binary_function< value_type, value_type, bool >
		{
			protected:
				key_compare	comp;

			public:
				//	Initializes the internal instance of the comparator to c.
				value_compare( void ) : comp() {}
				value_compare( key_compare c ) : comp(c) {}
				value_compare( const value_compare& other ) : comp(other.comp) {}
				~value_compare( void ) {}

				//	Compares lhs.first and rhs.first by calling the stored comparator.
				bool	operator()( const value_type& lhs, const value_type& rhs ) const
				{
					return (comp(lhs.first, rhs.first));
				}
		};


	private:

		typedef	ft::red_black_tree<Key, T, value_compare>		tree;
		typedef	typename tree::node								node;

	public:

		typedef typename tree::iterator							iterator;
		typedef typename tree::const_iterator					const_iterator;
		typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;


	private:

/* =================	Member objects						================= */

		allocator_type	_alloc;
		tree			_tree;
		key_compare		_comp;


	public:

/* =================	Constructors						================= */

		//	(1) Constructs an empty container.
		map( void ) : _tree(tree()) {}											//	is this one even callable or only the explicit one?

		//	(2) Constructs an empty container.
		explicit map( const key_compare& comp, const allocator_type& alloc = allocator_type() ) : _comp(comp), _alloc(alloc) {}

		//	(4) Constructs the container with the contents of the range [first, last). If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted.
		template< class InputIt >
		map( InputIt first, InputIt last, const key_compare& comp = Compare(), const allocator_type& alloc = allocator_type() ) : _comp(comp), _alloc(alloc)
		{
			insert(first, last);
		}

		//	(6) Copy constructor. Constructs the container with the copy of the contents of other.
		map( const_reference other )
		{
			*this = other;
		}

		//	Destructs the map. The destructors of the elements are called and the used storage is deallocated. Note, that if the elements are pointers, the pointed-to objects are not destroyed.
		~map( void )
		{
			clear();
		}

		//	Copy assignment operator. Replaces the contents with a copy of the contents of other.
		reference	operator=( const_reference other )
		{
			if (this != &other)
			{
				_alloc = other._alloc;
				_comp = other._comp;
				_tree = other._tree;
			}
			return (*this);
		}

		//	Returns the allocator associated with the container.
		allocator_type	get_allocator( void ) const
		{
			return (_alloc);
		}


/* =================	Element access						================= */

		//	Returns a reference to the mapped value of the element with key equivalent to key. If no such element exists, an exception of type std::out_of_range is thrown.
		mapped_type&	at( const key_type& key )
		{
			iterator	it = _tree.find(key);
			if (it == end())
				throw std::out_of_range("map");
			else
				return (it.second);
		}

		//	Returns a reference to the value that is mapped to a key equivalent to key, performing an insertion if such key does not already exist.
		//	More information is on cppreference!!
		mapped_type&	operator[]( const key_type& key )
		{
			return (insert(value_type(key, mapped_type())).first->value_pair.second);
		}


/* =================	Iterators							================= */

		//	Returns an iterator to the first element of the map. If the map is empty, the returned iterator will be equal to end().
		iterator	begin( void )
		{
			return (_tree.begin());
		}

		const_iterator	begin( void ) const
		{
			return (_tree.begin());
		}

		//	Returns an iterator to the element following the last element of the map. This element acts as a placeholder; attempting to access it results in undefined behavior.
		iterator	end( void )
		{
			return (_tree.end());
		}

		const_iterator	end( void ) const
		{
			return (_tree.end());
		}

		//	Returns a reverse iterator to the first element of the reversed map. It corresponds to the last element of the non-reversed map. If the map is empty, the returned iterator is equal to rend().
		reverse_iterator	rbegin( void )
		{
			return (reverse_iterator(end()));
		}

		const_reverse_iterator	rbegin( void ) const
		{
			return (reverse_iterator(end()));
		}

		//	Returns a reverse iterator to the element following the last element of the reversed map. It corresponds to the element preceding the first element of the non-reversed map. This element acts as a placeholder, attempting to access it results in undefined behavior.
		reverse_iterator	rend( void )
		{
			return (reverse_iterator(begin()));
		}

		const_reverse_iterator	rend( void ) const
		{
			return (reverse_iterator(begin()));
		}


/* =================	Capacity							================= */

		//	Checks if the container has no elements.
		bool	empty( void ) const
		{
			return (_size == 0);
		}

		//	Returns the number of elements in the container.
		size_type	size( void ) const
		{
			return (_tree.size());
		}

		//	Returns the maximum number of elements the container is able to hold due to system or library implementation limitations.
		size_type	max_size( void ) const
		{
			return (_tree.max_size());
		}


/* =================	Modifiers							================= */

		//	Erases all elements from the container. After this call, size() returns zero.
		void	clear( void )
		{
			_tree.clear();
		}

		//	Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
		//	(1) Inserts value.
		ft::pair<iterator, bool>	insert( const value_type& value )
		{
			return (_tree->insert(value, NULL));
		}

		//	Inserts value in the position as close as possible to the position just prior to pos.
		iterator	insert( iterator pos, const value_type& value )
		{
			return (_tree->insert(value, pos.base()).first);
		}

		//	(7) Inserts elements from range [first, last). If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted.
		template< class InputIt >
		void	insert( InputIt first, InputIt last )
		{
			for ( ; first != last; first++)
			{
				_tree.insert(*first, NULL); // what happens if one insert() fails??
			}
		}

		//	(1) Removes the element at pos.
		void	erase( iterator pos )
		{
			_tree.erase(pos);
		}

		//	(2) Removes the elements in the range [first; last), which must be a valid range in *this.
		void	erase( iterator first, iterator last )
		{
			for ( ; first != last; first++)
				_tree.erase(first);
		}

		//	(3) Removes the element (if one exists) with the key equivalent to key.
		size_type	erase( const key_type& key )
		{
			iterator	it = find(key);
			if (it == end())
				return (0);
			_tree.erase(it);
			return (1);
		}

		//	Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on individual elements.
		void	swap( reference other )
		{
			allocator_type	tmp_alloc = _alloc;
			tree			tmp_tree = _tree;
			key_compare		tmp_comp = _comp;

			_alloc = other._alloc;
			_tree = other._tree;
			_comp = other._comp;

			other._alloc = tmp_alloc;
			other._tree = tmp_tree;
			other._comp = tmp_comp;
		}


/* =================	Lookup								================= */

		//	(1) Returns the number of elements with key key. This is either 1 or 0 since this container does not allow duplicates.
		size_type	count( const key_type& key ) const
		{
			return (find(key) != end());
		}

		//	Finds an element with key equivalent to key.
		iterator	find( const key_type& key )
		{
			return (_tree.find(key));
		}
		
		const_iterator	find( const key_type& key ) const
		{
			return (_tree.find(key));
		}

		//	Returns a range containing all elements with the given key in the container. The range is defined by two iterators, one pointing to the first element that is not less than key and another pointing to the first element greater than key. Alternatively, the first iterator may be obtained with lower_bound(), and the second with upper_bound().
		ft::pair<iterator, iterator>	equal_range( const key_type& key )
		{
			return (ft::pair<iterator, iterator>(lower_bound(key), upper_bound(key)));
		}
		
		ft::pair<const_iterator, const_iterator>	equal_range( const key_type& key ) const
		{
			return (ft::pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key)));
		}

		//	Returns an iterator pointing to the first element that is not less than (i.e. greater or equal to) key.
		iterator	lower_bound( const key_type& key )
		{
			return (_tree->find(key));
		}

		const_iterator	lower_bound( const key_type& key ) const
		{
			return (_tree->find(key));
		}

		//	Returns an iterator pointing to the first element that is greater than key.
		iterator	upper_bound( const key_type& key )
		{
			return (++_tree->find(key));
		}

		const_iterator	upper_bound( const key_type& key ) const
		{
			return (++_tree->find(key));
		}


/* =================	Observers							================= */

		//	Returns the function object that compares the keys, which is a copy of this container's constructor argument comp.
		key_compare	key_comp() const
		{
			return (_comp);
		}

		//	Returns a function object that compares objects of type ft::map::value_type (key-value pairs) by using key_comp to compare the first components of the pairs.
		value_compare	value_comp() const
		{
			return (value_compare(_comp));
		}

}; // class map


/* =================	Non-member functions				================= */

//	Compares the contents of two maps.
template< class Key, class T, class Compare, class Alloc >
bool	operator==( const ft::map< Key, T, Compare, Alloc >& lhs,
					const ft::map< Key, T, Compare, Alloc >& rhs )
{
	return (lhs.size() == rhs.size()
			&& ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template< class Key, class T, class Compare, class Alloc >
bool	operator!=( const ft::map< Key, T, Compare, Alloc >& lhs,
					const ft::map< Key, T, Compare, Alloc >& rhs )
{
	return (!(lhs == rhs));
}

template< class Key, class T, class Compare, class Alloc >
bool	operator<( const ft::map< Key, T, Compare, Alloc >& lhs,
					const ft::map< Key, T, Compare, Alloc >& rhs )
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(),
										rhs.begin(), rhs.end()));
}

template< class Key, class T, class Compare, class Alloc >
bool	operator<=( const ft::map< Key, T, Compare, Alloc >& lhs,
					const ft::map< Key, T, Compare, Alloc >& rhs )
{
	return (!(rhs < lhs));
}

template< class Key, class T, class Compare, class Alloc >
bool	operator>( const ft::map< Key, T, Compare, Alloc >& lhs,
					const ft::map< Key, T, Compare, Alloc >& rhs )
{
	return (rhs < lhs);
}

template< class Key, class T, class Compare, class Alloc >
bool	operator>=( const ft::map< Key, T, Compare, Alloc >& lhs,
					const ft::map< Key, T, Compare, Alloc >& rhs )
{
	return (!(lhs < rhs));
}

//	Specializes the ft::swap algorithm for ft::map. Swaps the contents of lhs and rhs.
template< class Key, class T, class Compare, class Alloc >
void	swap( ft::map< Key, T, Compare, Alloc >& lhs,
				ft::map< Key, T, Compare, Alloc >& rhs )
{
	lhs.swap(rhs);
}

} // namespace ft
