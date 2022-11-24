/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 23:00:39 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/11/21 23:13:35 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MAP_HPP
# define MAP_HPP

# include "utils/red_black_tree.hpp"

namespace ft
{



/* ************************************************************************** */
/*                                      MAP                                   */
/* ************************************************************************** */

template<typename Key,
         typename T,
         typename Compare = ft::less<Key>,
         typename Alloc = std::allocator<ft::pair<const Key, T> > >
class map
{
public:

    /* MEMBER TYPES */
    typedef Key                                                 key_type;
    typedef T                                                   mapped_type;
    typedef ft::pair<const key_type, mapped_type>               value_type;
    typedef Compare                                             key_compare;
    typedef Alloc                                               allocator_type;
    typedef typename allocator_type::reference                  reference;
    typedef typename allocator_type::const_reference            const_reference;
    typedef typename allocator_type::pointer                    pointer;
    typedef typename allocator_type::const_pointer              const_pointer;
    typedef typename allocator_type::size_type                  size_type;
    typedef typename allocator_type::difference_type            difference_type;

    /* SUBCLASS */
    class value_compare : ft::binary_function<value_type, value_type, bool>
    {
    private:

        friend class map;

    public:
    
        /* MEMBER TYPES */
        typedef bool                                            result_type;
        typedef value_type                                      first_argument_type;
        typedef value_type                                      second_argument_type;

    protected:

        key_compare comp;
        value_compare(key_compare c) : comp(c) {}

    public:

        bool operator()(const value_type& x, const value_type& y) const
        { return comp(x.first, y.first); }

    };

    /* TREE TYPE */
    typedef ft::red_black_tree<value_type, value_compare, allocator_type> tree_type;

    /* ITERATOR TYPES */
    typedef typename tree_type::iterator                        iterator;
    typedef typename tree_type::const_iterator                  const_iterator;
    typedef typename tree_type::reverse_iterator                reverse_iterator;
    typedef typename tree_type::const_reverse_iterator          const_reverse_iterator;

private:

    /* MEMBER ATTRIBUTES */
    tree_type _tree;

public:

    explicit map(const key_compare& comp = key_compare(), 
                 const allocator_type& alloc = allocator_type());

    template<typename InputIterator>
    map(InputIterator first,
        InputIterator last,
        const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type());

    map(const map& rhs);

    ~map();

    map& operator=(const map& rhs);

    /* ITERATORS */
    iterator                                   begin();
    const_iterator                             begin() const;
    iterator                                   end();
    const_iterator                             end() const;
    reverse_iterator                           rbegin();
    const_reverse_iterator                     rbegin() const;
    reverse_iterator                           rend();
    const_reverse_iterator                     rend() const;

    /* CAPACITY */
    bool                                       empty() const;
    size_type                                  size() const;
    size_type                                  max_size() const;

    /* ELEMENT ACCESS */
    mapped_type&                               operator[](const key_type& k);
    mapped_type&                               at(const key_type& k);
    const mapped_type&                         at(const key_type& k) const;

    /* MODIFIERS */
    ft::pair<iterator, bool>                   insert(const value_type &val);
    iterator                                   insert(iterator position, const value_type& val);
    template<typename InputIterator>
    void                                       insert(InputIterator first, InputIterator last);
    void                                       erase(iterator position);
    size_type                                  erase(const key_type& k);
    void                                       erase(iterator first, iterator last);
    void                                       swap(map& x);
    void                                       clear();

    /* OBSERVERS */
    key_compare                                key_comp() const;
    value_compare                              value_comp() const;

    /* OPERATIONS */
    iterator                                   find(const key_type& k);
    const_iterator                             find(const key_type& k) const;
    size_type                                  count(const key_type& k) const;
    iterator                                   lower_bound(const key_type& k);
    const_iterator                             lower_bound(const key_type& k) const;
    iterator                                   upper_bound(const key_type& k);
    const_iterator                             upper_bound(const key_type& k) const;
    ft::pair<iterator, iterator>               equal_range(const key_type& k);
    ft::pair<const_iterator, const_iterator>   equal_range(const key_type& k) const;
    
    /* ALLOCATOR */
    allocator_type                             get_allocator() const;

};

/* ************************************************************************** */
/*                                      MAP                                   */
/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
map<Key, T, Compare, Alloc>::map(const key_compare& comp, const allocator_type& alloc)
: _tree(value_compare(comp), alloc) {}


template<typename Key, typename T, typename Compare, typename Alloc>
template <class InputIterator>
map<Key, T, Compare, Alloc>::map(InputIterator first,
                                 InputIterator last,
                                 const key_compare& comp,
                                 const allocator_type& alloc)
: _tree(first, last, value_compare(comp), alloc) {}


template<typename Key, typename T, typename Compare, typename Alloc>
map<Key, T, Compare, Alloc>::map(const map& rhs)
: _tree(rhs._tree) {}

/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
map<Key, T, Compare, Alloc>::~map() {}

/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
map<Key, T, Compare, Alloc>&
map<Key, T, Compare, Alloc>::operator=(const map& rhs)
{
    if (this != &rhs)
        this->_tree = rhs._tree;
    return *this;
}

/* ************************************************************************** */
/*                                   ITERATORS                                */
/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
inline
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::begin()
{ return _tree.begin(); }


template<typename Key, typename T, typename Compare, typename Alloc>
inline
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::begin() const
{ return _tree.begin(); }

/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
inline
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::end()
{ return _tree.end(); }


template<typename Key, typename T, typename Compare, typename Alloc>
inline
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::end() const
{ return _tree.end(); }

/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::reverse_iterator
map<Key, T, Compare, Alloc>::rbegin()
{ return _tree.rbegin(); }


template<typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::const_reverse_iterator
map<Key, T, Compare, Alloc>::rbegin() const
{ return _tree.rbegin(); }

/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::reverse_iterator
map<Key, T, Compare, Alloc>::rend()
{ return _tree.rend(); }


template<typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::const_reverse_iterator
map<Key, T, Compare, Alloc>::rend() const
{ return _tree.rend(); }

/* ************************************************************************** */
/*                                   CAPACITY                                 */
/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
inline
bool
map<Key, T, Compare, Alloc>::empty() const
{ return _tree.empty(); }

/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
inline
typename map<Key, T, Compare, Alloc>::size_type
map<Key, T, Compare, Alloc>::size() const
{ return _tree.size(); }

/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
inline
typename map<Key, T, Compare, Alloc>::size_type
map<Key, T, Compare, Alloc>::max_size() const
{ return _tree.max_size(); }

/* ************************************************************************** */
/*                                 ELEMENT ACCESS                             */
/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::mapped_type&
map<Key, T, Compare, Alloc>::operator[](const key_type& k)
{ return insert(ft::make_pair(k, mapped_type())).first->second; }

/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::mapped_type&
map<Key, T, Compare, Alloc>::at(const key_type& k)
{
    iterator tmp = _tree.find(ft::make_pair(k, mapped_type()));
    if (tmp == end())
        throw std::out_of_range("ft::map");
    return (*tmp).second;
}


template<typename Key, typename T, typename Compare, typename Alloc>
const typename map<Key, T, Compare, Alloc>::mapped_type&
map<Key, T, Compare, Alloc>::at(const key_type& k) const
{
    const_iterator tmp = _tree.find(ft::make_pair(k, mapped_type()));
    if (tmp == end())
        throw std::out_of_range("ft::map");
    return (*tmp).second;
}

/* ************************************************************************** */
/*                                   MODIFIERS                                */
/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
typename ft::pair<typename map<Key, T, Compare, Alloc>::iterator, bool>
map<Key, T, Compare, Alloc>::insert(const value_type &val)
{ return _tree.insert(val); }


template<typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::insert(iterator position, const value_type& val)
{ return _tree.insert(position, val); }


template<typename Key, typename T, typename Compare, typename Alloc>
template<typename InputIterator>
void
map<Key, T, Compare, Alloc>::insert(InputIterator first, InputIterator last)
{ _tree.insert(first, last); }

/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
void
map<Key, T, Compare, Alloc>::erase(iterator position)
{ _tree.erase(position); }


template<typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::size_type
map<Key, T, Compare, Alloc>::erase(const key_type& k)
{ return _tree.erase(ft::make_pair(k, mapped_type())); }


template<typename Key, typename T, typename Compare, typename Alloc>
void 
map<Key, T, Compare, Alloc>::erase(iterator first, iterator last)
{ _tree.erase(first, last); }

/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
void
map<Key, T, Compare, Alloc>::swap(map& x)
{ _tree.swap(x._tree); }

/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
void
map<Key, T, Compare, Alloc>::clear(void)
{ _tree.clear(); }

/* ************************************************************************** */
/*                                   OBSERVERS                                */
/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::key_compare
map<Key, T, Compare, Alloc>::key_comp(void) const
{ return key_compare(); }

/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::value_compare
map<Key, T, Compare, Alloc>::value_comp(void) const
{ return value_compare(key_compare()); }

/* ************************************************************************** */
/*                                   OPERATIONS                               */
/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::find(const key_type& k)
{ return _tree.find(ft::make_pair(k, mapped_type())); }


template<typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::find(const key_type& k) const
{ return _tree.find(ft::make_pair(k, mapped_type())); }

/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::size_type
map<Key, T, Compare, Alloc>::count(const key_type& k) const
{ return _tree.count(ft::make_pair(k, mapped_type())); }

/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::lower_bound(const key_type& k)
{ return _tree.lower_bound(ft::make_pair(k, mapped_type())); }


template<typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::lower_bound(const key_type& k) const
{ return _tree.lower_bound(ft::make_pair(k, mapped_type())); }

/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::upper_bound(const key_type& k)
{ return _tree.upper_bound(ft::make_pair(k, mapped_type())); }


template<typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator
map<Key, T, Compare, Alloc>::upper_bound(const key_type& k) const
{ return _tree.upper_bound(ft::make_pair(k, mapped_type())); }

/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
pair<typename map<Key, T, Compare, Alloc>::iterator,
     typename map<Key, T, Compare, Alloc>::iterator>
map<Key, T, Compare, Alloc>::equal_range(const key_type& k)
{ return _tree.equal_range(ft::make_pair(k, mapped_type())); }


template<typename Key, typename T, typename Compare, typename Alloc>
pair<typename map<Key, T, Compare, Alloc>::const_iterator,
     typename map<Key, T, Compare, Alloc>::const_iterator>
map<Key, T, Compare, Alloc>::equal_range(const key_type& k) const
{ return _tree.equal_range(ft::make_pair(k, mapped_type())); }

/* ************************************************************************** */
/*                                   ALLOCATOR                                */
/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
typename map<Key, T, Compare, Alloc>::allocator_type
map<Key, T, Compare, Alloc>::get_allocator(void) const
{ return _tree.get_allocator(); }

/* ************************************************************************** */
/*                                      MAP                                   */
/* ************************************************************************** */






/* ************************************************************************** */
/*                               NON-MEMBER FUNCTIONS                         */
/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
void
swap(map<Key, T, Compare, Alloc>& lhs, map<Key, T, Compare, Alloc>& rhs)
{ lhs.swap(rhs); }

/* ************************************************************************** */
/*                               RELATIONAL OPERATORS                         */
/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
bool
operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{ return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()); }

/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
bool
operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{ return !(lhs == rhs); }

/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
bool
operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{ return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }

/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
bool
operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{ return !(rhs < lhs); }

/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
bool
operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{ return rhs < lhs; }

/* ************************************************************************** */

template<typename Key, typename T, typename Compare, typename Alloc>
bool
operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
{ return !(lhs < rhs); }

/* ************************************************************************** */



}

#endif /* MAP_HPP */
