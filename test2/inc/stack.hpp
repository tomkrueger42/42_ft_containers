/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 02:05:54 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/11/23 22:08:07 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{



/* ************************************************************************** */
/*                                    STACK                                   */
/* ************************************************************************** */

template<typename T,
         typename Container = ft::vector<T> >
class stack
{
public:

    /* MEMBER TYPES */
    typedef T                                            value_type;
    typedef Container                                    container_type;
    typedef typename container_type::reference           reference;
    typedef typename container_type::const_reference     const_reference;
    typedef typename container_type::pointer             pointer;
    typedef typename container_type::const_pointer       const_pointer;
    typedef typename container_type::size_type           size_type;
    typedef typename container_type::difference_type     difference_type;

protected:

    container_type c;

    template<typename U, typename V>
    friend bool operator==(const stack<U, V>& lhs, const stack<U, V>& rhs);
    template<typename U, typename V>
    friend bool operator<(const stack<U, V>& lhs, const stack<U, V>& rhs);

public:

    explicit stack(const container_type& ctnr = container_type());
    stack(const stack& rhs);
    ~stack();

    stack& operator=(const stack& rhs);

    /* CAPACITY */
    bool                            empty() const;
    size_type                       size() const;

    /* ELEMENT ACCESSS */
    value_type&                     top();
    const value_type&               top() const;

    /* MODIFIERS */
    void                            push(const value_type& val);
    void                            pop();

};

/* ************************************************************************** */
/*                                    STACK                                   */
/* ************************************************************************** */

template<typename T, typename Container>
stack<T, Container>::stack(const container_type& ctnr) : c(ctnr) {}


template<typename T, typename Container>
stack<T, Container>::stack(const stack& rhs) : c(rhs.c) {}

/* ************************************************************************** */

template<typename T, typename Container>
stack<T, Container>::~stack() {}

/* ************************************************************************** */

template<typename T, typename Container>
stack<T, Container>&
stack<T, Container>::operator=(const stack& rhs)
{
    if (this != &rhs)
        this->c = rhs.c;
    return *this;
}

/* ************************************************************************** */
/*                                   CAPACITY                                 */
/* ************************************************************************** */

template<typename T, typename Container>
inline
bool
stack<T, Container>::empty(void) const
{ return c.empty(); }

/* ************************************************************************** */

template<typename T, typename Container>
inline
typename stack<T, Container>::size_type
stack<T, Container>::size(void) const
{ return c.size(); }

/* ************************************************************************** */
/*                                ELEMENT ACCESS                              */
/* ************************************************************************** */

template<typename T, typename Container>
inline
typename stack<T, Container>::value_type&
stack<T, Container>::top(void)
{ return c.back(); }


template<typename T, typename Container>
inline
const typename stack<T, Container>::value_type&
stack<T, Container>::top(void) const
{ return c.back(); }

/* ************************************************************************** */
/*                                   MODIFIERS                                */
/* ************************************************************************** */

template<typename T, typename Container>
void
stack<T, Container>::push(const value_type& val)
{ c.push_back(val); }

/* ************************************************************************** */

template<typename T, typename Container>
void
stack<T, Container>::pop(void)
{ c.pop_back(); }

/* ************************************************************************** */
/*                                    STACK                                   */
/* ************************************************************************** */






/* ************************************************************************** */
/*                               NON-MEMBER FUNCTIONS                         */
/* ************************************************************************** */

/* ************************************************************************** */
/*                               RELATIONAL OPERATORS                         */
/* ************************************************************************** */

template<typename T, typename Container>
bool
operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{ return lhs.c == rhs.c; }


template<typename T, typename Container>
bool
operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{ return !(lhs == rhs); }

/* ************************************************************************** */

template<typename T, typename Container>
bool
operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{ return lhs.c < rhs.c; }


template<typename T, typename Container>
bool
operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{ return !(rhs < lhs); }

/* ************************************************************************** */

template<typename T, typename Container>
bool
operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{ return rhs < lhs; }


template<typename T, typename Container>
bool
operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
{ return !(lhs < rhs); }

/* ************************************************************************** */



}

#endif /* STACK_HPP */
