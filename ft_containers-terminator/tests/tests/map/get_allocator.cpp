/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_allocator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkruger <tkruger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:25:38 by mleblanc          #+#    #+#             */
/*   Updated: 2022/11/24 15:41:26 by tkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_prelude.hpp"

void map_test_get_allocator()
{
    intmap m;

    track_allocator<NAMESPACE::pair<const int, std::string> > alloc = m.get_allocator();

    NAMESPACE::pair<const int, std::string>* buff = alloc.allocate(64);

    alloc.deallocate(buff, 64);
}

MAIN(map_test_get_allocator)
