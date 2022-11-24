/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:14:46 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/11/21 17:46:04 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef UTILITY_HPP
# define UTILITY_HPP

namespace ft
{



/* ************************************************************************** */
/*                                     PAIR                                   */
/* ************************************************************************** */

template<typename T1, typename T2>
struct pair
{

    /* MEMBER TYPES */
    typedef T1                     first_type;
    typedef T2                     second_type;

    /* MEMBER OBJECTS */
    first_type                     first;
    second_type                    second;

    /* MEMBER FUNCTIONS */
    pair() : first(), second() {};

    template<typename U1, typename U2> // added this c11 probably
    pair(const pair<U1, U2>& pr) : first(pr.first), second(pr.second) {}

    pair(const first_type& a, const second_type& b) : first(a), second(b) {}

    pair& operator=(const pair& rhs)
    {
        if (this != &rhs)
        {
            this->first = rhs.first;
            this->second = rhs.second;
        }
        return *this;
    }

};

/* ************************************************************************** */
/*                                     PAIR                                   */
/* ************************************************************************** */






/* ************************************************************************** */
/*                               NON-MEMBER FUNCTIONS                         */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                   MAKE PAIR                                */
/* ************************************************************************** */

template<typename T1, typename T2>
pair<T1, T2>
make_pair(T1 a, T2 b)
{ return pair<T1, T2>(a, b); }

/* ************************************************************************** */
/*                               RELATIONAL OPERATORS                         */
/* ************************************************************************** */

template<typename T1, typename T2>
inline
bool
operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{ return lhs.first == rhs.first && lhs.second == rhs.second; }

/* ************************************************************************** */

template<typename T1, typename T2>
inline
bool
operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{ return !(lhs == rhs); }

/* ************************************************************************** */

template<typename T1, typename T2>
inline
bool
operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{ return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }

/* ************************************************************************** */

template<typename T1, typename T2>
inline
bool
operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{ return !(rhs < lhs); }

/* ************************************************************************** */

template<typename T1, typename T2>
inline
bool
operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{ return rhs < lhs; }

/* ************************************************************************** */

template<typename T1, typename T2>
inline
bool
operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
{ return !(lhs < rhs); }

/* ************************************************************************** */



}

#endif /* UTILITY_H */
