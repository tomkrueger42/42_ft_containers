/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:14:42 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/11/24 02:10:26 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>

# include "iterator/random_access_iterator.hpp"
# include "iterator/reverse_iterator.hpp"
# include "utils/algorithm.hpp"
# include "utils/type_traits.hpp"

namespace ft
{



/* ************************************************************************** */
/*                                    VECTOR                                  */
/* ************************************************************************** */

template<typename T,
         typename Alloc = std::allocator<T> >
class vector
{
public:

    /* MEMBER TYPES */
    typedef T                                               value_type;
    typedef Alloc                                           allocator_type;
    typedef typename allocator_type::size_type              size_type;
    typedef typename allocator_type::difference_type        difference_type;
    typedef typename allocator_type::reference              reference;
    typedef typename allocator_type::const_reference        const_reference;
    typedef typename allocator_type::pointer                pointer;
    typedef typename allocator_type::const_pointer          const_pointer;

    /* ITERATOR TYPES */
    typedef ft::random_access_iterator<value_type>          iterator;
    typedef ft::random_access_iterator<const value_type>    const_iterator;
    typedef ft::reverse_iterator<iterator>                  reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;

private:

    allocator_type   _alloc;
    pointer          _begin;
    size_type        _size;
    size_type        _capacity;

public:

    explicit vector(const allocator_type& alloc = allocator_type());
    explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
    template<typename InputIterator>
    vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
    vector(const vector& rhs);
    ~vector();

    vector& operator=(const vector& rhs);

    /* ITERATORS */
    iterator                 begin();
    const_iterator           begin() const;
    iterator                 end();
    const_iterator           end() const;
    reverse_iterator         rbegin();
    const_reverse_iterator   rbegin() const;
    reverse_iterator         rend();
    const_reverse_iterator   rend() const;

    /* CAPACITY */
    size_type                size(void) const;
    size_type                max_size(void) const;
    void                     resize(size_type n, value_type val = value_type());
    size_type                capacity(void) const;
    bool                     empty(void) const;
    void                     reserve(size_type n);

    /* ELEMENT ACCESSS */
    reference                operator[](size_type i);
    const_reference          operator[](size_type i) const;
    reference                at(size_type );
    const_reference          at(size_type i) const;
    reference                front(void);
    const_reference          front(void) const;
    reference                back(void);
    const_reference          back(void) const;

    /* MODIFIERS */
    template<typename InputIterator>
    void                     assign(InputIterator first,
                                    InputIterator last,
    typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL);
    void                     assign(size_type n, const_reference val);
    void                     push_back(const_reference val);
    void                     pop_back(void);
    iterator                 insert(iterator position, const value_type& val);
    void                     insert(iterator position, size_type n, const value_type& val);
    template<typename InputIterator>
    void                     insert(iterator position,
                                    InputIterator first,
                                    InputIterator last,
    typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL);
    iterator                 erase(iterator position);
    iterator                 erase(iterator first, iterator last);
    void                     swap(vector& x);
    void                     clear(void);

    /* ALLOCATOR */
    allocator_type           get_allocator(void) const;

private:

    /* UTILITY */
    size_type                _request_size(size_type n);
    pointer                  _allocate_vector(const size_type& capacity);
    void                     _copy_vector(pointer tmp);
    void                     _reallocate_vector(size_type insert_size, size_type offset_front, size_type offset_back);
    void                     _deallocate_vector();
    void                     _destroy_from_back(size_type pos);

    /* HELPER */
    template<typename InputIterator>
    void                     _assign_range_helper(InputIterator first, 
                                                  InputIterator last, 
                                                  random_access_iterator_tag);
    template<typename InputIterator>
    void                     _assign_range_helper(InputIterator first, 
                                                  InputIterator last,
                                                  input_iterator_tag);
    template<typename InputIterator>
    void                     _insert_range_helper(iterator position,
                                                  InputIterator first,
                                                  InputIterator last,
                                                  random_access_iterator_tag);
    template<typename InputIterator>
    void                     _insert_range_helper(iterator position,
                                                  InputIterator first,
                                                  InputIterator last,
                                                  input_iterator_tag);

};

/* ************************************************************************** */
/*                                    VECTOR                                  */
/* ************************************************************************** */

template<typename T, typename Alloc>
vector<T, Alloc>::vector(const allocator_type& alloc)
:  _alloc(alloc), _begin(NULL), _size(0), _capacity(0) {}


template<typename T, typename Alloc>
vector<T, Alloc>::vector(size_type n, const value_type& val, const allocator_type& alloc)
: _alloc(alloc), _begin(NULL), _size(0), _capacity(0)
{ assign(n, val); }


template<typename T, typename Alloc>
template<typename InputIterator>
vector<T, Alloc>::vector(InputIterator first, InputIterator last, const allocator_type& alloc)
: _alloc(alloc), _begin(NULL), _size(0), _capacity(0)
{ assign(first, last); }


template<typename T, typename Alloc>
vector<T, Alloc>::vector(const vector& rhs)
: _alloc(rhs._alloc), _begin(NULL), _size(0), _capacity(rhs._capacity)
{
    if (!rhs._begin)
        return ;
    _begin = _allocate_vector(_capacity);
    for (; _size < rhs._size; ++_size)
        _alloc.construct(_begin + _size, *(rhs._begin + _size));
}

/* ************************************************************************** */

template<typename T, typename Alloc>
vector<T, Alloc>::~vector()
{ _deallocate_vector(); }

/* ************************************************************************** */

template<typename T, typename Alloc>
vector<T, Alloc>&
vector<T, Alloc>::operator=(const vector& rhs)
{
    if (this != &rhs)
        assign(rhs.begin(), rhs.end());
    return (*this);
}

/* ************************************************************************** */
/*                                   ITERATORS                                */
/* ************************************************************************** */

template<typename T, typename Alloc>
inline
typename vector<T, Alloc>::iterator
vector<T, Alloc>::begin()
{ return iterator(_begin); }


template<typename T, typename Alloc>
inline
typename vector<T, Alloc>::const_iterator
vector<T, Alloc>::begin() const
{ return const_iterator(_begin); }

/* ************************************************************************** */

template<typename T, typename Alloc>
inline
typename vector<T, Alloc>::iterator
vector<T, Alloc>::end()
{ return iterator(_begin + _size); }


template<typename T, typename Alloc>
inline
typename vector<T, Alloc>::const_iterator
vector<T, Alloc>::end() const
{ return const_iterator(_begin + _size); }

/* ************************************************************************** */

template<typename T, typename Alloc>
inline
typename vector<T, Alloc>::reverse_iterator
vector<T, Alloc>::rbegin()
{ return reverse_iterator(iterator(_begin + _size)); }


template<typename T, typename Alloc>
inline
typename vector<T, Alloc>::const_reverse_iterator
vector<T, Alloc>::rbegin() const
{ return const_reverse_iterator(const_iterator(_begin + _size)); }

/* ************************************************************************** */

template<typename T, typename Alloc>
inline
typename vector<T, Alloc>::reverse_iterator
vector<T, Alloc>::rend()
{ return reverse_iterator(iterator(_begin)); }


template<typename T, typename Alloc>
inline
typename vector<T, Alloc>::const_reverse_iterator
vector<T, Alloc>::rend() const
{ return const_reverse_iterator(const_iterator(_begin)); }

/* ************************************************************************** */
/*                                   CAPACITY                                 */
/* ************************************************************************** */

template<typename T, typename Alloc>
inline
typename vector<T, Alloc>::size_type
vector<T, Alloc>::size() const
{ return _size; }

/* ************************************************************************** */

template<typename T, typename Alloc>
typename vector<T, Alloc>::size_type
vector<T, Alloc>::max_size() const
{
    size_type max1 = _alloc.max_size();
    size_type max2 = std::numeric_limits<size_type>::max() / 2;
    return (max1 < max2) ? max1 : max2;
}

/* ************************************************************************** */

template<typename T, typename Alloc>
void
vector<T, Alloc>::resize(size_type n, value_type val)
{
    if (n < _size)
        _destroy_from_back(n);
    else if (n > _size)
    {
        reserve(n);
        for (; _size < n; ++_size)
            _alloc.construct(_begin + _size, val);
    }
}

/* ************************************************************************** */

template<typename T, typename Alloc>
inline
typename vector<T, Alloc>::size_type
vector<T, Alloc>::capacity() const
{ return _capacity; }

/* ************************************************************************** */

template<typename T, typename Alloc>
inline
bool
vector<T, Alloc>::empty() const
{ return _size == 0; }

/* ************************************************************************** */

template<typename T, typename Alloc>
void
vector<T, Alloc>::reserve(size_type n)
{
    if (n > max_size())
        throw std::length_error("ft::vector");
    else if (n > _capacity)
    {
        pointer tmp = _allocate_vector(n);
        _copy_vector(tmp);
        _capacity = n;
    }
}

/* ************************************************************************** */
/*                                ELEMENT ACCESS                              */
/* ************************************************************************** */

template<typename T, typename Alloc>
inline
typename vector<T, Alloc>::reference
vector<T, Alloc>::operator[](size_type i)
{ return *(_begin + i); }


template<typename T, typename Alloc>
inline
typename vector<T, Alloc>::const_reference
vector<T, Alloc>::operator[](size_type i) const
{ return *(_begin + i); }

/* ************************************************************************** */

template<typename T, typename Alloc>
inline
typename vector<T, Alloc>::reference
vector<T, Alloc>::at(size_type i)
{
    if (i >= _size)
        throw std::out_of_range("ft::vector");
    return *(_begin + i);
}


template<typename T, typename Alloc>
inline
typename vector<T, Alloc>::const_reference
vector<T, Alloc>::at(size_type i) const
{
    if (i >= _size)
        throw std::out_of_range("ft::vector");
    return *(_begin + i);
}

/* ************************************************************************** */

template<typename T, typename Alloc>
inline
typename vector<T, Alloc>::reference
vector<T, Alloc>::front()
{ return *(_begin); }


template<typename T, typename Alloc>
inline
typename vector<T, Alloc>::const_reference
vector<T, Alloc>::front() const
{ return *(_begin); }

/* ************************************************************************** */

template<typename T, typename Alloc>
inline
typename vector<T, Alloc>::reference
vector<T, Alloc>::back()
{ return *(_begin + _size - 1); }


template<typename T, typename Alloc>
inline
typename vector<T, Alloc>::const_reference
vector<T, Alloc>::back() const
{ return *(_begin + _size - 1); }

/* ************************************************************************** */
/*                                   MODIFIERS                                */
/* ************************************************************************** */

template<typename T, typename Alloc>
template<typename InputIterator>
void
vector<T, Alloc>::assign(InputIterator first,
                         InputIterator last,
typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*)
{ _assign_range_helper(first, last, typename ft::iterator_traits<InputIterator>::iterator_category()); }

/* ************************************************************************** */

template<typename T, typename Alloc>
void
vector<T, Alloc>::assign(size_type n, const_reference val)
{
    clear();
    reserve(n);

    for (; _size < n; ++_size)
        _alloc.construct(_begin + _size, val);
}

/* ************************************************************************** */

template<typename T, typename Alloc>
void
vector<T, Alloc>::push_back(const_reference val)
{
    if (_size == _capacity)
    {
        if (_begin)
        {
            size_type tmp_capacity = _request_size(_size);
            pointer tmp = _allocate_vector(tmp_capacity);
            _copy_vector(tmp);
            _capacity = tmp_capacity;
        }
        else if (!_begin)
        {
            _begin = _alloc.allocate(1);
            _capacity = 1;
        }
    }
    _alloc.construct(_begin + _size, val);
    ++_size;
}

/* ************************************************************************** */

template<typename T, typename Alloc>
void
vector<T, Alloc>::pop_back()
{
    _alloc.destroy(_begin + _size - 1);
    --_size;
}

/* ************************************************************************** */

template<typename T, typename Alloc>
typename vector<T, Alloc>::iterator
vector<T, Alloc>::insert(iterator position, const value_type& val)
{
    size_type insert_size = 1;
    size_type offset_front = static_cast<size_type>(ft::distance(begin(), position));
    size_type offset_back = static_cast<size_type>(ft::distance(position, end()));

    _reallocate_vector(insert_size, offset_front, offset_back);

    for (size_type i = offset_front; i < offset_front + insert_size; ++i)
        _alloc.construct(_begin + i, val);

    _size += insert_size;
    return _begin + offset_front;
}


template<typename T, typename Alloc>
void
vector<T, Alloc>::insert(iterator position, size_type n, const value_type& val)
{
    if (!n)
        return ;
    size_type insert_size = n;
    size_type offset_front = static_cast<size_type>(ft::distance(begin(), position));
    size_type offset_back = static_cast<size_type>(ft::distance(position, end()));
    
    _reallocate_vector(insert_size, offset_front, offset_back);

    for (size_type i = offset_front; i < offset_front + insert_size; ++i)
        _alloc.construct(_begin + i, val);

    _size += insert_size;
}


template<typename T, typename Alloc>
template<typename InputIterator>
void
vector<T, Alloc>::insert(iterator position,
                         InputIterator first,
                         InputIterator last,
typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*)
{ _insert_range_helper(position, first, last, typename ft::iterator_traits<InputIterator>::iterator_category()); }

/* ************************************************************************** */

template<typename T, typename Alloc>
typename vector<T, Alloc>::iterator
vector<T, Alloc>::erase(iterator position)
{
    if (position == end())
        return position;

    size_type erase_size = 1;
    size_type offset_front = static_cast<size_type>(ft::distance(begin(), position));
    size_type offset_back = static_cast<size_type>(ft::distance(position, end()) - 1);

    for (size_type i = 0; i < erase_size; ++i)
        _alloc.destroy(_begin + offset_front + i);

    iterator head = position + 1;
    for (size_type i = 0; i < offset_back; ++i)
    {
        _alloc.construct(_begin + offset_front + i, *head);
        _alloc.destroy(_begin + offset_front + erase_size + i);
        ++head;
    }

    _size -= erase_size;
    return _begin + offset_front;
}


template<typename T, typename Alloc>
typename vector<T, Alloc>::iterator
vector<T, Alloc>::erase(iterator first, iterator last)
{
    size_type erase_size = static_cast<size_type>(ft::distance(first, last));

    if (!erase_size)
        return first;

    size_type offset_front = static_cast<size_type>(ft::distance(begin(), first));
    size_type offset_back = static_cast<size_type>(ft::distance(last, end()));

    for (size_type i = 0; i < erase_size; ++i)
        _alloc.destroy(_begin + offset_front + i);

    iterator head = last;
    for (size_type i = 0; i < offset_back; ++i)
    {
        _alloc.construct(_begin + offset_front + i, *head);
        _alloc.destroy(_begin + offset_front + erase_size + i);
        ++head;
    }

    _size -= erase_size;
    return _begin + offset_front;
}

/* ************************************************************************** */

template<typename T, typename Alloc>
void
vector<T, Alloc>::swap(vector& x)
{
    ft::swap(_alloc, x._alloc);
    ft::swap(_begin, x._begin);
    ft::swap(_size, x._size);
    ft::swap(_capacity, x._capacity);
}

/* ************************************************************************** */

template<typename T, typename Alloc>
inline
void
vector<T, Alloc>::clear(void)
{ _destroy_from_back(0); }

/* ************************************************************************** */
/*                                   ALLOCATOR                                */
/* ************************************************************************** */

template<typename T, typename Alloc>
inline
typename vector<T, Alloc>::allocator_type
vector<T, Alloc>::get_allocator(void) const
{ return _alloc; }

/* ************************************************************************** */
/*                                    PRIVATE                                 */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                    UTILITY                                 */
/* ************************************************************************** */

template<typename T, typename Alloc>
inline
typename vector<T, Alloc>::size_type
vector<T, Alloc>::_request_size(size_type n)
{
    if (n > max_size())
        throw std::length_error("ft::vector");
    return (n <= _capacity * 2) ? _capacity * 2 : n;
}

/* ************************************************************************** */

template<typename T, typename Alloc>
typename vector<T, Alloc>::pointer
vector<T, Alloc>::_allocate_vector(const size_type& capacity)
{
    if (capacity > max_size())
        throw std::length_error("ft::vector");
    return _alloc.allocate(capacity);
}

/* ************************************************************************** */

template<typename T, typename Alloc>
void
vector<T, Alloc>::_copy_vector(pointer tmp)
{
    if (_begin)
    {
        for (size_type i = 0; i < _size; ++i)
            _alloc.construct(tmp + i, *(_begin + i));

        for (size_type i = 0; i < _size; ++i)
            _alloc.destroy(_begin + i);
        _alloc.deallocate(_begin, _capacity);
    }
    _begin = tmp;
}

/* ************************************************************************** */

template<typename T, typename Alloc>
void
vector<T, Alloc>::_reallocate_vector(size_type insert_size, size_type offset_front, size_type offset_back)
{
    if (_size + insert_size > _capacity)
        reserve(_request_size(_size + insert_size));

    iterator tail = end() - 1;
    for (size_type i = offset_back; i > 0; --i)
    {
        _alloc.construct(_begin + offset_front + insert_size + i - 1, *tail);
        _alloc.destroy(_begin + offset_front + i - 1);
        --tail;
    }
}

/* ************************************************************************** */

template<typename T, typename Alloc>
void
vector<T, Alloc>::_deallocate_vector()
{
    if (_begin)
    {
        clear();
        _alloc.deallocate(_begin, _capacity);
        _begin = NULL;
        _capacity = 0;
    }
}

/* ************************************************************************** */

template<typename T, typename Alloc>
void
vector<T, Alloc>::_destroy_from_back(size_type pos)
{
    for (; _size > pos; --_size)
        _alloc.destroy(_begin + _size - 1);
}

/* ************************************************************************** */
/*                                    HELPER                                  */
/* ************************************************************************** */

template<typename T, typename Alloc>
template<typename InputIterator>
void
vector<T, Alloc>::_assign_range_helper(InputIterator first,
                                       InputIterator last,
                                       random_access_iterator_tag)
{
    size_type n = static_cast<size_type>(ft::distance(first, last));

    clear();

    reserve(n);

    for (; first != last; ++first)
        push_back(*first);
}


template<typename T, typename Alloc>
template<typename InputIterator>
void
vector<T, Alloc>::_assign_range_helper(InputIterator first,
                                       InputIterator last,
                                       input_iterator_tag)
{
    clear();
    for (; first != last; ++first)
        push_back(*first);
}

/* ************************************************************************** */

template<typename T, typename Alloc>
template<typename InputIterator>
void
vector<T, Alloc>::_insert_range_helper(iterator position,
                                       InputIterator first,
                                       InputIterator last,
                                       random_access_iterator_tag)
{
    size_type insert_size = static_cast<size_type>(ft::distance(first, last));
    size_type offset_front = static_cast<size_type>(ft::distance(begin(), position));
    size_type offset_back = static_cast<size_type>(ft::distance(position, end()));
    
    _reallocate_vector(insert_size, offset_front, offset_back);

    for (size_type i = offset_front; i < offset_front + insert_size; ++i)
    {
        _alloc.construct(_begin + i, *first);
        ++first;
    }

    _size += insert_size;
}


template<typename T, typename Alloc>
template<typename InputIterator>
void
vector<T, Alloc>::_insert_range_helper(iterator position,
                                       InputIterator first,
                                       InputIterator last,
                                       input_iterator_tag)
{
    for (; first != last; ++first, ++position)
        position = insert(position, *first);
}

/* ************************************************************************** */
/*                                    VECTOR                                  */
/* ************************************************************************** */






/* ************************************************************************** */
/*                               NON-MEMBER FUNCTIONS                         */
/* ************************************************************************** */

template<typename T, typename Alloc>
void
swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
{ x.swap(y); }

/* ************************************************************************** */
/*                               RELATIONAL OPERATORS                         */
/* ************************************************************************** */

template<typename T, typename Alloc>
bool
operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
{ return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()); }

/* ************************************************************************** */

template<typename T, typename Alloc>
bool
operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
{ return !(lhs == rhs); }

/* ************************************************************************** */

template<typename T, typename Alloc>
bool
operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
{ return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }

/* ************************************************************************** */

template<typename T, typename Alloc>
bool
operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
{ return !(rhs < lhs); }

/* ************************************************************************** */

template<typename T, typename Alloc>
bool
operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
{ return rhs < lhs; }

/* ************************************************************************** */

template<typename T, typename Alloc>
bool
operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
{ return !(lhs < rhs); }

/* ************************************************************************** */



}

#endif /* VECTOR_HPP */
