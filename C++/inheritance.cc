#include <iostream>

class A{
public:
	int getA(){return a;};
	int getB(){return b;};
	int a = 5;
protected:
	int b = 3;
};

class B : private A{
public:
	int getAfromA(){return A::a;};
	int getBfromA(){return A::b;};
};

int main(){
	A a;
	B b;
	std::cout << a.a << std::endl;
	std::cout << b.getAfromA() << " " << b.getBfromA() <<std::endl;
	//std::cout << a.b << std::endl;
}