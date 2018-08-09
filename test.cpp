#include <iostream>
#include "threadpool.h"
#include <cstdlib>
#include <unistd.h>
#include <cstring>

char* func(char *buf)
{
	strcpy(buf, "HELLO WORLD");	
	return buf;
}

int main()
{
	ThreadPool pool(5);
	char buf[20] = "hello world";
	// enqueue and store future
	for (int i = 0; i< 10; i++)
	{ 
		auto result = pool.enqueue(func, buf);
		std::cout << result.get() << std::endl;
	}

}
