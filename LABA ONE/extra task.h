#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <time.h>


int B(std::vector<int>& v1, std::vector<int>& v2);
int O(std::vector<int>& v1, std::vector<int>& v2);
int P(std::vector<int>& v1, std::vector<int>& v2);
int I(std::vector<int> v1, std::vector<int> v2);
int C(std::vector<int>& v1, std::vector<int>& v2);
int D(std::vector<int>& v1, std::vector<int>& v2);
int W(std::vector<int>& v1, std::vector<int>& v2);
int choosing(std::vector<int>& v1, std::vector<int>& v2);
int CoctailSort(std::vector<int>& v1, std::vector<int>& v2);


int bank() {
	srand(time(NULL));


	std::vector<int> number_bank;
	std::vector<int> amount_bank;

	for (int i{ 0 }; i < 50; i++) {
		number_bank.push_back(1001 + rand() % 100);
		amount_bank.push_back(rand());
		if (i > 0) {
			for (int j{ 0 }; j < i; j++) {
				if (number_bank[i] == number_bank[j]) {
					while (number_bank[i] == number_bank[j])
						number_bank[i] = 1001 + rand() % 100;
					j = 0;
				}
			}
		}
	}

	choosing(number_bank, amount_bank);

	return 0;
}

void transactions() {
	std::cout << "You have 50 opened bank accounts. These are some options you can manage them:" << std::endl;
	std::cout << "Transaction O - to open a new account with an initial deposit." << std::endl;
	std::cout << "Transaction B - to reveal an account balance." << std::endl;
	std::cout << "Transaction D - to add a deposit to an account." << std::endl;
	std::cout << "Transaction W - to get money from an account" << std::endl;
	std::cout << "Transaction C - to close an account." << std::endl;
	std::cout << "Transaction P - to print all available accounts and their balances." << std::endl;
	std::cout << "Transaction I - to estimate the balances of accounts after a year adding an interest rate." << std::endl;
	std::cout << "Your choice is ";
}

int choosing(std::vector<int>& v1, std::vector<int>& v2) {

	transactions();
	char choice;
	std::cin >> choice;

	while (1) {
		if (choice == 'O') {
			P(v1, v2);
			O(v1, v2);
			std::cout << std::endl << "Maybe you can choose one more option? If there's no need then enter something different." << std::endl;
			transactions();
			std::cin >> choice;

		}
		else if (choice == 'B') {
			P(v1, v2);
			B(v1, v2);
			std::cout << std::endl << "Maybe you can choose one more option? If there's no need then enter something different." << std::endl;
			transactions();
			std::cin >> choice;

		}
		else if (choice == 'D') {
			P(v1, v2);
			D(v1, v2);
			std::cout << std::endl << "Maybe you can choose one more option? If there's no need then enter something different." << std::endl;
			transactions();
			std::cin >> choice;

		}
		else if (choice == 'W') {
			P(v1, v2);
			W(v1, v2);
			std::cout << std::endl << "Maybe you can choose one more option? If there's no need then enter something different." << std::endl;
			transactions();
			std::cin >> choice;

		}
		else if (choice == 'C') {
			P(v1, v2);
			C(v1, v2);
			std::cout << std::endl << "Maybe you can choose one more option? If there's no need then enter something different." << std::endl;
			transactions();
			std::cin >> choice;

		}
		else if (choice == 'P') {
			P(v1, v2);
			
			std::cout << std::endl << "Maybe you can choose one more option? If there's no need then enter something different." << std::endl;
			transactions();
			std::cin >> choice;
		}
		else if (choice == 'I') {
			P(v1, v2);
			I(v1, v2);
			std::cout << std::endl << "Maybe you can choose one more option? If there's no need then enter something different." << std::endl;
			transactions();
			std::cin >> choice;
		}
		else {
			std::cout << std::endl << "There's not option like that." << std::endl;
			return 0;
		}
	}



}

int O(std::vector<int>& v1, std::vector<int>& v2) {

	std::cout << "Enter a deposit for your new account: ";

	int amount;
	std::cin >> amount;

	CoctailSort(v1, v2);

	if (v1.size() < 100) {
		for (int i{ 0 }; i < v1.size()-1; i++) {
			if (v1[(i + 1)] != v1[i] + 1) {
				v1.push_back(v1[i] + 1);
				v2.push_back(amount);
				std::cout << "NEW ACC NUM = " << v1[v1.size() - 1] << std::endl;
				std::cout << "NEW ACC AMOUNT = " << v2[v2.size() - 1] << std::endl;
				P(v1, v2);
				return 0;
			}
		}
	}

	else if (v1.size() >= 100) {
		v1.push_back(1000 + v1.size()+1);
		std::cout << "NEW ACC NUM = " << v1[v1.size() - 1] << std::endl;
		std::cout << "NEW ACC AMOUNT = " << v2[v2.size() - 1] << std::endl;
		P(v1, v2);
		return 0;

	}
}

int B(std::vector<int>& v1, std::vector<int>& v2) {

	std::cout << "Enter the number of the account: ";
	
	int account_number;
	std::cin >> account_number;

	for (int i{ 0 }; i < v1.size(); i++) {
		if (v1[i] == account_number) {
			std::cout << "ACC NUM = " << v1[i] << std::endl;
			std::cout << "ACC AMOUNT = " << v2[i] << std::endl;
			return 0;
		}
	}

		std::cout << "There's no account number like this." << std::endl;
		return 0;
	}

int D(std::vector<int>& v1, std::vector<int>& v2) {

	std::cout << "Enter the number of the account: ";
	int account_number;
	std::cin >> account_number;

	std::cout << "Enter a deposit to add: ";
	int amount;
	std::cin >> amount;

	for (int i{ 0 }; i < v1.size(); i++) {
		if (v1[i] == account_number) {
			std::cout << "ACC NUM = " << v1[i] << std::endl;
			std::cout << "ACC AMOUNT = " << v2[i] << std::endl;
			v2[i] += amount;
			std::cout << "ACC NUM = " << v1[i] << std::endl;
			std::cout << "NEW ACC AMOUNT = " << v2[i] << std::endl;
			return 0;
		}
	}

	std::cout << "There's no account number like this." << std::endl;
	return 0;
}

int W(std::vector<int>& v1, std::vector<int>& v2) {

	std::cout << "Enter the number of the account: ";
	int account_number;
	std::cin >> account_number;

	std::cout << "Enter the sum to get from the account: ";
	int amount;
	std::cin >> amount;

	for (int i{ 0 }; i < v1.size(); i++) {
		if (v1[i] == account_number) {
			std::cout << "ACC NUM = " << v1[i] << std::endl;
			std::cout << "ACC AMOUNT = " << v2[i] << std::endl;
			if (v2[i] - amount < 0) {
				std::cout << "The amount on this account is lower than you wanna get." << std::endl;
			}
			else {
				v2[i] -= amount;
				std::cout << "ACC NUM = " << v1[i] << std::endl;
				std::cout << "NEW ACC AMOUNT = " << v2[i] << std::endl;
			}
			return 0;
		}
	}
	std::cout << "There's no account number like this." << std::endl;
	return 0;
}

int C(std::vector<int>& v1, std::vector<int>& v2) {

	std::cout << "The number of opened accounts: " << v1.size() << std::endl;

	std::cout << "Enter the number of the account to be closed: ";
	int account_number;
	std::cin >> account_number;

	for (int i{ 0 }; i < v1.size(); i++) {
		if (v1[i] == account_number) {
			std::cout << "ACC NUM = " << v1[i] << std::endl;
			std::cout << "ACC AMOUNT = " << v2[i] << std::endl;
			v1.erase(v1.begin() + i);
			v2.erase(v2.begin() + i);
			std::cout << "The account was successfully closed." << std::endl;
			std::cout << "The number of remaining accounts: " << v1.size() << std::endl;
			return 0;
		}
	}
	std::cout << "There's no account number like this." << std::endl;
	return 0;
}

int P(std::vector<int>& v1, std::vector<int>& v2) {

	std::cout << std::internal << std::setw(10) << "ACCOUNT NUMBER:";
	std::cout<< std::internal << std::setw(35) << "ACCOUNT AMOUNT:"<<std::endl;
	for (int i{ 0 }; i < v1.size(); i++) {
		std::cout << std::internal << std::setw(10) << v1[i];
		std::cout << std::internal << std::setw(35) << v2[i] << std::endl;
	}
	return 0;
}

int I(std::vector<int> v1, std::vector<int> v2) {

	std::cout << "Enter the interest rate: ";

	double interest_rate;
	std::cin >> interest_rate;

	std::cout << std::internal << std::setw(10) << "ACCOUNT NUMBER:";
	std::cout << std::internal << std::setw(35) << "NEW ACCOUNT AMOUNT:" << std::endl;

	for (int i{ 0 }; i < v2.size(); i++) {
		v2[i] = v2[i] + ((v2[i]) * (interest_rate / 100));
		std::cout << std::internal << std::setw(10) << v1[i];
		std::cout << std::internal << std::setw(35) << v2[i] << std::endl;
	}
	
	return 0;
}

int CoctailSort(std::vector<int>& v1, std::vector<int>& v2) {
	
	int start = 0;
	int finish = v1.size() - 2;
	int dop = 0;
	int another_dop = v1.size();
	
	while (finish >= start) {
		
		for (int i = start; i < another_dop - 1; i++) {
			if (v1[i] > v1[i + 1]) {
				std::swap(v1[i], v1[i + 1]);
				std::swap(v2[i], v2[i + 1]);
			}
		}
		
		for (int j = finish; j > dop; j--) {
			if (v1[j] < v1[j - 1]) {
				std::swap(v1[j - 1], v1[j]);
				std::swap(v2[j - 1], v2[j]);
			}
		}

		start++;
		finish--;
		another_dop--;
		dop++;
	}

	return 0;
}
