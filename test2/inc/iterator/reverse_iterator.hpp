/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 00:14:50 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/11/17 01:20:48 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator.hpp"

namespace ft
{



/* ************************************************************************** */
/*                                REVERSE ITERATOR                            */
/* ************************************************************************** */

template<typename Iter>
class reverse_iterator
{
public:

    /* MEMBER TYPES */
    typedef Iter                                                    iterator_type;
    typedef typename iterator_traits<Iter>::value_type              value_type;
    typedef typename iterator_traits<Iter>::pointer                 pointer;
    typedef typename iterator_traits<Iter>::reference               reference;
    typedef typename iterator_traits<Iter>::difference_type         difference_type;
    typedef typename iterator_traits<Iter>::iterator_category       iterator_category;

protected:

    /* MEMBER OBJECTS */
    iterator_type _iter;

public:

    reverse_iterator();
    explicit reverse_iterator(iterator_type it);
    template<typename U>
    reverse_iterator(const reverse_iterator<U>& rhs);
    ~reverse_iterator();

    template<typename U>
    reverse_iterator& operator=(const reverse_iterator<U>& rhs);

    /* ELEMENT ACCESS */
    reference                                       operator[](difference_type i) const;
    reference                                       operator*() const;
    pointer                                         operator->() const;

    /* ARITHMETIC ASSIGNMENT */
    reverse_iterator&                               operator+=(difference_type i);
    reverse_iterator&                               operator-=(difference_type i);

    /* ARITHMETIC */
    reverse_iterator                                operator+(difference_type i) const;
    reverse_iterator                                operator-(difference_type i) const;

    /* PREFIX */
    reverse_iterator&                               operator++();
    reverse_iterator&                               operator--();

    /* POSTFIX */
    reverse_iterator                                operator++(int);
    reverse_iterator                                operator--(int);

    /* ACCESSOR */
    iterator_type                                   base() const;

    /* CONSTANT CAST OVERLOAD */
    operator reverse_iterator<const iterator_type>() const;

};

/* ************************************************************************** */
/*                                REVERSE ITERATOR                            */
/* ************************************************************************** */

template<typename Iter>
reverse_iterator<Iter>::reverse_iterator()
: _iter() {}


template<typename Iter>
reverse_iterator<Iter>::reverse_iterator(iterator_type it)
: _iter(it) {}


template<typename Iter>
template<typename U>
reverse_iterator<Iter>::reverse_iterator(const reverse_iterator<U>& rhs)
: _iter(rhs.base()) {}

/* ************************************************************************** */

template<typename Iter>
reverse_iterator<Iter>::~reverse_iterator() {}

/* ************************************************************************** */

template<typename Iter>
template<typename U>
reverse_iterator<Iter>&
reverse_iterator<Iter>::operator=(const reverse_iterator<U>& rhs)
{
    this->_iter = rhs.base();
    return *this;
}

/* ************************************************************************** */
/*                                 ELEMENT ACCESS                             */
/* ************************************************************************** */

template<typename Iter>
inline
typename reverse_iterator<Iter>::reference
reverse_iterator<Iter>::operator[](difference_type i) const
{ return base()[-i-1]; }

/* ************************************************************************** */

template<typename Iter>
inline
typename reverse_iterator<Iter>::reference
reverse_iterator<Iter>::operator*() const
{
    iterator_type tmp(_iter);
    return *(--tmp);
}

/* ************************************************************************** */

template<typename Iter>
inline
typename reverse_iterator<Iter>::pointer
reverse_iterator<Iter>::operator->() const
{ return &(operator*()); }

/* ************************************************************************** */
/*                             ARITHMETIC ASSIGNMENT                          */
/* ************************************************************************** */

template<typename Iter>
inline
reverse_iterator<Iter>&
reverse_iterator<Iter>::operator+=(difference_type i)
{
    _iter -= i;
    return *this;
}


template<typename Iter>
inline
reverse_iterator<Iter>&
reverse_iterator<Iter>::operator-=(difference_type i)
{
    _iter += i;
    return *this;
}

/* ************************************************************************** */
/*                                 ARITHMETIC                                 */
/* ************************************************************************** */

template<typename Iter>
inline
reverse_iterator<Iter>
reverse_iterator<Iter>::operator+(difference_type i) const
{ return reverse_iterator(_iter - i); }


template<typename Iter>
inline
reverse_iterator<Iter>
reverse_iterator<Iter>::operator-(difference_type i) const
{ return reverse_iterator(_iter + i); }

/* ************************************************************************** */
/*                                   PREFIX                                   */
/* ************************************************************************** */

template<typename Iter>
inline
reverse_iterator<Iter>&
reverse_iterator<Iter>::operator++()
{
    --_iter;
    return *this;
}


template<typename Iter>
inline
reverse_iterator<Iter>&
reverse_iterator<Iter>::operator--()
{
    ++_iter;
    return *this;
}

/* ************************************************************************** */
/*                                  POSTFIX                                   */
/* ************************************************************************** */

template<typename Iter>
inline
reverse_iterator<Iter>
reverse_iterator<Iter>::operator++(int)
{
    reverse_iterator tmp(*this);
    --_iter;
    return tmp;
}


template<typename Iter>
inline
reverse_iterator<Iter>
reverse_iterator<Iter>::operator--(int)
{
    reverse_iterator tmp(*this);
    ++_iter;
    return tmp;
}

/* ************************************************************************** */
/*                                   ACCESSOR                                 */
/* ************************************************************************** */

template<typename Iter>
inline
typename reverse_iterator<Iter>::iterator_type
reverse_iterator<Iter>::base() const
{ return _iter; }

/* ************************************************************************** */
/*                             CONSTANT CAST OVERLOAD                         */
/* ************************************************************************** */

template<typename Iter>
inline
reverse_iterator<Iter>::operator reverse_iterator<const iterator_type>() const
{ return _iter; }

/* ************************************************************************** */
/*                                REVERSE ITERATOR                            */
/* ************************************************************************** */






/* ************************************************************************** */
/*                               NON-MEMBER FUNCTIONS                         */
/* ************************************************************************** */

/* ************************************************************************** */
/*                               RELATIONAL OPERATORS                         */
/* ************************************************************************** */

template<typename Iter>
inline
bool
operator==(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
{ return lhs.base() == rhs.base(); }


template<typename Iter1, typename Iter2>
inline
bool
operator==(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
{ return lhs.base() == rhs.base(); }

/* ************************************************************************** */

template<typename Iter>
inline
bool
operator!=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
{ return lhs.base() != rhs.base(); }


template<typename Iter1, typename Iter2>
inline
bool
operator!=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
{ return lhs.base() != rhs.base(); }

/* ************************************************************************** */

template<typename Iter>
inline
bool
operator<(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
{ return lhs.base() > rhs.base(); }


template<typename Iter1, typename Iter2>
inline
bool
operator<(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
{ return lhs.base() > rhs.base(); }

/* ************************************************************************** */

template<typename Iter>
inline
bool
operator<=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
{ return lhs.base() >= rhs.base(); }


template<typename Iter1, typename Iter2>
inline
bool
operator<=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
{ return lhs.base() >= rhs.base(); }

/* ************************************************************************** */

template<typename Iter>
inline
bool
operator>(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
{ return lhs.base() < rhs.base(); }


template<typename Iter1, typename Iter2>
inline
bool
operator>(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
{ return lhs.base() < rhs.base(); }

/* ************************************************************************** */

template<typename Iter>
inline
bool
operator>=(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
{ return lhs.base() <= rhs.base(); }


template<typename Iter1, typename Iter2>
inline
bool
operator>=(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
{ return lhs.base() <= rhs.base(); }

/* ************************************************************************** */
/*                                 ARITHMETIC                                 */
/* ************************************************************************** */

template<typename Iter>
reverse_iterator<Iter>
operator+(typename reverse_iterator<Iter>::difference_type i, const reverse_iterator<Iter>& rev_it)
{ return reverse_iterator<Iter>(rev_it.base() - i); }

/* ************************************************************************** */

template<typename Iter>
typename reverse_iterator<Iter>::difference_type
operator-(const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs)
{ return rhs.base() - lhs.base(); }


template<typename Iter1, typename Iter2>
typename reverse_iterator<Iter1>::difference_type
operator-(const reverse_iterator<Iter1>& lhs, const reverse_iterator<Iter2>& rhs)
{ return rhs.base() - lhs.base(); }

/* ************************************************************************** */



}

#endif /* REVERSE_ITERATOR_HPP */
