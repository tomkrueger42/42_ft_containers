/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 00:07:29 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/11/21 23:02:44 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator.hpp"

namespace ft
{



/* ************************************************************************** */
/*                              RANDOM ACCESS ITERATOR                        */
/* ************************************************************************** */

template<typename T>
class random_access_iterator
{
public:

    /* MEMBER TYPES */
    typedef T*                                                           iterator_type;
    typedef typename iterator_traits<iterator_type>::value_type          value_type;
    typedef typename iterator_traits<iterator_type>::pointer             pointer;
    typedef typename iterator_traits<iterator_type>::reference           reference;
    typedef typename iterator_traits<iterator_type>::difference_type     difference_type;
    typedef typename iterator_traits<iterator_type>::iterator_category   iterator_category;

protected:

    /* MEMBER ATTRIBUTES */
    iterator_type _ptr;

public:

    random_access_iterator();
    random_access_iterator(const iterator_type& ptr);
    random_access_iterator(const random_access_iterator& rhs);
    ~random_access_iterator();

    random_access_iterator& operator=(const random_access_iterator& rhs);

    /* ELEMENT ACCESS */
    reference                                       operator[](difference_type i) const;
    reference                                       operator*() const;
    pointer                                         operator->() const;

    /* ARITHMETIC ASSIGNMENT */
    random_access_iterator&                         operator+=(difference_type i);
    random_access_iterator&                         operator-=(difference_type i);

    /* ARITHMETIC */
    random_access_iterator                          operator+(difference_type i) const;
    random_access_iterator                          operator-(difference_type i) const;

    /* PREFIX */
    random_access_iterator&                         operator++();
    random_access_iterator&                         operator--();

    /* POSTFIX */
    random_access_iterator                          operator++(int);
    random_access_iterator                          operator--(int);

    /* ACCESSOR */
    iterator_type                                   base() const;

     /* CONSTANT CAST OVERLOAD */
    operator random_access_iterator<const T>() const;

};

/* ************************************************************************** */
/*                              RANDOM ACCESS ITERATOR                        */
/* ************************************************************************** */

template<typename T>
random_access_iterator<T>::random_access_iterator()
: _ptr() {}


template<typename T>
random_access_iterator<T>::random_access_iterator(const iterator_type& ptr)
: _ptr(ptr) {}


template<typename T>
random_access_iterator<T>::random_access_iterator(const random_access_iterator& rhs)
: _ptr(rhs._ptr) {}

/* ************************************************************************** */

template<typename T>
random_access_iterator<T>::~random_access_iterator() {}

/* ************************************************************************** */

template<typename T>
random_access_iterator<T>&
random_access_iterator<T>::operator=(const random_access_iterator& rhs)
{
    if (this != &rhs)
        this->_ptr = rhs.base();
    return *this;
}

/* ************************************************************************** */
/*                                 ELEMENT ACCESS                             */
/* ************************************************************************** */

template<typename T>
inline
typename random_access_iterator<T>::reference
random_access_iterator<T>::operator[](difference_type i) const
{ return *(_ptr + i); }

/* ************************************************************************** */

template<typename T>
inline
typename random_access_iterator<T>::reference
random_access_iterator<T>::operator*() const
{ return *_ptr; }

/* ************************************************************************** */

template<typename T>
inline
typename random_access_iterator<T>::pointer
random_access_iterator<T>::operator->() const
{ return _ptr; }

/* ************************************************************************** */
/*                             ARITHMETIC ASSIGNMENT                          */
/* ************************************************************************** */

template<typename T>
inline
random_access_iterator<T>&
random_access_iterator<T>::operator+=(difference_type i)
{
    _ptr += i;
    return *this;
}


template<typename T>
inline
random_access_iterator<T>&
random_access_iterator<T>::operator-=(difference_type i)
{
    _ptr -= i;
    return *this;
}

/* ************************************************************************** */
/*                                 ARITHMETIC                                 */
/* ************************************************************************** */

template<typename T>
inline
random_access_iterator<T>
random_access_iterator<T>::operator+(difference_type i) const
{ return random_access_iterator(_ptr + i); }


template<typename T>
inline
random_access_iterator<T>
random_access_iterator<T>::operator-(difference_type i) const
{ return random_access_iterator(_ptr - i); }

/* ************************************************************************** */
/*                                   PREFIX                                   */
/* ************************************************************************** */

template<typename T>
inline
random_access_iterator<T>&
random_access_iterator<T>::operator++()
{
    ++_ptr;
    return *this;
}


template<typename T>
inline
random_access_iterator<T>&
random_access_iterator<T>::operator--()
{
    --_ptr;
    return *this;
}

/* ************************************************************************** */
/*                                  POSTFIX                                   */
/* ************************************************************************** */

template<typename T>
inline
random_access_iterator<T>
random_access_iterator<T>::operator++(int)
{
    random_access_iterator tmp(*this);
    ++_ptr;
    return tmp;
}


template<typename T>
inline
random_access_iterator<T>
random_access_iterator<T>::operator--(int)
{
    random_access_iterator tmp(*this);
    --_ptr;
    return tmp;
}

/* ************************************************************************** */
/*                                   ACCESSOR                                 */
/* ************************************************************************** */

template<typename T>
inline
typename random_access_iterator<T>::iterator_type
random_access_iterator<T>::base() const
{ return _ptr; }

/* ************************************************************************** */
/*                             CONSTANT CAST OVERLOAD                         */
/* ************************************************************************** */

template<typename T>
inline
random_access_iterator<T>::operator random_access_iterator<const T>() const
{ return _ptr; }

/* ************************************************************************** */
/*                             RANDOM ACCESS ITERATOR                         */
/* ************************************************************************** */






/* ************************************************************************** */
/*                               NON-MEMBER FUNCTIONS                         */
/* ************************************************************************** */

/* ************************************************************************** */
/*                               RELATIONAL OPERATORS                         */
/* ************************************************************************** */

template<typename T>
inline
bool
operator==(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
{ return lhs.base() == rhs.base(); }


template<typename T1, typename T2>
inline
bool
operator==(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
{ return lhs.base() == rhs.base(); }

/* ************************************************************************** */

template<typename T>
inline
bool
operator!=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
{ return !(lhs == rhs); }


template<typename T1, typename T2>
inline
bool
operator!=(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
{ return !(lhs == rhs); }

/* ************************************************************************** */

template<typename T>
inline
bool
operator<(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
{ return lhs.base() < rhs.base(); }


template<typename T1, typename T2>
inline
bool
operator<(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
{ return lhs.base() < rhs.base(); }

/* ************************************************************************** */

template<typename T>
inline
bool
operator<=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
{ return !(rhs < lhs); }


template<typename T1, typename T2>
inline
bool
operator<=(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
{ return !(rhs < lhs); }

/* ************************************************************************** */

template<typename T>
inline
bool
operator>(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
{ return rhs < lhs; }


template<typename T1, typename T2>
inline
bool
operator>(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
{ return rhs < lhs; }

/* ************************************************************************** */

template<typename T>
inline
bool
operator>=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs)
{ return !(lhs < rhs); }


template<typename T1, typename T2>
inline
bool
operator>=(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs)
{ return !(lhs < rhs); }

/* ************************************************************************** */
/*                                 ARITHMETIC                                 */
/* ************************************************************************** */

template<typename T>
inline
random_access_iterator<T>
operator+(const typename random_access_iterator<T>::difference_type& i, const random_access_iterator<T>& iter)
{ return random_access_iterator<T>(iter.base() + i); }


template<typename T>
inline
random_access_iterator<T>
operator-(const typename random_access_iterator<T>::difference_type& i, const random_access_iterator<T>& iter)
{ return random_access_iterator<T>(iter.base() - i); }

/* ************************************************************************** */

template<typename T>
inline
typename random_access_iterator<T>::difference_type
operator+(const random_access_iterator<T>& rhs, const random_access_iterator<T>& lhs)
{ return rhs.base() + lhs.base(); }


template<typename T>
inline
typename random_access_iterator<T>::difference_type
operator-(const random_access_iterator<T>& rhs, const random_access_iterator<T>& lhs)
{ return rhs.base() - lhs.base(); }

/* ************************************************************************** */

template<typename T1, typename T2>
inline
typename random_access_iterator<T1>::difference_type
operator+(const random_access_iterator<T1>& rhs, const random_access_iterator<T2>& lhs)
{ return rhs.base() + lhs.base(); }


template<typename T1, typename T2>
inline
typename random_access_iterator<T1>::difference_type
operator-(const random_access_iterator<T1>& rhs, const random_access_iterator<T2>& lhs)
{ return rhs.base() - lhs.base(); }

/* ************************************************************************** */



}

#endif /* RANDOM_ACCESS_ITERATOR_HPP */
