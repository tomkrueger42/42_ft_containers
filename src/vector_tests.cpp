#include "vector.hpp"
#include <vector>

#define LOG(msg) std::cout << msg
#define LOGN(msg) std::cout << msg << std::endl;
#define LOGI(...) std::cout << #__VA_ARGS__ << ": " << __VA_ARGS__ << std::endl;

template<typename T>
void	printVector(const T& vec)
{
	for (typename T::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		LOGI(*it);
	}
	LOGI(vec.size());
	LOGI(vec.capacity());
	LOGI(vec.data());
	std::cout << "-------------------------" << std::endl;
}

void	constructor_test()
{
	std::vector<int>	vec1;
	printVector(vec1);
	
	std::vector<int>	vec2(vec1.get_allocator());
	printVector(vec2);

	std::vector<int>	vec3(5, 6);
	printVector(vec3);

	std::vector<int>	vec5(vec3.begin(), vec3.end());
	printVector(vec5);

	std::vector<int>	vec6(vec5);
	printVector(vec6);
}

void	operator_assign_test()
{
	std::vector<int>	vec(3, 4);
	vec.reserve(15);
	std::vector<int>	vec2(7,8);
	printVector(vec2);
	vec2 = vec;
	vec.push_back(5);
	printVector(vec2);
	std::vector<int>	vec3;
	vec2 = vec3;
	printVector(vec2);
	vec2.push_back(7);
	vec2.push_back(7);
	vec2.push_back(7);
	printVector(vec2);
	vec2.push_back(7);
	printVector(vec2);
}

void	assign_test(int overload)
{
	if (overload == 1)
	{
		std::vector<int>	vec;
		vec.assign(3, 4);
		printVector(vec);
		vec.assign(5, 5);
		printVector(vec);
		vec.assign(2, 42);
		printVector(vec);
		vec.assign(vec.max_size() / 100000000000, 42);
	}
	else if (overload == 2)
	{
		ft::vector<int>	vec;
		for (size_t i = 0; i < 10; i++)
			vec.push_back(i);
		ft::vector<int>	vec2;
		
		vec2.assign(vec.begin(), vec.end());
		printVector(vec2);
		
		vec2.assign(vec.begin(), vec.begin());
		printVector(vec2);
		
		vec2.assign(vec.end(), vec.end());
		printVector(vec2);

		vec2.assign(vec.end(), vec.begin());
		printVector(vec2);
	}
}

void	get_allocator_test()
{
	ft::vector<int>	vec;
	ft::vector<int>	vec2(vec.get_allocator());
	vec2.assign(2, 3);
	printVector(vec2);
}

void	at_test()
{
	{
		ft::vector<int>	vec;
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
		const ft::vector<int>	vec;
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
		const ft::vector<int>	vec(3, 7);
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

void	operator_bracket_test()
{
	{
		ft::vector<int>	vec;
		vec.push_back(1);
		vec.push_back(2);
		LOGI(vec[0]);
		LOGI(vec[1]);
	}
	{
		const ft::vector<int>	vec(2, 3);
		LOGI(vec[0]);
		LOGI(vec[1]);
	}
}

void	front_back_test()
{
	ft::vector<int>	vec;
	vec.push_back(1);
	vec.push_back(2);
	LOGI(vec.front());
	LOGI(vec.back());
	const ft::vector<int>	vec2(2, 4);
	LOGI(vec2.front());
	LOGI(vec2.back());
}

void	data_test()		//	ft::vector does not create container-overflow like STL
{
	ft::vector<int>	vec;
	LOGI(vec.data());
	vec.reserve(2);
	LOGI(vec.data());
	int * ptr = vec.data();
	ptr[0] = 42;
	ptr[1] = 24;
	printVector(vec);
}

void	iterator_test()
{
	//	Member-functions

	ft::vector<int>::iterator	it;
	LOGI(it.base());

	ft::vector<int>	vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	ft::vector<int>::iterator	it2(vec.begin());
	ft::vector<int>::iterator	it3(vec.end() - 1);
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

void	reverse_iterator_test()
{
	ft::vector<ft::vector<int>::iterator>::reverse_iterator	rit;
	// LOGI(rit.base());

	ft::vector<int>	vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	ft::vector<ft::vector<int>::iterator>::reverse_iterator	rit2(vec.rbegin());
	// ft::vector<ft::vector<int>::iterator>::reverse_iterator	rit3(vec.rend());
}

void	empty_test()
{
	std::vector<int>	vec;
	LOGI(vec.empty());
	vec.push_back(1);
	LOGI(vec.empty());
}

void	size_test()
{
	ft::vector<int>	vec;
	LOGI(vec.size());
	vec.assign(2, 3);
	LOGI(vec.size());
}

void	max_size_test()
{
	ft::vector<int>	vec;
	LOGI(vec.max_size());
}

void	reserve_test()
{
	ft::vector<int>	vec;
	vec.reserve(3);
	printVector(vec);
	vec.assign(4, 5);
	printVector(vec);
	vec.reserve(2);
	printVector(vec);
	vec.reserve(7);
	printVector(vec);
	vec.reserve(-1);
	printVector(vec);
}

void	capacity_test()
{
	ft::vector<int> vec;
	LOGI(vec.capacity());
	vec.assign(2, 3);
	LOGI(vec.capacity());
}

void	clear_test()
{
	std::vector<int>	vec;
	vec.clear();
	printVector(vec);
	vec.assign(3, 4);
	printVector(vec);
	vec.clear();
	printVector(vec);
}

void	insert_test(int overload)
{
	if (overload == 1)
	{
		ft::vector<int>	vec;
		vec.insert(vec.begin(), 3);
		vec.insert(vec.end(), 5);
		printVector(vec);

		ft::vector<int> vec2;
		vec2.insert(vec2.end(), 3);
		vec2.insert(vec2.begin(), 5);
		vec2.insert(vec2.end() - 1, 4);
		printVector(vec2);
	}
	else if (overload == 3)
	{
		ft::vector<int>	vec;
		vec.insert(vec.begin(), 2, 27);
		vec.insert(vec.end(), 2, 29);
		LOGI(vec.insert(vec.begin() + 2, 2, 28).base());
		printVector(vec);
	}
	else if (overload == 4)
	{
		ft::vector<int>	vec(3, 4);
		ft::vector<int>	vec2;
		vec2.insert(vec2.begin(), vec.begin(), vec.end());
		
		ft::vector<int>	vec3(2, 7);
		vec2.insert(vec2.end(), vec3.begin(), vec3.end());
		printVector(vec2);
	}
}

void	erase_test(int overload)
{
	if (overload == 1)
	{
		ft::vector<int>	vec;
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		LOGI(vec.erase(vec.end() - 2).base());
		LOGI((vec.end()).base());
		LOGI(vec.begin().base());
		printVector(vec);
	}
	else if (overload == 2)
	{
		ft::vector<int>	vec;
		vec.push_back(5);
		vec.push_back(6);
		vec.push_back(7);
		vec.push_back(8);
		LOGI(vec.erase(vec.begin() + 1, vec.end() - 1).base());
		LOGI(vec.begin().base());
		LOGI(vec.end().base());
		printVector(vec);
	}
}

void	push_back_test()
{
	ft::vector<int>	vec;
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
	printVector(vec);
}

void	pop_back_test()
{
	ft::vector<int>	vec(2, 12);
	printVector(vec);
	vec.pop_back();
	printVector(vec);
	vec.pop_back();
	printVector(vec);
}

void	resize()
{
	std::vector<int>	vec;
	vec.resize(3, 7);
	printVector(vec);
	vec.resize(4, 8);
	printVector(vec);
	vec.resize(2, 9);
	printVector(vec);
	vec.resize(0, 10);
	printVector(vec);
	vec.resize(-2, 5);
	printVector(vec);
}

void	swap()
{
	ft::vector<int>	vec;
	ft::vector<int>	vec2;
	LOGI(vec.data() );
	LOGI(vec2.data());
	vec.swap(vec2);
	printVector(vec);
	printVector(vec2);

	vec.assign(3, 4);
	LOGI(vec.data() );
	LOGI(vec2.data());
	vec2.swap(vec);
	printVector(vec);
	printVector(vec2);

	vec.assign(5, 6);
	LOGI(vec.data() );
	LOGI(vec2.data());
	vec2.swap(vec);
	printVector(vec);
	printVector(vec2);
}

void	operator_test()
{
	std::vector<int>	vec(1, 2);
	std::vector<int>	vec2(1, 3);
	LOGI((vec == vec2));
	LOGI((vec != vec2));
	LOGI((vec < vec2));
	LOGI((vec <= vec2));
	LOGI((vec > vec2));
	LOGI((vec >= vec2));
}

void	non_member_swap_test()
{
	std::vector<int>	vec;
	std::vector<int>	vec2;
	LOGI(vec.data() );
	LOGI(vec2.data());
	swap(vec, vec2);
	printVector(vec);
	printVector(vec2);

	vec.assign(3, 4);
	LOGI(vec.data() );
	LOGI(vec2.data());
	swap(vec2, vec);
	printVector(vec);
	printVector(vec2);

	vec.assign(5, 6);
	LOGI(vec.data() );
	LOGI(vec2.data());
	swap(vec2, vec);
	printVector(vec);
	printVector(vec2);
}
