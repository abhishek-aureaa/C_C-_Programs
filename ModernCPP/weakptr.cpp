#include <iostream>
#include<memory>
#include<mutex>

int main_weakptr()
{
	std::shared_ptr<int> sp = std::make_shared<int>(10);
	std::weak_ptr<int> wp = sp;

	if (auto sp2 = wp.lock()) {
	    std::cout << wp.use_count();
	}

	return 0;
}
