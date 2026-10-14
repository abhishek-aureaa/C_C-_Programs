#include <iostream>
#include<memory>
#include<mutex>
#include <vector>

int main_cppconcepts(); 
int main_DLL1(); 
int main_linkedlist(); 
int main_LL(); 
int main_mutex(); 
int main_pipe(); 
int main_shrdptr(); 
int main_vector();
int main_weakptr();
int main_rvalue();

int main()
{
/*
	std::vector<int> v;
	v.reserve(10);	
	std::cout<<v.capacity();
	std::cout<<"\n"<<main_shrdptr()<<"\n";
*/
	//main_weakptr();
	main_rvalue();

	return 0;
}
