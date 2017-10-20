#include <iostream>
int main()
{
	std::string test;
	for (int i = 0; i < 6; ++i)
	{
		getline(std::cin, test);
		std::cout << test << std::endl;		
	}
}