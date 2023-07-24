#include<iostream>
#include<thread>
#include<chrono>

int main(){
	int val = 0;
	// lambda as first argument, no explicit function arguments
	// val captured by-reference through the lambda
	std::thread t([&](){
		for (int i = 0; i < 10; i++)
		{
		std::cout << ++val << std::endl;
		// blocks thread execution for given duration
		std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	});
	// could do something else here in the meantime
	// wait for thread to finish execution
	std::cout << "This is an example for the sleep_for function, code is executed first that is written in the source code later!" << std::endl;
	std::cout << "Splendid!" << std::endl;
	t.join();
	return 0;
}