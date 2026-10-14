#include <iostream>
#include<memory>
#include<mutex>
#include<thread>
#include <chrono>


class ABC{
	public:
		ABC()
		{
			std::cout<<"ABC private constructor\n";
		}
};

//std::mutex m1;
std::recursive_mutex m1;
void work()
{
	//std::lock_guard<std::mutex> lock(m1);  
	/*
	std::unique_lock<std::mutex> lock(m1); //, std::defer_lock);  
	std::cout<<"work() function\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout<<"111111\n";
	std::cout<<"222222\n";
	std::cout<<"3333333\n";
	m1.lock();
	m1.unlock();
	m1.unlock();
	*/
	m1.lock();
	std::cout<<"work() function\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout<<"111111\n";
	std::cout<<"222222\n";
	std::cout<<"3333333\n";
	m1.unlock();
}

int main_mutex()
{
	std::thread t(work);
	std::thread t1(work);
	std::thread t2(work);
	std::thread t3(work);
	t.join();
	t1.join();
	t2.join();
	t3.join();
	return 0;
}
