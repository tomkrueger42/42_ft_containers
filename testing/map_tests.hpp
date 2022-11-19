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

template< typename T >
void	map_print_structure( const T& map )
{

}

void	map_constructor( void )
{
	NS::map<int, char>	map;
	map_print(map);

	// NS::map<int, char>	map2(map.get_allocator());							//	weird, because this works with STL but shouldn't as in the documentation
	// map_print(map2);

	
}

void	map_operator_assign( void )
{
	NS::map<int, char>	map;
	map_print(map);

	NS::map<int, char>	map2 = map;
	map_print(map2);

	map.insert(NS::pair<int, char>(1, a));
	map.insert(NS::pair<int, char>(2, b));
	map.insert(NS::pair<int, char>(3, c));
	map_print(map);

	NS::map<int, char>	map2 = map;
	map_print(map2);
	map.erase(map.begin());
	map_print(map2);
}

void	map_get_allocator( void )
{
	NS::map<int, char>	map;
	NS::map<int, char>	map2(map.get_allocator());
	map_print();
}

void	map_at( void )
{
	NS::map<int, char>	map;
	try
	{
		map.find(0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		map.find(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	map.insert(NS::pair<int, char>(1, a));
	try
	{
		map.find(0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		map.find(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	map_operator_at( void )
{
	NS::map<int, char>	map;
	LOGI(map[0]);
	
	map.insert(NS::pair<int, char>(1, a));
	LOGI(map[1]);
	LOGI(map[2]);
	map_print(map);

	map.insert(NS::pair<int, char>(2, b));
	LOGI(map[1]);
	LOGI(map[2]);
	map_print(map);
}

void	map_iterator( void )
{
	NS::map<int, char>	map;
	LOGI(map.begin().base());
	LOGI(map.end().base());
	LOGI(map.begin() == map.end());
	LOGI(map.begin() != map.end());

	map.insert(NS::pair<int, char>(1, a));
	for (NS::map<int, char>::iterator it = map.begin(); it != map.end(); it++)
		LOGI(it->second);
	map.insert(NS::pair<int, char>(2, b));
	NS::map<int, char>::iterator	it = map.begin();
	LOGI(it->second);
	++it;
	LOGI(it->second);
	--it;
	LOGI(it->second);
	it++;
	LOGI(it->second);
	it--;
	LOGI(it->second);
	it = map.end();
	it--;
	LOGI(it->second);

	map.erase(1);
	it = map.end();
	--it;
	LOGI(it->second);
}

void	map_reverse_iterator( void )
{
	NS::map<int, char>	map;
	LOGI(map.rbegin().base());
	LOGI(map.rend().base());
	LOGI(map.rbegin() == map.rend());
	LOGI(map.rbegin() != map.rend());

	map.insert(NS::pair<int, char>(1, a));
	for (NS::map<int, char>::reverse_iterator it = map.rbegin(); it != map.rend(); it++)
		LOGI(it->second);
	map.insert(NS::pair<int, char>(2, b));
	NS::map<int, char>::reverse_iterator	it = map.rbegin();
	LOGI(it->second);
	++it;
	LOGI(it->second);
	--it;
	LOGI(it->second);
	it++;
	LOGI(it->second);
	it--;
	LOGI(it->second);
	it = map.rend();
	it--;
	LOGI(it->second);

	map.erase(1);
	it = map.rend();
	--it;
	LOGI(it->second);
}

void	map_empty( void )
{
	NS::map<int, char>	map;
	LOGI(map.empty());
	map.insert(NS::pair<int, char>(1, a));
	LOGI(map.empty());
	map.erase(1);
	LOGI(map.empty());
}

void	map_size( void )
{
	NS::map<int, char>	map;
	LOGI(map.size());
	map.insert(NS::pair<int, char>(1, a));
	LOGI(map.size());
	map.erase(1);
	LOGI(map.size());
}

void	map_size( void )
{
	NS::map<int, char>	map;
	LOGI(map.max_size());
}

void	map_clear( void )
{
	NS::map<int, char>	map;
	map_print(map);
	map.clear();
	map_print(map);
	map.insert(NS::pair<int, char>(1, a));
	map_print(map);
	map.clear();
	map_print(map);
	map.insert(NS::pair<int, char>(1, a));
	map.insert(NS::pair<int, char>(2, b));
	map.insert(NS::pair<int, char>(3, c));
	map.insert(NS::pair<int, char>(4, d));
	map.insert(NS::pair<int, char>(5, e));
	map_print(map);
	map_clear();
	map_print(map);
}

void	map_insert( int overload )
{
	NS::map<int, char>	map;
	print_map(map);
	map.insert(NS::pair<int, char>(1, a));
	print_map(map);
	map.insert(NS::pair<int, char>(1, a));
	print_map(map);
	map.insert(NS::pair<int, char>(5, e));
	print_map(map);
	map.insert(NS::pair<int, char>(0, c));

}

