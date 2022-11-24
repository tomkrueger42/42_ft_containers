/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functional.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:42:33 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/11/15 20:09:20 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FUNCTIONAL_HPP
# define FUNCTIONAL_HPP

namespace ft
{



/* ************************************************************************** */
/*                         BINARY FUNCTION BASE CLASS                         */
/* ************************************************************************** */

template<typename Arg1,
         typename Arg2,
         typename Result>
struct binary_function
{

    /* MEMBER TYPES */
    typedef Arg1            first_argument_type;
    typedef Arg2            second_argument_type;
    typedef Result          result_type;

};

/* ************************************************************************** */
/*                                    LESS                                    */
/* ************************************************************************** */

template <typename T>
struct less : public binary_function<T, T, bool>
{

    /* MEMBER FUNCTIONS */
    bool operator()(const T& lhs, const T& rhs) const { return lhs < rhs; }

};

/* ************************************************************************** */



}

#endif /* FUNCTIONAL_HPP */
