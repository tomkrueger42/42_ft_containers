#include <iostream>
#include <map>

int main(void )
{
	std::map<int, int> m;
	m.insert(4);
	m.insert(2);
	m.insert(10);
	for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		std::cout << (it)->second << std::endl;
	}
	return (0);
}