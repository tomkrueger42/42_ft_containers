/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:09:06 by mleblanc          #+#    #+#             */
/*   Updated: 2022/11/24 14:59:25 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_prelude.hpp"

void map_test_assignment()
{
    SETUP_ARRAYS();

    {
        intmap m1;
        intmap m2;

        m1 = m2;

        PRINT_ALL(m1);

        m2 = intmap(intstr_arr, intstr_arr + intstr_size);

        PRINT_ALL(m2);

        m1 = m2;

        PRINT_ALL(m1);

        m1 = intmap(intstr_arr, intstr_arr + 10);

        PRINT_ALL(m1);

        m2 = m1;

        PRINT_ALL(m2);
    }

    {
        strmap m1;
        strmap m2;

        m1 = m2;

        PRINT_ALL(m1);

        m2 = strmap(strstr_arr, strstr_arr + strstr_size);

        PRINT_ALL(m2);

        m1 = m2;

        PRINT_ALL(m1);

        m1 = strmap(strstr_arr, strstr_arr + 10);

        PRINT_ALL(m1);

        m2 = m1;

        PRINT_ALL(m2);
    }
}

MAIN(map_test_assignment)
