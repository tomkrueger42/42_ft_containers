#include <iostream>
#include <map>
#include <string>

#define LOG(msg) std::cout << msg
#define LOGN(msg) std::cout << msg << std::endl;
#define LOGI(...) std::cout << #__VA_ARGS__ << ": " << __VA_ARGS__ << std::endl;

template<class T>
void	mapMeta(T& map)
{
	LOGI(map.empty());
	LOGI(map.size());
	LOGI(map.max_size());
	LOGN("--------------------");
}

int main(void )
{
	// std::map<int, std::string> m;
	// mapMeta(m);
	// m.insert(std::pair<int, std::string>(4, "hello"));
	// mapMeta(m);
	// m.insert(std::pair<int, std::string>(5, "heya"));
	// m.insert(std::pair<int, std::string>(1, "huhu"));
	// m.insert(std::pair<int, std::string>(3, "heyo"));
	// m.insert(std::pair<int, std::string>(3, "hiii"));

	// std::map<int, std::string> n = m;
	// n.erase(4);
	// for (std::map<int, std::string>::iterator it = m.begin(); it != m.end(); it++)
	// {
	// 	std::cout << (it)->second << std::endl;
	// }
	return (0);
}