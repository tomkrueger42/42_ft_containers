/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 23:35:41 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/11/24 16:17:06 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/VectorTest.hpp"
#include "stack/StackTest.hpp"
#include "map/MapTest.hpp"
#include "set/SetTest.hpp"
#include "tree/TreeTest.hpp"

void printGoodbye()
{
    system("clear");

    std::cout << std::endl;
    std::cout << "   \033[1;35m ___ __       \033[0m                                         " << std::endl;
    std::cout << "   \033[1;35m(_  ( . ) )__ \033[0m                 \033[1;33m'.    \\   :   /    .'\033[0m   " << std::endl;
    std::cout << "   \033[1;35m  '(___(_____)\033[0m      __           \033[1;33m'.   \\  :  /   .'\033[0m     " << std::endl;
    std::cout << "                     /. _\\            \033[1;33m'.  \\ : /  .'\033[0m       " << std::endl;
    std::cout << "                .--.|/_/__      \033[1;33m-----____   _  _____-----\033[0m   " << std::endl;
    std::cout << "\033[1;36m_______________\033[0m''.--o/___  \\\033[1;34m_______________\033[1;33m(_)\033[0m\033[1;34m___________ \033[0m" << std::endl;
    std::cout << "       ~        /.'o|_o  '.|  ~                   ~   ~   " << std::endl;
    std::cout << "  ~            |/    |_|  ~'         ~                    " << std::endl;
    std::cout << "               '  ~  |_|        ~       ~     ~     ~     " << std::endl;
    std::cout << "      ~    ~          |_|  ~ \033[1;31mO\033[0m                      ~     " << std::endl;
    std::cout << "             ~     ___|_|____\033[1;31m|\033[0m_     ~       ~    ~        " << std::endl;
    std::cout << "   ~    ~      .'':. .|_|:. .\033[1;31mA\033[0m::''.                      " << std::endl;
    std::cout << "             /:.  .:::|_|.\\ .:.  :.:\\   ~               " << std::endl;
    std::cout << "  ~         :..:. .:. .::..:  .:  ..:.       ~   ~    ~   " << std::endl;
    std::cout << "             \\.: .:  :. .: ..:: .lcf/                    " << std::endl;
    std::cout << "    ~      ~      ~    ~    ~         ~                   " << std::endl;
    std::cout << "               ~           ~    ~   ~             ~       " << std::endl;
    std::cout << "        ~         ~            ~   ~                 ~    " << std::endl;
    std::cout << "   ~                  ~    ~ ~                 ~          " << std::endl;
    std::cout << std::endl;
    std::cout << PRINT_ORANGE << "We hope you enjoyed <FT_CONTAINERS>." << PRINT_END << std::endl;
    std::cout << PRINT_ORANGE << "Until next time!" << PRINT_END << std::endl;
    std::cout << std::endl;
}

void printOptions()
{
    system("clear");

    std::cout << std::endl;
    std::cout << "          \033[1;33mWelcome to wonderful...\033[0m                   \033[1;36m____\033[0m" << std::endl;
    std::cout << "                                         \033[1;34mv\033[0m        \033[1;36m_(\033[0m \033[1;34m42\033[0m \033[1;36m)\033[0m" << std::endl;
    std::cout << "        _ ^ _                          \033[1;33mv\033[0m         \033[1;36m(___(__)\033[0m" << std::endl;
    std::cout << "       '_\\V/ `                                                            " << std::endl;
    std::cout << "       ' oX`                                              " << std::endl;
    std::cout << "          X                            \033[1;34mv\033[0m                                   " << std::endl;
    std::cout << "          X             \033[1;31m-HELP!\033[0m                                             " << std::endl;
    std::cout << "          X                                                 \033[1;33m.\033[0m              " << std::endl;
    std::cout << "          X        \033[1;31m\\O/\033[0m                                      \033[1;33m|\\\033[0m" << std::endl;
    std::cout << "          X.a##a.   \033[1;31mM\033[0m                                       \033[1;33m|_\\\033[0m" << std::endl;
    std::cout << "       .aa########a.\033[1;31m>>\033[0m                                    __\033[1;33m|\033[0m__" << std::endl;
    std::cout << "    .a################aa.                                 \\ \033[1;33m42\033[0m /          " << std::endl;
    std::cout << "\033[1;34m~~~\033[0m/\033[1;34m~~~~~~~~~~~~~~~~~~~~~\033[0m\\\033[1;34m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m" << std::endl;
    std::cout << "   /    ;    \033[1;33mF T\033[0m   ` \" . \\                                               " << std::endl;
    std::cout << "   \\ \033[1;33mC O N T A I N E R S\033[0m /                              David S. Issel    " << std::endl;
    std::cout << "    \\   (╯°□°）╯ ︵ ┻━┻  \"                                ft. jpfuhl     " << std::endl;
    std::cout << std::endl;

    std::cout << PRINT_BLUE << "<1> :: Vector" << PRINT_END << std::endl;
    std::cout << PRINT_BLUE << "<2> :: Stack" << PRINT_END << std::endl;
    std::cout << PRINT_RED << "<3> :: Map" << PRINT_END << std::endl;
    std::cout << PRINT_BLACK << "<4> :: Set" << PRINT_END << std::endl;
    std::cout << PRINT_RED << "<5> :: Red" << PRINT_END 
              << PRINT_BLACK << "-Black-" << PRINT_END 
              << PRINT_RED << "Tree" << PRINT_END << std::endl;
    std::cout << PRINT_BLUE << "<6> :: Exit" << PRINT_END << std::endl;

    std::cout << std::endl;
    std::cout << PRINT_ORANGE << "Press <Number> to continue..." << PRINT_END << std::endl;
}

int main()
{
    std::string input;

    while (1)
    {
        printOptions();
        std::getline(std::cin, input);
        if (input == "1")
        {
            VectorTest vec;
            vec.run();
        }
        else if (input == "2")
        {
            StackTest stack;
            stack.run();
        }
        else if (input == "3")
        {
            MapTest map;
            map.run();
        }
        else if (input == "4")
        {
            SetTest set;
            set.run();
        }
        else if (input == "5")
        {
            TreeTest tree;
            tree.run();
        }
        else if (input == "6")
        {
            printGoodbye();
            break ;
        }
    }
    std::getline(std::cin, input);
    return 0;
}
