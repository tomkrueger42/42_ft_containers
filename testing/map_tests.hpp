#pragma once

#include <log.hpp>

#include "map.hpp"
#include <map>

#ifdef USING_STD
	#define NAMESPACE std
#else
	#define NAMESPACE ft
#endif

template <typename T>
void init_array_int_str(NAMESPACE::pair<int, std::string>* arr, std::size_t size)
{
    std::string x[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
                          "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
                          "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
                          "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
                          "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
                          "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
                          "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
                          "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
                          "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
                          "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
                          "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
                          "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
                          "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
                          "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
                          "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
                          "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
                          "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
                          "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
                          "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
                          "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
                          "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
                          "1IRLC9sfQI5AzDYeotLd" };

    for (std::size_t i = 0; i < size; ++i) {
        arr[i] = NAMESPACE::make_pair(rand(), x[i]);
    }
}

template <typename T>
void init_array_str_str(NAMESPACE::pair<std::string, std::string>* arr, std::size_t size)
{
    std::string x[32] = { "RxWAUMME3GtF9Zbv3a4M", "WC96vs7Z6I6TfdGxObUg", "2beuhrfBZvjdkmfqV9yn",
                          "AuIhF3lUgwT0OMy8DuUx", "dVW2KAL06gB4s7rEf508", "jnsp7MGfl5wZNZVfQSvp",
                          "p26Kfhz0Iof6rJDy27vc", "bnWXfp2eexq7MPpcmRSI", "tMEU0L6RNvqDAaV6HN0e",
                          "POcbaPteUMFfltrwdu7r", "epDGhJZoKoL4i1HO67XS", "o83N1RTIeOafqBfqeAYh",
                          "aYRtwuDT8k7k7iIfTrtU", "fEPXIREoFGKXqnNKySG5", "QrqmIbVVIQzf8WKBxiga",
                          "k5NSg0Dq0b9ewfrhYdy7", "Tf9dsqBADfMeWVQGG3Zk", "dS2LouElpUXsXNCClr4B",
                          "tsvf3JaWNg5JlSDZs1Dm", "oWurB8fBAIBQq1ZnlFiR", "8YllXP80XunEXhqnjkZc",
                          "Spt36tVcEkIFjwogWli0", "c25H1u6DF9RVdagn81DA", "AjWfT7TlXgzSKOywpoTH",
                          "ZwTg8WNnmXOJKdW6ZeJv", "E9aYpoCXd1kbSWhdLOnf", "QN1iAuoSNQ5WvHeSeSSL",
                          "7g5wfNllowIaqMUVjywr", "b38gJrosdk9xEQ2K8Gbu", "KdVdRVLHJg9Bazc4cpM7",
                          "COJeGmQEzjXwqKCAnd6J", "2k6XCpXEkP7QoST6uYoy" };

    std::string y[32] = { "TZ3QuE3ZNUbFrEpQhgcY", "BX2lyPzOWRIznb34T5OT", "v7lPrSeDokdBIUXR9QGh",
                          "nAQxkuEYL5k1Er7FspKu", "r8T4oZaWBI1m7sPBEDz3", "pdxM9tJrYZskZla7L7yM",
                          "dIIx6eKTfygu24SNKa32", "tw04BOo705mdWxuDciNO", "q94icFprhKrrFXLvjEN3",
                          "uM25BWUl14NTlTwFsNIv", "2oTV9fXUESLQqzvsPFmd", "W6ASLRzrlOggx5b7CtYN",
                          "bz4BQ7rLU203RNwwmbMK", "jfWgRPiuy1P3NGDPWmbe", "PgtdYLdGuneYEUgMA8SB",
                          "eaaFugCSOOU5my4y4SkG", "gGd4FiUEJwgvhOCSHu9g", "9K0ZhqlbyDCJXYXHoEIN",
                          "VTmk8m7rbEGl8ntGpTCQ", "eRJ98PUF2tSMX6zpDOi4", "wFMJIDAbjYnJkxMxkAtL",
                          "JCOXV4iPcIt72DcNnbuY", "LsnOUrHHD2FNFH5DMvbc", "YVPp2jPqK3jmif7yY14r",
                          "JBMhRRtLY3QX3x1ZVDCs", "Uwo5PD2RLMx5ByW9Rscq", "O4Q6DPBJHOelMtBKc9GQ",
                          "Bq0H2eqnuCYqyj9F5Lkn", "P2fJf0TYN92iUXkwELjG", "f656ltXlumpc7YyPVjan",
                          "YQfr76LAA1xKokfq8HpL", "6utvLeZ9t0IM4OkdfAQ2" };

    for (std::size_t i = 0; i < size; ++i) {
        arr[i] = NAMESPACE::make_pair(x[i], y[i]);
    }
}

#define SETUP_ARRAYS()                                                                             \
    NAMESPACE::pair<int, std::string> intstr_arr[64];                                              \
    init_array_int_str<void>(intstr_arr, 64);                                                      \
    NAMESPACE::pair<std::string, std::string> strstr_arr[32];                                      \
    init_array_str_str<void>(strstr_arr, 32);                                                      \
    std::size_t intstr_size = 64;                                                                  \
    std::size_t strstr_size = 32;                                                                  \
    (void)intstr_arr;                                                                              \
    (void)strstr_arr;                                                                              \
    (void)intstr_size;                                                                             \

template< typename T >
void	map_print( const T& map )
{
	LOGN1("map_tests: map_print()");
	for (typename T::const_iterator it = map.begin(); it != map.end(); it++)
	{
		LOG(it->first);
		LOG(": ");
		LOGN(it->second);
	}
	LOGI(map.size());
	LOGI((map.begin() == map.end()));
	LOGN("-------------------------");
}

void	map_constructor( void )
{
	NAMESPACE::map<int, char>	map;
	map_print(map);

	NAMESPACE::map<int, char>	map2(map.key_comp(), map.get_allocator());
	map_print(map2);

	// NAMESPACE::map<int, char>	map2(map.get_allocator());							//	weird, because this works with STL but shouldn't as in the documentation
	// map_print(map2);

	 
}

template <typename It>
void print_map(It first, It last)
{
    for (; first != last; ++first) {
        std::cout << "K: " << first->first << " V: " << first->second << " ";
    }
    std::cout << std::endl;
}

void	map_operator_assign( void )
{
	SETUP_ARRAYS();

	{
		NAMESPACE::map<int, std::string>	m1;
		NAMESPACE::map<int, std::string>	m2;

		m1 = m2;

		print_map(m1.begin(), m1.end());
		LOGI(m1.size());

		m2 = NAMESPACE::map<int, std::string>(intstr_arr, intstr_arr + intstr_size);

        print_map(m2.begin(), m2.end());
		LOGI(m2.size());

        m1 = m2;

        print_map(m1.begin(), m1.end());
		LOGI(m1.size());

        m1 = NAMESPACE::map<int, std::string>(intstr_arr, intstr_arr + 10);

        print_map(m1.begin(), m1.end());
		LOGI(m1.size());

        m2 = m1;

        print_map(m2.begin(), m2.end());
		LOGI(m2.size());
    }

    {
        NAMESPACE::map<std::string, std::string> m1;
        NAMESPACE::map<std::string, std::string> m2;

        m1 = m2;

        print_map(m1.begin(), m1.end());
		LOGI(m1.size());

        m2 = NAMESPACE::map<std::string, std::string>(strstr_arr, strstr_arr + strstr_size);

        print_map(m2.begin(), m2.end());
		LOGI(m2.size());

        m1 = m2;

        print_map(m1.begin(), m1.end());
		LOGI(m1.size());

        m1 = NAMESPACE::map<std::string, std::string>(strstr_arr, strstr_arr + 10);

        print_map(m1.begin(), m1.end());
		LOGI(m1.size());

        m2 = m1;

        print_map(m2.begin(), m2.end());
		LOGI(m2.size());
    }
}

void	map_get_allocator( void )
{
	NAMESPACE::map<int, char>	map;
	NAMESPACE::map<int, char>	map2(map.key_comp(), map.get_allocator());
	map_print(map2);
}

void	map_at( void )
{
	NAMESPACE::map<int, char>	map;
	try
	{
		map.at(0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		map.at(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	map.insert(NAMESPACE::make_pair(1, 'a'));
	try
	{
		map.at(0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		LOGN(map.at(1));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	map_operator_at( void )
{
	NAMESPACE::map<int, char>	map;
	LOGI(map[0]);
	
	map.insert(NAMESPACE::make_pair(1, 'a'));
	LOGI(map[1]);
	LOGI(map[2]);
	map_print(map);

	map.insert(NAMESPACE::make_pair(2, 'b'));
	LOGI(map[1]);
	LOGI(map[2]);
	map_print(map);
}

void	map_iterator( void )
{
	NAMESPACE::map<int, char>	map;
	LOGI((map.begin() == map.end()));
	LOGI((map.begin() != map.end()));

	NAMESPACE::map<int, char>::iterator it_empty;
	LOGI((it_empty == map.begin()));

	map.insert(NAMESPACE::make_pair(1, 'a'));
	for (NAMESPACE::map<int, char>::iterator it = map.begin(); it != map.end(); it++)
		LOGI(it->first);
	map.insert(NAMESPACE::make_pair(2, 'b'));
	NAMESPACE::map<int, char>::iterator	it = map.begin();
	LOGI(it->first);
	++it;
	LOGI(it->first);
	--it;
	LOGI(it->first);
	it++;
	LOGI(it->first);
	it--;
	LOGI(it->first);
	it = map.end();
	it--;
	LOGI(it->first);
	map_print(map);
	it->second = 'z';
	map_print(map);

	map.erase(1);
	it = map.end();
	--it;
	LOGI(it->first);
}

void	map_reverse_iterator( void )
{
	NAMESPACE::map<int, char>	map;
	LOGI((map.rbegin() == map.rend()));
	LOGI((map.rbegin() != map.rend()));

	map.insert(NAMESPACE::make_pair(1, 'a'));
	for (NAMESPACE::map<int, char>::reverse_iterator it = map.rbegin(); it != map.rend(); it++)
		LOGI(it->first);
	map.insert(NAMESPACE::make_pair(2, 'b'));
	NAMESPACE::map<int, char>::reverse_iterator	it = map.rbegin();
	LOGI(it->first);
	++it;
	LOGI(it->first);
	--it;
	LOGI(it->first);
	it++;
	LOGI(it->first);
	it--;
	LOGI(it->first);
	it = map.rend();
	it--;
	LOGI(it->first);
	map_print(map);
	it->second = 'z';
	map_print(map);

	map.erase(1);
	it = map.rend();
	--it;
	LOGI(it->first);
}

void	map_empty( void )
{
	NAMESPACE::map<int, char>	map;
	LOGI(map.empty());
	map.insert(NAMESPACE::make_pair(1, 'a'));
	LOGI(map.empty());
	map.erase(1);
	LOGI(map.empty());
}

void	map_size( void )
{
	NAMESPACE::map<int, char>	map;
	LOGI(map.size());
	map.insert(NAMESPACE::make_pair(1, 'a'));
	LOGI(map.size());
	map.erase(1);
	LOGI(map.size());

	NAMESPACE::map<int, char> map2;
	NAMESPACE::map<int, char> map3;
	map2 = map3;
	LOGI(map2.size());
}

void	map_max_size( void )
{
	NAMESPACE::map<int, char>	map;
	LOGI(map.max_size());
}

void	map_clear( void )
{
	NAMESPACE::map<int, char>	map;
	map_print(map);
	map.clear();
	map_print(map);
	map.insert(NAMESPACE::make_pair(1, 'a'));
	map_print(map);
	map.clear();
	map_print(map);
	map.insert(NAMESPACE::make_pair(1, 'a'));
	map.insert(NAMESPACE::make_pair(2, 'b'));
	map.insert(NAMESPACE::make_pair(3, 'c'));
	map.insert(NAMESPACE::make_pair(4, 'd'));
	map.insert(NAMESPACE::make_pair(5, 'e'));
	map_print(map);
	map.clear();
	map_print(map);
}

void	map_insert( int overload )
{
	if (overload == 1)
	{
		NAMESPACE::map<int, char>	map;
		map_print(map);
		map.insert(NAMESPACE::make_pair(5, 'e'));
		map_print(map);
		map.insert(NAMESPACE::make_pair(5, 'e'));
		map_print(map);
		map.insert(NAMESPACE::make_pair(2, 'b'));
		map_print(map);
		map.insert(NAMESPACE::make_pair(7, 'g'));
		map_print(map);
		map.insert(NAMESPACE::make_pair(3, 'c'));
		map_print(map);
		map.insert(NAMESPACE::make_pair(7, 'g'));
		map_print(map);
		map.insert(NAMESPACE::make_pair(6, 'f'));
		map_print(map);
		map.insert(NAMESPACE::make_pair(1, 'a'));
		map_print(map);
		map.insert(NAMESPACE::make_pair(8, 'h'));
		map_print(map);
		map.insert(NAMESPACE::make_pair(9, 'i'));
		map.insert(NAMESPACE::make_pair(10, 'j'));
		map.insert(NAMESPACE::make_pair(11, 'k'));
		map.insert(NAMESPACE::make_pair(12, 'l'));
		map.insert(NAMESPACE::make_pair(13, 'm'));
		map.insert(NAMESPACE::make_pair(14, 'n'));
		map.insert(NAMESPACE::make_pair(15, 'o'));
		map.insert(NAMESPACE::make_pair(16, 'p'));
		map.insert(NAMESPACE::make_pair(17, 'q'));
		map.insert(NAMESPACE::make_pair(18, 'r'));
		map.insert(NAMESPACE::make_pair(19, 's'));
		map_print(map);
	}
	else if (overload == 2)
	{
		{
			LOGN("always map.begin()");
			NAMESPACE::map<int, char>	map;
			map_print(map);
			map.insert(map.begin(), NAMESPACE::make_pair(5, 'e'));
			map_print(map);
			map.insert(map.begin(), NAMESPACE::make_pair(5, 'e'));
			map_print(map);
			map.insert(map.begin(), NAMESPACE::make_pair(2, 'b'));
			map_print(map);
			map.insert(map.begin(), NAMESPACE::make_pair(7, 'g'));
			map_print(map);
			map.insert(map.begin(), NAMESPACE::make_pair(3, 'c'));
			map_print(map);
			map.insert(map.begin(), NAMESPACE::make_pair(7, 'g'));
			map_print(map);
			map.insert(map.begin(), NAMESPACE::make_pair(6, 'f'));
			map_print(map);
			map.insert(map.begin(), NAMESPACE::make_pair(1, 'a'));
			map_print(map);
			map.insert(map.begin(), NAMESPACE::make_pair(8, 'h'));
			map_print(map);
			LOGN("--------------------------------------");
		}
		{
			LOGN("always map.end()");
			NAMESPACE::map<int, char>	map;
			map_print(map);
			map.insert(map.end(), NAMESPACE::make_pair(5, 'e'));
			map_print(map);
			map.insert(map.end(), NAMESPACE::make_pair(5, 'e'));
			map_print(map);
			map.insert(map.end(), NAMESPACE::make_pair(2, 'b'));
			map_print(map);
			map.insert(map.end(), NAMESPACE::make_pair(7, 'g'));
			map_print(map);
			map.insert(map.end(), NAMESPACE::make_pair(3, 'c'));
			map_print(map);
			map.insert(map.end(), NAMESPACE::make_pair(7, 'g'));
			map_print(map);
			map.insert(map.end(), NAMESPACE::make_pair(6, 'f'));
			map_print(map);
			map.insert(map.end(), NAMESPACE::make_pair(1, 'a'));
			map_print(map);
			map.insert(map.end(), NAMESPACE::make_pair(8, 'h'));
			map_print(map);
			LOGN("--------------------------------------");
		}
		{
			LOGN("mixed map.begin() and map.end()");
			NAMESPACE::map<int, char>	map;
			map_print(map);
			map.insert(map.begin(), NAMESPACE::make_pair(5, 'e'));
			map_print(map);
			map.insert(map.end(), NAMESPACE::make_pair(5, 'e'));
			map_print(map);
			map.insert(map.begin(), NAMESPACE::make_pair(2, 'b'));
			map_print(map);
			map.insert(map.end(), NAMESPACE::make_pair(7, 'g'));
			map_print(map);
			map.insert(map.begin(), NAMESPACE::make_pair(3, 'c'));
			map_print(map);
			map.insert(map.end(), NAMESPACE::make_pair(7, 'g'));
			map_print(map);
			map.insert(map.begin(), NAMESPACE::make_pair(6, 'f'));
			map_print(map);
			map.insert(map.end(), NAMESPACE::make_pair(1, 'a'));
			map_print(map);
			map.insert(map.begin(), NAMESPACE::make_pair(8, 'h'));
			map_print(map);
		}
	}
	else if (overload == 3)
	{
		NAMESPACE::map<int, char>	map;
		NAMESPACE::map<int, char>	map2;
		map2.insert(map.begin(), map.end());
		map_print(map2);
		map.insert(map2.begin(), map2.begin());
		map_print(map);
		map2.insert(map.end(), map.end());
		map_print(map2);
		map_print(map2);
		map.insert(map.begin(), map.end());
		map_print(map);
		map.insert(map.begin(), map.begin());
		map_print(map);
		map.insert(map.end(), map.end());
		map_print(map);
		map_print(map);

		map.insert(NAMESPACE::make_pair(5, 'e'));
		map.insert(NAMESPACE::make_pair(5, 'e'));
		map.insert(NAMESPACE::make_pair(2, 'b'));
		map.insert(NAMESPACE::make_pair(7, 'g'));
		map.insert(NAMESPACE::make_pair(3, 'c'));
		map.insert(NAMESPACE::make_pair(7, 'g'));
		map.insert(NAMESPACE::make_pair(6, 'f'));
		map.insert(NAMESPACE::make_pair(1, 'a'));
		map.insert(NAMESPACE::make_pair(8, 'h'));
		map_print(map);

		map2.insert(map.begin(), map.begin());
		map_print(map2);
		map2.insert(map.end(), map.end());
		map_print(map2);
		map_print(map2);
		map2.insert(map.begin(), map.end());
		map_print(map);
	}
}

void	map_erase( int overload )
{
	if (overload == 1)
	{
		NAMESPACE::map<int, char>	map;

		// map.insert(NAMESPACE::make_pair(5, 'e'));
		// LOGI((map.begin() == map.end()));
		// map.erase(map.begin());
		// LOGI((map.begin() == map.end()));

		map.insert(NAMESPACE::make_pair(5, 'e'));
		map.insert(NAMESPACE::make_pair(6, 'f'));
		map.insert(NAMESPACE::make_pair(7, 'g'));

		map.erase(map.insert(NAMESPACE::make_pair(6, 'f')).first);
		map.erase(map.insert(NAMESPACE::make_pair(6, 'f')).first);
		map.erase(map.insert(NAMESPACE::make_pair(5, 'f')).first);
		map.erase(map.insert(NAMESPACE::make_pair(7, 'f')).first);
		map_print(map);
	}
	else if (overload == 2)
	{
		NAMESPACE::map<int, char>	map;
		map.erase(map.begin(), map.begin());
		map.erase(map.end(), map.end());
		map.erase(map.end(), map.begin());
		map.erase(map.begin(), map.end());

		map_print(map);

		map.insert(NAMESPACE::make_pair(5, 'e'));
		map.insert(NAMESPACE::make_pair(6, 'f'));
		map.insert(NAMESPACE::make_pair(7, 'g'));

		map_print(map);

		// map.erase(map.begin(), map.begin());
		// map.erase(map.end(), map.end());
		// map.erase(map.end(), map.begin());
		map.erase(map.begin(), map.end());

		// map_print(map);
	}
	else if (overload == 3)
	{
		NAMESPACE::map<int, char>	map;
		LOGI(map.erase(0));
		LOGI(map.erase(1));

		map.insert(NAMESPACE::make_pair(5, 'e'));
		LOGI(map.erase(0));
		LOGI((map.begin() == map.end()));
		LOGI(map.erase(5));
		LOGI((map.begin() == map.end()));
		LOGI(map.erase(5));

		map.insert(NAMESPACE::make_pair(5, 'e'));
		map.insert(NAMESPACE::make_pair(6, 'f'));
		map.insert(NAMESPACE::make_pair(7, 'g'));

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
	NAMESPACE::map<int, char>	map;
	NAMESPACE::map<int, char>	map2;

	map_print(map);
	map.swap(map2);
	map2.swap(map);
	map.swap(map);
	map_print(map);
	map.insert(NAMESPACE::make_pair(1, 'a'));
	map.insert(NAMESPACE::make_pair(2, 'b'));
	map.insert(NAMESPACE::make_pair(3, 'c'));
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
	NAMESPACE::map<int, char>	map;

	LOGI(map.count(0));
	LOGI(map.count(1));

	map.insert(NAMESPACE::make_pair(2, 'b'));
	LOGI(map.count(0));
	LOGI(map.count(2));
}

void	map_find( void )
{
	{
		NAMESPACE::map<int, char>	map;

		LOGI((map.find(0) == map.end()));

		map.insert(NAMESPACE::make_pair(2, 'b'));
		LOGI((map.find(0) == map.end()));
		LOGI(map.find(2)->first);
	}
	{
		const NAMESPACE::map<int, char>	map;

		LOGI((map.find(0) == map.end()));
	}
}

void	map_equal_range( void )
{
	{
		LOGN("const");
		const NAMESPACE::map<int, char>	map;

		LOGI((map.equal_range(0).first == map.end()));
		LOGI((map.equal_range(0).second == map.end()));
	}
	{
		LOGN("non-const");
		NAMESPACE::map<int, char>	map;

		LOGI((map.equal_range(0).first == map.end()));
		LOGI((map.equal_range(0).second == map.end()));

		map.insert(NAMESPACE::make_pair(1, 'a'));
		LOGI((map.equal_range(0).first == map.end()));
		LOGI((map.equal_range(0).second == map.end()));
		if (map.equal_range(1).first != map.end())
		LOGI(map.equal_range(1).first->first);
		if (map.equal_range(1).second != map.end())
			LOGI(map.equal_range(1).second->first);

		map.insert(NAMESPACE::make_pair(2, 'b'));
		map.insert(NAMESPACE::make_pair(3, 'c'));
		map.insert(NAMESPACE::make_pair(4, 'd'));
		map.insert(NAMESPACE::make_pair(5, 'e'));
		if (map.equal_range(1).first != map.end())
			LOGI(map.equal_range(3).first->first);
		if (map.equal_range(1).second != map.end())
			LOGI(map.equal_range(3).second->first);
	}
}

void	map_lower_bound( void )
{
	{
		LOGN("const");
		const NAMESPACE::map<int, char>	map;

		if (map.lower_bound(0) != map.end())
			LOGI(map.lower_bound(0)->first);
	}
	{
		LOGN("non-const");
		NAMESPACE::map<int, char>	map;

		if (map.lower_bound(0) != map.end())
			LOGI(map.lower_bound(0)->first);

		map.insert(NAMESPACE::make_pair(1, 'a'));
		if (map.lower_bound(0) != map.end())
			LOGI(map.lower_bound(0)->first);
		if (map.lower_bound(2) != map.end())
			LOGI(map.lower_bound(2)->first);

		map.insert(NAMESPACE::make_pair(2, 'b'));
		// map.insert(NAMESPACE::make_pair(3, 'c'));
		map.insert(NAMESPACE::make_pair(4, 'd'));
		map.insert(NAMESPACE::make_pair(5, 'e'));
		if (map.lower_bound(3) != map.end())
			LOGI(map.lower_bound(3)->first);
	}
}

void	map_upper_bound( void )
{
	{
		LOGN("const");
		const NAMESPACE::map<int, char>	map;

		if (map.upper_bound(0) != map.end())
			LOGI(map.upper_bound(0)->first);
	}
	{
		LOGN("non-const");
		NAMESPACE::map<int, char>	map;

		if (map.upper_bound(0) != map.end())
			LOGI(map.upper_bound(0)->first);

		map.insert(NAMESPACE::make_pair(1, 'a'));
		if (map.upper_bound(0) != map.end())
			LOGI(map.upper_bound(0)->first);
		if (map.upper_bound(1) != map.end())
			LOGI(map.upper_bound(1)->first);
		if (map.upper_bound(2) != map.end())
			LOGI(map.upper_bound(2)->first);

		map.insert(NAMESPACE::make_pair(2, 'b'));
		map.insert(NAMESPACE::make_pair(3, 'c'));
		map.insert(NAMESPACE::make_pair(4, 'd'));
		map.insert(NAMESPACE::make_pair(5, 'e'));
		if (map.upper_bound(3) != map.end())
			LOGI(map.upper_bound(3)->first);
	}
}

void	map_key_comp( void )
{
	NAMESPACE::map<int, char>	map;
	NAMESPACE::map<int, char>	map2(map.key_comp(), map.get_allocator());
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
			const NAMESPACE::map<int, char>	map;
			const NAMESPACE::map<int, char>	map2;

			LOGI((map == map2));
			LOGI((map2 == map));
		}
		{
			NAMESPACE::map<int, char>	map;
			NAMESPACE::map<int, char>	map2;

			LOGI((map == map2));
			LOGI((map2 == map));

			map.insert(NAMESPACE::make_pair(1, 'a'));
			LOGI((map == map2));
			LOGI((map2 == map));

			map2.insert(NAMESPACE::make_pair(2, 'b'));
			LOGI((map == map2));
			LOGI((map2 == map));

			map2.insert(NAMESPACE::make_pair(3, 'c'));
			LOGI((map == map2));
			LOGI((map2 == map));

			map.insert(NAMESPACE::make_pair(2, 'b'));
			map.insert(NAMESPACE::make_pair(3, 'c'));
			map2.insert(NAMESPACE::make_pair(1, 'a'));
			LOGI((map == map2));
			LOGI((map2 == map));
		}
	}
	else if (overload == 3)
	{
		{
			const NAMESPACE::map<int, char>	map;
			const NAMESPACE::map<int, char>	map2;

			LOGI((map < map2));
			LOGI((map2 < map));
		}
		{
			NAMESPACE::map<int, char>	map;
			NAMESPACE::map<int, char>	map2;

			LOGI((map < map2));
			LOGI((map2 < map));

			map.insert(NAMESPACE::make_pair(1, 'a'));
			LOGI((map < map2));
			LOGI((map2 < map));

			map2.insert(NAMESPACE::make_pair(2, 'b'));
			LOGI((map < map2));
			LOGI((map2 < map));

			map2.insert(NAMESPACE::make_pair(3, 'c'));
			LOGI((map < map2));
			LOGI((map2 < map));

			map.insert(NAMESPACE::make_pair(2, 'b'));
			map.insert(NAMESPACE::make_pair(3, 'c'));
			map2.insert(NAMESPACE::make_pair(1, 'a'));
			LOGI((map < map2));
			LOGI((map2 < map));
		}
	}
}

void	map_swap_non_member( void )
{
	NAMESPACE::map<int, char>	map;
	NAMESPACE::map<int, char>	map2;

	swap(map, map2);

	map.insert(NAMESPACE::make_pair(1, 'a'));
	map.insert(NAMESPACE::make_pair(2, 'b'));
	map_print(map);
	map_print(map2);

	swap(map, map2);
	map_print(map);
	map_print(map2);
}
