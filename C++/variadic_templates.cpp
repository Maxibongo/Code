#include<iostream>

template<typename T>
double horner(double x, T head){
	return head;
}

template<typename T, typename... Ts>
double horner(double x,T head, Ts... tail){
	return head + x * horner(x, x * tail...);
}

int main(){
	double value = horner(1, 2, 1);
	std::cout << value << std::endl;
}