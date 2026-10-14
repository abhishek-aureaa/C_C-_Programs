#include <iostream>
#include<memory>
#include<mutex>

int main_rvalue()
{
	int&& i = 10;
	std::cout<<i;
	return 0;
}
