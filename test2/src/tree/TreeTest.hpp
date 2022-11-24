/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeTest.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:57:20 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/11/24 16:27:09 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef TREE_TEST_HPP
# define TREE_TEST_HPP

# include "../../inc/utils/red_black_tree.hpp"
# include "../../inc/utils/colours.hpp"

/* ************************************************************************** */
/*                                   TREE TEST                                */
/* ************************************************************************** */

class TreeTest
{

public:

    TreeTest();
    ~TreeTest();

    void run();

private:

    ft::red_black_tree<int, ft::less<int>, std::allocator<int> > _tree;

    /* utility */
    void _print_welcome_message();
    void _print_goodbye_message();

    /* examples */
    void _insert(int n);
    void _delete(int n);

    /* print */
    void _print_tree() const;
    void _print_black() const;
    void _print_single() const;
    void _print_small() const;
    void _print_medium() const;
    void _print_large() const;
    void _print_vibrant() const;

};

/* ************************************************************************** */
/*                                   TREE TEST                                */
/* ************************************************************************** */

#endif /* TREE_TEST_HPP */
