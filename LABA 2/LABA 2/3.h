#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


double mean(std::vector<int> v1) {
	double mean_value = 0;
	int symbols = 0;
	for (std::vector<int>::iterator i = v1.begin(); i != v1.end(); i++) {
		mean_value += *i;
		symbols++;
	}
	std::cout << "mean value :" << mean_value << std::endl;
	mean_value = mean_value / symbols;
	
	return mean_value;
	}

double median(std::vector<int> v1) {
	double medial = 0;
	int symbols = 0;
	int change = 0;
	for (int i{ 0 }; i < v1.size(); i++) {
		for (int j{ i+1 }; j < v1.size(); j++) {
			if (v1[j] < v1[i]) {
				change = v1[i];
				v1[i] = v1[j];
				v1[j] = change;
			}
		}
		std::cout << v1[i] << " ";
	}
	for (std::vector<int>::iterator i = v1.begin(); i != v1.end(); i++) {
		symbols++;
	}
	std::cout << "symbols :" << symbols << std::endl;
	if (symbols % 2 == 0) {
		medial = (v1[(symbols / 2) - 1] + v1[(symbols / 2)]);
		medial = medial / 2;
		return medial;
	}
	else {
		medial = v1[((symbols + 1)  / 2) - 1];
		return medial;
	}

	}

// работает для любой моды
double moda(std::vector<int> v1) {
	std::vector<int> amount(v1.size(), 1);

	for (int i = 0; i < v1.size(); i++) {
		if (amount[i] == 0)
			continue;
		for ( int j = i+1; j < v1.size(); j++) {
			if (v1[i] == v1[j]) {
				amount[i]++;
				amount[j] = 0;
			}
		}
	
	}
	int max = amount[0];
		for (int i{ 1 }; i < amount.size(); i++) {
			if (amount[i] > max)
				max = amount[i];
	}
		for (int i{ 0 }; i < amount.size(); i++) {
			if (amount[i] == max)
				std::cout << v1[i];
	}
		
	return 228;
}