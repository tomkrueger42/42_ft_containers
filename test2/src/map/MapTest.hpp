/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapTest.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:13:22 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/11/24 16:27:28 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MAP_TEST_HPP
# define MAP_TEST_HPP

# include "../../inc/map.hpp"
# include "../../inc/utils/colours.hpp"

/* ************************************************************************** */
/*                                   MAP TEST                                 */
/* ************************************************************************** */

class MapTest
{

public:

    MapTest();
    ~MapTest();

    void run();

private:

    void (MapTest::*_tests[23]) (bool);

    /* utility */
    void _print_image() const;
    void _print_welcome_message() const;
    void _print_goodbye_message() const;

    /* examples :: from cplusplus.com */
    void _map_ctor(bool isSTD);
    void _map_assignment(bool isSTD);

    /* iterators */
    void _map_iterator(bool isSTD);
    void _map_riterator(bool isSTD);

    /* capacity */
    void _map_empty(bool isSTD);
    void _map_size(bool isSTD);
    void _map_max_size(bool isSTD);

    /* element access */
    void _map_brackets(bool isSTD);
    void _map_at(bool isSTD);

    /* modifiers */
    void _map_insert(bool isSTD);
    void _map_erase(bool isSTD);
    void _map_swap(bool isSTD);
    void _map_clear(bool isSTD);

    /* observers */
    void _map_key_comp(bool isSTD);
    void _map_value_comp(bool isSTD);

    /* operations */
    void _map_find(bool isSTD);
    void _map_count(bool isSTD);
    void _map_bounds(bool isSTD);
    void _map_equal_range(bool isSTD);

    /* allocator */
    void _map_allocator(bool isSTD);

    /* non-member functions */
    void _map_relational_operators(bool isSTD);
    void _map_external_swap(bool isSTD);

    /* leaks */
    void _map_leaks(bool isSTD);

};

/* ************************************************************************** */
/*                                   MAP TEST                                 */
/* ************************************************************************** */

#endif /* MAP_TEST_HPP */
