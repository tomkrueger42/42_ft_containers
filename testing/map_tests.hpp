#pragma once

#include <log.hpp>

#if USING_STD
	#include <map>
	#include <utility>
	#define NS std
#else
	#include "map.hpp"
	#include "utility.hpp"
	#define NS ft
#endif

template< typename T >
void	map_print( const T& map )
{
	for (typename T::const_iterator it = map.begin(); it != map.end(); it++)
	{
		LOG(it->first);
		LOG(": ");
		LOGN(it->second);
	}
	LOGI(map.size());
	LOGN("-------------------------")
}

void	map_constructor( void )
{
	NS::map<int, char>	map;
	map_print(map);
}