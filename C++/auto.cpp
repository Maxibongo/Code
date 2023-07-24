#include<iostream>

auto test(int i, double j) -> decltype(i*j)
{
	return i * j;
}

int main(){
	auto i = 5;
	std::cout << i << std::endl;
	std::cout << test(4, 3.3453) << std::endl;
	return 0;
}