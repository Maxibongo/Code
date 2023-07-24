#include<iostream>
#include<string>

void hello(std::string t){
	std::cout << t << std::endl;
}

void twice(void f(std::string), std::string t){
	f(t);
	f(t);
}

int main(int argc, char** argv){
	void (*t)(std::string);
	t = &hello;
	twice(hello,"this is a test");
	twice(t, argv[1]);
	return 0;
}