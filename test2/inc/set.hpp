/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:43:24 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/11/21 22:59:14 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SET_HPP
# define SET_HPP

# include "utils/red_black_tree.hpp"

namespace ft
{



template<typename T,
         typename Compare = ft::less<T>,
         typename Alloc = std::allocator<T> >
class set
{
public:

    /* MEMBER TYPES */
    typedef T                                                   key_type;
    typedef T                                                   value_type;
    typedef Compare                                             key_compare;
    typedef Compare                                             value_compare;
    typedef Alloc                                               allocator_type;
    typedef typename allocator_type::reference                  reference;
    typedef typename allocator_type::const_reference            const_reference;
    typedef typename allocator_type::pointer                    pointer;
    typedef typename allocator_type::const_pointer              const_pointer;
    typedef typename allocator_type::size_type                  size_type;
    typedef typename allocator_type::difference_type            difference_type;

    /* TREE TYPE */
    typedef ft::red_black_tree<value_type, value_compare, allocator_type> tree_type;

    /* ITERATOR TYPES */
    typedef typename tree_type::const_iterator                  iterator;
    typedef typename tree_type::const_iterator                  const_iterator;
    typedef typename tree_type::const_reverse_iterator          reverse_iterator;
    typedef typename tree_type::const_reverse_iterator          const_reverse_iterator;

private:

    /* MEMBER ATTRIBUTES */
    tree_type _tree;

public:

    explicit set(const key_compare& comp = key_compare(),
                 const allocator_type& = allocator_type());

    template<typename InputIterator>
    set(InputIterator first, 
        InputIterator last,
        const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type());

    set(const set& rhs);

    ~set();

    set& operator=(const set& rhs);

    /* ITERATORS */

    iterator                        begin();
    const_iterator                  begin() const;
    iterator                        end();
    const_iterator                  end() const;
    reverse_iterator                rbegin();
    const_reverse_iterator          rbegin() const;
    reverse_iterator                rend();
    const_reverse_iterator          rend() const;

    /* CAPACITY */
    bool                            empty() const;
    size_type                       size() const;
    size_type                       max_size() const;

    /* MODIFIERS */
    ft::pair<iterator, bool>        insert(const value_type& val);
    iterator                        insert(iterator position, const value_type& val);
    template<typename InputIterator>
    void                            insert(InputIterator first, InputIterator last);
    void                            erase(iterator position);
    size_type                       erase(const value_type& val);
    void                            erase(iterator first, iterator last);
    void                            swap(set& x);
    void                            clear();

    /* OBSERVERS */
    key_compare                     key_comp() const;
    value_compare                   value_comp() const;

    /* OPERATIONS */
    iterator                        find(const value_type& val) const;
    size_type                       count(const value_type& val) const;
    iterator                        lower_bound(const value_type& val) const;
    iterator                        upper_bound(const value_type& val) const;
    ft::pair<iterator, iterator>    equal_range(const value_type& val) const;

    /* ALLOCATOR */
    allocator_type                  get_allocator() const;

};

/* ************************************************************************** */
/*                                      SET                                   */
/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
set<T, Compare, Alloc>::set(const key_compare& comp, const allocator_type& alloc)
: _tree(comp, alloc) {}


template<typename T, typename Compare, typename Alloc>
template<typename InputIterator>
set<T, Compare, Alloc>::set(InputIterator first, 
                            InputIterator last,
                            const key_compare& comp,
                            const allocator_type& alloc)
: _tree(first, last, comp, alloc) {}


template<typename T, typename Compare, typename Alloc>
set<T, Compare, Alloc>::set(const set& rhs)
: _tree(rhs._tree) {}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
set<T, Compare, Alloc>::~set() {}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
set<T, Compare, Alloc>&
set<T, Compare, Alloc>::operator=(const set& rhs)
{
    if (this != &rhs)
        this->_tree = rhs._tree;
    return *this;
}

/* ************************************************************************** */
/*                                   ITERATORS                                */
/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename set<T, Compare, Alloc>::iterator
set<T, Compare, Alloc>::begin()
{ return _tree.begin(); }


template<typename T, typename Compare, typename Alloc>
typename set<T, Compare, Alloc>::const_iterator
set<T, Compare, Alloc>::begin() const
{ return _tree.begin(); }

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename set<T, Compare, Alloc>::iterator
set<T, Compare, Alloc>::end()
{ return _tree.end(); }


template<typename T, typename Compare, typename Alloc>
typename set<T, Compare, Alloc>::const_iterator
set<T, Compare, Alloc>::end() const
{ return _tree.end(); }

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename set<T, Compare, Alloc>::reverse_iterator
set<T, Compare, Alloc>::rbegin()
{ return _tree.rbegin(); }


template<typename T, typename Compare, typename Alloc>
typename set<T, Compare, Alloc>::const_reverse_iterator
set<T, Compare, Alloc>::rbegin() const
{ return _tree.rbegin(); }

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename set<T, Compare, Alloc>::reverse_iterator
set<T, Compare, Alloc>::rend()
{ return _tree.rend(); }


template<typename T, typename Compare, typename Alloc>
typename set<T, Compare, Alloc>::const_reverse_iterator
set<T, Compare, Alloc>::rend() const
{ return _tree.rend(); }

/* ************************************************************************** */
/*                                   CAPACITY                                 */
/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
bool
set<T, Compare, Alloc>::empty() const
{ return _tree.empty(); }

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename set<T, Compare, Alloc>::size_type
set<T, Compare, Alloc>::size() const
{ return _tree.size(); }

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename set<T, Compare, Alloc>::size_type
set<T, Compare, Alloc>::max_size() const
{ return _tree.max_size(); }

/* ************************************************************************** */
/*                                   MODIFIERS                                */
/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
ft::pair<typename set<T, Compare, Alloc>::iterator, bool>
set<T, Compare, Alloc>::insert(const value_type& val)
{ return _tree.insert(val); }


template<typename T, typename Compare, typename Alloc>
typename set<T, Compare, Alloc>::iterator
set<T, Compare, Alloc>::insert(iterator position, const value_type& val)
{
    (void)position;
    return _tree.insert(val).first;
}


template<typename T, typename Compare, typename Alloc>
template<typename InputIterator>
void
set<T, Compare, Alloc>::insert(InputIterator first, InputIterator last)
{
    for (; first != last; ++first)
        _tree.insert(*first);
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
void
set<T, Compare, Alloc>::erase(iterator position)
{ _tree.erase(*position); }


template<typename T, typename Compare, typename Alloc>
typename set<T, Compare, Alloc>::size_type
set<T, Compare, Alloc>::erase(const value_type& val)
{ return _tree.erase(val); }


template<typename T, typename Compare, typename Alloc>
void
set<T, Compare, Alloc>::erase(iterator first, iterator last)
{
    ft::vector<value_type> tmp;

    for (; first != last; ++first)
        tmp.push_back(*first);

    while (!tmp.empty())
    {
        erase(tmp.back());
        tmp.pop_back();
    }
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
void
set<T, Compare, Alloc>::swap(set& x)
{ _tree.swap(x._tree); }


template<typename T, typename Compare, typename Alloc>
void
set<T, Compare, Alloc>::clear()
{ _tree.clear(); }

/* ************************************************************************** */
/*                                   OBSERVERS                                */
/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename set<T, Compare, Alloc>::key_compare
set<T, Compare, Alloc>::key_comp() const
{ return key_compare(); }

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename set<T, Compare, Alloc>::value_compare
set<T, Compare, Alloc>::value_comp() const
{ return value_compare(key_compare()); }

/* ************************************************************************** */
/*                                   OPERATIONS                               */
/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename set<T, Compare, Alloc>::iterator
set<T, Compare, Alloc>::find(const value_type& val) const
{ return _tree.find(val); }

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename set<T, Compare, Alloc>::size_type
set<T, Compare, Alloc>::count(const value_type& val) const
{ return _tree.count(val); }

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename set<T, Compare, Alloc>::iterator
set<T, Compare, Alloc>::lower_bound(const value_type& val) const
{ return _tree.lower_bound(val); }

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename set<T, Compare, Alloc>::iterator
set<T, Compare, Alloc>::upper_bound(const value_type& val) const
{ return _tree.upper_bound(val); }

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
ft::pair<typename set<T, Compare, Alloc>::iterator,
          typename set<T, Compare, Alloc>::iterator>
set<T, Compare, Alloc>::equal_range(const value_type& val) const
{ return _tree.equal_range(val); }

/* ************************************************************************** */
/*                                   ALLOCATOR                                */
/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename set<T, Compare, Alloc>::allocator_type
set<T, Compare, Alloc>::get_allocator() const
{ return _tree.get_allocator(); }

/* ************************************************************************** */
/*                                      SET                                   */
/* ************************************************************************** */






/* ************************************************************************** */
/*                               NON-MEMBER FUNCTIONS                         */
/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
void
swap(set<T, Compare, Alloc>& lhs, set<T, Compare, Alloc>& rhs)
{ lhs.swap(rhs); }

/* ************************************************************************** */
/*                               RELATIONAL OPERATORS                         */
/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
bool
operator==(const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs)
{ return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()); }


template<typename T, typename Compare, typename Alloc>
bool
operator!=(const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs)
{ return !(lhs == rhs); }

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
bool
operator<(const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs)
{ return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }


template<typename T, typename Compare, typename Alloc>
bool
operator<=(const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs)
{ return !(rhs < lhs); }

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
bool
operator>(const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs)
{ return rhs < lhs; }


template<typename T, typename Compare, typename Alloc>
bool
operator>=(const set<T, Compare, Alloc>& lhs, const set<T, Compare, Alloc>& rhs)
{ return !(lhs < rhs); }

/* ************************************************************************** */



}

#endif /* SET_HPP */
