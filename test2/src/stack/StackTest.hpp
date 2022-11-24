/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackTest.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:06:14 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/11/24 16:27:16 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef STACK_TEST_HPP
# define STACK_TEST_HPP

# include "../../inc/stack.hpp"
# include "../../inc/vector.hpp" 
# include "../../inc/utils/colours.hpp"

/* ************************************************************************** */
/*                                  STACK TEST                                */
/* ************************************************************************** */

class StackTest
{
public:

    StackTest();
    ~StackTest();

    void run();

private:

    void (StackTest::*_tests[8]) (bool);

    /* utility */
    void _print_image() const;
    void _print_welcome_message() const;
    void _print_goodbye_message() const;

    /* examples :: from cplusplus.com */
    void _stack_ctor(bool isSTD);

    /* member functions */
    void _stack_empty(bool isSTD);
    void _stack_size(bool isSTD);
    void _stack_top(bool isSTD);
    void _stack_push(bool isSTD);
    void _stack_pop(bool isSTD);

    /* non-member functions */
    void _stack_relational_operators(bool isSTD);

    /* leaks */
    void _stack_leaks(bool isSTD);

};

/* ************************************************************************** */
/*                                  STACK TEST                                */
/* ************************************************************************** */

#endif /* STACK_TEST_HPP */
