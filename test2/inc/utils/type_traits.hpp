/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 02:46:02 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/11/21 22:25:13 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft
{



/* ************************************************************************** */
/*                                   ENABLE IF                                */
/* ************************************************************************** */

template<bool, typename T = void>
struct enable_if {};

template<typename T>
struct enable_if<true, T>
{ typedef T type; };

/* ************************************************************************** */
/*                                  IS INTEGRAL                               */
/* ************************************************************************** */

template<typename T, T v>
struct integral_constant
{

    /* MEMBER TYPES */
    typedef T                           value_type;
    typedef integral_constant<T, v>     type;

    /* MEMBER CONSTANTS */
    static const value_type value = v;

    /* MEMBER FUNCTIONS */
    operator value_type() const { return value; }

};

/* ************************************************************************** */
/*                                SPECIALIZATIONS                             */
/* ************************************************************************** */

typedef integral_constant<bool, true>   true_type;
typedef integral_constant<bool, false>  false_type;

/* ************************************************************************** */

template<typename T>
struct is_integral : public false_type {};

/* ************************************************************************** */

template<>
struct is_integral<bool> : public true_type {};

template<>
struct is_integral<const bool> : public true_type {};

template<>
struct is_integral<volatile bool> : public true_type {};

template<>
struct is_integral<const volatile bool> : public true_type {};

/* ************************************************************************** */

template<>
struct is_integral<char> : public true_type {};

template<>
struct is_integral<const char> : public true_type {};

template<>
struct is_integral<volatile char> : public true_type {};

template<>
struct is_integral<const volatile char> : public true_type {};

/* ************************************************************************** */

template<>
struct is_integral<wchar_t> : public true_type {};

template<>
struct is_integral<const wchar_t> : public true_type {};

template<>
struct is_integral<volatile wchar_t> : public true_type {};

template<>
struct is_integral<const volatile wchar_t> : public true_type {};

/* ************************************************************************** */

template<>
struct is_integral<signed char> : public true_type {};

template<>
struct is_integral<const signed char> : public true_type {};

template<>
struct is_integral<volatile signed char> : public true_type {};

template<>
struct is_integral<const volatile signed char> : public true_type {};

/* ************************************************************************** */

template<>
struct is_integral<short int> : public true_type {};

template<>
struct is_integral<const short int> : public true_type {};

template<>
struct is_integral<volatile short int> : public true_type {};

template<>
struct is_integral<const volatile short int> : public true_type {};

/* ************************************************************************** */

template<>
struct is_integral<int> : public true_type {};

template<>
struct is_integral<const int> : public true_type {};

template<>
struct is_integral<volatile int> : public true_type {};

template<>
struct is_integral<const volatile int> : public true_type {};

/* ************************************************************************** */

template<>
struct is_integral<long int> : public true_type {};

template<>
struct is_integral<const long int> : public true_type {};

template<>
struct is_integral<volatile long int> : public true_type {};

template<>
struct is_integral<const volatile long int> : public true_type {};

/* ************************************************************************** */

template<>
struct is_integral<long long int> : public true_type {};

template<>
struct is_integral<const long long int> : public true_type {};

template<>
struct is_integral<volatile long long int> : public true_type {};

template<>
struct is_integral<const volatile long long int> : public true_type {};

/* ************************************************************************** */

template<>
struct is_integral<unsigned char> : public true_type {};

template<>
struct is_integral<const unsigned char> : public true_type {};

template<>
struct is_integral<volatile unsigned char> : public true_type {};

template<>
struct is_integral<const volatile unsigned char> : public true_type {};

/* ************************************************************************** */

template<>
struct is_integral<unsigned short int> : public true_type {};

template<>
struct is_integral<const unsigned short int> : public true_type {};

template<>
struct is_integral<volatile unsigned short int> : public true_type {};

template<>
struct is_integral<const volatile unsigned short int> : public true_type {};

/* ************************************************************************** */

template<>
struct is_integral<unsigned int> : public true_type {};

template<>
struct is_integral<const unsigned int> : public true_type {};

template<>
struct is_integral<volatile unsigned int> : public true_type {};

template<>
struct is_integral<const volatile unsigned int> : public true_type {};

/* ************************************************************************** */

template<>
struct is_integral<unsigned long int> : public true_type {};

template<>
struct is_integral<const unsigned long int> : public true_type {};

template<>
struct is_integral<volatile unsigned long int> : public true_type {};

template<>
struct is_integral<const volatile unsigned long int> : public true_type {};

/* ************************************************************************** */

template<>
struct is_integral<unsigned long long int> : public true_type {};

template<>
struct is_integral<const unsigned long long int> : public true_type {};

template<>
struct is_integral<volatile unsigned long long int> : public true_type {};

template<>
struct is_integral<const volatile unsigned long long int> : public true_type {};

/* ************************************************************************** */



}

#endif /* TYPE_TRAITS_HPP */
