#include <iostream>
#include <vector>
#include <string>

void by_iter(std::vector<int> v1, std::vector<std::string> v2) {
	std::cout << "Marks and names:" << std::endl;
	for (std::vector<int>::iterator i = v1.begin(); i != v1.end(); i++) {
		std::cout << *i << " ";
	}
	std::cout << "Names:" << std::endl;
	for (std::vector<std::string>::iterator i = v2.begin(); i != v2.end(); i++) {
		std::cout << *i << " ";
	}
}

int by_base(std::vector<int> v1/*, std::vector<std::string> v2*/) {
	for (int i{ 0 }; i < v1.size(); i++) {
		std::cout << v1[i] << " ";
	}
	return 0;
	/*for (int i{ 0 }; i < v1.size(); i++) {
		std::cout << v2[i] << " ";
	}*/
}

void range_based(std::vector<int> v1, std::vector<std::string> v2) {
	for (int i : v1)
		std::cout << i << " ";
	for (std::string i : v2)
		std::cout << i << " ";
}