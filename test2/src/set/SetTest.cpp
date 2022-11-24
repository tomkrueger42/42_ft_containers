/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SetTest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:34:20 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/11/24 02:28:40 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SetTest.hpp"
#include <set>

/* ************************************************************************** */
/*                                   SET TEST                                 */
/* ************************************************************************** */

SetTest::SetTest()
{
    _tests[0] = &SetTest::_set_ctor;
    _tests[1] = &SetTest::_set_assignment;

    _tests[2] = &SetTest::_set_iterator;
    _tests[3] = &SetTest::_set_riterator;

    _tests[4] = &SetTest::_set_empty;
    _tests[5] = &SetTest::_set_size;
    _tests[6] = &SetTest::_set_max_size;

    _tests[7] = &SetTest::_set_insert;
    _tests[8] = &SetTest::_set_erase;
    _tests[9] = &SetTest::_set_swap;
    _tests[10] = &SetTest::_set_clear;

    _tests[11] = &SetTest::_set_key_comp;
    _tests[12] = &SetTest::_set_value_comp;

    _tests[13] = &SetTest::_set_find;
    _tests[14] = &SetTest::_set_count;
    _tests[15] = &SetTest::_set_bounds;
    _tests[16] = &SetTest::_set_equal_range;
    
    _tests[17] = &SetTest::_set_allocator;

    _tests[18] = &SetTest::_set_relational_operators;
    _tests[19] = &SetTest::_set_external_swap;

    _tests[20] = &SetTest::_set_leaks;    
}

/* ************************************************************************** */

SetTest::~SetTest() {}

/* ************************************************************************** */
/*                                     MAIN                                   */
/* ************************************************************************** */

void SetTest::run()
{
    std::string buffer;

    system("clear");
    _print_welcome_message();
    std::getline(std::cin, buffer);

    for (int i = 0; i < 21; ++i)
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

void SetTest::_print_image() const
{
    std::cout << std::endl;
    std::cout << "     \033[1;31m.;:;:.\033[0m   " << std::endl;
    std::cout << "     \033[1;31m::;;':\033[0m   " << std::endl;
    std::cout << "   \033[1;32m_\033[0m \033[1;31m';:;;'\033[0m   " << std::endl;
    std::cout << "   \033[1;32m>'.\033[0m ||  \033[1;32m_\033[0m  " << std::endl;
    std::cout << "   \033[1;32m`> \\\033[0m||\033[1;32m.'<\033[0m  " << std::endl;
    std::cout << "     \033[1;32m`>\033[0m|\033[1;32m/ <`\033[0m  " << std::endl;
    std::cout << "      \033[1;32m`\033[0m||\033[1;32m/`\033[0m   " << std::endl;
    std::cout << "^jgs^^^^^^^^^^^" << std::endl;
    std::cout << std::endl;
}

/* ************************************************************************** */

void SetTest::_print_welcome_message() const
{
    _print_image();
    std::cout << PRINT_ORANGE << "Welcome to <SetTest>>." << PRINT_END << std::endl << std::endl;
    std::cout << PRINT_ORANGE << "Press <Enter> to continue..." << PRINT_END << std::endl;
    std::cout << std::endl;
}

/* ************************************************************************** */

void SetTest::_print_goodbye_message() const
{
    std::cout << std::endl;
    std::cout << "           \033[1;31m`::`\033[0m " << std::endl;
    std::cout << "            \033[1;32m/\033[0m   " << std::endl;
    std::cout << "           \033[1;32m`\033[0m    \033[1;31m`;:`\033[0m " << std::endl;
    std::cout << "                      " << std::endl;
    std::cout << "                      " << std::endl;
    std::cout << "     \033[1;31m.;:;\033[0m        \033[1;32m/\033[0m    " << std::endl;
    std::cout << "     \033[1;31m::;\033[0m        \033[1;32m`\033[0m     " << std::endl;
    std::cout << "   \033[1;32m_\033[0m \033[1;31m';:;;'\033[0m           " << std::endl;
    std::cout << "   \033[1;32m>'.\033[0m ||  \033[1;32m_\033[0m          " << std::endl;
    std::cout << "   \033[1;32m`> \\\033[0m||\033[1;32m.'<\033[0m          " << std::endl;
    std::cout << "     \033[1;32m`>\033[0m|\033[1;32m/ <`\033[0m          " << std::endl;
    std::cout << "      \033[1;32m`\033[0m||\033[1;32m/`\033[0m           " << std::endl;
    std::cout << "^jgs^^^^^^^^^^^       " << std::endl;
    std::cout << std::endl;
    std::cout << PRINT_ORANGE << "We hope you enjoyed <SetTest>." << PRINT_END << std::endl;
    std::cout << PRINT_ORANGE << "Until next time!" << PRINT_END << std::endl;
    std::cout << std::endl;
}

/* ************************************************************************** */
/*                                    EXAMPLES                                */
/* ************************************************************************** */

void SetTest::_set_ctor(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: CONSTRUCTOR ---" << PRINT_END << std::endl;


    std::set<std::string> first;
    std::set<std::string> second;
    second.insert("mango");
    second.insert("orange");
    second.insert("banana");
    second.insert("apple");
    second.insert("blueberry");
    std::cout << "Insert : mango, orange, banana, apple, blueberry ..." << std::endl << std::endl;


    std::set<std::string> third(second.begin(),second.end());
    std::set<std::string> fourth(third);

    std::cout << "std::set<std::string> first" << std::endl;
    for (std::set<std::string>::iterator it = first.begin(); it != first.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << std::endl;

    std::cout << "std::set<std::string> second (with added values)" << std::endl;
    for (std::set<std::string>::iterator it = second.begin(); it != second.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << std::endl;

        std::cout << "std::set<std::string> third(second.begin(),second.end())" << std::endl;
    for (std::set<std::string>::iterator it = third.begin(); it != third.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << std::endl;

        std::cout << "std::set<std::string> fourth(third)" << std::endl;
    for (std::set<std::string>::iterator it = fourth.begin(); it != fourth.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: CONSTRUCTOR ---" << PRINT_END << std::endl;


    ft::set<std::string> first;
    ft::set<std::string> second;
    second.insert("mango");
    second.insert("orange");
    second.insert("banana");
    second.insert("apple");
    second.insert("blueberry");
    std::cout << "Insert : mango, orange, banana, apple, blueberry ..." << std::endl << std::endl;


    ft::set<std::string> third(second.begin(),second.end());
    ft::set<std::string> fourth(third);

    std::cout << "ft::set<std::string> first" << std::endl;
    for (ft::set<std::string>::iterator it = first.begin(); it != first.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << std::endl;

    std::cout << "ft::set<std::string> second (with added values)" << std::endl;
    for (ft::set<std::string>::iterator it = second.begin(); it != second.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << std::endl;

        std::cout << "ft::set<std::string> third(second.begin(),second.end())" << std::endl;
    for (ft::set<std::string>::iterator it = third.begin(); it != third.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << std::endl;

        std::cout << "ft::set<std::string> fourth(third)" << std::endl;
    for (ft::set<std::string>::iterator it = fourth.begin(); it != fourth.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void SetTest::_set_assignment(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: ASSIGNMENT ---" << PRINT_END << std::endl;


    int myints[]={ 12,82,37,64,15 };
    std::set<int> first (myints,myints+5);   // set with 5 ints
    std::set<int> second;                    // empty set

    second = first;                          // now second contains the 5 ints
    first = std::set<int>();                 // and first is empty

    std::cout << "Size of first: " << int (first.size()) << std::endl;
    std::cout << "Size of second: " << int (second.size()) << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: ASSIGNMENT ---" << PRINT_END << std::endl;


    int myints[]={ 12,82,37,64,15 };
    ft::set<int> first (myints,myints+5);   // set with 5 ints
    ft::set<int> second;                    // empty set

    second = first;                          // now second contains the 5 ints
    first = ft::set<int>();                 // and first is empty

    std::cout << "Size of first: " << int (first.size()) << std::endl;
    std::cout << "Size of second: " << int (second.size()) << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */
/*                                   ITERATORS                                */
/* ************************************************************************** */

void SetTest::_set_iterator(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: ITERATOR ---" << PRINT_END << std::endl;


    int myints[] = {75,23,65,42,13};
    std::set<int> myset (myints,myints+5);

    std::cout << "myset contains:";
    for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: ITERATOR ---" << PRINT_END << std::endl;


    int myints[] = {75,23,65,42,13};
    ft::set<int> myset (myints,myints+5);

    std::cout << "myset contains:";
    for (ft::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */

void SetTest::_set_riterator(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: REVERSE_ITERATOR ---" << PRINT_END << std::endl;


    int myints[] = {21,64,17,78,49};
    std::set<int> myset (myints,myints+5);

    std::set<int>::reverse_iterator rit;

    std::cout << "myset contains:";
    for (rit=myset.rbegin(); rit != myset.rend(); ++rit)
        std::cout << ' ' << *rit;
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: REVERSE_ITERATOR ---" << PRINT_END << std::endl;


    int myints[] = {21,64,17,78,49};
    ft::set<int> myset (myints,myints+5);

    ft::set<int>::reverse_iterator rit;

    std::cout << "myset contains:";
    for (rit=myset.rbegin(); rit != myset.rend(); ++rit)
        std::cout << ' ' << *rit;
    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */
/*                                   CAPACITY                                 */
/* ************************************************************************** */

void SetTest::_set_empty(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: EMPTY ---" << PRINT_END << std::endl;


    std::set<int> myset;

    myset.insert(20);
    myset.insert(30);
    myset.insert(10);

    std::cout << "myset contains:";
    while (!myset.empty())
    {
         std::cout << ' ' << *myset.begin();
         myset.erase(myset.begin());
    }
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: EMPTY ---" << PRINT_END << std::endl;


    ft::set<int> myset;

    myset.insert(20);
    myset.insert(30);
    myset.insert(10);

    std::cout << "myset contains:";
    while (!myset.empty())
    {
         std::cout << ' ' << *myset.begin();
         myset.erase(myset.begin());
    }
    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */

void SetTest::_set_size(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: SIZE ---" << PRINT_END << std::endl;


    std::set<int> myints;
    std::cout << "0. size: " << myints.size() << std::endl;

    for (int i=0; i<10; ++i) myints.insert(i);
    std::cout << "1. size: " << myints.size() << std::endl;

    myints.insert (100);
    std::cout << "2. size: " << myints.size() << std::endl;

    myints.erase(5);
    std::cout << "3. size: " << myints.size() << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: SIZE ---" << PRINT_END << std::endl;


    ft::set<int> myints;
    std::cout << "0. size: " << myints.size() << std::endl;

    for (int i=0; i<10; ++i) myints.insert(i);
    std::cout << "1. size: " << myints.size() << std::endl;

    myints.insert (100);
    std::cout << "2. size: " << myints.size() << std::endl;

    myints.erase(5);
    std::cout << "3. size: " << myints.size() << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void SetTest::_set_max_size(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: MAX_SIZE ---" << PRINT_END << std::endl;


    int i;
    std::set<int> myset;

    std::cout << "Max Size :: " << myset.max_size() << std::endl;
    if (myset.max_size()>1000)
    {
        for (i=0; i<1000; i++) myset.insert(i);
        std::cout << "The set contains 1000 elements.\n";
    }
    else std::cout << "The set could not hold 1000 elements.\n";
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: MAX_SIZE ---" << PRINT_END << std::endl;


    int i;
    std::set<int> myset;

    std::cout << "Max Size :: " << myset.max_size() << std::endl;
    if (myset.max_size()>1000)
    {
        for (i=0; i<1000; i++) myset.insert(i);
        std::cout << "The set contains 1000 elements.\n";
    }
    else std::cout << "The set could not hold 1000 elements.\n";
    std::cout << std::endl;
}
}

/* ************************************************************************** */
/*                                   MODIFIERS                                */
/* ************************************************************************** */

void SetTest::_set_insert(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: INSERT ---" << PRINT_END << std::endl;


    std::set<int> myset;
    std::set<int>::iterator it;
    std::pair<std::set<int>::iterator,bool> ret;

    // set some initial values:
    for (int i=1; i<=5; ++i) myset.insert(i*10);    // set: 10 20 30 40 50

    ret = myset.insert(20);               // no new element inserted

    if (ret.second==false) it=ret.first;  // "it" now points to element 20

    myset.insert (it,25);                 // max efficiency inserting
    myset.insert (it,24);                 // max efficiency inserting
    myset.insert (it,26);                 // no max efficiency inserting

    int myints[]= {5,10,15};              // 10 already in set, not inserted
    myset.insert (myints,myints+3);

    std::cout << "myset contains:";
    for (it=myset.begin(); it!=myset.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: INSERT ---" << PRINT_END << std::endl;


    ft::set<int> myset;
    ft::set<int>::iterator it;
    ft::pair<ft::set<int>::iterator,bool> ret;

    // set some initial values:
    for (int i=1; i<=5; ++i) myset.insert(i*10);    // set: 10 20 30 40 50

    ret = myset.insert(20);               // no new element inserted

    if (ret.second==false) it=ret.first;  // "it" now points to element 20

    myset.insert (it,25);                 // max efficiency inserting
    myset.insert (it,24);                 // max efficiency inserting
    myset.insert (it,26);                 // no max efficiency inserting

    int myints[]= {5,10,15};              // 10 already in set, not inserted
    myset.insert (myints,myints+3);

    std::cout << "myset contains:";
    for (it=myset.begin(); it!=myset.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */

void SetTest::_set_erase(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: ERASE ---" << PRINT_END << std::endl;


    std::set<int> myset;
    std::set<int>::iterator it;

    // insert some values:
    for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90

    it = myset.begin();
    ++it;                                         // "it" points now to 20

    myset.erase (it);

    myset.erase (40);

    it = myset.find (60);
    myset.erase (it, myset.end());

    std::cout << "myset contains:";
    for (it=myset.begin(); it!=myset.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: ERASE ---" << PRINT_END << std::endl;


    ft::set<int> myset;
    ft::set<int>::iterator it;

    // insert some values:
    for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90

    it = myset.begin();
    ++it;                                         // "it" points now to 20

    myset.erase (it);

    myset.erase (40);

    it = myset.find (60);
    myset.erase (it, myset.end());

    std::cout << "myset contains:";
    for (it=myset.begin(); it!=myset.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */

void SetTest::_set_swap(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: SWAP ---" << PRINT_END << std::endl;


    int myints[]={12,75,10,32,20,25};
    std::set<int> first (myints,myints+3);     // 10,12,75
    std::set<int> second (myints+3,myints+6);  // 20,25,32

    first.swap(second);

    std::cout << "first contains:";
    for (std::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    std::cout << "second contains:";
    for (std::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: SWAP ---" << PRINT_END << std::endl;


    int myints[]={12,75,10,32,20,25};
    ft::set<int> first (myints,myints+3);     // 10,12,75
    ft::set<int> second (myints+3,myints+6);  // 20,25,32

    first.swap(second);

    std::cout << "first contains:";
    for (ft::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    std::cout << "second contains:";
    for (ft::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */

void SetTest::_set_clear(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: CLEAR ---" << PRINT_END << std::endl;


    std::set<int> myset;

    myset.insert (100);
    myset.insert (200);
    myset.insert (300);

    std::cout << "myset contains:";
    for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    myset.clear();
    myset.insert (1101);
    myset.insert (2202);

    std::cout << "myset contains:";
    for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: CLEAR ---" << PRINT_END << std::endl;


    ft::set<int> myset;

    myset.insert (100);
    myset.insert (200);
    myset.insert (300);

    std::cout << "myset contains:";
    for (ft::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    myset.clear();
    myset.insert (1101);
    myset.insert (2202);

    std::cout << "myset contains:";
    for (ft::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */
/*                                   OBSERVERS                                */
/* ************************************************************************** */

void SetTest::_set_key_comp(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: KEY_COMPARE ---" << PRINT_END << std::endl;


    std::set<int> myset;
    int highest;

    std::set<int>::key_compare mycomp = myset.key_comp();

    for (int i=0; i<=5; i++) myset.insert(i);

    std::cout << "myset contains:";

    highest=*myset.rbegin();
    std::set<int>::iterator it=myset.begin();
    do {
        std::cout << ' ' << *it;
    } while ( mycomp(*(++it),highest) );
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: KEY_COMPARE ---" << PRINT_END << std::endl;


    ft::set<int> myset;
    int highest;

    ft::set<int>::key_compare mycomp = myset.key_comp();

    for (int i=0; i<=5; i++) myset.insert(i);

    std::cout << "myset contains:";

    highest=*myset.rbegin();
    ft::set<int>::iterator it=myset.begin();
    do {
        std::cout << ' ' << *it;
    } while ( mycomp(*(++it),highest) );
    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */

void SetTest::_set_value_comp(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: VALUE_COMPARE ---" << PRINT_END << std::endl;


    std::set<int> myset;

    std::set<int>::value_compare mycomp = myset.value_comp();

    for (int i=0; i<=5; i++) myset.insert(i);

    std::cout << "myset contains:";

    int highest=*myset.rbegin();
    std::set<int>::iterator it=myset.begin();
    do {
      std::cout << ' ' << *it;
    } while ( mycomp(*(++it),highest) );
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: VALUE_COMPARE ---" << PRINT_END << std::endl;


    ft::set<int> myset;

    ft::set<int>::value_compare mycomp = myset.value_comp();

    for (int i=0; i<=5; i++) myset.insert(i);

    std::cout << "myset contains:";

    int highest=*myset.rbegin();
    ft::set<int>::iterator it=myset.begin();
    do {
      std::cout << ' ' << *it;
    } while ( mycomp(*(++it),highest) );
    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */
/*                                   OPERATIONS                               */
/* ************************************************************************** */

void SetTest::_set_find(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: FIND ---" << PRINT_END << std::endl;


    std::set<int> myset;
    std::set<int>::iterator it;

    // set some initial values:
    for (int i=1; i<=5; i++) myset.insert(i*10);    // set: 10 20 30 40 50

    it=myset.find(20);
    myset.erase (it);
    myset.erase (myset.find(40));

    std::cout << "myset contains:";
    for (it=myset.begin(); it!=myset.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: FIND ---" << PRINT_END << std::endl;


    ft::set<int> myset;
    ft::set<int>::iterator it;

    // set some initial values:
    for (int i=1; i<=5; i++) myset.insert(i*10);    // set: 10 20 30 40 50

    it=myset.find(20);
    myset.erase (it);
    myset.erase (myset.find(40));

    std::cout << "myset contains:";
    for (it=myset.begin(); it!=myset.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */

void SetTest::_set_count(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: COUNT ---" << PRINT_END << std::endl;


    std::set<int> myset;

    // set some initial values:
    for (int i=1; i<5; ++i) myset.insert(i*3);    // set: 3 6 9 12

    for (int i=0; i<10; ++i)
    {
        std::cout << i;
        if (myset.count(i)!=0)
            std::cout << " is an element of myset.\n";
        else
            std::cout << " is not an element of myset.\n";
    }
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: COUNT ---" << PRINT_END << std::endl;


    ft::set<int> myset;

    // set some initial values:
    for (int i=1; i<5; ++i) myset.insert(i*3);    // set: 3 6 9 12

    for (int i=0; i<10; ++i)
    {
        std::cout << i;
        if (myset.count(i)!=0)
            std::cout << " is an element of myset.\n";
        else
            std::cout << " is not an element of myset.\n";
    }
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void SetTest::_set_bounds(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: LOWER_BOUND ---" << PRINT_END << std::endl;


    std::set<int> myset;
    std::set<int>::iterator itlow,itup;

    for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

    itlow=myset.lower_bound (30);                //       ^
    itup=myset.upper_bound (60);                 //                   ^

    myset.erase(itlow,itup);                     // 10 20 70 80 90

    std::cout << "myset contains:";
    for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: LOWER_BOUND ---" << PRINT_END << std::endl;


    ft::set<int> myset;
    ft::set<int>::iterator itlow,itup;

    for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

    itlow=myset.lower_bound (30);                //       ^
    itup=myset.upper_bound (60);                 //                   ^

    myset.erase(itlow,itup);                     // 10 20 70 80 90

    std::cout << "myset contains:";
    for (ft::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */

void SetTest::_set_equal_range(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: EQUAL_RANGE ---" << PRINT_END << std::endl;


    std::set<int> myset;

    for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

    std::pair<std::set<int>::const_iterator,std::set<int>::const_iterator> ret;
    ret = myset.equal_range(30);

    std::cout << "the lower bound points to: " << *ret.first << std::endl;
    std::cout << "the upper bound points to: " << *ret.second << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: EQUAL_RANGE ---" << PRINT_END << std::endl;


    ft::set<int> myset;

    for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

    ft::pair<ft::set<int>::const_iterator,ft::set<int>::const_iterator> ret;
    ret = myset.equal_range(30);

    std::cout << "the lower bound points to: " << *ret.first << std::endl;
    std::cout << "the upper bound points to: " << *ret.second << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */
/*                                    ALLOCATOR                               */
/* ************************************************************************** */

void SetTest::_set_allocator(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: ALLOCATOR ---" << PRINT_END << std::endl;


    std::set<int> myset;
    int * p;
    unsigned int i;

    // allocate an array of 5 elements using myset's allocator:
    p=myset.get_allocator().allocate(5);

    // assign some values to array
    for (i=0; i<5; i++) p[i]=(i+1)*10;

    std::cout << "The allocated array contains:";
    for (i=0; i<5; i++) std::cout << ' ' << p[i];
    std::cout << std::endl;

    myset.get_allocator().deallocate(p,5);

    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: ALLOCATOR ---" << PRINT_END << std::endl;


    ft::set<int> myset;
    int * p;
    unsigned int i;

    // allocate an array of 5 elements using myset's allocator:
    p=myset.get_allocator().allocate(5);

    // assign some values to array
    for (i=0; i<5; i++) p[i]=(i+1)*10;

    std::cout << "The allocated array contains:";
    for (i=0; i<5; i++) std::cout << ' ' << p[i];
    std::cout << std::endl;

    myset.get_allocator().deallocate(p,5);

    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */
/*                               NON-MEMBER FUNCTIONS                         */
/* ************************************************************************** */

void SetTest::_set_relational_operators(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: RELATIONAL_OPERATORS ---" << PRINT_END << std::endl;


    std::set<int> foo,bar;
    foo.insert(10);
    bar.insert(20);
    bar.insert(30);
    foo.insert(40);
  
    // foo ({10,40}) vs bar ({20,30}):
    if (foo==bar) std::cout << "foo and bar are equal\n";
    if (foo!=bar) std::cout << "foo and bar are not equal\n";
    if (foo< bar) std::cout << "foo is less than bar\n";
    if (foo> bar) std::cout << "foo is greater than bar\n";
    if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
    if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: RELATIONAL_OPERATORS ---" << PRINT_END << std::endl;


    ft::set<int> foo,bar;
    foo.insert(10);
    bar.insert(20);
    bar.insert(30);
    foo.insert(40);
  
    // foo ({10,40}) vs bar ({20,30}):
    if (foo==bar) std::cout << "foo and bar are equal\n";
    if (foo!=bar) std::cout << "foo and bar are not equal\n";
    if (foo< bar) std::cout << "foo is less than bar\n";
    if (foo> bar) std::cout << "foo is greater than bar\n";
    if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
    if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}
}

/* ************************************************************************** */

void SetTest::_set_external_swap(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: EXTERNAL_SWAP ---" << PRINT_END << std::endl;


    int myints[]={12,75,10,32,20,25};
    std::set<int> first (myints,myints+3);     // 10,12,75
    std::set<int> second (myints+3,myints+6);  // 20,25,32
  
    swap(first,second);
  
    std::cout << "first contains:";
    for (std::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
  
    std::cout << "second contains:";
    for (std::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: EXTERNAL_SWAP ---" << PRINT_END << std::endl;


    int myints[]={12,75,10,32,20,25};
    ft::set<int> first (myints,myints+3);     // 10,12,75
    ft::set<int> second (myints+3,myints+6);  // 20,25,32
  
    swap(first,second);
  
    std::cout << "first contains:";
    for (ft::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
  
    std::cout << "second contains:";
    for (ft::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */
/*                                    LEAKS                                   */
/* ************************************************************************** */

void SetTest::_set_leaks(bool isSTD)
{
    if (!isSTD)
        return ;
    system("leaks ft_containers");
    std::cout << std::endl;
}

/* ************************************************************************** */
/*                                   SET TEST                                 */
/* ************************************************************************** */
