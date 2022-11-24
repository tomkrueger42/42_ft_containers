/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorTest.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:22:42 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/11/24 16:23:53 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VectorTest.hpp"
#include <vector>

/* ************************************************************************** */
/*                                 VECTOR TEST                                */
/* ************************************************************************** */

VectorTest::VectorTest()
{
    _tests[0] = &VectorTest::_vector_ctor;
    _tests[1] = &VectorTest::_vector_assignment;

    _tests[2] = &VectorTest::_vector_iterator;
    _tests[3] = &VectorTest::_vector_riterator;

    _tests[4] = &VectorTest::_vector_size;
    _tests[5] = &VectorTest::_vector_max_size;
    _tests[6] = &VectorTest::_vector_resize;
    _tests[7] = &VectorTest::_vector_capacity;
    _tests[8] = &VectorTest::_vector_empty;
    _tests[9] = &VectorTest::_vector_reserve;

    _tests[10] = &VectorTest::_vector_brackets;
    _tests[11] = &VectorTest::_vector_at;
    _tests[12] = &VectorTest::_vector_front;
    _tests[13] = &VectorTest::_vector_back;

    _tests[14] = &VectorTest::_vector_assign;
    _tests[15] = &VectorTest::_vector_push_back;
    _tests[16] = &VectorTest::_vector_pop_back;
    _tests[17] = &VectorTest::_vector_insert;
    _tests[18] = &VectorTest::_vector_erase;
    _tests[19] = &VectorTest::_vector_swap;
    _tests[20] = &VectorTest::_vector_clear;

    _tests[21] = &VectorTest::_vector_allocator;

    _tests[22] = &VectorTest::_vector_relational_operators;
    _tests[23] = &VectorTest::_vector_external_swap;

    _tests[24] = &VectorTest::_vector_leaks;
}

/* ************************************************************************** */

VectorTest::~VectorTest() {}

/* ************************************************************************** */
/*                                     MAIN                                   */
/* ************************************************************************** */

void VectorTest::run()
{
    std::string buffer;

    system("clear");
    _print_welcome_message();
    std::getline(std::cin, buffer);

    for (int i = 0; i < 25; ++i)
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

void VectorTest::_print_image() const
{
    std::cout << std::endl;
    std::cout << "             \033[1;36m*\033[0m     \033[1;33m,MMM8&&&.\033[0m            \033[1;35m*\033[0m" << std::endl;
    std::cout << "                  \033[1;33mMMMM88&&&&&\033[0m    \033[1;33m.\033[0m" << std::endl;
    std::cout << "                 \033[1;33mMMMM88&&&&&&&\033[0m" << std::endl;
    std::cout << "     \033[1;33m*\033[0m           \033[1;33mMMM88&&&&&&&&\033[0m" << std::endl;
    std::cout << "                 \033[1;33mMMM88&&&&&&&&\033[0m" << std::endl;
    std::cout << "                 \033[1;33m'MMM88&&&&&&'\033[0m" << std::endl;
    std::cout << "                   \033[1;33m'MMM8&&&'\033[0m      \033[1;36m*\033[0m" << std::endl;
    std::cout << "          |\\___/|" << std::endl;
    std::cout << "         =) ^Y^ (=            \033[1;33m.\033[0m              \033[1;33m'\033[0m" << std::endl;
    std::cout << "          \\  ^  /" << std::endl;
    std::cout << "           )=*=(       \033[1;35m*\033[0m" << std::endl;
    std::cout << "          /     \\" << std::endl;
    std::cout << "          |     |" << std::endl;
    std::cout << "         /| | | |\\" << std::endl;
    std::cout << "         \\| | |_|/\\" << std::endl;
    std::cout << "  jgs_/\\_//_// ___/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_" << std::endl;
    std::cout << "  |  |  |  | \\_) |  |  |  |  |  |  |  |  |  |" << std::endl;
    std::cout << "  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |" << std::endl;
    std::cout << "  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |" << std::endl;
    std::cout << "  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |" << std::endl;
    std::cout << "  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |" << std::endl;
    std::cout << std::endl;
}

/* ************************************************************************** */

void VectorTest::_print_welcome_message() const
{
    _print_image();
    std::cout << PRINT_PURPLE << "Welcome to <VectorTest>>." << PRINT_END << std::endl << std::endl;
    std::cout << PRINT_PURPLE << "Press <Enter> to continue..." << PRINT_END << std::endl;
    std::cout << std::endl;
}

/* ************************************************************************** */

void VectorTest::_print_goodbye_message() const
{
    std::cout << std::endl;
    std::cout << "             \033[1;36m*\033[0m     \033[1;33m,MMM8&&&.\033[0m            \033[1;35m*\033[0m" << std::endl;
    std::cout << "                  \033[1;33mMMMM88&&&&&\033[0m    \033[1;33m.\033[0m" << std::endl;
    std::cout << "                 \033[1;33mMMM88&&&&&&&&\033[0m" << std::endl;
    std::cout << "     \033[1;33m*\033[0m           \033[1;33mMM88&&&&&&&&&\033[0m" << std::endl;
    std::cout << "                 \033[1;33mMMM88&&&&&&&&\033[0m" << std::endl;
    std::cout << "                 \033[1;33m'MMM88&&&&&&'\033[0m" << std::endl;
    std::cout << "                   \033[1;33m'MMM8&&&'\033[0m      \033[1;36m*\033[0m" << std::endl;
    std::cout << "          |\\___/|" << std::endl;
    std::cout << "          )     (             \033[1;33m.\033[0m              \033[1;33m'\033[0m" << std::endl;
    std::cout << "         =\\     /=" << std::endl;
    std::cout << "           )===(       \033[1;35m*\033[0m" << std::endl;
    std::cout << "          /     \\ " << std::endl;
    std::cout << "          |     |" << std::endl;
    std::cout << "         /       \\ " << std::endl;
    std::cout << "         \\       /" << std::endl;
    std::cout << "  _/\\_/\\_/\\__  _/_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_" << std::endl;
    std::cout << "  |  |  |  |( (  |  |  |  |  |  |  |  |  |  |" << std::endl;
    std::cout << "  |  |  |  | ) ) |  |  |  |  |  |  |  |  |  |" << std::endl;
    std::cout << "  |  |  |  |(_(  |  |  |  |  |  |  |  |  |  |" << std::endl;
    std::cout << "  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |" << std::endl;
    std::cout << "  jgs|  |  |  |  |  |  |  |  |  |  |  |  |  |" << std::endl;
    std::cout << std::endl;
    std::cout << PRINT_PURPLE << "We hope you enjoyed <VectorTest>." << PRINT_END << std::endl;
    std::cout << PRINT_PURPLE << "Until next time!" << PRINT_END << std::endl;
    std::cout << std::endl;
}

/* ************************************************************************** */
/*                                    EXAMPLES                                */
/* ************************************************************************** */

void VectorTest::_vector_ctor(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE << "--- STD :: CONSTRUCTOR ---" << PRINT_END << std::endl;


    std::vector<int> first;                                // empty vector of ints
    std::vector<int> second (4,100);                       // four ints with value 100
    std::vector<int> third (second.begin(),second.end());  // iterating through second
    std::vector<int> fourth (third);                       // a copy of third

    // the iteratorructor can also be used toruct from arrays:
    int myints[] = {16,2,77,29};
    std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

    std::cout << "The contents of fifth are:";
    for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: CONSTRUCTOR ---" << PRINT_END << std::endl;

    ft::vector<int> first;                                // empty vector of ints
    ft::vector<int> second (4,100);                       // four ints with value 100
    ft::vector<int> third (second.begin(),second.end());  // iterating through second
    ft::vector<int> fourth (third);                       // a copy of third

    // the iteratorructor can also be used toruct from arrays:
    int myints[] = {16,2,77,29};
    ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

    std::cout << "The contents of fifth are:";
    for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */

void VectorTest::_vector_assignment(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE << "--- STD :: ASSIGNMENT ---" << PRINT_END << std::endl;


    std::vector<int> foo (3,0);
    std::vector<int> bar (5,0);

    bar = foo;
    foo = std::vector<int>();

    std::cout << "Size of foo: " << int(foo.size()) << std::endl;
    std::cout << "Size of bar: " << int(bar.size()) << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: ASSIGNMENT ---" << PRINT_END << std::endl;


    ft::vector<int> foo (3,0);
    ft::vector<int> bar (5,0);

    bar = foo;
    foo = ft::vector<int>();

    std::cout << "Size of foo: " << int(foo.size()) << std::endl;
    std::cout << "Size of bar: " << int(bar.size()) << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */
/*                                   ITERATORS                                */
/* ************************************************************************** */

void VectorTest::_vector_iterator(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: ITERATOR ---" << PRINT_END << std::endl;


    std::vector<int> myvector;
    for (int i=1; i<=5; i++) myvector.push_back(i);

    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: ITERATOR ---" << PRINT_END << std::endl;


    ft::vector<int> myvector;
    for (int i=1; i<=5; i++) myvector.push_back(i);

    std::cout << "myvector contains:";
    for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */

void VectorTest::_vector_riterator(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: REVERSE_ITERATOR ---" << PRINT_END << std::endl;


    std::vector<int> myvector (5);  // 5 defaultructed ints

    int i=0;

    std::vector<int>::reverse_iterator rit = myvector.rbegin();
    for (; rit!= myvector.rend(); ++rit)
        *rit = ++i;

    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: REVERSE_ITERATOR ---" << PRINT_END << std::endl;


    ft::vector<int> myvector (5);  // 5 defaultructed ints

    int i=0;

    ft::vector<int>::reverse_iterator rit = myvector.rbegin();
    for (; rit!= myvector.rend(); ++rit)
        *rit = ++i;

    std::cout << "myvector contains:";
    for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */
/*                                   CAPACITY                                 */
/* ************************************************************************** */

void VectorTest::_vector_size(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: SIZE ---" << PRINT_END << std::endl;


    std::vector<int> myints;
    std::cout << "0. size: " << myints.size() << std::endl;

    for (int i=0; i<10; i++) myints.push_back(i);
    std::cout << "1. size: " << myints.size() << std::endl;

    myints.insert (myints.end(),10,100);
    std::cout << "2. size: " << myints.size() << std::endl;

    myints.pop_back();
    std::cout << "3. size: " << myints.size() << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: SIZE ---" << PRINT_END << std::endl;


    ft::vector<int> myints;
    std::cout << "0. size: " << myints.size() << std::endl;

    for (int i=0; i<10; i++) myints.push_back(i);
    std::cout << "1. size: " << myints.size() << std::endl;

    myints.insert (myints.end(),10,100);
    std::cout << "2. size: " << myints.size() << std::endl;

    myints.pop_back();
    std::cout << "3. size: " << myints.size() << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void VectorTest::_vector_max_size(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: MAX_SIZE ---" << PRINT_END << std::endl;


    std::vector<int> myvector;

    // set some content in the vector:
    for (int i=0; i<100; i++) myvector.push_back(i);

    std::cout << "size: " << myvector.size() << "\n";
    std::cout << "capacity: " << myvector.capacity() << "\n";
    std::cout << "max_size: " << myvector.max_size() << "\n";
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: MAX_SIZE ---" << PRINT_END << std::endl;


    ft::vector<int> myvector;

    // set some content in the vector:
    for (int i=0; i<100; i++) myvector.push_back(i);

    std::cout << "size: " << myvector.size() << "\n";
    std::cout << "capacity: " << myvector.capacity() << "\n";
    std::cout << "max_size: " << myvector.max_size() << "\n";
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void VectorTest::_vector_resize(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: RESIZE ---" << PRINT_END << std::endl;


    std::vector<int> myvector;

    // set some initial content:
    for (int i=1;i<10;i++) myvector.push_back(i);

    myvector.resize(5);
    myvector.resize(8,100);
    myvector.resize(12);

    std::cout << "myvector contains:";
    for (unsigned long i=0;i<myvector.size();i++)
        std::cout << ' ' << myvector[i];
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: RESIZE ---" << PRINT_END << std::endl;


    ft::vector<int> myvector;

    // set some initial content:
    for (int i=1;i<10;i++) myvector.push_back(i);

    myvector.resize(5);
    myvector.resize(8,100);
    myvector.resize(12);

    std::cout << "myvector contains:";
    for (unsigned long  i=0;i<myvector.size();i++)
        std::cout << ' ' << myvector[i];
    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */

void VectorTest::_vector_capacity(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: CAPACITY ---" << PRINT_END << std::endl;


    std::vector<int> myvector;

    // set some content in the vector:
    for (int i=0; i<100; i++) myvector.push_back(i);

    std::cout << "size: " << (int) myvector.size() << std::endl;
    std::cout << "capacity: " << (int) myvector.capacity() << std::endl;
    std::cout << "max_size: " << (int) myvector.max_size() << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: CAPACITY ---" << PRINT_END << std::endl;


    ft::vector<int> myvector;

    // set some content in the vector:
    for (int i=0; i<100; i++) myvector.push_back(i);

    std::cout << "size: " << (int) myvector.size() << std::endl;
    std::cout << "capacity: " << (int) myvector.capacity() << std::endl;
    std::cout << "max_size: " << (int) myvector.max_size() << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void VectorTest::_vector_empty(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: EMPTY ---" << PRINT_END << std::endl;


    std::vector<int> myvector;
    int sum (0);

    for (int i=1;i<=10;i++) myvector.push_back(i);

    while (!myvector.empty())
    {
        sum += myvector.back();
        myvector.pop_back();
    }

    std::cout << "total: " << sum << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: EMPTY ---" << PRINT_END << std::endl;

    ft::vector<int> myvector;
    int sum (0);

    for (int i=1;i<=10;i++) myvector.push_back(i);

    while (!myvector.empty())
    {
        sum += myvector.back();
        myvector.pop_back();
    }

    std::cout << "total: " << sum << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */


void VectorTest::_vector_reserve(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: RESERVE ---" << PRINT_END << std::endl;


    std::vector<int>::size_type sz;

    std::vector<int> foo;
    sz = foo.capacity();
    std::cout << "making foo grow:\n";
    for (int i=0; i<100; ++i) {
        foo.push_back(i);
        if (sz!=foo.capacity()) {
            sz = foo.capacity();
            std::cout << "capacity changed: " << sz << std::endl;
        }
    }

    std::vector<int> bar;
    sz = bar.capacity();
    bar.reserve(100);   // this is the only difference with foo above
    std::cout << "making bar grow:\n";
    for (int i=0; i<100; ++i) {
        bar.push_back(i);
        if (sz!=bar.capacity()) {
            sz = bar.capacity();
            std::cout << "capacity changed: " << sz << std::endl;
        }
    }
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: RESERVE ---" << PRINT_END << std::endl;


    ft::vector<int>::size_type sz;

    ft::vector<int> foo;
    sz = foo.capacity();
    std::cout << "making foo grow:\n";
    for (int i=0; i<100; ++i) {
        foo.push_back(i);
        if (sz!=foo.capacity()) {
            sz = foo.capacity();
            std::cout << "capacity changed: " << sz << std::endl;
        }
    }

    ft::vector<int> bar;
    sz = bar.capacity();
    bar.reserve(100);   // this is the only difference with foo above
    std::cout << "making bar grow:\n";
    for (int i=0; i<100; ++i) {
        bar.push_back(i);
        if (sz!=bar.capacity()) {
            sz = bar.capacity();
            std::cout << "capacity changed: " << sz << std::endl;
        }
    }
    std::cout << std::endl;
}
}

/* ************************************************************************** */
/*                                ELEMENT ACCESS                              */
/* ************************************************************************** */

void VectorTest::_vector_brackets(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: OPERATOR[] ---" << PRINT_END << std::endl;


    std::vector<int> myvector (10);   // 10 zero-initialized elements

    std::vector<int>::size_type sz = myvector.size();

    // assign some values:
    for (unsigned i=0; i<sz; i++) myvector[i]=i;

    // reverse vector using operator[]:
    for (unsigned i=0; i<sz/2; i++)
    {
        int temp;
        temp = myvector[sz-1-i];
        myvector[sz-1-i]=myvector[i];
        myvector[i]=temp;
    }

    std::cout << "myvector contains:";
    for (unsigned i=0; i<sz; i++)
        std::cout << ' ' << myvector[i];
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: OPERATOR[] ---" << PRINT_END << std::endl;


    ft::vector<int> myvector (10);   // 10 zero-initialized elements

    ft::vector<int>::size_type sz = myvector.size();

    // assign some values:
    for (unsigned i=0; i<sz; i++) myvector[i]=i;

    // reverse vector using operator[]:
    for (unsigned i=0; i<sz/2; i++)
    {
        int temp;
        temp = myvector[sz-1-i];
        myvector[sz-1-i]=myvector[i];
        myvector[i]=temp;
    }

    std::cout << "myvector contains:";
    for (unsigned i=0; i<sz; i++)
        std::cout << ' ' << myvector[i];
    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */

void VectorTest::_vector_at(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: AT ---" << PRINT_END << std::endl;


    std::vector<int> myvector (10);   // 10 zero-initialized ints
  
    // assign some values:
    for (unsigned i=0; i<myvector.size(); i++)
        myvector.at(i)=i;
  
    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size(); i++)
        std::cout << ' ' << myvector.at(i);
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: AT ---" << PRINT_END << std::endl;


    ft::vector<int> myvector (10);   // 10 zero-initialized ints
  
    // assign some values:
    for (unsigned i=0; i<myvector.size(); i++)
        myvector.at(i)=i;
  
    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size(); i++)
        std::cout << ' ' << myvector.at(i);
    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */

void VectorTest::_vector_front(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: FRONT ---" << PRINT_END << std::endl;


    std::vector<int> myvector;

    myvector.push_back(78);
    myvector.push_back(16);

    // now front equals 78, and back 16

    myvector.front() -= myvector.back();
  
    std::cout << "myvector.front() is now " << myvector.front() << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: FRONT ---" << PRINT_END << std::endl;


    ft::vector<int> myvector;

    myvector.push_back(78);
    myvector.push_back(16);

    // now front equals 78, and back 16

    myvector.front() -= myvector.back();
  
    std::cout << "myvector.front() is now " << myvector.front() << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void VectorTest::_vector_back(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: BACK ---" << PRINT_END << std::endl;


    std::vector<int> myvector;

    myvector.push_back(10);

    while (myvector.back() != 0)
    {
        myvector.push_back ( myvector.back() -1 );
    }

    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size() ; i++)
        std::cout << ' ' << myvector[i];
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: BACK ---" << PRINT_END << std::endl;


    ft::vector<int> myvector;

    myvector.push_back(10);

    while (myvector.back() != 0)
    {
        myvector.push_back ( myvector.back() -1 );
    }

    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size() ; i++)
        std::cout << ' ' << myvector[i];
    std::cout << std::endl << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */
/*                                   MODIFIERS                                */
/* ************************************************************************** */

void VectorTest::_vector_assign(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: ASSIGN ---" << PRINT_END << std::endl;


    std::vector<int> first;
    std::vector<int> second;
    std::vector<int> third;

    first.assign (7,100);             // 7 ints with a value of 100

    std::vector<int>::iterator it;
    it=first.begin()+1;

    second.assign (it,first.end()-1); // the 5 central values of first

    int myints[] = {1776,7,4};
    third.assign (myints,myints+3);   // assigning from array.
  
    std::cout << "Size of first: " << int (first.size()) << std::endl;
    std::cout << "Size of second: " << int (second.size()) << std::endl;
    std::cout << "Size of third: " << int (third.size()) << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: ASSIGN ---" << PRINT_END << std::endl;


    ft::vector<int> first;
    ft::vector<int> second;
    ft::vector<int> third;

    first.assign (7,100);             // 7 ints with a value of 100

    ft::vector<int>::iterator it;
    it=first.begin()+1;

    second.assign (it,first.end()-1); // the 5 central values of first

    int myints[] = {1776,7,4};
    third.assign (myints,myints+3);   // assigning from array.

    std::cout << "Size of first: " << int (first.size()) << std::endl;
    std::cout << "Size of second: " << int (second.size()) << std::endl;
    std::cout << "Size of third: " << int (third.size()) << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void VectorTest::_vector_push_back(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: PUSH_BACK ---" << PRINT_END << std::endl;


    std::vector<int> myvector;

    std::cout << "push back ..." << std::endl;
    for (int i = 1; i < 10; ++i)
        myvector.push_back(i * i);

    for (unsigned long i = 0; i < myvector.size(); ++i)
        std::cout << myvector[i] << " ";
    std::cout << std::endl;

    std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: PUSH_BACK ---" << PRINT_END << std::endl;


    ft::vector<int> myvector;

    std::cout << "push back ..." << std::endl;
    for (int i = 1; i < 10; ++i)
        myvector.push_back(i * i);

    for (unsigned long i = 0; i < myvector.size(); ++i)
        std::cout << myvector[i] << " ";
    std::cout << std::endl;

    std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void VectorTest::_vector_pop_back(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: POP_BACK ---" << PRINT_END << std::endl;


    std::vector<int> myvector;
    int sum (0);
    myvector.push_back (100);
    myvector.push_back (200);
    myvector.push_back (300);
  
    while (!myvector.empty())
    {
        sum+=myvector.back();
        myvector.pop_back();
    }

    std::cout << "The elements of myvector add up to " << sum << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: POP_BACK ---" << PRINT_END << std::endl;


    ft::vector<int> myvector;
    int sum (0);
    myvector.push_back (100);
    myvector.push_back (200);
    myvector.push_back (300);
  
    while (!myvector.empty())
    {
        sum+=myvector.back();
        myvector.pop_back();
    }

    std::cout << "The elements of myvector add up to " << sum << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void VectorTest::_vector_insert(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: INSERT ---" << PRINT_END << std::endl;


    std::vector<int> myvector (3,100);
    std::vector<int>::iterator it;

    it = myvector.begin();
    it = myvector.insert ( it , 200 );

    myvector.insert (it,2,300);

    // "it" no longer valid, get a new one:
    it = myvector.begin();

    std::vector<int> anothervector (2,400);
    myvector.insert (it+2,anothervector.begin(),anothervector.end());

    int myarray [] = { 501,502,503 };
    myvector.insert (myvector.begin(), myarray, myarray+3);

    std::cout << "myvector contains:";
    for (it=myvector.begin(); it<myvector.end(); it++)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: INSERT ---" << PRINT_END << std::endl;


    ft::vector<int> myvector (3,100);
    ft::vector<int>::iterator it;

    it = myvector.begin();
    it = myvector.insert ( it , 200 );

    myvector.insert (it,2,300);

    // "it" no longer valid, get a new one:
    it = myvector.begin();

    ft::vector<int> anothervector (2,400);
    myvector.insert (it+2,anothervector.begin(),anothervector.end());

    int myarray [] = { 501,502,503 };
    myvector.insert (myvector.begin(), myarray, myarray+3);

    std::cout << "myvector contains:";
    for (it=myvector.begin(); it<myvector.end(); it++)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */

void VectorTest::_vector_erase(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: ERASE ---" << PRINT_END << std::endl;


    std::vector<int> myvector;

    // set some values (from 1 to 10)
    for (int i=1; i<=10; i++) myvector.push_back(i);

    // erase the 6th element
    myvector.erase (myvector.begin()+5);

    // erase the first 3 elements:
    myvector.erase (myvector.begin(),myvector.begin()+3);

    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size(); ++i)
        std::cout << ' ' << myvector[i];
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: ERASE ---" << PRINT_END << std::endl;


    ft::vector<int> myvector;

    // set some values (from 1 to 10)
    for (int i=1; i<=10; i++) myvector.push_back(i);

    // erase the 6th element
    myvector.erase (myvector.begin()+5);

    // erase the first 3 elements:
    myvector.erase (myvector.begin(),myvector.begin()+3);

    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size(); ++i)
        std::cout << ' ' << myvector[i];
    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */

void VectorTest::_vector_swap(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: SWAP ---" << PRINT_END << std::endl;


    std::vector<int> foo (3,100);   // three ints with a value of 100
    std::vector<int> bar (5,200);   // five ints with a value of 200

    foo.swap(bar);

    std::cout << "foo contains:";
    for (unsigned i=0; i<foo.size(); i++)
        std::cout << ' ' << foo[i];
    std::cout << std::endl;

    std::cout << "bar contains:";
    for (unsigned i=0; i<bar.size(); i++)
        std::cout << ' ' << bar[i];
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: SWAP ---" << PRINT_END << std::endl;


    ft::vector<int> foo (3,100);   // three ints with a value of 100
    ft::vector<int> bar (5,200);   // five ints with a value of 200

    foo.swap(bar);

    std::cout << "foo contains:";
    for (unsigned i=0; i<foo.size(); i++)
        std::cout << ' ' << foo[i];
    std::cout << std::endl;

    std::cout << "bar contains:";
    for (unsigned i=0; i<bar.size(); i++)
        std::cout << ' ' << bar[i];
    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */

void VectorTest::_vector_clear(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: CLEAR ---" << PRINT_END << std::endl;


    std::vector<int> myvector;
    myvector.push_back (100);
    myvector.push_back (200);
    myvector.push_back (300);

    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size(); i++)
        std::cout << ' ' << myvector[i];
    std::cout << std::endl;

    myvector.clear();
    myvector.push_back (1101);
    myvector.push_back (2202);

    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size(); i++)
        std::cout << ' ' << myvector[i];
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: CLEAR ---" << PRINT_END << std::endl;


    ft::vector<int> myvector;
    myvector.push_back (100);
    myvector.push_back (200);
    myvector.push_back (300);

    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size(); i++)
        std::cout << ' ' << myvector[i];
    std::cout << std::endl;

    myvector.clear();
    myvector.push_back (1101);
    myvector.push_back (2202);

    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size(); i++)
        std::cout << ' ' << myvector[i];
    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */
/*                                    ALLOCATOR                               */
/* ************************************************************************** */

void VectorTest::_vector_allocator(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: ALLOCATOR ---" << PRINT_END << std::endl;


    std::vector<int> myvector;
    int * p;
    unsigned int i;

    // allocate an array with space for 5 elements using vector's allocator:
    p = myvector.get_allocator().allocate(5);

    //ruct values in-place on the array:
    for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

    std::cout << "The allocated array contains:";
    for (i=0; i<5; i++) std::cout << ' ' << p[i];
    std::cout << std::endl;

    // destroy and deallocate:
    for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
    myvector.get_allocator().deallocate(p,5);
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: ALLOCATOR ---" << PRINT_END << std::endl;


    ft::vector<int> myvector;
    int * p;
    unsigned int i;

    // allocate an array with space for 5 elements using vector's allocator:
    p = myvector.get_allocator().allocate(5);

    //ruct values in-place on the array:
    for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

    std::cout << "The allocated array contains:";
    for (i=0; i<5; i++) std::cout << ' ' << p[i];
    std::cout << std::endl;

    // destroy and deallocate:
    for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
    myvector.get_allocator().deallocate(p,5);
    std::cout << std::endl;
}
}

/* ************************************************************************** */
/*                               NON-MEMBER FUNCTIONS                         */
/* ************************************************************************** */

void VectorTest::_vector_relational_operators(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: RELATIONAL_OPERATORS ---" << PRINT_END << std::endl;


    std::vector<int> foo (3,100);   // three ints with a value of 100
    std::vector<int> bar (2,200);   // two ints with a value of 200

    if (foo==bar) std::cout << "foo and bar are equal\n";
    if (foo!=bar) std::cout << "foo and bar are not equal\n";
    if (foo< bar) std::cout << "foo is less than bar\n";
    if (foo> bar) std::cout << "foo is greater than bar\n";
    if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
    if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: RELATIONAL_OPERATORS ---" << PRINT_END << std::endl;


    ft::vector<int> foo (3,100);   // three ints with a value of 100
    ft::vector<int> bar (2,200);   // two ints with a value of 200

    if (foo==bar) std::cout << "foo and bar are equal\n";
    if (foo!=bar) std::cout << "foo and bar are not equal\n";
    if (foo< bar) std::cout << "foo is less than bar\n";
    if (foo> bar) std::cout << "foo is greater than bar\n";
    if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
    if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */

void VectorTest::_vector_external_swap(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: EXTERNAL_SWAP ---" << PRINT_END << std::endl;


    std::vector<int> foo (3,100);   // three ints with a value of 100
    std::vector<int> bar (5,200);   // five ints with a value of 200
  
    foo.swap(bar);
  
    std::cout << "foo contains:";
    for (std::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
  
    std::cout << "bar contains:";
    for (std::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: EXTERNAL_SWAP ---" << PRINT_END << std::endl;


    ft::vector<int> foo (3,100);   // three ints with a value of 100
    ft::vector<int> bar (5,200);   // five ints with a value of 200
  
    foo.swap(bar);
  
    std::cout << "foo contains:";
    for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
  
    std::cout << "bar contains:";
    for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl << std::endl;
}
}

/* ************************************************************************** */
/*                                    LEAKS                                   */
/* ************************************************************************** */

void VectorTest::_vector_leaks(bool isSTD)
{
    if (!isSTD)
        return ;
    system("leaks ft_containers");
    std::cout << std::endl;
}

/* ************************************************************************** */
/*                                 VECTOR TEST                                */
/* ************************************************************************** */
