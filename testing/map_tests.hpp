#pragma once

#include <log.hpp>

#ifdef USING_STD
	#include <map>
	#define NAME_SPACE std
#else
	#include "map.hpp"
	#define NAME_SPACE ft
#endif

template< typename T >
void	map_print( const T& map )
{
	LOGN("map_print()");
	// for (typename T::const_iterator it = map.begin(); it != map.end(); it++)
	// {
	// 	LOG(it->first);
	// 	LOG(": ");
	// 	LOGN(it->second);
	// }
	LOGI(map.size());
	LOGI((map.begin() == map.end()));
	LOGN("-------------------------")
}

void	map_constructor( void )
{
	NAME_SPACE::map<int, char>	map;
	map_print(map);

	// NAME_SPACE::map<int, char>	map2(map.get_allocator());							//	weird, because this works with STL but shouldn't as in the documentation
	// map_print(map2);

	
}

void	map_operator_assign( void )
{
	NAME_SPACE::map<int, char>	map;
	map_print(map);

	NAME_SPACE::map<int, char>	map2 = map;
	map_print(map2);

	map.insert(NAME_SPACE::make_pair(1, 'a'));
	map.insert(NAME_SPACE::make_pair(2, 'b'));
	map.insert(NAME_SPACE::make_pair(3, 'c'));
	map_print(map);

	map2 = map;
	map_print(map2);
	map.erase(map.begin());
	map_print(map2);
}

void	map_get_allocator( void )
{
	NAME_SPACE::map<int, char>	map;
	NAME_SPACE::map<int, char>	map2(map.key_comp(), map.get_allocator());
	map_print(map2);
}

void	map_at( void )
{
	NAME_SPACE::map<int, char>	map;
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

	map.insert(NAME_SPACE::make_pair(1, 'a'));
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
	NAME_SPACE::map<int, char>	map;
	LOGI(map[0]);
	
	map.insert(NAME_SPACE::make_pair(1, 'a'));
	LOGI(map[1]);
	LOGI(map[2]);
	map_print(map);

	map.insert(NAME_SPACE::make_pair(2, 'b'));
	LOGI(map[1]);
	LOGI(map[2]);
	map_print(map);
}

void	map_iterator( void )
{
	NAME_SPACE::map<int, char>	map;
	LOGI(map.begin()->first);
	LOGI(map.end()->first);
	LOGI((map.begin() == map.end()));
	LOGI((map.begin() != map.end()));

	map.insert(NAME_SPACE::make_pair(1, 'a'));
	for (NAME_SPACE::map<int, char>::iterator it = map.begin(); it != map.end(); it++)
		LOGI(it->second);
	map.insert(NAME_SPACE::make_pair(2, 'b'));
	NAME_SPACE::map<int, char>::iterator	it = map.begin();
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
	// NAME_SPACE::map<int, char>	map;
	// // LOGI(map.rbegin()->first);
	// // LOGI(map.rend()->first);
	// LOGI((map.rbegin() == map.rend()));
	// LOGI((map.rbegin() != map.rend()));

	// map.insert(NAME_SPACE::make_pair(1, 'a'));
	// for (NAME_SPACE::map<int, char>::reverse_iterator it = map.rbegin(); it != map.rend(); it++)
	// 	LOGI(it->second);
	// map.insert(NAME_SPACE::make_pair(2, 'b'));
	// NAME_SPACE::map<int, char>::reverse_iterator	it = map.rbegin();
	// LOGI(it->second);
	// ++it;
	// LOGI(it->second);
	// --it;
	// LOGI(it->second);
	// it++;
	// LOGI(it->second);
	// it--;
	// LOGI(it->second);
	// it = map.rend();
	// it--;
	// LOGI(it->second);

	// map.erase(1);
	// it = map.rend();
	// --it;
	// LOGI(it->second);
}

void	map_empty( void )
{
	NAME_SPACE::map<int, char>	map;
	LOGI(map.empty());
	map.insert(NAME_SPACE::make_pair(1, 'a'));
	LOGI(map.empty());
	map.erase(1);
	LOGI(map.empty());
}

void	map_size( void )
{
	NAME_SPACE::map<int, char>	map;
	LOGI(map.size());
	map.insert(NAME_SPACE::make_pair(1, 'a'));
	LOGI(map.size());
	map.erase(1);
	LOGI(map.size());
}

void	map_max_size( void )
{
	NAME_SPACE::map<int, char>	map;
	LOGI(map.max_size());
}

void	map_clear( void )
{
	NAME_SPACE::map<int, char>	map;
	map_print(map);
	map.clear();
	map_print(map);
	map.insert(NAME_SPACE::make_pair(1, 'a'));
	map_print(map);
	map.clear();
	map_print(map);
	map.insert(NAME_SPACE::make_pair(1, 'a'));
	map.insert(NAME_SPACE::make_pair(2, 'b'));
	map.insert(NAME_SPACE::make_pair(3, 'c'));
	map.insert(NAME_SPACE::make_pair(4, 'd'));
	map.insert(NAME_SPACE::make_pair(5, 'e'));
	map_print(map);
	map.clear();
	map_print(map);
}

void	map_insert( int overload )
{
	if (overload == 1)
	{
		NAME_SPACE::map<int, char>	map;
		map_print(map);
		map.insert(NAME_SPACE::make_pair(5, 'e'));
		map_print(map);
		map.insert(NAME_SPACE::make_pair(5, 'e'));
		map_print(map);
		map.insert(NAME_SPACE::make_pair(2, 'b'));
		map_print(map);
		map.insert(NAME_SPACE::make_pair(7, 'g'));
		map_print(map);
		map.insert(NAME_SPACE::make_pair(3, 'c'));
		map_print(map);
		map.insert(NAME_SPACE::make_pair(7, 'g'));
		map_print(map);
		map.insert(NAME_SPACE::make_pair(6, 'f'));
		map_print(map);
		map.insert(NAME_SPACE::make_pair(1, 'a'));
		map_print(map);
		map.insert(NAME_SPACE::make_pair(8, 'h'));
		map_print(map);
	}
	else if (overload == 2)
	{
		{
			LOGN("always map.begin()");
			NAME_SPACE::map<int, char>	map;
			map_print(map);
			map.insert(map.begin(), NAME_SPACE::make_pair(5, 'e'));
			map_print(map);
			map.insert(map.begin(), NAME_SPACE::make_pair(5, 'e'));
			map_print(map);
			map.insert(map.begin(), NAME_SPACE::make_pair(2, 'b'));
			map_print(map);
			map.insert(map.begin(), NAME_SPACE::make_pair(7, 'g'));
			map_print(map);
			map.insert(map.begin(), NAME_SPACE::make_pair(3, 'c'));
			map_print(map);
			map.insert(map.begin(), NAME_SPACE::make_pair(7, 'g'));
			map_print(map);
			map.insert(map.begin(), NAME_SPACE::make_pair(6, 'f'));
			map_print(map);
			map.insert(map.begin(), NAME_SPACE::make_pair(1, 'a'));
			map_print(map);
			map.insert(map.begin(), NAME_SPACE::make_pair(8, 'h'));
			map_print(map);
			LOGN("--------------------------------------");
		}
		{
			LOGN("always map.end()");
			NAME_SPACE::map<int, char>	map;
			map_print(map);
			map.insert(map.end(), NAME_SPACE::make_pair(5, 'e'));
			map_print(map);
			map.insert(map.end(), NAME_SPACE::make_pair(5, 'e'));
			map_print(map);
			map.insert(map.end(), NAME_SPACE::make_pair(2, 'b'));
			map_print(map);
			map.insert(map.end(), NAME_SPACE::make_pair(7, 'g'));
			map_print(map);
			map.insert(map.end(), NAME_SPACE::make_pair(3, 'c'));
			map_print(map);
			map.insert(map.end(), NAME_SPACE::make_pair(7, 'g'));
			map_print(map);
			map.insert(map.end(), NAME_SPACE::make_pair(6, 'f'));
			map_print(map);
			map.insert(map.end(), NAME_SPACE::make_pair(1, 'a'));
			map_print(map);
			map.insert(map.end(), NAME_SPACE::make_pair(8, 'h'));
			map_print(map);
			LOGN("--------------------------------------");
		}
		{
			LOGN("mixed map.begin() and map.end()");
			NAME_SPACE::map<int, char>	map;
			map_print(map);
			map.insert(map.begin(), NAME_SPACE::make_pair(5, 'e'));
			map_print(map);
			map.insert(map.end(), NAME_SPACE::make_pair(5, 'e'));
			map_print(map);
			map.insert(map.begin(), NAME_SPACE::make_pair(2, 'b'));
			map_print(map);
			map.insert(map.end(), NAME_SPACE::make_pair(7, 'g'));
			map_print(map);
			map.insert(map.begin(), NAME_SPACE::make_pair(3, 'c'));
			map_print(map);
			map.insert(map.end(), NAME_SPACE::make_pair(7, 'g'));
			map_print(map);
			map.insert(map.begin(), NAME_SPACE::make_pair(6, 'f'));
			map_print(map);
			map.insert(map.end(), NAME_SPACE::make_pair(1, 'a'));
			map_print(map);
			map.insert(map.begin(), NAME_SPACE::make_pair(8, 'h'));
			map_print(map);
		}
	}
	else if (overload == 3)
	{
		NAME_SPACE::map<int, char>	map;
		NAME_SPACE::map<int, char>	map2;
		map2.insert(map.begin(), map.end());
		map_print(map2);
		map.insert(map2.begin(), map2.begin());
		map_print(map);
		map2.insert(map.end(), map.end());
		map_print(map2);
		map2.insert(map.end(), map.begin());
		map_print(map2);
		map.insert(map.begin(), map.end());
		map_print(map);
		map.insert(map.begin(), map.begin());
		map_print(map);
		map.insert(map.end(), map.end());
		map_print(map);
		map.insert(map.end(), map.begin());
		map_print(map);

		map.insert(NAME_SPACE::make_pair(5, 'e'));
		map.insert(NAME_SPACE::make_pair(5, 'e'));
		map.insert(NAME_SPACE::make_pair(2, 'b'));
		map.insert(NAME_SPACE::make_pair(7, 'g'));
		map.insert(NAME_SPACE::make_pair(3, 'c'));
		map.insert(NAME_SPACE::make_pair(7, 'g'));
		map.insert(NAME_SPACE::make_pair(6, 'f'));
		map.insert(NAME_SPACE::make_pair(1, 'a'));
		map.insert(NAME_SPACE::make_pair(8, 'h'));
		map_print(map);

		map2.insert(map.begin(), map.begin());
		map_print(map2);
		map2.insert(map.end(), map.end());
		map_print(map2);
		map2.insert(map.end(), map.begin());
		map_print(map2);
		map2.insert(map.begin(), map.end());
		map_print(map);
	}
}

void	map_erase( int overload )
{
	if (overload == 1)
	{
		NAME_SPACE::map<int, char>	map;
		map.erase(map.begin());
		map.erase(map.end());

		map.insert(NAME_SPACE::make_pair(5, 'e'));
		map.erase(map.end());
		LOGI((map.begin() == map.end()));
		map.erase(map.begin());
		LOGI((map.begin() == map.end()));
		map.erase(map.begin());

		map.insert(NAME_SPACE::make_pair(5, 'e'));
		map.insert(NAME_SPACE::make_pair(6, 'f'));
		map.insert(NAME_SPACE::make_pair(7, 'g'));

		map.erase(map.insert(NAME_SPACE::make_pair(6, 'f')).first);
		map.erase(map.insert(NAME_SPACE::make_pair(6, 'f')).first);
		map.erase(map.insert(NAME_SPACE::make_pair(5, 'f')).first);
		map.erase(map.insert(NAME_SPACE::make_pair(7, 'f')).first);
	}
	else if (overload == 2)
	{
		NAME_SPACE::map<int, char>	map;
		map.erase(map.begin(), map.begin());
		map.erase(map.end(), map.end());
		map.erase(map.end(), map.begin());
		map.erase(map.begin(), map.end());

		map_print(map);

		map.insert(NAME_SPACE::make_pair(5, 'e'));
		map.insert(NAME_SPACE::make_pair(6, 'f'));
		map.insert(NAME_SPACE::make_pair(7, 'g'));

		map_print(map);

		map.erase(map.begin(), map.begin());
		map.erase(map.end(), map.end());
		map.erase(map.end(), map.begin());
		map.erase(map.begin(), map.end());

		map_print(map);
	}
	else if (overload == 3)
	{
		NAME_SPACE::map<int, char>	map;
		LOGI(map.erase(0));
		LOGI(map.erase(1));

		map.insert(NAME_SPACE::make_pair(5, 'e'));
		LOGI(map.erase(0));
		LOGI((map.begin() == map.end()));
		LOGI(map.erase(5));
		LOGI((map.begin() == map.end()));
		LOGI(map.erase(5));

		map.insert(NAME_SPACE::make_pair(5, 'e'));
		map.insert(NAME_SPACE::make_pair(6, 'f'));
		map.insert(NAME_SPACE::make_pair(7, 'g'));

		LOGI(map.erase(0));
		LOGI(map.erase(6));
		LOGI(map.erase(6));
		LOGI(map.erase(0));
		LOGI(map.erase(5));
		LOGI(map.erase(7));
	}
}

void	map_swap( void )
{
	NAME_SPACE::map<int, char>	map;
	NAME_SPACE::map<int, char>	map2;

	map_print(map);
	map.swap(map2);
	map2.swap(map);
	map.swap(map);
	map_print(map);
	map.insert(NAME_SPACE::make_pair(1, 'a'));
	map.insert(NAME_SPACE::make_pair(2, 'b'));
	map.insert(NAME_SPACE::make_pair(3, 'c'));
	map_print(map);
	map_print(map2);
	map.swap(map2);
	map_print(map);
	map_print(map2);
	map2.swap(map2);
	map_print(map);
	map_print(map2);
}

void	map_count( void )
{
	NAME_SPACE::map<int, char>	map;

	LOGI(map.count(0));
	LOGI(map.count(1));

	map.insert(NAME_SPACE::make_pair(2, 'b'));
	LOGI(map.count(0));
	LOGI(map.count(2));
}

void	map_find( void )
{
	{
		NAME_SPACE::map<int, char>	map;

		LOGI(map.find(0)->first);
		LOGI(map.find(0)->second);

		map.insert(NAME_SPACE::make_pair(2, 'b'));
		LOGI(map.find(0)->first);
		LOGI(map.find(0)->second);
		LOGI(map.find(2)->first);
		LOGI(map.find(2)->second);
	}
	{
		const NAME_SPACE::map<int, char>	map;

		LOGI(map.find(0)->first);
		LOGI(map.find(0)->second);
	}
}

void	map_equal_range( void )
{
	{
		LOGN("const");
		const NAME_SPACE::map<int, char>	map;

		LOGI(map.equal_range(0).first->first);
		LOGI(map.equal_range(0).second->first);
	}
	{
		LOGN("non-const");
		NAME_SPACE::map<int, char>	map;

		LOGI(map.equal_range(0).first->first);
		LOGI(map.equal_range(0).second->first);

		map.insert(NAME_SPACE::make_pair(1, 'a'));
		LOGI(map.equal_range(0).first->first);
		LOGI(map.equal_range(0).second->first);
		LOGI(map.equal_range(1).first->first);
		LOGI(map.equal_range(1).second->first);
		LOGI(map.equal_range(1).first->second);
		LOGI(map.equal_range(1).second->second);

		map.insert(NAME_SPACE::make_pair(2, 'b'));
		map.insert(NAME_SPACE::make_pair(3, 'c'));
		map.insert(NAME_SPACE::make_pair(4, 'd'));
		map.insert(NAME_SPACE::make_pair(5, 'e'));
		LOGI(map.equal_range(3).first->second);
		LOGI(map.equal_range(3).second->second);
	}
}

void	map_lower_bound( void )
{
	{
		LOGN("const");
		const NAME_SPACE::map<int, char>	map;

		LOGI(map.lower_bound(0)->first);
	}
	{
		LOGN("non-const");
		NAME_SPACE::map<int, char>	map;

		LOGI(map.lower_bound(0)->first);

		map.insert(NAME_SPACE::make_pair(1, 'a'));
		LOGI(map.lower_bound(0)->first);
		LOGI(map.lower_bound(1)->first);
		LOGI(map.lower_bound(1)->first);
		LOGI(map.lower_bound(1)->second);

		map.insert(NAME_SPACE::make_pair(2, 'b'));
		map.insert(NAME_SPACE::make_pair(3, 'c'));
		map.insert(NAME_SPACE::make_pair(4, 'd'));
		map.insert(NAME_SPACE::make_pair(5, 'e'));
		LOGI(map.lower_bound(3)->first);
		LOGI(map.lower_bound(3)->second);
	}
}

void	map_upper_bound( void )
{
	{
		LOGN("const");
		const NAME_SPACE::map<int, char>	map;

		LOGI(map.upper_bound(0)->first);
	}
	{
		LOGN("non-const");
		NAME_SPACE::map<int, char>	map;

		LOGI(map.upper_bound(0)->first);

		map.insert(NAME_SPACE::make_pair(1, 'a'));
		LOGI(map.upper_bound(0)->first);
		LOGI(map.upper_bound(1)->first);
		LOGI(map.upper_bound(1)->first);
		LOGI(map.upper_bound(1)->second);

		map.insert(NAME_SPACE::make_pair(2, 'b'));
		map.insert(NAME_SPACE::make_pair(3, 'c'));
		map.insert(NAME_SPACE::make_pair(4, 'd'));
		map.insert(NAME_SPACE::make_pair(5, 'e'));
		LOGI(map.upper_bound(3)->first);
		LOGI(map.upper_bound(3)->second);
	}
}

void	map_key_comp( void )
{
	NAME_SPACE::map<int, char>	map;
	NAME_SPACE::map<int, char>	map2(map.key_comp(), map.get_allocator());
	map_print(map);
}

void	map_value_comp( void )
{
	//	wat??
}

void	map_comparison_operators( int overload )
{
	if (overload == 1)
	{
		{
			const NAME_SPACE::map<int, char>	map;
			const NAME_SPACE::map<int, char>	map2;

			LOGI((map == map2));
			LOGI((map2 == map));
		}
		{
			NAME_SPACE::map<int, char>	map;
			NAME_SPACE::map<int, char>	map2;

			LOGI((map == map2));
			LOGI((map2 == map));

			map.insert(NAME_SPACE::make_pair(1, 'a'));
			LOGI((map == map2));
			LOGI((map2 == map));

			map2.insert(NAME_SPACE::make_pair(2, 'b'));
			LOGI((map == map2));
			LOGI((map2 == map));

			map2.insert(NAME_SPACE::make_pair(3, 'c'));
			LOGI((map == map2));
			LOGI((map2 == map));

			map.insert(NAME_SPACE::make_pair(2, 'b'));
			map.insert(NAME_SPACE::make_pair(3, 'c'));
			map2.insert(NAME_SPACE::make_pair(1, 'a'));
			LOGI((map == map2));
			LOGI((map2 == map));
		}
	}
	else if (overload == 3)
	{
		{
			const NAME_SPACE::map<int, char>	map;
			const NAME_SPACE::map<int, char>	map2;

			LOGI((map < map2));
			LOGI((map2 < map));
		}
		{
			NAME_SPACE::map<int, char>	map;
			NAME_SPACE::map<int, char>	map2;

			LOGI((map < map2));
			LOGI((map2 < map));

			map.insert(NAME_SPACE::make_pair(1, 'a'));
			LOGI((map < map2));
			LOGI((map2 < map));

			map2.insert(NAME_SPACE::make_pair(2, 'b'));
			LOGI((map < map2));
			LOGI((map2 < map));

			map2.insert(NAME_SPACE::make_pair(3, 'c'));
			LOGI((map < map2));
			LOGI((map2 < map));

			map.insert(NAME_SPACE::make_pair(2, 'b'));
			map.insert(NAME_SPACE::make_pair(3, 'c'));
			map2.insert(NAME_SPACE::make_pair(1, 'a'));
			LOGI((map < map2));
			LOGI((map2 < map));
		}
	}
}

void	map_swap_non_member( void )
{
	NAME_SPACE::map<int, char>	map;
	NAME_SPACE::map<int, char>	map2;

	swap(map, map2);

	map.insert(NAME_SPACE::make_pair(1, 'a'));
	map.insert(NAME_SPACE::make_pair(2, 'b'));
	map_print(map);
	map_print(map2);

	swap(map, map2);
	map_print(map);
	map_print(map2);
}
