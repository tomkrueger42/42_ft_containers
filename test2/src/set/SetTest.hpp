/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SetTest.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:25:39 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/11/24 16:27:22 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SET_TEST_HPP
# define SET_TEST_HPP

# include "../../inc/set.hpp"
# include "../../inc/utils/colours.hpp"

/* ************************************************************************** */
/*                                   SET TEST                                 */
/* ************************************************************************** */

class SetTest
{

public:

    SetTest();
    ~SetTest();

    void run();

private:

    void (SetTest::*_tests[22]) (bool);

    /* utility */
    void _print_image() const;
    void _print_welcome_message() const;
    void _print_goodbye_message() const;

    /* examples :: from cplusplus.com */
    void _set_ctor(bool isSTD);
    void _set_assignment(bool isSTD);

    /* iterators */
    void _set_iterator(bool isSTD);
    void _set_riterator(bool isSTD);

    /* capacity */
    void _set_empty(bool isSTD);
    void _set_size(bool isSTD);
    void _set_max_size(bool isSTD);

    /* modifiers */
    void _set_insert(bool isSTD);
    void _set_erase(bool isSTD);
    void _set_swap(bool isSTD);
    void _set_clear(bool isSTD);

    /* observers */
    void _set_key_comp(bool isSTD);
    void _set_value_comp(bool isSTD);

    /* operations */
    void _set_find(bool isSTD);
    void _set_count(bool isSTD);
    void _set_bounds(bool isSTD);
    void _set_equal_range(bool isSTD);

    /* allocator */
    void _set_allocator(bool isSTD);

    /* non-member functions */
    void _set_relational_operators(bool isSTD);
    void _set_external_swap(bool isSTD);

    /* leaks */
    void _set_leaks(bool isSTD);

};

/* ************************************************************************** */
/*                                   SET TEST                                 */
/* ************************************************************************** */

#endif /* SET_TEST_HPP */
