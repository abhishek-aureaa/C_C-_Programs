#include <iostream>
#include<memory>
#include<mutex>

class ABC{
	public:
		ABC()
		{
			std::cout<<"ABC private constructor\n";
		}
};

int main_shrdptr()
{
	/*
	std::shared_ptr<ABC> p(new ABC);
	std::shared_ptr<ABC> p1 = std::make_shared<ABC>();
	std::weak_ptr<ABC> p2 = p;
	std::cout<<p2.use_count();
	auto p3 = p2.lock();
	std::cout<<"\n"<<p2.use_count();
	auto p4 = p2.lock();
	std::cout<<"\n"<<p2.use_count();
	if(p4)
		std::cout<<"\n"<<"p4 exists\n";
	
	*/

	/*
	std::unique_ptr<ABC> p2(new ABC);
	std::unique_ptr<ABC> p3 = std::move(p2);

	if(p2 == nullptr)
		std::cout<<"p2 is nullptr\n";
	std::cout<<p.use_count();
	*/
	/*
	std::shared_ptr<int> sp = std::shared_ptr<int>(new int(10));
	std::shared_ptr<int> sp1 = sp;
	std::cout<<sp1.use_count();
	std::unique_ptr<int> up1 = std::unique_ptr<int>(new int(10));
	std::unique_ptr<int> up2 = std::move(up1);
	if(up1 == nullptr)
		std::cout<<"up1 is null\n";
	*/
	std::shared_ptr<int> sp = std::make_shared<int>(10);
	std::shared_ptr<int> sp1 = sp;
	std::shared_ptr<int> sp2 = sp;
	std::cout<<sp1.use_count();

	return 0;
}
