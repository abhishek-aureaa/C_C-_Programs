#include <stdio.h>
#include <iostream>
#include<memory>
#include<mutex>
#include<thread>
#include <chrono>
#include <cstring>
#include <sys/socket.h>   // socket(), bind(), listen(), accept(), connect()
#include <netinet/in.h>   // sockaddr_in, htons(), htonl()
#include <arpa/inet.h>    // inet_pton(), inet_ntop()
#include <unistd.h>       // close()

int main_pipe()
{
	int p[2];
	std::cout<<p[0]<<":"<<p[1]<<std::endl;
	int ret = pipe(p);
	std::cout<<p[0]<<":"<<p[1]<<std::endl;
	return 0;
}
