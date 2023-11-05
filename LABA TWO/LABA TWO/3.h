#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> CoctailSort(std::vector<int>v1);
std::vector<std::string> dictionary();

double mean(std::vector<int> v1) {
	double mean_value = 0;
	for (std::vector<int>::iterator i = v1.begin(); i != v1.end(); i++) {
		mean_value += *i;
	}
	std::cout << "mean value :" << mean_value << std::endl;
	mean_value = mean_value / v1.size();

	return mean_value;
}

double median(std::vector<int> v1) {
	double medial = 0;
	/*int change = 0;*/
	
	/*for (int i{ 0 }; i < v1.size(); i++) {
		for (int j{ i + 1 }; j < v1.size(); j++) {
			if (v1[j] < v1[i]) {
				change = v1[i];
				v1[i] = v1[j];
				v1[j] = change;
			}
		}
		std::cout << v1[i] << " ";*/

	//}
	
	v1 = CoctailSort(v1);
	if (v1.size() % 2 == 0) {
		medial = (v1[(v1.size() / 2) - 1] + v1[(v1.size() / 2)]);
		medial = medial / 2;
		return medial;
	}
	else {
		medial = v1[((v1.size() + 1) / 2) - 1];
		return medial;
	}

}

// работает для любой моды
double moda(std::vector<int> v1) {
	std::vector<int> amount(v1.size(), 1);


	for (int i = 0; i < v1.size(); i++) {
		if (amount[i] == 0)
			continue;
		for (int j = i + 1; j < v1.size(); j++) {
			if (v1[i] == v1[j]) {
				amount[i]++;
				amount[j] = 0;
			}
		}

	}
	int max = amount[0];
	int is_there_moda = 0;

	for (int i{ 1 }; i < amount.size(); i++) {
		if (amount[i] > max)
			max = amount[i];
	}


	for (int i{ 0 }; i < amount.size(); i++) {
		if (amount[i] == max)
			is_there_moda++;
	}
	if(max * is_there_moda == amount.size()){
		std::cout << "There's no moda. Each number repeats itself equal amount of times." << std::endl;
		return true;
	}

	for (int i{ 0 }; i < amount.size(); i++) {
		if (amount[i] == max)
			std::cout<<v1[i]<<" ";
	}
	std::cout <<"Repeats = " << max;
	return 0;
}

std::vector<int> CoctailSort(std::vector<int>v1) {
	int start = 0;
	int finish = v1.size() - 2;
	int dop = 0;

	while (finish >= start) {
		for (int i = start; i < v1.size() - 1; i++) {
			if (v1[i] > v1[i + 1])
				std::swap(v1[i], v1[i + 1]);
		}
		for (int j = finish; j > dop; j--) {
			if (v1[j] < v1[j - 1])
				std::swap(v1[j - 1], v1[j]);
		}
		start++;
		finish--;
		dop++;
	}

	return v1;
}



bool moda_names(std::vector<std::string> v1) {
	
	std::vector<int> amount(v1.size(), 1);

	for (int i = 0; i < v1.size(); i++) {
		if (amount[i] == 0)
			continue;
		for (int j = i + 1; j < v1.size(); j++) {
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
	
	if (max > 1)
		return false;
	else
		return true;

}
	