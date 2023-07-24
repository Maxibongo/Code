#include<iostream>

constexpr int factorial_recursive(int n){
	if(n==1){
		return 1;
	}
	else{
		return n * factorial_recursive(n-1);
	}
}

constexpr int factorial_iterative(int n){
	int fact = 1;
   	for(int i=1; i<=n; i++)
   		fact = fact * i;
   	return fact;
}


int main(){
	int x = factorial_recursive(5);
	int y = factorial_iterative(5);
	std::cout << x << std::endl;
	std::cout << y << std::endl;
}