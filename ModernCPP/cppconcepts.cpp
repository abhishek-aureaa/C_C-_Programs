#include <iostream>
#include<memory>
#include<mutex>
#include<thread>
#include <chrono>
#include <cstring>

class ABC {
	public :
	char* ptr = NULL;
	ABC()
	{
		ptr = new char[10];
		strcpy(ptr,"MoveCheck");
		std::cout<<"normal constructor\n";
	}

	ABC(const ABC& abc)
	{
		std::cout<<"Copy constructor\n";
		int len = 0;
		if(abc.ptr != NULL)
		    len = 1+strlen(abc.ptr);
		
		ptr = new char[1+len];
		strcpy(ptr, abc.ptr);
	}

	ABC& operator=(ABC&& abc) noexcept
	{
		std::cout<<"ABC Assignement Operator\n";
		if (&abc == this)
			return *this;

		if (abc.ptr != nullptr)
		{
			if (this->ptr != nullptr)
				delete(this->ptr);

			this->ptr = abc.ptr;
		}

		abc.ptr = nullptr;

		return *this;
	}
	ABC(ABC&& abc) noexcept
	{
		std::cout<<"ABC Move Constructor\n";
		if (abc.ptr != nullptr)
		{

			this->ptr = abc.ptr;
		}
		abc.ptr = nullptr;
		return;
	}
};

int main_concepts()
{
	ABC up;
	ABC up1 = up;
	std::cout<<up1.ptr<<"\n";
	ABC abc1 = std::move(up);
	if((&up)->ptr == nullptr)
		std::cout<<"up is null\n";

	ABC abc2;
	abc2 = std::move(abc1);
	if((&abc1)->ptr == nullptr)
	{
		std::cout<<"abc1 is null\n";
		return 1;
	}
	return 0;
}
