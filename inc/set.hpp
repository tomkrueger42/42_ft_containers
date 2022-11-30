#pragma once

#include <functional>                                                           //  for std::less<> and maybe also std::binary_function
#include "algorithm.hpp"                                                        //  for ft::lexicographical_compare()
#include "utility.hpp"                                                          //  for ft::pair<>
#include "red_black_tree.hpp"
#include "reverse_iterator.hpp"

namespace ft {

template<
    class Key,
    class Compare = std::less< Key >,
    class Allocator = std::allocator< Key >
> class set
{

public:

/* =================    Member types                        ================= */

    typedef Key                                             key_type;
    typedef Key                                             value_type;
    typedef std::size_t                                     size_type;
    typedef std::ptrdiff_t                                  difference_type;
    typedef Compare                                         key_compare;
    typedef Compare                                         value_compare;
    typedef Allocator                                       allocator_type;
    typedef value_type&                                     reference;
    typedef const value_type&                               const_reference;
    typedef typename allocator_type::pointer                pointer;
    typedef typename allocator_type::const_pointer          const_pointer;

private:

    typedef ft::red_black_tree< value_type, value_compare > tree;

public:

    typedef typename tree::const_iterator                   iterator;
    typedef typename tree::const_iterator                   const_iterator;
    typedef typename ft::reverse_iterator<iterator>         reverse_iterator;
    typedef typename ft::reverse_iterator<const_iterator>   const_reverse_iterator;


private:

/* =================    Member objects                      ================= */

    value_compare   _compare;
    allocator_type  _value_alloc;
    tree            _tree;


public:

/* =================    Constructors                        ================= */

    //  Constructs an empty container.
    explicit set( const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type() )
    {
        _compare = comp;
        _value_alloc = alloc;
    }

    //  Constructs the container with the contents of the range [first, last). If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted.
    template< class InputIt >
    set( InputIt first, InputIt last,
        const key_compare& comp = Compare(),
        const allocator_type& alloc = allocator_type() )
    {
        _compare = comp;
        _value_alloc = alloc;
        insert(first, last);
    }

    //  Copy constructor. Constructs the container with the copy of the contents of other.
    set( const set& other )
    {
        *this = other;
    }

    //  Destructs the set. The destructors of the elements are called and the used storage is deallocated. Note, that if the elements are pointers, the pointed-to objects are not destroyed.
    ~set( void ) {}

    //  Copy assignment operator. Replaces the contents with a copy of the contents of other.
    const set&  operator=( const set& other )
    {
        if (this != &other)
        {
            _compare = other.value_comp();
            _value_alloc = other.get_allocator();
            _tree = other._tree;
        }
        return (*this);
    }

    //  Returns the allocator associated with the container.
    allocator_type  get_allocator( void ) const
    {
        return (_value_alloc);
    }


/* =================    Iterators                           ================= */

    //  Returns an iterator to the first element of the set. If the set is empty, the returned iterator will be equal to end().
    iterator    begin( void )
    {
        return (_tree.begin());
    }

    const_iterator  begin( void ) const
    {
        return (_tree.begin());
    }

    //  Returns an iterator to the element following the last element of the set. This element acts as a placeholder; attempting to access it results in undefined behavior.
    iterator    end( void )
    {
        return (_tree.end());
    }

    const_iterator  end( void ) const
    {
        return (_tree.end());
    }

    //  Returns a reverse iterator to the first element of the reversed set. It corresponds to the last element of the non-reversed set. If the set is empty, the returned iterator is equal to rend().
    reverse_iterator    rbegin( void )
    {
        return (reverse_iterator(end()));
    }

    const_reverse_iterator  rbegin( void ) const
    {
        return (const_reverse_iterator(end()));
    }

    //  Returns a reverse iterator to the element following the last element of the reversed set. It corresponds to the element preceding the first element of the non-reversed set. This element acts as a placeholder, attempting to access it results in undefined behavior.
    reverse_iterator    rend( void )
    {
        return (reverse_iterator(begin()));
    }

    const_reverse_iterator  rend( void ) const
    {
        return (const_reverse_iterator(begin()));
    }


/* =================    Capacity                            ================= */

    //  Checks if the container has no elements.
    bool    empty( void ) const
    {
        return (_tree.size() == 0);
    }

    //  Returns the number of elements in the container.
    size_type   size( void ) const
    {
        return (_tree.size());
    }

    //  Returns the maximum number of elements the container is able to hold due to system or library implementation limitations.
    size_type   max_size( void ) const
    {
        return (_tree.max_size());
    }


/* =================    Modifiers                           ================= */

    //  Erases all elements from the container. After this call, size() returns zero.
    void    clear( void )
    {
        _tree.clear();
    }

    //  Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
    //  (1) Inserts value.
    ft::pair<iterator, bool>    insert( const value_type& value )
    {
        ft::pair<iterator, bool> pair = _tree.insert(value, NULL);
        return (pair);
    }

    //  Inserts value in the position as close as possible to the position just prior to pos.
    iterator    insert( iterator pos, const value_type& value )
    {
        (void)pos;
        return (_tree.insert(value, NULL).first);
    }

    //  (7) Inserts elements from range [first, last). If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted.
    template< class InputIt >
    void    insert( InputIt first, InputIt last )
    {
        for ( ; first != last; first++)
        {
            _tree.insert(*first, NULL);
        }
    }

    //  (1) Removes the element at pos.
    void    erase( iterator pos )
    {
        _tree.erase(pos.base());
    }

    //  (2) Removes the elements in the range [first; last), which must be a valid range in *this.
    void    erase( iterator first, iterator last )
    {
        while (first != last)
        {
            iterator    it = first;
            ++it;
            _tree.erase(first.base());
            first = it;
        }
    }

    //  (3) Removes the element (if one exists) with the key equivalent to key.
    size_type   erase( const key_type& key )
    {
        iterator    it = find(key);
        if (it == end())
            return (0);
        _tree.erase(it.base());
        return (1);
    }

    //  Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on individual elements.
    void    swap( set& other )
    {
        ft::swap(_compare, other._compare);
        ft::swap(_value_alloc, other._value_alloc);
        _tree.swap(other._tree);
    }


/* =================    Lookup                              ================= */

    //  (1) Returns the number of elements with key key. This is either 1 or 0 since this container does not allow duplicates.
    size_type   count( const key_type& key ) const
    {
        return (find(key) != end());
    }

    //  Finds an element with key equivalent to key.
    iterator    find( const key_type& key )
    {
        return (_tree.search(key, NULL));
    }
    
    const_iterator  find( const key_type& key ) const
    {
        return (const_iterator(_tree.search(key, NULL)));
    }

    //  Returns a range containing all elements with the given key in the container. The range is defined by two iterators, one pointing to the first element that is not less than key and another pointing to the first element greater than key. Alternatively, the first iterator may be obtained with lower_bound(), and the second with upper_bound().
    ft::pair<iterator, iterator>    equal_range( const key_type& key )
    {
        return (ft::pair<iterator, iterator>(lower_bound(key), upper_bound(key)));
    }
    
    ft::pair<const_iterator, const_iterator>    equal_range( const key_type& key ) const
    {
        return (ft::pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key)));
    }

    //  Returns an iterator pointing to the first element that is not less than (i.e. greater or equal to) key.
    iterator    lower_bound( const key_type& key )
    {
        return (_tree.lower_bound(key));
    }

    const_iterator  lower_bound( const key_type& key ) const
    {
        return (_tree.lower_bound(key));
    }

    //  Returns an iterator pointing to the first element that is greater than key.
    iterator    upper_bound( const key_type& key )
    {
        return (_tree.upper_bound(key));
    }

    const_iterator  upper_bound( const key_type& key ) const
    {
        return (_tree.upper_bound(key));
    }


/* =================    Observers                           ================= */

    //  Returns the function object that compares the keys, which is a copy of this container's constructor argument comp.
    key_compare key_comp() const
    {
        return (key_compare());
    }

    //  Returns a function object that compares objects of type ft::set::value_type (key-value pairs) by using key_comp to compare the first components of the pairs.
    value_compare   value_comp() const
    {
        return (_compare);
    }
}; // class set


/* =================    Non-member functions                ================= */

//  Compares the contents of two sets.
template< class Key, class Compare, class Alloc >
bool    operator==( const ft::set< Key, Compare, Alloc >& lhs,
                    const ft::set< Key, Compare, Alloc >& rhs )
{
    return (lhs.size() == rhs.size()
            && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template< class Key, class Compare, class Alloc >
bool    operator!=( const ft::set< Key, Compare, Alloc >& lhs,
                    const ft::set< Key, Compare, Alloc >& rhs )
{
    return (!(lhs == rhs));
}

template< class Key, class Compare, class Alloc >
bool    operator<( const ft::set< Key, Compare, Alloc >& lhs,
                    const ft::set< Key, Compare, Alloc >& rhs )
{
    return (ft::lexicographical_compare(lhs.begin(), lhs.end(),
                                        rhs.begin(), rhs.end()));
}

template< class Key, class Compare, class Alloc >
bool    operator<=( const ft::set< Key, Compare, Alloc >& lhs,
                    const ft::set< Key, Compare, Alloc >& rhs )
{
    return (!(rhs < lhs));
}

template< class Key, class Compare, class Alloc >
bool    operator>( const ft::set< Key, Compare, Alloc >& lhs,
                    const ft::set< Key, Compare, Alloc >& rhs )
{
    return (rhs < lhs);
}

template< class Key, class Compare, class Alloc >
bool    operator>=( const ft::set< Key, Compare, Alloc >& lhs,
                    const ft::set< Key, Compare, Alloc >& rhs )
{
    return (!(lhs < rhs));
}

//  Specializes the ft::swap algorithm for ft::set. Swaps the contents of lhs and rhs.
template< class Key, class Compare, class Alloc >
void    swap( ft::set< Key, Compare, Alloc >& lhs,
                ft::set< Key, Compare, Alloc >& rhs )
{
    lhs.swap(rhs);
}

} // namespace ft
