/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapTest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 23:29:56 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/11/24 02:28:29 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MapTest.hpp"
#include <map>

/* ************************************************************************** */
/*                                   MAP TEST                                 */
/* ************************************************************************** */

MapTest::MapTest()
{
    _tests[0] = &MapTest::_map_ctor;
    _tests[1] = &MapTest::_map_assignment;

    _tests[2] = &MapTest::_map_iterator;
    _tests[3] = &MapTest::_map_riterator;

    _tests[4] = &MapTest::_map_empty;
    _tests[5] = &MapTest::_map_size;
    _tests[6] = &MapTest::_map_max_size;

    _tests[7] = &MapTest::_map_brackets;
    _tests[8] = &MapTest::_map_at;

    _tests[9] = &MapTest::_map_insert;
    _tests[10] = &MapTest::_map_erase;
    _tests[11] = &MapTest::_map_swap;
    _tests[12] = &MapTest::_map_clear;

    _tests[13] = &MapTest::_map_key_comp;
    _tests[14] = &MapTest::_map_value_comp;

    _tests[15] = &MapTest::_map_find;
    _tests[16] = &MapTest::_map_count;
    _tests[17] = &MapTest::_map_bounds;
    _tests[18] = &MapTest::_map_equal_range;
    
    _tests[19] = &MapTest::_map_allocator;

    _tests[20] = &MapTest::_map_relational_operators;
    _tests[21] = &MapTest::_map_external_swap;

    _tests[22] = &MapTest::_map_leaks;    
}

/* ************************************************************************** */

MapTest::~MapTest() {}

/* ************************************************************************** */
/*                                     MAIN                                   */
/* ************************************************************************** */

void MapTest::run()
{
    std::string buffer;

    system("clear");
    _print_welcome_message();
    std::getline(std::cin, buffer);

    for (int i = 0; i < 23; ++i)
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

void MapTest::_print_image() const
{
    std::cout << std::endl;
    std::cout << "              \033[1;33m,@@@@@@@,\033[0m " << std::endl;
    std::cout << "       \033[1;32m,,,.\033[0m   \033[1;33m,@@@@@@/@@,\033[0m  \033[1;32m.oo8888o.\033[0m  " << std::endl;
    std::cout << "    \033[1;32m,&%%&%&&%,\033[0m\033[1;33m@@@@@/@@@@@@,\033[0m\033[1;32m8888\\88/8o\033[0m " << std::endl;
    std::cout << "   \033[1;32m,%&\\%&&%&&%\033[0m,\033[1;33m@@@\\@@@/@@@\033[0m\033[1;32m88\\88888/88'\033[0m    " << std::endl;
    std::cout << "   \033[1;32m%&&%&%&/%&&%\033[0m\033[1;33m@@\\@@/ /@@@\033[0m\033[1;32m88888\\88888'\033[0m    " << std::endl;
    std::cout << "   \033[1;32m%&&%/ %&%%&&\033[0m\033[1;33m@@\\ V /@@'\033[0m `\033[1;32m88\\8 `/88'\033[0m " << std::endl;
    std::cout << "   \033[1;32m`&%\\ ` /%&'\033[0m    |.|        \\ '|\033[1;32m8'\033[0m   " << std::endl;
    std::cout << "       |o|        | |         | | " << std::endl;
    std::cout << "       |.|        | |         | | " << std::endl;
    std::cout << "jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_ " << std::endl;
    std::cout << std::endl;
}

/* ************************************************************************** */

void MapTest::_print_welcome_message() const
{
    _print_image();
    std::cout << PRINT_ORANGE << "Welcome to <MapTest>>." << PRINT_END << std::endl << std::endl;
    std::cout << PRINT_GREEN<< "Press <Enter> to continue..." << PRINT_END << std::endl;
    std::cout << std::endl;
}

/* ************************************************************************** */

void MapTest::_print_goodbye_message() const
{
    std::cout << std::endl;
    std::cout << "               \033[1;35m,@@@@@@@,\033[0m " << std::endl;
    std::cout << "       \033[1;33m,,,.\033[0m   \033[1;35m,@@@@@@/@@,\033[0m  \033[1;31m.oo8888o.\033[0m  " << std::endl;
    std::cout << "    \033[1;33m,&%%&%&&%,\033[0m\033[1;35m@@@@@/@@@@@@,\033[0m\033[1;31m8888\\88/8o\033[0m " << std::endl;
    std::cout << "   \033[1;33m,%&\\%&&%&&%\033[0m\033[1;35m,@@@\\@@@/@@@\033[0m\033[1;31m88\\88888/88'\033[0m    " << std::endl;
    std::cout << "   \033[1;33m%&&%&%&/%&&%\033[0m\033[1;35m@@\\@@/ /@@@\033[0m\033[1;31m88888\\88888'\033[0m    " << std::endl;
    std::cout << "   \033[1;33m%&&%/ %&%%&&\033[0m\033[1;35m@@\\ V /@@'\033[0m \033[1;31m`88\\8 `/88'\033[0m " << std::endl;
    std::cout << "   \033[1;33m`&%\\ ` /%&'\033[0m    |.|        \\ '|\033[1;31m8'\033[0m   " << std::endl;
    std::cout << "       |o|        | |         | | " << std::endl;
    std::cout << "       |.|        | |         | | " << std::endl;
    std::cout << "jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_ " << std::endl;
    std::cout << std::endl;
    std::cout << PRINT_RED << "We hope you enjoyed <MapTest>." << PRINT_END << std::endl;
    std::cout << PRINT_ORANGE << "Until next time!" << PRINT_END << std::endl;
    std::cout << std::endl;
}

/* ************************************************************************** */
/*                                    EXAMPLES                                */
/* ************************************************************************** */

void MapTest::_map_ctor(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: CONSTRUCTOR ---" << PRINT_END << std::endl;


    std::map<int,std::string> first;
    std::map<int,std::string> second;
    second[1]="alpha";
    second[2]="beta";
    second[3]="gamma";
    second[4]="delta";

    std::map<int,std::string> third(second.begin(),second.end());
    std::map<int,std::string> fourth(third);

    std::cout << "std::map<int,std::string> first" << std::endl;
    for (std::map<int,std::string>::iterator it = first.begin(); it != first.end(); ++it)
        std::cout << it->first << "['" << it->second << "']" << std::endl;
    std::cout << std::endl;

    std::cout << "std::map<int,std::string> second (with added values)" << std::endl;
    for (std::map<int,std::string>::iterator it = second.begin(); it != second.end(); ++it)
        std::cout << it->first << "['" << it->second << "']" << std::endl;
    std::cout << std::endl << std::endl;

        std::cout << "std::map<int,std::string> third(second.begin(),second.end())" << std::endl;
    for (std::map<int,std::string>::iterator it = third.begin(); it != third.end(); ++it)
        std::cout << it->first << "['" << it->second << "']" << std::endl;
    std::cout << std::endl;

        std::cout << "std::map<int,std::string> fourth(third)" << std::endl;
    for (std::map<int,std::string>::iterator it = fourth.begin(); it != fourth.end(); ++it)
        std::cout << it->first << "['" << it->second << "']" << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: CONSTRUCTOR ---" << PRINT_END << std::endl;


    ft::map<int,std::string> first;
    ft::map<int,std::string> second;
    second[1]="alpha";
    second[2]="beta";
    second[3]="gamma";
    second[4]="delta";

    ft::map<int,std::string> third(second.begin(),second.end());
    ft::map<int,std::string> fourth(third);

    std::cout << "ft::map<int,std::string> first" << std::endl;
    for (ft::map<int,std::string>::iterator it = first.begin(); it != first.end(); ++it)
        std::cout << it->first << "['" << it->second << "']" << std::endl;
    std::cout << std::endl;

    std::cout << "ft::map<int,std::string> second (with added values)" << std::endl;
    for (ft::map<int,std::string>::iterator it = second.begin(); it != second.end(); ++it)
        std::cout << it->first << "['" << it->second << "']" << std::endl;
    std::cout << std::endl << std::endl;

        std::cout << "ft::map<int,std::string> third(second.begin(),second.end())" << std::endl;
    for (ft::map<int,std::string>::iterator it = third.begin(); it != third.end(); ++it)
        std::cout << it->first << "['" << it->second << "']" << std::endl;
    std::cout << std::endl;

        std::cout << "ft::map<int,std::string> fourth(third)" << std::endl;
    for (ft::map<int,std::string>::iterator it = fourth.begin(); it != fourth.end(); ++it)
        std::cout << it->first << "['" << it->second << "']" << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void MapTest::_map_assignment(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: ASSIGNMENT ---" << PRINT_END << std::endl;


    std::map<char,int> first;
    std::map<char,int> second;

    first['x']=8;
    first['y']=16;
    first['z']=32;

    second=first;                // second now contains 3 ints
    first=std::map<char,int>();  // and first is now empty

    std::cout << "Size of first: " << first.size() << std::endl;
    std::cout << "Size of second: " << second.size() << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: ASSIGNMENT ---" << PRINT_END << std::endl;


    ft::map<char,int> first;
    ft::map<char,int> second;

    first['x']=8;
    first['y']=16;
    first['z']=32;

    second=first;                // second now contains 3 ints
    first=ft::map<char,int>();  // and first is now empty

    std::cout << "Size of first: " << first.size() << std::endl;
    std::cout << "Size of second: " << second.size() << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */
/*                                   ITERATORS                                */
/* ************************************************************************** */

void MapTest::_map_iterator(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: ITERATOR ---" << PRINT_END << std::endl;


    std::map<char,int> mymap;

    mymap['b'] = 100;
    mymap['a'] = 200;
    mymap['c'] = 300;

    // show content:
    for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: ITERATOR ---" << PRINT_END << std::endl;


    ft::map<char,int> mymap;

    mymap['b'] = 100;
    mymap['a'] = 200;
    mymap['c'] = 300;

    // show content:
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void MapTest::_map_riterator(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: REVERSE_ITERATOR ---" << PRINT_END << std::endl;


    std::map<char,int> mymap;

    mymap['x'] = 100;
    mymap['y'] = 200;
    mymap['z'] = 300;

    // show content:
    std::map<char,int>::reverse_iterator rit;
    for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
        std::cout << rit->first << " => " << rit->second << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: REVERSE_ITERATOR ---" << PRINT_END << std::endl;


    ft::map<char,int> mymap;

    mymap['x'] = 100;
    mymap['y'] = 200;
    mymap['z'] = 300;

    // show content:
    ft::map<char,int>::reverse_iterator rit;
    for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
        std::cout << rit->first << " => " << rit->second << std::endl;
}
}

/* ************************************************************************** */
/*                                   CAPACITY                                 */
/* ************************************************************************** */

void MapTest::_map_empty(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: EMPTY ---" << PRINT_END << std::endl;


    std::map<char,int> mymap;

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;

    while (!mymap.empty())
    {
        std::cout << mymap.begin()->first << " => " << mymap.begin()->second << std::endl;
        mymap.erase(mymap.begin());
    }
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: EMPTY ---" << PRINT_END << std::endl;


    ft::map<char,int> mymap;

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;

    while (!mymap.empty())
    {
        std::cout << mymap.begin()->first << " => " << mymap.begin()->second << std::endl;
        mymap.erase(mymap.begin());
    }
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void MapTest::_map_size(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: SIZE ---" << PRINT_END << std::endl;


    std::map<char,int> mymap;
    mymap['a']=101;
    mymap['b']=202;
    mymap['c']=302;

    std::cout << "mymap.size() is " << mymap.size() << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: SIZE ---" << PRINT_END << std::endl;


    ft::map<char,int> mymap;
    mymap['a']=101;
    mymap['b']=202;
    mymap['c']=302;

    std::cout << "mymap.size() is " << mymap.size() << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void MapTest::_map_max_size(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: MAX_SIZE ---" << PRINT_END << std::endl;


    int i;
    std::map<int,int> mymap;

    std::cout << "Max Size :: " << mymap.max_size() << std::endl;
    if (mymap.max_size()>1000)
    {
        for (i=0; i<1000; i++) mymap[i]=0;
        std::cout << "The map contains 1000 elements.\n";
    }
    else std::cout << "The map could not hold 1000 elements.\n";
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: MAX_SIZE ---" << PRINT_END << std::endl;


    int i;
    ft::map<int,int> mymap;

    std::cout << "Max Size :: " << mymap.max_size() << std::endl;
    if (mymap.max_size()>1000)
    {
        for (i=0; i<1000; i++) mymap[i]=0;
        std::cout << "The map contains 1000 elements.\n";
    }
    else std::cout << "The map could not hold 1000 elements.\n";
    std::cout << std::endl;
}
}

/* ************************************************************************** */
/*                                ELEMENT ACCESS                              */
/* ************************************************************************** */

void MapTest::_map_brackets(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: OPERATOR[] ---" << PRINT_END << std::endl;


    std::map<char,std::string> mymap;

    mymap['a']="an element";
    mymap['b']="another element";
    mymap['c']=mymap['b'];

    std::cout << "mymap['a'] is " << mymap['a'] << std::endl;
    std::cout << "mymap['b'] is " << mymap['b'] << std::endl;
    std::cout << "mymap['c'] is " << mymap['c'] << std::endl;
    std::cout << "mymap['d'] is " << mymap['d'] << std::endl;

    std::cout << "mymap now contains " << mymap.size() << " elements.\n";
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: OPERATOR[] ---" << PRINT_END << std::endl;


    ft::map<char,std::string> mymap;

    mymap['a']="an element";
    mymap['b']="another element";
    mymap['c']=mymap['b'];

    std::cout << "mymap['a'] is " << mymap['a'] << std::endl;
    std::cout << "mymap['b'] is " << mymap['b'] << std::endl;
    std::cout << "mymap['c'] is " << mymap['c'] << std::endl;
    std::cout << "mymap['d'] is " << mymap['d'] << std::endl;

    std::cout << "mymap now contains " << mymap.size() << " elements.\n";
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void MapTest::_map_at(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: AT ---" << PRINT_END << std::endl;


    std::map<std::string,int> mymap;

    mymap["alpha"] = 0;
    mymap["beta"] = 0;
    mymap["gamma"] = 0;

    mymap.at("alpha") = 10;
    mymap.at("beta") = 20;
    mymap.at("gamma") = 30;

    for (std::map<std::string,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << ": " << it->second << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: AT ---" << PRINT_END << std::endl;


    ft::map<std::string,int> mymap;

    mymap["alpha"] = 0;
    mymap["beta"] = 0;
    mymap["gamma"] = 0;

    mymap.at("alpha") = 10;
    mymap.at("beta") = 20;
    mymap.at("gamma") = 30;

    for (ft::map<std::string,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << ": " << it->second << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */
/*                                   MODIFIERS                                */
/* ************************************************************************** */


void MapTest::_map_insert(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: INSERT ---" << PRINT_END << std::endl;


    std::map<char,int> mymap;

    // first insert function version (single parameter):
    mymap.insert ( std::pair<char,int>('a',100) );
    mymap.insert ( std::pair<char,int>('z',200) );

    std::pair<std::map<char,int>::iterator,bool> ret;
    ret = mymap.insert ( std::pair<char,int>('z',500) );
    if (ret.second==false) {
        std::cout << "element 'z' already existed";
        std::cout << " with a value of " << ret.first->second << std::endl;
    }

    // second insert function version (with hint position):
    std::map<char,int>::iterator it = mymap.begin();
    mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
    mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

    // third insert function version (range insertion):
    std::map<char,int> anothermap;
    anothermap.insert(mymap.begin(),mymap.find('c'));

    // showing contents:
    std::cout << "mymap contains:\n";
    for (it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;

    std::cout << "anothermap contains:\n";
    for (it=anothermap.begin(); it!=anothermap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: INSERT ---" << PRINT_END << std::endl;


    ft::map<char,int> mymap;

    // first insert function version (single parameter):
    mymap.insert ( ft::pair<char,int>('a',100) );
    mymap.insert ( ft::pair<char,int>('z',200) );

    ft::pair<ft::map<char,int>::iterator,bool> ret;
    ret = mymap.insert ( ft::pair<char,int>('z',500) );
    if (ret.second==false) {
        std::cout << "element 'z' already existed";
        std::cout << " with a value of " << ret.first->second << std::endl;
    }

    // second insert function version (with hint position):
    ft::map<char,int>::iterator it = mymap.begin();
    mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
    mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

    // third insert function version (range insertion):
    ft::map<char,int> anothermap;
    anothermap.insert(mymap.begin(),mymap.find('c'));

    // showing contents:
    std::cout << "mymap contains:\n";
    for (it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;

    std::cout << "anothermap contains:\n";
    for (it=anothermap.begin(); it!=anothermap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void MapTest::_map_erase(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: ERASE ---" << PRINT_END << std::endl;


    std::map<char,int> mymap;
    std::map<char,int>::iterator it;

    // insert some values:
    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    mymap['d']=40;
    mymap['e']=50;
    mymap['f']=60;

    it=mymap.find('b');
    mymap.erase (it);                   // erasing by iterator

    mymap.erase ('c');                  // erasing by key

    it=mymap.find ('e');
    mymap.erase ( it, mymap.end() );    // erasing by range

    // show content:
    for (it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: ERASE ---" << PRINT_END << std::endl;


    ft::map<char,int> mymap;
    ft::map<char,int>::iterator it;

    // insert some values:
    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    mymap['d']=40;
    mymap['e']=50;
    mymap['f']=60;

    it=mymap.find('b');
    mymap.erase (it);                   // erasing by iterator

    mymap.erase ('c');                  // erasing by key

    it=mymap.find ('e');
    mymap.erase ( it, mymap.end() );    // erasing by range

    // show content:
    for (it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void MapTest::_map_swap(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: SWAP ---" << PRINT_END << std::endl;


    std::map<char,int> foo,bar;

    foo['x']=100;
    foo['y']=200;
  
    bar['a']=11;
    bar['b']=22;
    bar['c']=33;
  
    foo.swap(bar);

    std::cout << "foo contains:\n";
    for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;

    std::cout << "bar contains:\n";
    for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: SWAP ---" << PRINT_END << std::endl;


    ft::map<char,int> foo,bar;

    foo['x']=100;
    foo['y']=200;
  
    bar['a']=11;
    bar['b']=22;
    bar['c']=33;
  
    foo.swap(bar);

    std::cout << "foo contains:\n";
    for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;

    std::cout << "bar contains:\n";
    for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void MapTest::_map_clear(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: CLEAR ---" << PRINT_END << std::endl;


    std::map<char,int> mymap;

    mymap['x']=100;
    mymap['y']=200;
    mymap['z']=300;

    std::cout << "mymap contains:\n";
    for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;

    mymap.clear();
    mymap['a']=1101;
    mymap['b']=2202;

    std::cout << "mymap contains:\n";
    for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: CLEAR ---" << PRINT_END << std::endl;


    ft::map<char,int> mymap;

    mymap['x']=100;
    mymap['y']=200;
    mymap['z']=300;

    std::cout << "mymap contains:\n";
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;

    mymap.clear();
    mymap['a']=1101;
    mymap['b']=2202;

    std::cout << "mymap contains:\n";
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */
/*                                   OBSERVERS                                */
/* ************************************************************************** */

void MapTest::_map_key_comp(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: KEY_COMPARE ---" << PRINT_END << std::endl;


    std::map<char,int> mymap;

    std::map<char,int>::key_compare mycomp = mymap.key_comp();

    mymap['a']=100;
    mymap['b']=200;
    mymap['c']=300;

    std::cout << "mymap contains:\n";

    char highest = mymap.rbegin()->first;     // key value of last element

    std::map<char,int>::iterator it = mymap.begin();
    do {
        std::cout << it->first << " => " << it->second << std::endl;
    } while ( mycomp((*it++).first, highest) );

    std::cout << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: KEY_COMPARE ---" << PRINT_END << std::endl;


    ft::map<char,int> mymap;

    ft::map<char,int>::key_compare mycomp = mymap.key_comp();

    mymap['a']=100;
    mymap['b']=200;
    mymap['c']=300;

    std::cout << "mymap contains:\n";

    char highest = mymap.rbegin()->first;     // key value of last element

    ft::map<char,int>::iterator it = mymap.begin();
    do {
        std::cout << it->first << " => " << it->second << std::endl;
    } while ( mycomp((*it++).first, highest) );

    std::cout << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void MapTest::_map_value_comp(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: VALUE_COMPARE ---" << PRINT_END << std::endl;


    std::map<char,int> mymap;

    mymap['x']=1001;
    mymap['y']=2002;
    mymap['z']=3003;

    std::cout << "mymap contains:\n";

    std::pair<char,int> highest = *mymap.rbegin();          // last element

    std::map<char,int>::iterator it = mymap.begin();
    do {
        std::cout << it->first << " => " << it->second << std::endl;
    } while ( mymap.value_comp()(*it++, highest) );
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: VALUE_COMPARE ---" << PRINT_END << std::endl;


    ft::map<char,int> mymap;

    mymap['x']=1001;
    mymap['y']=2002;
    mymap['z']=3003;

    std::cout << "mymap contains:\n";

    ft::pair<char,int> highest = *mymap.rbegin();          // last element

    ft::map<char,int>::iterator it = mymap.begin();
    do {
        std::cout << it->first << " => " << it->second << std::endl;
    } while ( mymap.value_comp()(*it++, highest) );
    std::cout << std::endl;
}
}

/* ************************************************************************** */
/*                                   OPERATIONS                               */
/* ************************************************************************** */

void MapTest::_map_find(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: FIND ---" << PRINT_END << std::endl;


    std::map<char,int> mymap;
    std::map<char,int>::iterator it;

    mymap['a']=50;
    mymap['b']=100;
    mymap['c']=150;
    mymap['d']=200;

    it = mymap.find('b');
    if (it != mymap.end())
        mymap.erase (it);

    // print content:
    std::cout << "elements in mymap:" << std::endl;
    std::cout << "a => " << mymap.find('a')->second << std::endl;
    std::cout << "c => " << mymap.find('c')->second << std::endl;
    std::cout << "d => " << mymap.find('d')->second << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: FIND ---" << PRINT_END << std::endl;


    ft::map<char,int> mymap;
    ft::map<char,int>::iterator it;

    mymap['a']=50;
    mymap['b']=100;
    mymap['c']=150;
    mymap['d']=200;

    it = mymap.find('b');
    if (it != mymap.end())
        mymap.erase (it);

    // print content:
    std::cout << "elements in mymap:" << std::endl;
    std::cout << "a => " << mymap.find('a')->second << std::endl;
    std::cout << "c => " << mymap.find('c')->second << std::endl;
    std::cout << "d => " << mymap.find('d')->second << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void MapTest::_map_count(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: COUNT ---" << PRINT_END << std::endl;


    std::map<char,int> mymap;
    char c;

    mymap ['a']=101;
    mymap ['c']=202;
    mymap ['f']=303;

    for (c='a'; c<'h'; c++)
    {
        std::cout << c;
        if (mymap.count(c)>0)
            std::cout << " is an element of mymap.\n";
        else 
            std::cout << " is not an element of mymap.\n";
    }
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: COUNT ---" << PRINT_END << std::endl;


    ft::map<char,int> mymap;
    char c;

    mymap ['a']=101;
    mymap ['c']=202;
    mymap ['f']=303;

    for (c='a'; c<'h'; c++)
    {
        std::cout << c;
        if (mymap.count(c)>0)
            std::cout << " is an element of mymap.\n";
        else 
            std::cout << " is not an element of mymap.\n";
    }
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void MapTest::_map_bounds(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: LOWER_BOUND / UPPER_BOUND ---" << PRINT_END << std::endl;


    std::map<char,int> mymap;
    std::map<char,int>::iterator itlow,itup;

    mymap['a']=20;
    mymap['b']=40;
    mymap['c']=60;
    mymap['d']=80;
    mymap['e']=100;

    itlow=mymap.lower_bound ('b');  // itlow points to b
    itup=mymap.upper_bound ('d');   // itup points to e (not d!)

    mymap.erase(itlow,itup);        // erases [itlow,itup)

    // print content:
    for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: LOWER_BOUND / UPPER_BOUND ---" << PRINT_END << std::endl;


    ft::map<char,int> mymap;
    ft::map<char,int>::iterator itlow,itup;

    mymap['a']=20;
    mymap['b']=40;
    mymap['c']=60;
    mymap['d']=80;
    mymap['e']=100;

    itlow=mymap.lower_bound ('b');  // itlow points to b
    itup=mymap.upper_bound ('d');   // itup points to e (not d!)

    mymap.erase(itlow,itup);        // erases [itlow,itup)

    // print content:
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void MapTest::_map_equal_range(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: EQUAL_RANGE ---" << PRINT_END << std::endl;


    std::map<char,int> mymap;

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;

    std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
    ret = mymap.equal_range('b');

    std::cout << "lower bound points to: ";
    std::cout << ret.first->first << " => " << ret.first->second << std::endl;

    std::cout << "upper bound points to: ";
    std::cout << ret.second->first << " => " << ret.second->second << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: EQUAL_RANGE ---" << PRINT_END << std::endl;


    ft::map<char,int> mymap;

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;

    ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
    ret = mymap.equal_range('b');

    std::cout << "lower bound points to: ";
    std::cout << ret.first->first << " => " << ret.first->second << std::endl;

    std::cout << "upper bound points to: ";
    std::cout << ret.second->first << " => " << ret.second->second << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */
/*                                    ALLOCATOR                               */
/* ************************************************************************** */

void MapTest::_map_allocator(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: ALLOCATOR ---" << PRINT_END << std::endl;


    int psize;
    std::map<char,int> mymap;
    std::pair<const char,int>* p;

    // allocate an array of 5 elements using mymap's allocator:
    p=mymap.get_allocator().allocate(5);

    // assign some values to array
    psize = sizeof(std::map<char,int>::value_type)*5;

    std::cout << "The allocated array has a size of " << psize << " bytes.\n";

    mymap.get_allocator().deallocate(p,5);
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: ALLOCATOR ---" << PRINT_END << std::endl;


    int psize;
    ft::map<char,int> mymap;
    ft::pair<const char,int>* p;

    // allocate an array of 5 elements using mymap's allocator:
    p=mymap.get_allocator().allocate(5);

    // assign some values to array
    psize = sizeof(ft::map<char,int>::value_type)*5;

    std::cout << "The allocated array has a size of " << psize << " bytes.\n";

    mymap.get_allocator().deallocate(p,5);
    std::cout << std::endl;
}
}

/* ************************************************************************** */
/*                               NON-MEMBER FUNCTIONS                         */
/* ************************************************************************** */

void MapTest::_map_relational_operators(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: RELATIONAL_OPERATORS ---" << PRINT_END << std::endl;


    std::map<char,int> foo,bar;
    foo['a']=100;
    foo['b']=200;
    bar['a']=10;
    bar['z']=1000;

    // foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
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


    ft::map<char,int> foo,bar;
    foo['a']=100;
    foo['b']=200;
    bar['a']=10;
    bar['z']=1000;

    // foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
    if (foo==bar) std::cout << "foo and bar are equal\n";
    if (foo!=bar) std::cout << "foo and bar are not equal\n";
    if (foo< bar) std::cout << "foo is less than bar\n";
    if (foo> bar) std::cout << "foo is greater than bar\n";
    if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
    if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
    std::cout << std::endl;
}
}

/* ************************************************************************** */

void MapTest::_map_external_swap(bool isSTD)
{
if (isSTD)
{
    std::cout << PRINT_BLUE <<  "--- STD :: EXTERNAL_SWAP ---" << PRINT_END << std::endl;


    std::map<char,int> foo,bar;

    foo['x']=100;
    foo['y']=200;

    bar['a']=11;
    bar['b']=22;
    bar['c']=33;

    swap(foo,bar);

    std::cout << "foo contains:\n";
    for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;

    std::cout << "bar contains:\n";
    for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    std::cout << std::endl;
}
else
{
    std::cout << PRINT_ORANGE << "--- FT :: EXTERNAL_SWAP ---" << PRINT_END << std::endl;


    ft::map<char,int> foo,bar;

    foo['x']=100;
    foo['y']=200;

    bar['a']=11;
    bar['b']=22;
    bar['c']=33;

    swap(foo,bar);

    std::cout << "foo contains:\n";
    for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;

    std::cout << "bar contains:\n";
    for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
        std::cout << it->first << " => " << it->second << std::endl;
    std::cout << std::endl;
}
}

/* ************************************************************************** */
/*                                    LEAKS                                   */
/* ************************************************************************** */

void MapTest::_map_leaks(bool isSTD)
{
    if (!isSTD)
        return ;
    system("leaks ft_containers");
    std::cout << std::endl;
}

/* ************************************************************************** */
/*                                   MAP TEST                                 */
/* ************************************************************************** */
