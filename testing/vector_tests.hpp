#pragma once

#include <log.hpp>

#ifdef USING_STD
	#include <vector>
	#define NAME_SPACE std
#else
	#include "vector.hpp"
	#define NAME_SPACE ft
#endif


template<typename T>
void	vector_print(const T& vec)
{
	for (typename T::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		LOGI(*it);
	}
	LOGI(vec.size());
	LOGI(vec.capacity());
	LOGI(vec.data());
	LOGN("-------------------------");
}

void	vector_constructor()
{
	NAME_SPACE::vector<int>	vec1;
	vector_print(vec1);
	
	NAME_SPACE::vector<int>	vec2(vec1.get_allocator());
	vector_print(vec2);

	NAME_SPACE::vector<int>	vec3(5, 6);
	vector_print(vec3);

	NAME_SPACE::vector<int>	vec5(vec3.begin(), vec3.end());
	vector_print(vec5);

	NAME_SPACE::vector<int>	vec6(vec5);
	vector_print(vec6);
}

void	vector_operator_assign()
{
	NAME_SPACE::vector<int>	vec(3, 4);
	vec.reserve(15);
	NAME_SPACE::vector<int>	vec2(7,8);
	vector_print(vec2);
	vec2 = vec;
	vec.push_back(5);
	vector_print(vec2);
	NAME_SPACE::vector<int>	vec3;
	vec2 = vec3;
	vector_print(vec2);
	vec2.push_back(7);
	vec2.push_back(7);
	vec2.push_back(7);
	vector_print(vec2);
	vec2.push_back(7);
	vector_print(vec2);
}

void	vector_assign(int overload)
{
	if (overload == 1)
	{
		NAME_SPACE::vector<int>	vec;
		vec.assign(3, 4);
		vector_print(vec);
		vec.assign(5, 5);
		vector_print(vec);
		vec.assign(2, 42);
		vector_print(vec);
		vec.assign(vec.max_size() / 100000000000, 42);
	}
	else if (overload == 2)
	{
		NAME_SPACE::vector<int>	vec;
		for (size_t i = 0; i < 10; i++)
			vec.push_back(i);
		NAME_SPACE::vector<int>	vec2;
		
		vec2.assign(vec.begin(), vec.end());
		vector_print(vec2);
		
		vec2.assign(vec.begin(), vec.begin());
		vector_print(vec2);
		
		vec2.assign(vec.end(), vec.end());
		vector_print(vec2);

		vec2.assign(vec.end(), vec.begin());
		vector_print(vec2);
	}
}

void	vector_get_allocator()
{
	NAME_SPACE::vector<int>	vec;
	NAME_SPACE::vector<int>	vec2(vec.get_allocator());
	vec2.assign(2, 3);
	vector_print(vec2);
}

void	vector_at()
{
	{
		NAME_SPACE::vector<int>	vec;
		try {
			vec.at(0);
		} catch (std::exception &e) {
			LOGN(e.what());
		}
		try {
			vec.at(1);
		} catch (std::exception &e) {
			LOGN(e.what());
		}
		try {
			vec.at(-1);
		} catch (std::exception &e) {
			LOGN(e.what());
		}
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		try {
			for (size_t i = 0; i < 10; i++)
				LOGI(vec.at(i));
		} catch (std::exception &e) {
			LOGN(e.what());
		}
	}
	{
		const NAME_SPACE::vector<int>	vec;
		try {
			vec.at(0);
		} catch (std::exception &e) {
			LOGN(e.what());
		}
		try {
			vec.at(1);
		} catch (std::exception &e) {
			LOGN(e.what());
		}
		try {
			vec.at(-1);
		} catch (std::exception &e) {
			LOGN(e.what());
		}
		try {
			for (size_t i = 0; i < 10; i++)
				LOGI(vec.at(i));
		} catch (std::exception &e) {
			LOGN(e.what());
		}
	}
	{
		const NAME_SPACE::vector<int>	vec(3, 7);
		try {
			vec.at(0);
		} catch (std::exception &e) {
			LOGN(e.what());
		}
		try {
			vec.at(1);
		} catch (std::exception &e) {
			LOGN(e.what());
		}
		try {
			vec.at(-1);
		} catch (std::exception &e) {
			LOGN(e.what());
		}
		try {
			for (size_t i = 0; i < 10; i++)
				LOGI(vec.at(i));
		} catch (std::exception &e) {
			LOGN(e.what());
		}
	}
}

void	vector_operator_at()
{
	{
		NAME_SPACE::vector<int>	vec;
		vec.push_back(1);
		vec.push_back(2);
		LOGI(vec[0]);
		LOGI(vec[1]);
	}
	{
		const NAME_SPACE::vector<int>	vec(2, 3);
		LOGI(vec[0]);
		LOGI(vec[1]);
	}
}

void	vector_front_back()
{
	NAME_SPACE::vector<int>	vec;
	vec.push_back(1);
	vec.push_back(2);
	LOGI(vec.front());
	LOGI(vec.back());
	const NAME_SPACE::vector<int>	vec2(2, 4);
	LOGI(vec2.front());
	LOGI(vec2.back());
}

void	vector_data()		//	ft::vector does not create container-overflow like STL
{
	NAME_SPACE::vector<int>	vec;
	LOGI(vec.data());
	vec.reserve(2);
	LOGI(vec.data());
	int * ptr = vec.data();
	ptr[0] = 42;
	ptr[1] = 24;
	vector_print(vec);
}

void	vector_iterator()
{
	//	Member-functions

	NAME_SPACE::vector<int>::iterator	it;
	LOGI(it.base());

	NAME_SPACE::vector<int>	vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	NAME_SPACE::vector<int>::iterator	it2(vec.begin());
	NAME_SPACE::vector<int>::iterator	it3(vec.end() - 1);
	LOGI(vec.begin().base());
	LOGI(it2.base());
	LOGI(it3.base());
	LOGI(*vec.begin());
	LOGI(*it2);
	LOGI(*it3);

	// LOGI(it2->_current);
	// LOGI(it3->_current);

	LOGI(it2[3]);

	++it2;
	it2++;
	it2 += 1;
	LOGI(it2[0]);

	--it2;
	it2--;
	it2 -= 1;
	LOGI(*it2);

	LOGI(*(it2 + 2));
	LOGI(*(it3 - 2));

	//	Non-member functions

	LOGI((it2 == it3));
	LOGI((it2 != it3));
	LOGI((it2 < it3));
	LOGI((it2 <= it3));
	LOGI((it2 > it3));
	LOGI((it2 >= it3));
	LOGI(*(3 + it2));
	LOGI((it3 - it2));

	advance(it2, 2);
	LOGI(*it2);
	advance(it2, -2);
	LOGI(*it2);

	LOGI(distance(it2, it3));
	LOGI(distance(it3, it2));
}

void	vector_reverse_iterator()
{
	NAME_SPACE::vector<NAME_SPACE::vector<int>::iterator>::reverse_iterator	rit;
	// LOGI(rit.base());

	NAME_SPACE::vector<int>	vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	// NAME_SPACE::vector<NAME_SPACE::vector<int>::iterator>::reverse_iterator	rit2(vec.rbegin());
	// NAME_SPACE::vector<NAME_SPACE::vector<int>::iterator>::reverse_iterator	rit3(vec.rend());
}

void	vector_empty()
{
	NAME_SPACE::vector<int>	vec;
	LOGI(vec.empty());
	vec.push_back(1);
	LOGI(vec.empty());
}

void	vector_size()
{
	NAME_SPACE::vector<int>	vec;
	LOGI(vec.size());
	vec.assign(2, 3);
	LOGI(vec.size());
}

void	vector_max_size()
{
	NAME_SPACE::vector<int>	vec;
	LOGI(vec.max_size());
}

void	vector_reserve()
{
	NAME_SPACE::vector<int>	vec;
	vec.reserve(3);
	vector_print(vec);
	vec.assign(4, 5);
	vector_print(vec);
	vec.reserve(2);
	vector_print(vec);
	vec.reserve(7);
	vector_print(vec);
	vec.reserve(-1);
	vector_print(vec);
}

void	vector_capacity()
{
	NAME_SPACE::vector<int> vec;
	LOGI(vec.capacity());
	vec.assign(2, 3);
	LOGI(vec.capacity());
}

void	vector_clear()
{
	NAME_SPACE::vector<int>	vec;
	vec.clear();
	vector_print(vec);
	vec.assign(3, 4);
	vector_print(vec);
	vec.clear();
	vector_print(vec);
}

void	vector_insert(int overload)
{
	if (overload == 1)
	{
		NAME_SPACE::vector<int>	vec;
		vec.insert(vec.begin(), 3);
		vec.insert(vec.end(), 5);
		vector_print(vec);

		NAME_SPACE::vector<int> vec2;
		vec2.insert(vec2.end(), 3);
		vec2.insert(vec2.begin(), 5);
		vec2.insert(vec2.end() - 1, 4);
		vector_print(vec2);
	}
	else if (overload == 3)
	{
		NAME_SPACE::vector<int>	vec;
		vec.insert(vec.begin(), 2, 27);
		vec.insert(vec.end(), 2, 29);
		LOGI(vec.insert(vec.begin() + 2, 2, 28).base());
		vector_print(vec);
	}
	else if (overload == 4)
	{
		NAME_SPACE::vector<int>	vec(3, 4);
		NAME_SPACE::vector<int>	vec2;
		vec2.insert(vec2.begin(), vec.begin(), vec.end());
		
		NAME_SPACE::vector<int>	vec3(2, 7);
		vec2.insert(vec2.end(), vec3.begin(), vec3.end());
		vector_print(vec2);
	}
}

void	vector_erase(int overload)
{
	if (overload == 1)
	{
		NAME_SPACE::vector<int>	vec;
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		LOGI(vec.erase(vec.end() - 2).base());
		LOGI((vec.end()).base());
		LOGI(vec.begin().base());
		vector_print(vec);
	}
	else if (overload == 2)
	{
		NAME_SPACE::vector<int>	vec;
		vec.push_back(5);
		vec.push_back(6);
		vec.push_back(7);
		vec.push_back(8);
		LOGI(vec.erase(vec.begin() + 1, vec.end() - 1).base());
		LOGI(vec.begin().base());
		LOGI(vec.end().base());
		vector_print(vec);
	}
}

void	vector_push_back()
{
	NAME_SPACE::vector<int>	vec;
	vec.push_back(2);
	LOGI(vec.size());
	LOGI(vec.capacity());
	vec.push_back(3);
	LOGI(vec.size());
	LOGI(vec.capacity());
	vec.push_back(4);
	LOGI(vec.size());
	LOGI(vec.capacity());
	vec.push_back(5);
	vector_print(vec);
}

void	vector_pop_back()
{
	NAME_SPACE::vector<int>	vec(2, 12);
	vector_print(vec);
	vec.pop_back();
	vector_print(vec);
	vec.pop_back();
	vector_print(vec);
}

void	vector_resize()
{
	NAME_SPACE::vector<int>	vec;
	vec.resize(3, 7);
	vector_print(vec);
	vec.resize(4, 8);
	vector_print(vec);
	vec.resize(2, 9);
	vector_print(vec);
	vec.resize(0, 10);
	vector_print(vec);
	vec.resize(-2, 5);
	vector_print(vec);
}

void	vector_swap()
{
	NAME_SPACE::vector<int>	vec;
	NAME_SPACE::vector<int>	vec2;
	LOGI(vec.data() );
	LOGI(vec2.data());
	vec.swap(vec2);
	vector_print(vec);
	vector_print(vec2);

	vec.assign(3, 4);
	LOGI(vec.data() );
	LOGI(vec2.data());
	vec2.swap(vec);
	vector_print(vec);
	vector_print(vec2);

	vec.assign(5, 6);
	LOGI(vec.data() );
	LOGI(vec2.data());
	vec2.swap(vec);
	vector_print(vec);
	vector_print(vec2);
}

void	vector_operator()
{
	NAME_SPACE::vector<int>	vec(1, 2);
	NAME_SPACE::vector<int>	vec2(1, 3);
	LOGI((vec == vec2));
	LOGI((vec != vec2));
	LOGI((vec < vec2));
	LOGI((vec <= vec2));
	LOGI((vec > vec2));
	LOGI((vec >= vec2));
}

void	vector_non_member_swap()
{
	NAME_SPACE::vector<int>	vec;
	NAME_SPACE::vector<int>	vec2;
	LOGI(vec.data() );
	LOGI(vec2.data());
	swap(vec, vec2);
	vector_print(vec);
	vector_print(vec2);

	vec.assign(3, 4);
	LOGI(vec.data() );
	LOGI(vec2.data());
	swap(vec2, vec);
	vector_print(vec);
	vector_print(vec2);

	vec.assign(5, 6);
	LOGI(vec.data() );
	LOGI(vec2.data());
	swap(vec2, vec);
	vector_print(vec);
	vector_print(vec2);
}
