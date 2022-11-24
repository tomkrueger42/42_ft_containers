/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeTest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:15:11 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/11/24 02:32:37 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TreeTest.hpp"

/* ************************************************************************** */
/*                                   TREE TEST                                */
/* ************************************************************************** */

TreeTest::TreeTest() : _tree(ft::less<int>(), std::allocator<int>()) {}

/* ************************************************************************** */

TreeTest::~TreeTest() {}

/* ************************************************************************** */
/*                                     MAIN                                   */
/* ************************************************************************** */

void TreeTest::run()
{
    std::string buffer;

    system("clear");
    _print_welcome_message();
    std::getline(std::cin, buffer);

    system("clear");
    _print_black();
    _tree.print_tree();
    std::cout << std::endl << PRINT_BLACK << "Empty : " << PRINT_END << PRINT_ORANGE << "(sentinel)" << PRINT_END << std::endl;
    std::cout << std::endl << PRINT_RED << "Press <Enter> to continue..." << PRINT_END << std::endl;
    std::getline(std::cin, buffer);

    _insert(10);
    _insert(18);
    _insert(7);
    _insert(15);
    _insert(16);
    _insert(30);
    _insert(25);
    _insert(40);
    _insert(60);
    _insert(2);
    _insert(1);
    _insert(9);
    _insert(12);
    _insert(20);
    _delete(40);
    _insert(76);
    _insert(4);
    _delete(7);
    _delete(9);
    _delete(1);
    _insert(3);
    _insert(56);
    _delete(30);
    _delete(18);
    _insert(55);
    _insert(90);
    _insert(80);
    _insert(50);
    _insert(35);
    _insert(14);
    _delete(10);
    _delete(18);
    _delete(7);
    _delete(15);
    _delete(16);
    _insert(29);
    _delete(25);

    system("clear");
    _print_goodbye_message();
    std::getline(std::cin, buffer);
}

/* ************************************************************************** */
/*                                    UTILITY                                 */
/* ************************************************************************** */

void TreeTest::_print_welcome_message()
{
    std::cout << std::endl;
    _print_black();
    std::cout << std::endl;
    std::cout << PRINT_RED << "Welcome to <TreeTest>>." << PRINT_END << std::endl;
    std::cout << PRINT_BLACK << "No idea what a red black tree is?" << PRINT_END << std::endl << std::endl;
    std::cout << PRINT_RED << "Press <Enter> to continue..." << PRINT_END << std::endl;
    std::cout << std::endl;
}

/* ************************************************************************** */

void TreeTest::_print_goodbye_message()
{
    std::cout << std::endl;
    _print_vibrant();
    _tree.print_tree();
    std::cout << std::endl;
    std::cout << PRINT_RED << "We hope you enjoyed <TreeTest>." << PRINT_END << std::endl;
    std::cout << PRINT_BLACK << "Until next time!" << PRINT_END << std::endl;
    std::cout << std::endl;
}

/* ************************************************************************** */
/*                                    EXAMPLES                                */
/* ************************************************************************** */

void TreeTest::_insert(int n)
{
    std::string buffer;

    _tree.insert(n);

    system("clear");
    _print_tree();
    _tree.print_tree();
    std::cout << std::endl;
    std::cout << PRINT_BLACK << "Inserted : (" << n << ")" << PRINT_END << std::endl << std::endl;
    std::cout << PRINT_RED << "Press <Enter> to continue..." << PRINT_END << std::endl;
    std::getline(std::cin, buffer);
}

/* ************************************************************************** */

void TreeTest::_delete(int n)
{
    std::string buffer;

    _tree.erase(n);

    system("clear");
    _print_tree();
    _tree.print_tree();
    std::cout << std::endl;
    std::cout << PRINT_BLACK << "Deleted : (" << n << ")" << PRINT_END << std::endl << std::endl;
    std::cout << PRINT_RED << "Press <Enter> to continue..." << PRINT_END << std::endl;
    std::getline(std::cin, buffer);
}

/* ************************************************************************** */
/*                                     PRINT                                  */
/* ************************************************************************** */

void TreeTest::_print_tree() const
{
    if (_tree.size() == 0)
        _print_black();
    else if (_tree.size() == 1)
        _print_single();
    else if (_tree.size() < 5)
        _print_small();
    else if (_tree.size() < 10)
        _print_medium();
    else if (_tree.size() < 15)
        _print_large();
    else
        _print_vibrant();
}

/* ************************************************************************** */

void TreeTest::_print_black() const
{
std::cout << std::endl;
std::cout << "           *             ,          " << std::endl;
std::cout << "                       _/^\\_     " << std::endl;
std::cout << "                      <     >     " << std::endl;
std::cout << "     *                 /.-.\\           *" << std::endl;
std::cout << "              *        `/&\\`                    *" << std::endl;
std::cout << "                      ,@.*;@,         " << std::endl;
std::cout << "                     /_o.I %_\\    *      " << std::endl;
std::cout << "        *           (`'--:o(_@;           " << std::endl;
std::cout << "                   /`;--.,__ `')             *        " << std::endl;
std::cout << "                  ;@`o % O,*`'`&\\     " << std::endl;
std::cout << "            *    (`'--)_@ ;o %'()\\      *        " << std::endl;
std::cout << "                 /`;--._`''--._O'@;       " << std::endl;
std::cout << "                /&*,()~o`;-.,_ `""`)      " << std::endl;
std::cout << "     *          /`,@ ;+& () o*`;-';\\      " << std::endl;
std::cout << "               (`""--.,_0 +% @' &()\\     " << std::endl;
std::cout << "               /-.,_    ``''--....-'`)  *             " << std::endl;
std::cout << "          *    /@%;o`:;'--,.__   __.'\\        " << std::endl;
std::cout << "              ;*,&(); @ % &^;~`\"`o;@();         *        " << std::endl;
std::cout << "              /(); o^~; & ().o@*&`;&%O\\               " << std::endl;
std::cout << "        jgs   `\"=\"==\"\"==,,,.,=\"==\"===\"`        " << std::endl;
std::cout << "           __.----.\033[1;31m(\\\033[0m-''#####---...___...-----._ " << std::endl;
std::cout << "         '`         \033[1;31m\\)_\033[0m`\"\"\"\"\"`                   " << std::endl;
std::cout << "                 \033[1;31m.--' ')\033[0m                      " << std::endl;
std::cout << "               \033[1;31mo(  )_-\\\033[0m                  " << std::endl;
std::cout << "                 \033[1;31m`\"\"\"` `\033[0m               " << std::endl;
std::cout << std::endl;
}

/* ************************************************************************** */

void TreeTest::_print_single() const
{
std::cout << std::endl;
std::cout << "           *             \033[1;33m,\033[0m      " << std::endl;
std::cout << "                       \033[1;33m_/^\\_\033[0m     " << std::endl;
std::cout << "                      \033[1;33m<     >\033[0m     " << std::endl;
std::cout << "     *                 \033[1;33m/.-.\\\033[0m           *" << std::endl;
std::cout << "              *        `/&\\`                    *" << std::endl;
std::cout << "                      ,@.*;@,         " << std::endl;
std::cout << "                     /_o.I %_\\    *      " << std::endl;
std::cout << "        *           (`'--:o(_@;           " << std::endl;
std::cout << "                   /`;--.,__ `')             *        " << std::endl;
std::cout << "                  ;@`o % O,*`'`&\\     " << std::endl;
std::cout << "            *    (`'--)_@ ;o %'()\\      *        " << std::endl;
std::cout << "                 /`;--._`''--._O'@;       " << std::endl;
std::cout << "                /&*,()~o`;-.,_ `""`)      " << std::endl;
std::cout << "     *          /`,@ ;+& () o*`;-';\\      " << std::endl;
std::cout << "               (`""--.,_0 +% @' &()\\     " << std::endl;
std::cout << "               /-.,_    ``''--....-'`)  *             " << std::endl;
std::cout << "          *    /@%;o`:;'--,.__   __.'\\        " << std::endl;
std::cout << "              ;*,&(); @ % &^;~`\"`o;@();         *        " << std::endl;
std::cout << "              /(); o^~; & ().o@*&`;&%O\\               " << std::endl;
std::cout << "        jgs   `\"=\"==\"\"==,,,.,=\"==\"===\"`        " << std::endl;
std::cout << "           __.----.\033[1;31m(\\\033[0m-''#####---...___...-----._ " << std::endl;
std::cout << "         '`         \033[1;31m\\)_\033[0m`\"\"\"\"\"`                   " << std::endl;
std::cout << "                 \033[1;31m.--' ')\033[0m                      " << std::endl;
std::cout << "               \033[1;31mo(  )_-\\\033[0m                  " << std::endl;
std::cout << "                 \033[1;31m`\"\"\"` `\033[0m               " << std::endl;
std::cout << std::endl;
}

/* ************************************************************************** */

void TreeTest::_print_small() const
{
std::cout << std::endl;
std::cout << "           *             \033[1;33m,\033[0m      " << std::endl;
std::cout << "                       \033[1;33m_/^\\_\033[0m     " << std::endl;
std::cout << "                      \033[1;33m<     >\033[0m     " << std::endl;
std::cout << "     \033[1;35m*\033[0m                 \033[1;33m/.-.\\\033[0m           *" << std::endl;
std::cout << "              *        `/&\\`                    *" << std::endl;
std::cout << "                      ,\033[1;34m@\033[0m.*;@,         " << std::endl;
std::cout << "                     /_o.I %_\\    *      " << std::endl;
std::cout << "        *           (`'--:o(_@;           " << std::endl;
std::cout << "                   /`;--.,__ `')             *        " << std::endl;
std::cout << "                  ;@`\033[1;33mo\033[0m % O,*`'`&\\     " << std::endl;
std::cout << "            *    (`'--)_@ ;o %'()\\      *        " << std::endl;
std::cout << "                 /`;--._`''--._\033[1;33mO\033[0m'@;       " << std::endl;
std::cout << "                /&*,()~o`;-.,_ `""`)      " << std::endl;
std::cout << "     \033[1;35m*\033[0m          /`,@ ;+& () o*`;-';\\      " << std::endl;
std::cout << "               (`""--.,_0 +% \033[1;34m@\033[0m' &()\\     " << std::endl;
std::cout << "               /-.,_    ``''--....-'`)  \033[1;35m*\033[0m             " << std::endl;
std::cout << "          *    /\033[1;34m@\033[0m%;o`:;'--,.__   __.'\\        " << std::endl;
std::cout << "              ;*,&(); @ % &^;~`\"`o;@();         *        " << std::endl;
std::cout << "              /(); o^~; & ().\033[1;33mo\033[0m@*&`;&%O\\               " << std::endl;
std::cout << "        jgs   `\"=\"==\"\"==,,,.,=\"==\"===\"`        " << std::endl;
std::cout << "           __.----.\033[1;31m(\\\033[0m-''#####---...___...-----._ " << std::endl;
std::cout << "         '`         \033[1;31m\\)_\033[0m`\"\"\"\"\"`                   " << std::endl;
std::cout << "                 \033[1;31m.--' ')\033[0m                      " << std::endl;
std::cout << "               \033[1;31mo(  )_-\\\033[0m                  " << std::endl;
std::cout << "                 \033[1;31m`\"\"\"` `\033[0m               " << std::endl;
std::cout << std::endl;
}

/* ************************************************************************** */

void TreeTest::_print_medium() const
{
std::cout << std::endl;
std::cout << "           *             \033[1;33m,\033[0m      " << std::endl;
std::cout << "                       \033[1;33m_/^\\_\033[0m     " << std::endl;
std::cout << "                      \033[1;33m<     >\033[0m     " << std::endl;
std::cout << "     \033[1;35m*\033[0m                 \033[1;33m/.-.\\\033[0m           *" << std::endl;
std::cout << "              *        `/&\\`                    *" << std::endl;
std::cout << "                      ,\033[1;34m@\033[0m.*;@,         " << std::endl;
std::cout << "                     /_o.I %_\\    \033[1;33m*\033[0m      " << std::endl;
std::cout << "        \033[1;33m*\033[0m           (`'--:o(_\033[1;35m@\033[0m;           " << std::endl;
std::cout << "                   /`;--.,__ `')             *        " << std::endl;
std::cout << "                  ;@`\033[1;33mo\033[0m % \033[1;33m0\033[0m,*`'`&\\     " << std::endl;
std::cout << "            *    (`'--)_\033[1;35m@\033[0m ;o %'()\\      *        " << std::endl;
std::cout << "                 /`;--._`''--._\033[1;33mO\033[0m'@;       " << std::endl;
std::cout << "                /&*,()~o`;-.,_ `""`)      " << std::endl;
std::cout << "     \033[1;35m*\033[0m          /`,@ ;+& () o*`;-';\\      " << std::endl;
std::cout << "               (`""--.,_\033[1;33m0\033[0m +% \033[1;34m@\033[0m' &()\\     " << std::endl;
std::cout << "               /-.,_    ``''--....-'`)  \033[1;35m*\033[0m             " << std::endl;
std::cout << "          *    /\033[1;34m@\033[0m%;o`:;'--,.__   __.'\\        " << std::endl;
std::cout << "              ;*,&(); @ % &^;~`\"`o;\033[1;35m@\033[0m();         \033[1;33m*\033[0m        " << std::endl;
std::cout << "              /\033[1;33m()\033[0m; o^~; & ().\033[1;33mo\033[0m@*&`;&%O\\               " << std::endl;
std::cout << "        jgs   `\"=\"==\"\"==,,,.,=\"==\"===\"`        " << std::endl;
std::cout << "           __.----.\033[1;31m(\\\033[0m-''#####---...___...-----._ " << std::endl;
std::cout << "         '`         \033[1;31m\\)_\033[0m`\"\"\"\"\"`                   " << std::endl;
std::cout << "                 \033[1;31m.--' ')\033[0m                      " << std::endl;
std::cout << "               \033[1;31mo(  )_-\\\033[0m                  " << std::endl;
std::cout << "                 \033[1;31m`\"\"\"` `\033[0m               " << std::endl;
std::cout << std::endl;
}

/* ************************************************************************** */

void TreeTest::_print_large() const
{
std::cout << std::endl;
std::cout << "           *             \033[1;33m,\033[0m      " << std::endl;
std::cout << "                       \033[1;33m_/^\\_\033[0m     " << std::endl;
std::cout << "                      \033[1;33m<     >\033[0m     " << std::endl;
std::cout << "     \033[1;35m*\033[0m                 \033[1;33m/.-.\\\033[0m           \033[1;34m*\033[0m" << std::endl;
std::cout << "              \033[1;34m*\033[0m        `/&\\`                    *" << std::endl;
std::cout << "                      ,\033[1;34m@\033[0m.*;@,         " << std::endl;
std::cout << "                     /_o.I %_\\    \033[1;33m*\033[0m      " << std::endl;
std::cout << "        \033[1;33m*\033[0m           (`'--:o(_\033[1;35m@\033[0m;           " << std::endl;
std::cout << "                   /`;--.,__ `')             \033[1;35m*\033[0m        " << std::endl;
std::cout << "                  ;\033[1;35m@\033[0m`\033[1;33mo\033[0m % \033[1;33m0\033[0m,*`'`&\\     " << std::endl;
std::cout << "            \033[1;34m*\033[0m    (`'--)_\033[1;35m@\033[0m ;o %'()\\      *        " << std::endl;
std::cout << "                 /`;--._`''--._\033[1;33mO\033[0m'\033[1;35m@\033[0m;       " << std::endl;
std::cout << "                /&*,\033[1;34m()\033[0m~o`;-.,_ `""`)      " << std::endl;
std::cout << "     \033[1;35m*\033[0m          /`,@ ;+& () o\033[1;35m@\033[0m`;-';\\      " << std::endl;
std::cout << "               (`""--.,_\033[1;33m0\033[0m +% \033[1;34m@\033[0m' &()\\     " << std::endl;
std::cout << "               /-.,_    ``''--....-'`)  \033[1;35m*\033[0m             " << std::endl;
std::cout << "          *    /\033[1;34m@\033[0m%;o`:;'--,.__   __.'\\        " << std::endl;
std::cout << "              ;*,&(); \033[1;35m@\033[0m % \033[1;35m@\033[0m^;~`\"`o;\033[1;35m@\033[0m();         \033[1;33m*\033[0m        " << std::endl;
std::cout << "              /\033[1;33m()\033[0m; o^~; & ().\033[1;33mo\033[0m@*&`;&%O\\               " << std::endl;
std::cout << "        jgs   `\"=\"==\"\"==,,,.,=\"==\"===\"`        " << std::endl;
std::cout << "           __.----.\033[1;31m(\\\033[0m-''#####---...___...-----._ " << std::endl;
std::cout << "         '`         \033[1;31m\\)_\033[0m`\"\"\"\"\"`                   " << std::endl;
std::cout << "                 \033[1;31m.--' ')\033[0m                      " << std::endl;
std::cout << "               \033[1;31mo(  )_-\\\033[0m                  " << std::endl;
std::cout << "                 \033[1;31m`\"\"\"` `\033[0m               " << std::endl;
std::cout << std::endl;
}

/* ************************************************************************** */

void TreeTest::_print_vibrant() const
{
std::cout << std::endl;
std::cout << "           \033[1;33m*\033[0m             \033[1;33m,\033[0m      " << std::endl;
std::cout << "                       \033[1;33m_/^\\_\033[0m     " << std::endl;
std::cout << "                      \033[1;33m<     >\033[0m     " << std::endl;
std::cout << "     \033[1;35m*\033[0m                 \033[1;33m/.-.\\\033[0m           \033[1;34m*\033[0m" << std::endl;
std::cout << "              \033[1;34m*\033[0m        `/&\\`                    \033[1;33m*\033[0m" << std::endl;
std::cout << "                      ,\033[1;34m@\033[0m.*;@,         " << std::endl;
std::cout << "                     /_\033[1;33mo\033[0m.I %_\\    \033[1;33m*\033[0m      " << std::endl;
std::cout << "        \033[1;33m*\033[0m           (`'--:\033[1;33mo\033[0m(_\033[1;35m@\033[0m;           " << std::endl;
std::cout << "                   /`;--.,__ `')             \033[1;35m*\033[0m        " << std::endl;
std::cout << "                  ;\033[1;35m@\033[0m`\033[1;33mo\033[0m % \033[1;33m0\033[0m,*`'`&\\     " << std::endl;
std::cout << "            \033[1;34m*\033[0m    (`'--)_\033[1;35m@\033[0m ;o %'()\\      \033[1;33m*\033[0m        " << std::endl;
std::cout << "                 /`;--._`''--._\033[1;33mO\033[0m'\033[1;35m@\033[0m;       " << std::endl;
std::cout << "                /&\033[1;33m*\033[0m,\033[1;34m()\033[0m~\033[1;33mo\033[0m`;-.,_ `""`)      " << std::endl;
std::cout << "     \033[1;35m*\033[0m          /`,@ ;+& \033[1;33m()\033[0m o\033[1;35m@\033[0m`;-';\\      " << std::endl;
std::cout << "               (`""--.,_\033[1;33m0\033[0m +% \033[1;34m@\033[0m' &()\\     " << std::endl;
std::cout << "               /-.,_    ``''--....-'`)  \033[1;35m*\033[0m             " << std::endl;
std::cout << "          \033[1;33m*\033[0m    /\033[1;34m@\033[0m%;o`:;'--,.__   __.'\\        " << std::endl;
std::cout << "              ;*,&(); \033[1;35m@\033[0m % \033[1;35m@\033[0m^;~`\"`o;\033[1;35m@\033[0m();         \033[1;33m*\033[0m        " << std::endl;
std::cout << "              /\033[1;33m()\033[0m; \033[1;33mo\033[0m^~; & ().\033[1;33mo\033[0m@*&`;&%\033[1;33mO\033[0m\\               " << std::endl;
std::cout << "        jgs   `\"=\"==\"\"==,,,.,=\"==\"===\"`        " << std::endl;
std::cout << "           __.----.\033[1;31m(\\\033[0m-''#####---...___...-----._ " << std::endl;
std::cout << "         '`         \033[1;31m\\)_\033[0m`\"\"\"\"\"`                   " << std::endl;
std::cout << "                 \033[1;31m.--' ')\033[0m                      " << std::endl;
std::cout << "               \033[1;31mo(  )_-\\\033[0m                  " << std::endl;
std::cout << "                 \033[1;31m`\"\"\"` `\033[0m               " << std::endl;
std::cout << std::endl;
}

/* ************************************************************************** */
/*                                   TREE TEST                                */
/* ************************************************************************** */
