#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

void by_iter(std::vector<int> v1, std::vector<std::string> v2) {
	std::vector<int>::iterator j = v1.begin();
	std::cout << std::setw(13) << "Name:" << "\t" << "Mark:" << std::endl;
	for (std::vector<std::string>::iterator i = v2.begin(); i < v2.end(); i++) {	
		std::cout << std::setw(13) << *i << "\t";
		for (j; j < v1.end(); i++) {
			std::cout << *j << std::endl;;
			break;
		}
		j++;
	}
	std::cout << std::endl;
}

void by_base(std::vector<int> v1, std::vector<std::string> v2) {
	std::cout << std::setw(13)<< "Name:" << "\t" << "Mark:" << std::endl;
	for (int i{ 0 }; i < v1.size(); i++)
		std::cout << std::setw(13) << v2[i] << "\t" << v1[i] << std::endl;
	std::cout << std::endl;
}

void range_based(std::vector<int> v1, std::vector<std::string> v2) {
	
	std::cout << std::setw(13) << "Name:" << "\t" << "Mark:" << std::endl;
	int temp = 0;
	
	for (auto i : v2) {
		std::cout << std::setw(13) << i<<"\t";
		for (auto j : v1) {
			if (j == v1[temp]) {
				std::cout << j<<std::endl;
				break;
			}
		}
			temp++;
	}
	std::cout << std::endl;
}