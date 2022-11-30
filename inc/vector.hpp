#pragma once

#include "log.hpp"

#include <memory>
#include <stdexcept>

#include "algorithm.hpp"
#include "type_traits.hpp"
#include "utility.hpp"

#include "vector_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft {

template<
    class T,
    class Allocator = std::allocator< T >
>class vector
{
   public:
/* =================    Member types                        ================= */

    typedef T                                               value_type;
    typedef Allocator                                       allocator_type;
    typedef typename Allocator::size_type                   size_type;
    typedef typename Allocator::difference_type             difference_type;
    typedef typename Allocator::reference                   reference;
    typedef typename Allocator::const_reference             const_reference;
    typedef typename Allocator::pointer                     pointer;
    typedef typename Allocator::const_pointer               const_pointer;
    typedef typename ft::vector_iterator<value_type>        iterator;
    typedef typename ft::vector_iterator<const value_type>  const_iterator;
    typedef typename ft::reverse_iterator<iterator>         reverse_iterator;
    typedef typename ft::reverse_iterator<const_iterator>   const_reverse_iterator;

   private:
/* =================    Member objects                      ================= */

    size_type       _size;
    size_type       _capacity;
    pointer         _ptr;
    allocator_type  _alloc;

   public:
/* =================    Constructors                        ================= */

    //  (1) Default constructor. Constructs an empty container with a default-constructed allocator.
    vector( void ) : _size(0), _capacity(0), _ptr(NULL), _alloc() {}

    //  (2) Constructs an empty container with the given allocator alloc.
    explicit vector( const Allocator& alloc )
                : _size(0), _capacity(0), _ptr(NULL), _alloc(alloc) {}

    //  (3) Constructs the container with count copies of elements with value value.
    explicit vector( size_type count, const T& value = T(),
                        const Allocator& alloc = Allocator() )
                        : _size(0), _capacity(0), _ptr(NULL), _alloc(alloc)
    {
        assign(count, value);
    }

    //  (5) Constructs the container with the contents of the range [first, last).
    //  This constructor has the same effect as vector(static_cast<size_type>(first), static_cast<value_type>(last), a) if InputIt is an integral type.
    template < class InputIt >
    vector( InputIt first, InputIt last, const Allocator& alloc = Allocator(),
            typename ft::enable_if<!ft::is_integral<InputIt>::value, bool>::type = true)
            : _size(0), _capacity(0), _ptr(NULL), _alloc(alloc)
    {
        assign(first, last);
    }

    //  (6) Copy constructor. Constructs the container with the copy of the contents of other.
    vector( const vector& other ) : _size(0), _capacity(0), _ptr(NULL)      // does _alloc need to be copied somehow??
    {
        *this = other;
    }

    //  Destructs the vector. The destructors of the elements are called and the used storage is deallocated.
    //  Note, that if the elements are pointers, the pointed-to objects are not destroyed.
    ~vector( void )
    {
        clear();
        if (_ptr != NULL)
            _alloc.deallocate(_ptr, _capacity);
        _ptr = NULL;
        _capacity = 0;
    }

    //  (1) Copy assignment operator. Replaces the contents with a copy of the contents of other.
    vector  &operator=( const vector& other )
    {
        if (this != &other)
        {
            _alloc = other.get_allocator();
            assign(other.begin(), other.end());
        }
        return (*this);
    }

    //  (1) Replaces the contents with count copies of value value
    void    assign( size_type count, const T& value )
    {
        clear();
        reserve(count);
        for (size_type i = 0; i < count; i++)
        {
            _alloc.construct(_ptr + i, value);
        }
        _size = count;
    }

    //  (2) Replaces the contents with copies of those in the range [first, last). The behavior is undefined if either argument is an iterator into *this. 
    //  This overload has the same effect as overload (1) if InputIt is an integral type.
    template< class InputIt >
    void    assign( InputIt first, InputIt last,
                    typename ft::enable_if<!ft::is_integral<InputIt>::value, bool>::type = true)
    {
        _assign_range(first, last, typename ft::iterator_traits<InputIt>::iterator_category());
    }

    //  Returns the allocator associated with the container.
    allocator_type  get_allocator() const
    {
        return (_alloc);
    }


/* =================    Element access                      ================= */

    //  Returns a reference to the element at specified location pos, with bounds checking.
    //  If pos is not within the range of the container, an exception of type std::out_of_range is thrown.
    reference   at( size_type pos )
    {
        if (pos >= _size)
            throw std::out_of_range("vector");
        return (_ptr[pos]);
    }

    const_reference at( size_type pos ) const
    {
        if (pos >= _size)
            throw std::out_of_range("vector");
        return (_ptr[pos]);
    }

    //  Returns a reference to the element at specified location pos. No bounds checking is performed.
    reference   operator[]( size_type pos )
    {
        return (_ptr[pos]);
    }

    const_reference operator[]( size_type pos ) const
    {
        return (_ptr[pos]);
    }

    //  Returns a reference to the first element in the container.
    //  Calling front on an empty container is undefined.
    reference   front()
    {
        return (_ptr[0]);
    }

    const_reference front() const
    {
        return (_ptr[0]);
    }

    //  Returns a reference to the last element in the container.
    //  Calling back on an empty container causes undefined behavior.
    reference   back()
    {
        return (_ptr[_size - 1]);
    }

    const_reference back() const
    {
        return (_ptr[_size - 1]);
    }

    //  Returns pointer to the underlying array serving as element storage.
    //  The pointer is such that range [data(); data()+size()) is always a valid range,
    //  even if the container is empty (data() is not dereferenceable in that case).
    T*  data()
    {
        return (_ptr);
    }

    const T*    data() const
    {
        return (_ptr);
    }


/* =================    Iterators                           ================= */

    //  Returns an iterator to the first element of the vector.
    //  If the vector is empty, the returned iterator will be equal to end().
    iterator    begin( void )
    {
        return (iterator(_ptr));
    }

    const_iterator  begin( void ) const
    {
        return (const_iterator(_ptr));
    }

    //  Returns an iterator to the element following the last element of the vector.
    //  This element acts as a placeholder; attempting to access it results in undefined behavior.
    iterator    end( void )
    {
        return (iterator(_ptr + _size));
    }

    const_iterator  end( void ) const
    {
        return (const_iterator(_ptr + _size));
    }

    //  Returns a reverse iterator to the first element of the reversed vector.
    //  It corresponds to the last element of the non-reversed vector.
    //  If the vector is empty, the returned iterator is equal to rend().
    reverse_iterator    rbegin( void )
    {
        return (reverse_iterator(end()));
    }
    
    const_reverse_iterator  rbegin( void ) const
    {
        return (const_reverse_iterator(end()));
    }

    //  Returns a reverse iterator to the element following the last element of the reversed vector.
    //  It corresponds to the element preceding the first element of the non-reversed vector.
    //  This element acts as a placeholder, attempting to access it results in undefined behavior.
    reverse_iterator    rend( void )
    {
        return (reverse_iterator(begin()));
    }

    const_reverse_iterator  rend( void ) const
    {
        return (const_reverse_iterator(begin()));
    }


/* =================    Capacity                            ================= */

    //  Checks if the container has no elements, i.e. whether begin() == end().
    bool    empty( void ) const
    {
        return (_size == 0);
    }

    //  Returns the number of elements in the container, i.e. std::ft::distance(begin(), end()).
    size_type   size( void ) const
    {
        return (_size);
    }

    //  Returns the maximum number of elements the container is able to hold due to system
    //  or library implementation limitations, i.e. std::ft::distance(begin(), end()) for the largest container.
    size_type   max_size() const
    {
        if (_alloc.max_size() < std::numeric_limits< size_type >::max() / 2)
            return (_alloc.max_size());
        return (std::numeric_limits< size_type >::max() / 2);
    }

    //  Increase the capacity of the vector to a value that's greater or equal to new_cap.
    //  If new_cap is greater than the current capacity(), new storage is allocated, otherwise the function does nothing.
    void    reserve( size_type newCapacity )
    {
        if (newCapacity > max_size() && (_capacity == 0 || _capacity == max_size()))
            throw std::length_error("vector");
        else if (newCapacity > max_size())
            newCapacity = max_size();
        else if (newCapacity < _capacity)
            return ;
        _realloc(newCapacity);
    }

    size_t  capacity( void ) const
    {
        return (_capacity);
    }


/* =================    Modifiers                           ================= */

    //  Erases all elements from the container. After this call, size() returns zero.
    void    clear( void )
    {
        for (size_type i = 0; i < _size; i++)
        {
            _alloc.destroy(_ptr + i);
        }
        _size = 0;
    }

    //  Inserts elements at the specified location in the container.
    //  (1) inserts value before pos.
    iterator    insert( iterator pos, const T& value )
    {
        return (insert(pos, 1, value));
    }

    //  (3) inserts count copies of the value before pos.
    iterator    insert( iterator pos, size_type count, const T& value )
    {
        if (count == 0)
            return (pos);

        size_type   position = ft::distance(begin(), pos);
        size_type   newSize = _size + count;
        pointer     newPTR = _alloc.allocate(newSize);

        for (size_type i = 0; i < position; i++)
        {
            _alloc.construct(newPTR + i, _ptr[i]);
        }
        for (size_type i = position; i < position + count; i++)
        {
            _alloc.construct(newPTR + i, value);
        }
        for (size_type i = position; i < _size; i++)
        {
            _alloc.construct(newPTR + count + i, _ptr[i]);
        }
        clear();
        if (_ptr != NULL)
            _alloc.deallocate(_ptr, _capacity);
        _ptr = newPTR;
        _size = newSize;
        _capacity = newSize;
        return (iterator(_ptr + position));
    }

    //  (4) inserts elements from range [first, last) before pos.
    //  This overload has the same effect as overload (3) if InputIt is an integral type.
    template< class InputIt >
    iterator    insert( iterator pos, InputIt first, InputIt last,
                        typename ft::enable_if<!ft::is_integral<InputIt>::value, bool>::type = true )
    {
        return (_insert_range(pos, first, last, typename ft::iterator_traits<InputIt>::iterator_category()));
    }

    //  Erases the specified elements from the container.
    //  (1) Removes the element at pos.
    iterator    erase( iterator pos )
    {
        for (iterator it = pos; it < end() - 1; it++)
        {
            *it = *(it + 1);
        }
        _alloc.destroy(_ptr + _size - 1);
        if (pos != end())
            --_size;
        return (pos);
    }

    //  (2) Removes the elements in the range [first, last).
    iterator    erase( iterator first, iterator last )
    {
        difference_type n = ft::distance(first, last);
        for (iterator it = first; last < end(); it++, last++)
        {
            *it = *last;
        }
        for (difference_type d = 1; n >= d; d++)
        {
            _alloc.destroy(end().base() - d);
        }
        _size -= n;
        return (first);
    }

    //  Appends the given element value to the end of the container.
    //  The new element is initialized as a copy of value.
    void    push_back( const T& value )
    {
        reserve(1);
        if (_size == _capacity)
            reserve(_capacity * 2);
        _alloc.construct(_ptr + _size, value);
        ++_size;
    }

    //  Removes the last element of the container. 
    void    pop_back( void )
    {
        _alloc.destroy(&(_ptr[_size - 1]));
        --_size;
    }

    //  Resizes the container to contain count elements. If the current
    //  size is greater than count, the container is reduced to its first count elements.
    //  If the current size is less than count, additional copies of value are appended.
    void    resize( size_type count, T value = T() )
    {
        if (count > max_size())
            throw std::length_error("vector");
        if (_capacity == 0)
            reserve(count);
        while (_size < count)
        {
            push_back(value);
        }
        erase(begin() + count, end());
    }

    //  Exchanges the contents of the container with those of other.
    //  Does not invoke any move, copy, or swap operations on individual elements.
    //  All iterators and references remain valid. The past-the-end iterator is invalidated. 
    void swap( vector& other )
    {
        ft::swap(_size, other._size);
        ft::swap(_capacity, other._capacity);
        ft::swap(_ptr, other._ptr);
        ft::swap(_alloc, other._alloc);
    }


   private:
    void    _realloc( size_type newCapacity )
    {
        pointer newPTR = _alloc.allocate(newCapacity);
        for (size_type i = newCapacity; newCapacity < _size; i++)
        {
            _alloc.destroy(_ptr + i);
        }
        if (newCapacity < _size)
            _size = newCapacity;
        for (size_type i = 0; i < _size; i++)
        {
            _alloc.construct(newPTR + i, _ptr[i]);
            _alloc.destroy(_ptr + i);
        }
        if (_ptr != NULL)
            _alloc.deallocate(_ptr, _capacity);
        _ptr = newPTR;
        _capacity = newCapacity;
    }

    template< typename InputIterator >
    void    _assign_range( InputIterator first, InputIterator last, input_iterator_tag  )
    {
        clear();
        for ( ; first != last; first++)
            push_back(*first);
    }

    template< typename InputIterator >
    void    _assign_range( InputIterator first, InputIterator last, random_access_iterator_tag )
    {
        clear();
        reserve(ft::distance(first, last));
        for (_size = 0; first != last; _size++, first++)
            _alloc.construct(_ptr + _size, *first);
    }

    template< typename InputIterator >
    iterator    _insert_range( iterator pos, InputIterator first, InputIterator last, random_access_iterator_tag )
    {
        size_type   count = ft::distance(first, last);
        if (count == 0)
            return (pos);

        size_type   position = ft::distance(begin(), pos);
        size_type   newSize = _size + count;
        pointer     newPTR = _alloc.allocate(newSize);

        for (size_type i = 0; i < position; i++)
        {
            _alloc.construct(newPTR + i, _ptr[i]);
        }
        for (size_type i = position; i < position + count; i++, first++)
        {
            _alloc.construct(newPTR + i, *first);
        }
        for (size_type i = position; i < _size; i++)
        {
            _alloc.construct(newPTR + count + i, _ptr[i]);
        }

        clear();
        if (_ptr != NULL)
            _alloc.deallocate(_ptr, _capacity);
        _ptr = newPTR;
        _size = newSize;
        _capacity = newSize;
        return (iterator(_ptr + position));
    }

    template< typename InputIterator >
    iterator    _insert_range( iterator pos, InputIterator first, InputIterator last, input_iterator_tag )
    {
        size_type   position = ft::distance(begin(), pos);
        for ( ; first != last; ++first, ++pos)
            pos = insert(pos, *first);
        return (iterator(_ptr + position));
    }
}; // class Vector

/* =================    Non-member functions                ================= */

//  Checks if the contents of lhs and rhs are equal, that is, they have the same number of elements
//  and each element in lhs compares equal with the element in rhs at the same position.
template< class T, class Alloc >
bool    operator==( const ft::vector<T,Alloc>& lhs,
                    const ft::vector<T,Alloc>& rhs )
{
    return (lhs.size() == rhs.size()
        && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template< class T, class Alloc >
bool    operator!=( const ft::vector<T,Alloc>& lhs,
                    const ft::vector<T,Alloc>& rhs )
{
    return (!(lhs == rhs));
}

//  Compares the contents of lhs and rhs lexicographically.
//  The comparison is performed by a function equivalent to std::lexicographical_compare.
template< class T, class Alloc >
bool    operator<( const ft::vector<T,Alloc>& lhs,
                    const ft::vector<T,Alloc>& rhs )
{
    return (ft::lexicographical_compare(lhs.begin(), lhs.end(),
                                        rhs.begin(), rhs.end()));
}

template< class T, class Alloc >
bool    operator<=( const ft::vector<T,Alloc>& lhs,
                    const ft::vector<T,Alloc>& rhs )
{
    return (!(rhs < lhs));
}

template< class T, class Alloc >
bool    operator>( const ft::vector<T,Alloc>& lhs,
                    const ft::vector<T,Alloc>& rhs )
{
    return (rhs < lhs);
}

template< class T, class Alloc >
bool    operator>=( const ft::vector<T,Alloc>& lhs,
                    const ft::vector<T,Alloc>& rhs )
{
    return (!(lhs < rhs));
}

//  Specializes the ft::swap algorithm for ft::vector. Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
template< class T, class Alloc >
void    swap( ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs )
{
    lhs.swap(rhs);
}

} // namespace ft
