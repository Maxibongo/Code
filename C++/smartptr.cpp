#include<iostream>
#include<memory>

int main(){
	// unique_ptr
	std::unique_ptr<int> v1 = std::make_unique<int>();

	*v1 = 7;
	if(v1)
		std::cout << *v1 << std::endl;
		auto v2 = std::move(v1);
	if(v2)
		std::cout << *v2 <<std::endl;
	std::cout << (v1 == nullptr) << std::endl;

	std::unique_ptr<int[]> arr = std::make_unique<int[]>(5);

	arr[0] = 1;
	arr[1] = 2;
	arr[3] = 5;

	for(int i =0; i < 5; i++){
		std::cout << arr[i] << std::endl;
	}

	// shared_ptr
	std::shared_ptr<int> shared1 = std::make_shared<int>();
	*shared1 = 15;
	auto shared2 = shared1;
	auto shared3 = shared1;
	auto shared4 = shared3;

	std::cout << shared1.use_count() << "\t" << *shared2 << "\t" << *shared4 <<std::endl;

	shared3 = std::make_shared<int>(5);

	std::cout << shared1.use_count() << "\t" << *shared2 << "\t" << *shared4 << "\t" << *shared3 <<std::endl;
	shared3.reset();

	std::cout << shared3 << std::endl;

	std::shared_ptr<int> sh1 = std::make_shared<int>(5);
	std::weak_ptr<int> weak1 = sh1;

	std::cout << sh1.use_count() << "\t" << weak1.use_count() <<std::endl;

	auto sh2 = weak1.lock();

	std::cout << sh1.use_count() << "\t" << weak1.use_count() <<std::endl;

	std::cout << *sh1 << "\t" << *sh2 << std::endl;

	sh1.reset();
	sh2.reset();

	std::cout << sh1.use_count() << "\t" << weak1.use_count() <<std::endl;

	auto sh3 = weak1.lock();

	std::cout << sh3.use_count() << "\t" << weak1.use_count() <<std::endl;

	return 0;
}