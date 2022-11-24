/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackTest.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:43:52 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/11/24 02:29:02 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StackTest.hpp"
#include <stack>
#include <vector>
#include <deque>

/* ************************************************************************** */
/*                                  STACK TEST                                */
/* ************************************************************************** */

StackTest::StackTest()
{
    _tests[0] = &StackTest::_stack_ctor;

    _tests[1] = &StackTest::_stack_empty;
    _tests[2] = &StackTest::_stack_size;
    _tests[3] = &StackTest::_stack_top;
    _tests[4] = &StackTest::_stack_push;
    _tests[5] = &StackTest::_stack_pop;

    _tests[6] = &StackTest::_stack_relational_operators;

    _tests[7] = &StackTest::_stack_leaks;
}

/* ************************************************************************** */

StackTest::~StackTest() {}

/* ************************************************************************** */
/*                                     MAIN                                   */
/* ************************************************************************** */

void StackTest::run()
{
    std::string buffer;

    system("clear");
    _print_welcome_message();
    std::getline(std::cin, buffer);

    for (int i = 0; i < 8; ++i)
    {
        system("clear");
        _print_image();
        (this->*_tests[i])(true);
        (this->*_tests[i])(false);


        std::cout << PRINT_PURPLE << "Press <Enter> to continue..." << PRINT_END << std::endl;
        std::getline(std::cin, buffer);
    }

    system("clear");
    _print_goodbye_message();
    std::getline(std::cin, buffer);
}

/* ************************************************************************** */
/*                                    UTILITY                                 */
/* ************************************************************************** */

void StackTest::_print_image() const
{
    std::cout << std::endl;
    std::cout << "            .     .               " << std::endl;
    std::cout << "           (\033[1;31m>\033[0m\\---/\033[1;31m<\033[0m)             " << std::endl;
    std::cout << "           ,'     `.              " << std::endl;
    std::cout << "          /  \033[1;33mq\033[0m   \033[1;33mp\033[0m  \\            " << std::endl;
    std::cout << "         (  >(_Y_)<  )            " << std::endl;
    std::cout << "          >-' \033[1;31m`-'\033[0m `-<-.           " << std::endl;
    std::cout << "         /  _.== ==.,- \\         " << std::endl;
    std::cout << "        /,    )`  '(    )         " << std::endl;
    std::cout << "       ; `._.'      `--<          " << std::endl;
    std::cout << "      :     \\        |  )        " << std::endl;
    std::cout << "      \\      )       ;_/  hjw    " << std::endl;
    std::cout << "       `._ _/_  ___.'-\\\\\\      " << std::endl;
    std::cout << "          `--\\\\\\               " << std::endl;
    std::cout << std::endl;
}

/* ************************************************************************** */

void StackTest::_print_welcome_message() const
{
    _print_image();
    std::cout << PRINT_BLUE << "Welcome to <StackTest>>." << PRINT_END << std::endl << std::endl;
    std::cout << PRINT_BLUE << "Press <Enter> to continue..." << PRINT_END << std::endl;
    std::cout << std::endl;
}

/* ************************************************************************** */

void StackTest::_print_goodbye_message() const
{
    std::cout << std::endl;
    std::cout << "            .     .               " << std::endl;
    std::cout << "           (\033[1;31m>\033[0m\\---/\033[1;31m<\033[0m)             " << std::endl;
    std::cout << "           ,'     `.              " << std::endl;
    std::cout << "          /  \033[1;33m^\033[0m   \033[1;33m^\033[0m  \\            " << std::endl;
    std::cout << "         (  >(_Y_)<  )  \033[1;34m;,'\033[0m       " << std::endl;
    std::cout << "          >-' \033[1;31m`U\033[0m_o_  \\ \033[1;34m;:;'\033[0m           " << std::endl;
    std::cout << "         /  ,-.'---`.__ \033[1;34m;\033[0m         " << std::endl;
    std::cout << "        /, ((j`=====',-\033[1;34m'\033[0m)         " << std::endl;
    std::cout << "       ; `._`-\\     /--<          " << std::endl;
    std::cout << "      :     \\ `-=-' |  )        " << std::endl;
    std::cout << "      \\      )       ;_/  hjw    " << std::endl;
    std::cout << "       `._ _/_  ___.'-\\\\\\      " << std::endl;
    std::cout << "          `--\\\\\\               " << std::endl;
    std::cout << std::endl;
    std::cout << PRINT_BLUE << "We hope you enjoyed <StackTest>." << PRINT_END << std::endl;
    std::cout << PRINT_BLUE << "Until next time!" << PRINT_END << std::endl;
    std::cout << std::endl;
}

/* ************************************************************************** */
/*                                    EXAMPLES                                */
/* ************************************************************************** */

void StackTest::_stack_ctor(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: CONSTRUCTOR ---" << PRINT_END << std::endl;


    std::deque<int> mydeque (3,100);          // deque with 3 elements
    std::vector<int> myvector (2,200);        // vector with 2 elements

    std::stack<int> first;                    // empty stack
    std::stack<int> second (mydeque);         // stack initialized to copy of deque

    std::stack<int,std::vector<int> > third;  // empty stack using vector
    std::stack<int,std::vector<int> > fourth (myvector);

    std::cout << "size of first: " << first.size() << std::endl;
    std::cout << "size of second: " << second.size() << std::endl;
    std::cout << "size of third: " << third.size() << std::endl;
    std::cout << "size of fourth: " << fourth.size() << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: CONSTRUCTOR ---" << PRINT_END << std::endl;


    std::deque<int> mydeque (3,100);          // deque with 3 elements
    ft::vector<int> myvector (2,200);        // vector with 2 elements

    ft::stack<int> first;                    // empty stack
    ft::stack<int,std::deque<int> > second (mydeque);         // stack initialized to copy of deque

    ft::stack<int,ft::vector<int> > third;  // empty stack using vector
    ft::stack<int,ft::vector<int> > fourth (myvector);

    std::cout << "size of first: " << first.size() << std::endl;
    std::cout << "size of second: " << second.size() << std::endl;
    std::cout << "size of third: " << third.size() << std::endl;
    std::cout << "size of fourth: " << fourth.size() << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */
/*                                MEMBER FUNCTIONS                            */
/* ************************************************************************** */

void StackTest::_stack_empty(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: EMPTY ---" << PRINT_END << std::endl;


    std::stack<int> mystack;
    int sum (0);

    for (int i=1;i<=10;i++) mystack.push(i);

    while (!mystack.empty())
    {
         sum += mystack.top();
         mystack.pop();
    }

    std::cout << "total: " << sum << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: EMPTY ---" << PRINT_END << std::endl;


    ft::stack<int> mystack;;

    int sum (0);

    for (int i=1;i<=10;i++) mystack.push(i);

    while (!mystack.empty())
    {
         sum += mystack.top();
         mystack.pop();
    }

    std::cout << "total: " << sum << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void StackTest::_stack_size(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: SIZE ---" << PRINT_END << std::endl;


    ft::stack<int> myints;
    std::cout << "0. size: " << myints.size() << std::endl;

    for (int i=0; i<5; i++) myints.push(i);
    std::cout << "1. size: " << myints.size() << std::endl;

    myints.pop();
    std::cout << "2. size: " << myints.size() << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: SIZE ---" << PRINT_END << std::endl;


    ft::stack<int> myints;
    std::cout << "0. size: " << myints.size() << std::endl;

    for (int i=0; i<5; i++) myints.push(i);
    std::cout << "1. size: " << myints.size() << std::endl;

    myints.pop();
    std::cout << "2. size: " << myints.size() << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void StackTest::_stack_top(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: TOP ---" << PRINT_END << std::endl;


    std::stack<int> mystack;

    mystack.push(10);
    mystack.push(20);

    mystack.top() -= 5;

    std::cout << "mystack.top() is now " << mystack.top() << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: TOP ---" << PRINT_END << std::endl;


    ft::stack<int> mystack;

    mystack.push(10);
    mystack.push(20);

    mystack.top() -= 5;

    std::cout << "mystack.top() is now " << mystack.top() << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void StackTest::_stack_push(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: PUSH ---" << PRINT_END << std::endl;


    std::stack<int> mystack;

    for (int i=0; i<5; ++i) mystack.push(i);

    std::cout << "Popping out elements...";
    while (!mystack.empty())
    {
        std::cout << ' ' << mystack.top();
        mystack.pop();
    }
    std::cout << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: PUSH ---" << PRINT_END << std::endl;


    ft::stack<int> mystack;

    for (int i=0; i<5; ++i) mystack.push(i);

    std::cout << "Popping out elements...";
    while (!mystack.empty())
    {
        std::cout << ' ' << mystack.top();
        mystack.pop();
    }
    std::cout << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void StackTest::_stack_pop(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: POP ---" << PRINT_END << std::endl;


    std::stack<int> mystack;

    for (int i=0; i<5; ++i) mystack.push(i);

    std::cout << "Popping out elements...";
    while (!mystack.empty())
    {
        std::cout << ' ' << mystack.top();
        mystack.pop();
    }
    std::cout << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: POP ---" << PRINT_END << std::endl;


    ft::stack<int> mystack;

    for (int i=0; i<5; ++i) mystack.push(i);

    std::cout << "Popping out elements...";
    while (!mystack.empty())
    {
        std::cout << ' ' << mystack.top();
        mystack.pop();
    }
    std::cout << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */
/*                               NON-MEMBER FUNCTIONS                         */
/* ************************************************************************** */

void StackTest::_stack_relational_operators(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: RELATIONAL_OPERATORS ---" << PRINT_END << std::endl;


    std::stack<int> foo,bar;
    foo.push (10); foo.push(20); foo.push(30);
    bar.push (111); bar.push(222);

    if (foo==bar) std::cout << "foo and bar are equal\n";
    if (foo!=bar) std::cout << "foo and bar are not equal\n";
    if (foo< bar) std::cout << "foo is less than bar\n";
    if (foo> bar) std::cout << "foo is greater than bar\n";
    if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
    if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
    std::cout << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: RELATIONAL_OPERATORS ---" << PRINT_END << std::endl;


    ft::stack<int> foo,bar;
    foo.push (10); foo.push(20); foo.push(30);
    bar.push (111); bar.push(222);

    if (foo==bar) std::cout << "foo and bar are equal\n";
    if (foo!=bar) std::cout << "foo and bar are not equal\n";
    if (foo< bar) std::cout << "foo is less than bar\n";
    if (foo> bar) std::cout << "foo is greater than bar\n";
    if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
    if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
    std::cout << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */
/*                                    LEAKS                                   */
/* ************************************************************************** */

void StackTest::_stack_leaks(bool isSTD)
{
    if (!isSTD)
        return ;
    system("leaks ft_containers");
    std::cout << std::endl;
}

/* ************************************************************************** */
/*                                  STACK TEST                                */
/* ************************************************************************** */
