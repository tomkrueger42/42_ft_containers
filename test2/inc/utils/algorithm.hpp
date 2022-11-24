/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:45:00 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/11/21 22:27:05 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

namespace ft
{



/* ************************************************************************** */
/*                                     EQUAL                                  */
/* ************************************************************************** */

template<typename InputIterator1, typename InputIterator2>
bool
equal(InputIterator1 first1, InputIterator1 last1,
      InputIterator2 first2)
{
    while (first1 != last1)
    {
        if (!(*first1 == *first2))
            return false;
        ++first1;
        ++first2;
    }
    return true;
}

/* ************************************************************************** */

template<typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
bool
equal(InputIterator1 first1, InputIterator1 last1,
      InputIterator2 first2,
      BinaryPredicate pred)
{
    while (first1 != last1)
    {
        if (!pred(*first1, *first2))
            return false;
        ++first1;
        ++first2;
    }
    return true;
}

/* ************************************************************************** */
/*                          LEXICOGRAPHICAL COMPARE                           */
/* ************************************************************************** */

template<typename InputIterator1, typename InputIterator2>
bool
lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                        InputIterator2 first2, InputIterator2 last2)
{
    while (first1 != last1)
    {
        if (first2 == last2 || *first2 < *first1)
            return false;
        else if (*first1 < *first2)
            return true;
        ++first1;
        ++first2;
    }
    return first2 != last2;
}

/* ************************************************************************** */

template<typename InputIterator1, typename InputIterator2, typename Compare>
bool
lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                        InputIterator2 first2, InputIterator2 last2,
                        Compare comp)
{
    while (first1 != last1)
    {
        if (first2 == last2 || comp(*first2, *first1))
            return false;
        else if (comp(*first1, *first2))
            return true;
        ++first1;
        ++first2;
    }
    return first2 != last2;
}

/* ************************************************************************** */
/*                                      SWAP                                  */
/* ************************************************************************** */

template<typename T>
void
swap(T& a, T& b)
{
    T c(a);
    a = b;
    b = c;
}



}

#endif /* ALGORITHM_HPP */
