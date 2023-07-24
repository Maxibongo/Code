#include<iostream>

int main(){
	int a = 5;
	int b = 2;

	auto f = [a] (int x)->double{return a + x;};

	int c = f(b);
	std::cout << c << std::endl;
	return 0;
}