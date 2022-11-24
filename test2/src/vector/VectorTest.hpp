/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorTest.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:14:46 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/11/24 16:26:59 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef VECTOR_TEST_HPP
# define VECTOR_TEST_HPP

# include "../../inc/vector.hpp"
# include "../../inc/utils/colours.hpp"

/* ************************************************************************** */
/*                                 VECTOR TEST                                */
/* ************************************************************************** */

class VectorTest
{

public:

    VectorTest();
    ~VectorTest();

    void run();

private:

    void (VectorTest::*_tests[25]) (bool);

    /* utility */
    void _print_image() const;
    void _print_welcome_message() const;
    void _print_goodbye_message() const;

    /* examples :: from cplusplus.com */
    void _vector_ctor(bool isSTD);
    void _vector_assignment(bool isSTD);

    /* iterators */
    void _vector_iterator(bool isSTD);
    void _vector_riterator(bool isSTD);

    /* capacity */
    void _vector_size(bool isSTD);
    void _vector_max_size(bool isSTD);
    void _vector_resize(bool isSTD);
    void _vector_capacity(bool isSTD);
    void _vector_empty(bool isSTD);
    void _vector_reserve(bool isSTD);

    /* element access */
    void _vector_brackets(bool isSTD);
    void _vector_at(bool isSTD);
    void _vector_front(bool isSTD);
    void _vector_back(bool isSTD);

    /* modifiers */
    void _vector_assign(bool isSTD);
    void _vector_push_back(bool isSTD);
    void _vector_pop_back(bool isSTD);
    void _vector_insert(bool isSTD);
    void _vector_erase(bool isSTD);
    void _vector_swap(bool isSTD);
    void _vector_clear(bool isSTD);

    /* allocator */
    void _vector_allocator(bool isSTD);

    /* non-member functions */
    void _vector_relational_operators(bool isSTD);
    void _vector_external_swap(bool isSTD);

    /* leaks */
    void _vector_leaks(bool isSTD);

};

/* ************************************************************************** */
/*                                 VECTOR TEST                                */
/* ************************************************************************** */

#endif /* VECTOR_TEST_HPP */
