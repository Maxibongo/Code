#include<iostream>
#include<type_traits>


// idea based on the input type use different version of method
template<class T>
void foo(T){
	std::cout << "T is signed" << std::endl;
}

template<class T, class = typename std::enable_if<std::is_unsigned<T>::value>::type>
void foo(T){
	std::cout << "T is unsigned" << std::endl;
}




int main(){
	unsigned int b = 100000;
	int a = 10;
	foo(a);
	foo(b);
	return 1;
}