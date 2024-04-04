#include <iostream>
#include <fstream>
#include <vector>
#include "Matrix.h"
#include <string>
#include <Windows.h>

int task1(std::string path1) {
	std::ifstream fin;

	fin.open(path1);
	try {
		if (!fin.is_open())
			throw std::string("File wasnt opened");
	}
	catch (std::string& exception) {
		std::cout << exception << std::endl;
		return 0;
	}

	std::string stroke;
	while (true) {
		std::cout << "Чтобы выйти введите ." << std::endl;
		std::cout << "Введите слово: ";
		std::cin >> stroke;
		if (stroke == ".")
			break;
		std::string stroke1;
		int counter{ 0 };
		std::vector<std::string> coincidence;
		while (!fin.eof()) {
			fin >> stroke1;
			if (stroke1 == stroke) {
				counter++;
				continue;
			}
			if (stroke1.size() > stroke.size()) {
				int j{ 0 };
				int counter2{ 0 };
				for (int i{ 0 }; i < stroke1.size(); i++) {
					if (j < stroke.size()) {
						if (stroke1[i] == stroke[j]) {
							counter2++;
							j++;
						}
						else {
							counter2 = 0;
							j = 0;
						}
					}
					if (counter2 == stroke.size()) {
						coincidence.push_back(stroke1);
						break;
					}
				}
			}
		}
		std::cout << "Количество точных совпадений: " << std::endl;
		std::cout << counter << std::endl;
		std::cout << "Возможные совпадения: " << std::endl;
		for (int i{ 0 }; i < coincidence.size(); i++)
			std::cout << coincidence[i] << " ";
		std::cout << std::endl;
		fin.seekg(0);
	}
	
	fin.close();
	return 0;
}

std::ostream& operator << (std::ostream& os, Matrix& matrix) {
	for (int i{ 0 }; i < matrix.n; i++) {
		for (int j{ 0 }; j < matrix.m; j++)
			os << (matrix.data)[i][j] << " ";
		os << "\n";
	}
	os << "\n";
	return os;
}
//можно просто записать весь объект MATRIX в бинарный файл,
//а потом считать из бинарного файла в другой объект класса matrix,
//и уже воспользовавшись перегрузками операторов или методов класса вывести матрицу на экран.
//но, как по мне, такая реализация интереснее (в бинарный файл записывается сама матрица, а не объект класса.
//проверить можно ли считывать матрицы разного размера
void binaryWriting(std::fstream& file, Matrix& matrix) {
	char gap = ' ';
	char newstoke = '\n';
	for (int i{ 0 }; i < matrix.n; i++) {
		for (int j{ 0 }; j < matrix.m; j++) {
			file.write((char*)&(matrix.data[i][j]), sizeof(matrix.data[i][j]));
			file.write(&gap, sizeof(gap));
		}
		file.write(&newstoke, sizeof(newstoke));
	}
	file.write(&newstoke, sizeof(newstoke));
}

void binaryReading(std::fstream& file, Matrix& matrix) {
	char gap;
	int num;
	bool num_or_gap = false;
	for (int i{ 1 }; i <= ((matrix.getRow() * matrix.getStr() * 2) + matrix.getStr()); i++) {
		if (i > 1 && i == (matrix.getRow() * 2 * (i / matrix.getRow() / 2)) + (i / matrix.getRow() / 2)) {
			file.read((char*)&gap, sizeof(gap));
			std::cout << gap;
			continue;
		}
		if (!num_or_gap) {
			file.read((char*)&num, sizeof(num));
			std::cout << num;
			num_or_gap = true;
		}
		else {
			file.read((char*)&gap, sizeof(gap));
			std::cout << gap;
			num_or_gap = false;
		}
	}
	file.read((char*)&gap, sizeof(gap));
	std::cout << gap;
}

int task2(std::string path2, std::string path2bin) {
	
	std::fstream file_matrixes;
	std::fstream file_matrixes_bin;
	file_matrixes.open(path2, std::ios_base::in | std::ios_base::out);
	file_matrixes_bin.open(path2bin, std::ios_base::binary | std::ios_base::out | std::ios_base::in);
	try {
		if (!file_matrixes.is_open())
			throw std::string("TXT FILE WASN'T OPENED!");
		if (!file_matrixes_bin.is_open())
			throw std::string("BINARY FILE WASN'T OPENED!");
	}
	catch (std::string& exception) {
		std::cout << exception << std::endl;
		return 0;
	}

	Matrix one;
	Matrix two;
	Matrix three;
	one.filling();
	two.filling();
	three.filling();
	file_matrixes << one;
	file_matrixes << two;
	file_matrixes << three;
	
	std::cout << "TXT:" << std::endl;
	file_matrixes.seekg(0);
	std::string schitivaem = "";
	while (std::getline(file_matrixes, schitivaem)) {
		std::cout << schitivaem << std::endl;
	}
	file_matrixes.close();

	Matrix oneforbin;
	Matrix twoforbin;
	Matrix threeforbin;
	binaryWriting(file_matrixes_bin, one);
	binaryWriting(file_matrixes_bin, two);
	binaryWriting(file_matrixes_bin, three);
	file_matrixes_bin.seekg(0);
	std::cout << "BINARY:" << std::endl;
	binaryReading(file_matrixes_bin, one);
	binaryReading(file_matrixes_bin, two);
	binaryReading(file_matrixes_bin, three);

	file_matrixes_bin.close();
	return 0;
}

class Catalog {
private:
	std::vector<int> IDs;
	std::vector<std::string> authors;
	std::vector<std::string> bookNames;
	std::vector<int> pages;
	std::fstream& datafile;

protected:
	void forDeleting(std::vector<int>& vec) {
		std::cout << "ID" << " Author" << " Title" << " Pages" << std::endl;
		std::string ID = "";
		for (auto& elem : vec) {
			if (IDs[elem] < 10)
				ID = "000";
			else if (IDs[elem] < 100)
				ID = "00";
			else if (IDs[elem] < 1000)
				ID = "0";
			else
				ID = "";
			std::cout << ID << IDs[elem] << " " << authors[elem] << " " << bookNames[elem] << " " << pages[elem] << std::endl;
		}
		std::string choice;
		std::cout << "Если в списке обнаружено то, что вы искали, введите ID этой записи." << std::endl;
		std::cout << "0 - ВЫХОД." << std::endl;
		std::cout << "ID: ";
		std::cin >> choice;
		std::cin.ignore();
	
		switch (std::stoi(choice)) {
		case 0:
			std::cout << "Ничего удалено не было." << std::endl;
			break;
		default:
			if (std::stoi(choice) <= IDs.size()) {
				IDs.erase(IDs.begin() + std::stoi(choice) - 1);
				authors.erase(authors.begin() + std::stoi(choice) - 1);
				bookNames.erase(bookNames.begin() + std::stoi(choice) - 1);
				pages.erase(pages.begin() + std::stoi(choice) - 1);
				IDless(std::stoi(choice) - 1);
				std::cout << "Запись успешно удалена." << std::endl;
			}
			else
				std::cout << "Некорректный ID." << std::endl;
			break;
		}
	}

	void forEditing(std::vector<int>& vec) {
		std::cout << "ID" << " Author" << " Title" << " Pages" << std::endl;
		std::string ID_print = "";
		for (auto& elem : vec) {
			if (IDs[elem] < 10)
				ID_print = "000";
			else if (IDs[elem] < 100)
				ID_print = "00";
			else if (IDs[elem] < 1000)
				ID_print = "0";
			else
				ID_print = "";
			std::cout << ID_print << IDs[elem] << " " << authors[elem] << " " << bookNames[elem] << " " << pages[elem] << std::endl;
		}
		std::string id;
		std::cout << "Если в списке обнаружено то, что вы искали, введите ID этой записи." << std::endl;
		std::cout << "0 - ВЫХОД." << std::endl;
		std::cout << "ID: ";
		std::cin >> id;
		std::cin.ignore();

		switch (std::stoi(id)) {
		case 0:
			std::cout << "Ничего отредактировано не было." << std::endl;
			break;
		default:
			if (std::stoi(id) <= IDs.size()) {
				toChange(std::stoi(id));
			}
			else
				std::cout << "Некорректный ID." << std::endl;
			break;
		}
	}

	void findingCoincidence(std::string& object, std::vector<std::string>& vec_obj, std::vector<int>& exact, std::vector<int>& coincidence) {
		for (int i{ 0 }; i < authors.size(); i++) {
			if (object == vec_obj[i]) {
				exact.push_back(i);
			}
			else {
				int j{ 0 };
				int counter2{ 0 };
				for (int k{ 0 }; k < vec_obj[i].size(); k++) {
					if (j < object.size()) {
						if ((vec_obj[i])[k] == object[j]) {
							counter2++;
							j++;
						}
						else {
							counter2 = 0;
							j = 0;
						}
					}
					if (counter2 == object.size()) {
						coincidence.push_back(i);
						break;
					}
				}
			}
		}
	}

	void toChange(int id) {
		std::cout << "Что вы хотите редактировать?" << std::endl;
		std::cout << "1 - автора" << std::endl;
		std::cout << "2 - название книги" << std::endl;
		std::cout << "3 - количество страниц" << std::endl;
		std::cout << "0 - ВЫХОД" << std::endl;
		int choice;
		std::cin >> choice;
		std::cin.ignore();
		switch (choice) {
		case 1: {
			std::string author;
			std::cout << "Введите новое имя автора: ";
			std::getline(std::cin, author);
			if (author.find(' ') != std::string::npos) {
				for (int j{ 0 }; j < author.size(); j++) {
					if (author[j] == ' ') {
						author.erase(j, 1);
						j--;
					}
				}
			}
			authors[id - 1] = author;
			fileRewriting();
			std::cout << "Запись успешно отредактирована." << std::endl;
			break;
		}
		case 2: {
			std::string book;
			std::cout << "Введите новое название книги: ";
			std::getline(std::cin, book);
			if (book.find(' ') != std::string::npos) {
				for (int j{ 0 }; j < book.size(); j++) {
					if (book[j] == ' ') {
						book.erase(j, 1);
						j--;
					}
				}
			}
			bookNames[id - 1] = book;
			fileRewriting();
			std::cout << "Запись успешно отредактирована." << std::endl;
			break;
		}
		case 3: {
			int page;
			std::cout << "Введите новое кол-во страниц: ";
			std::cin >> page;
			pages[id - 1] = page;
			std::cin.ignore();
			fileRewriting();
			std::cout << "Запись успешно отредактирована." << std::endl;
			break;
		}
		}
	}

	void IDless(int i) {
		for (i; i < IDs.size(); i++)
			IDs[i]--;	
		fileRewriting();
	}

	void fileRewriting() {
		datafile.close();
		datafile.open("3TASK.txt", std::ios_base::out);
		datafile << "ID" << " Author" << " Title" << " Pages" << std::endl;
		for (int i{ 0 }; i < IDs.size(); i++) {
			std::string ID = "";
			if (IDs[i] < 10)
				ID = "000";
			else if (IDs[i] < 100)
				ID = "00";
			else if (IDs[i] < 1000)
				ID = "0";
			else
				ID = "";
			if (i == IDs.size() - 1)
				datafile << ID << IDs[i] << " " << authors[i] << " " << bookNames[i] << " " << pages[i];
			else
				datafile << ID << IDs[i] << " " << authors[i] << " " << bookNames[i] << " " << pages[i] << std::endl;
		}
		datafile.close();
		datafile.open("3TASK.txt", std::ios_base::in | std::ios_base::app);
	}
public:
	Catalog(std::fstream& datafile) : datafile(datafile) {
			int count = 0;
			int int_data;
			std::string str_data;
			while (!datafile.eof()) {
				if (count == 0) {
					std::getline(datafile, str_data);
					if (datafile.eof())
						datafile.seekg(0);
					count++;
				}
				else if (count == 1) {
					datafile >> int_data;
					IDs.push_back(int_data);
					count++;
				}
				else if (count == 2) {
					datafile >> str_data;
					authors.push_back(str_data);
					count++;
				}
				else if (count == 3) {
					datafile >> str_data;
					bookNames.push_back(str_data);
					count++;
				}
				else if (count == 4) {
					datafile >> int_data;
					pages.push_back(int_data);
					count = 1;
				}
			}
			if (IDs.size() > authors.size())
				IDs.pop_back();
			datafile.clear();
	}	
	~Catalog() {
		datafile.close();
	}
	void GetInfo() {
		std::string ID = "";
		std::cout << "ID" << " Author" << " Title" << " Pages" << std::endl;
		for (int i{ 0 }; i < IDs.size(); i++) {
			if (IDs[i] < 10)
				ID = "000";
			else if (IDs[i] < 100)
				ID = "00";
			else if (IDs[i] < 1000)
				ID = "0";
			else
				ID = "";
			std::cout << ID << IDs[i] << " " << authors[i] << " " << bookNames[i] << " " << pages[i] << std::endl;
		}
	}

	void AddingNew() {
		int int_data;
		std::string str_data;
		std::cout << "Вам потребуется ввести данные для добавления новой записи." << std::endl;
		int_data = IDs[IDs.size() - 1] + 1;
		IDs.push_back(int_data);

		std::string ID;
		if (IDs[IDs.size() - 1] < 10)
			ID = "000";
		else if (IDs[IDs.size() - 1] < 100)
			ID = "00";
		else if (IDs[IDs.size() - 1] < 1000)
			ID = "0";
		else
			ID = "";
		datafile << "\n";
		datafile << ID << int_data << " ";

		std::cout << "Автор: ";
		std::getline(std::cin, str_data);
		if (str_data.find(' ') != std::string::npos) {
			for (int j{ 0 }; j < str_data.size(); j++) {
				if (str_data[j] == ' ') {
					str_data.erase(j, 1);
					j--;
				}
			}
		}
		authors.push_back(str_data);
		datafile << str_data << " ";

		std::cout << "Название книги: ";
		std::getline(std::cin, str_data);
		bookNames.push_back(str_data);
		datafile << str_data << " ";
		if (str_data.find(' ') != std::string::npos) {
			for (int j{ 0 }; j < str_data.size(); j++) {
				if (str_data[j] == ' ') {
					str_data.erase(j, 1);
					j--;
				}
			}
		}

		std::cout << "Кол-во страниц: ";
		std::cin >> int_data;
		pages.push_back(int_data);
		datafile << int_data;
		std::cin.ignore();

		std::cout << "Успешно добавлено." << std::endl;
	}

	void Deleting() {
		int choosing;
		std::cout << "Вы можете найти необходимую для удаления запись по:" << std::endl;
		std::cout << "1 - ID;" << std::endl;
		std::cout << "2 - Автору;" << std::endl;
		std::cout << "3 - Названию книги;" << std::endl;
		std::cout << "4 - Количеству страниц;" << std::endl;
		std::cout << "0 - ВЫХОД." << std::endl;
		std::cout << "Выберите вариант: ";
		std::cin >> choosing;
		switch (choosing) {
		case 1: {
			std::string id;
			std::cout << "Введите ID: ";
			std::cin >> id;
			for (int i{ 0 }; i < id.size(); i++) {
				if (id[i] == '0') {
					id.erase(i, 1);
					i--;
				}
				else
					break;
			}
			if (std::stoi(id) <= IDs.size()) {
				std::cout << "Ваши данные:" << std::endl;
				std::cout << "Author" << " Title" << " Pages" << std::endl;
				std::cout << authors[std::stoi(id) - 1] << " " << bookNames[std::stoi(id) - 1] << " " << pages[std::stoi(id) - 1] << std::endl;
				IDs.erase(IDs.begin() + std::stoi(id) - 1);
				authors.erase(authors.begin() + std::stoi(id) - 1);
				bookNames.erase(bookNames.begin() + std::stoi(id) - 1);
				pages.erase(pages.begin() + std::stoi(id) - 1);
				IDless(std::stoi(id) - 1);
				std::cout << "Запись успешно удалена." << std::endl;
			}
			else
				std::cout << "Некорректный ID." << std::endl;
			break;
		}
		case 2: {
			std::vector<int> coincidence;
			std::vector<int> exact;
			std::string author;
			std::cout << "Введите автора: ";
			std::cin.ignore();
			std::getline(std::cin, author);
			findingCoincidence(author, authors, exact, coincidence);
			if (exact.size() == 0 && coincidence.size() != 0) {
				std::cout << "По вашему запросу ничего не найдено." << std::endl;
				std::cout << "Похожие авторы: " << std::endl;
				std::cout << "ID" << " Author" << " Title" << " Pages" << std::endl;
				forDeleting(coincidence);
			}
			else if (exact.size() != 0) {
				std::cout << "По вашему запросу найдено:" << std::endl;
				std::cout << "ID" << " Author" << " Title" << " Pages" << std::endl;
				forDeleting(exact);
			}
			else
				std::cout << "Ничего не найдено..." << std::endl;
			break;
		}
		case 3: {
			std::vector<int> coincidence;
			std::vector<int> exact;
			std::string book;
			std::cout << "Введите название книги: ";
			std::cin.ignore();
			std::getline(std::cin, book);
			findingCoincidence(book, bookNames, exact, coincidence);
			if (exact.size() == 0 && coincidence.size() != 0) {
				std::cout << "По вашему запросу ничего не найдено." << std::endl;
				std::cout << "Похожие книги: " << std::endl;
				std::cout << "ID" << " Author" << " Title" << " Pages" << std::endl;
				forDeleting(coincidence);
			}
			else if (exact.size() != 0) {
				std::cout << "По вашему запросу найдено:" << std::endl;
				std::cout << "ID" << " Author" << " Title" << " Pages" << std::endl;
				forDeleting(exact);
			}
			else
				std::cout << "Ничего не найдено..." << std::endl;
			break;
		}
		case 4: {
			int page;
			std::vector<int> exact;
			std::cout << "Введите количество страниц: ";
			std::cin >> page;
			for (int i{ 0 }; i < pages.size(); i++) {
				if (pages[i] == page)
					exact.push_back(i);
			}
			if (exact.size() > 0)
				forDeleting(exact);
			else
				std::cout << "Ничего не найдено..." << std::endl;
			break;
		}
		default:
			std::cout << "Некорректное число!" << std::endl;
			break;
		}
	}

	void Finding() {
		int choosing;
		std::cout << "Вы можете найти необходимую запись по:" << std::endl;
		std::cout << "1 - ID;" << std::endl;
		std::cout << "2 - Автору;" << std::endl;
		std::cout << "3 - Названию книги;" << std::endl;
		std::cout << "4 - Количеству страниц;" << std::endl;
		std::cout << "0 - ВЫХОД." << std::endl;
		std::cout << "Выберите вариант: ";
		std::cin >> choosing;
		switch (choosing) {
		case 1: {
			std::string id;
			std::cout << "Введите ID: ";
			std::cin >> id;
			if (std::stoi(id) <= IDs.size()) {
				std::cout << "Ваши данные:" << std::endl;
				std::cout << "Author" << " Title" << " Pages" << std::endl;
				std::cout << authors[std::stoi(id) - 1] << " " << bookNames[std::stoi(id) - 1] << " " << pages[std::stoi(id) - 1] << std::endl;
			}
			else
				std::cout << "Некорректный ID." << std::endl;
			break;
		}
		case 2: {
			std::vector<int> coincidence;
			std::vector<int> exact;
			std::string author;
			std::cout << "Введите автора: ";
			std::cin.ignore();
			std::getline(std::cin, author);
			findingCoincidence(author, authors, exact, coincidence);
			if (exact.size() == 0 && coincidence.size() != 0) {
				std::cout << "По вашему запросу ничего не найдено." << std::endl;
				std::cout << "Похожие авторы: " << std::endl;
				std::cout << "ID" << " Author" << " Title" << " Pages" << std::endl;
				for (auto& elem : coincidence) {
					std::cout << IDs[elem] << " " << authors[elem] << " " << bookNames[elem] << " " << pages[elem] << std::endl;
				}
			}
			else if (exact.size() != 0) {
				std::cout << "По вашему запросу найдено:" << std::endl;
				std::cout << "ID" << " Author" << " Title" << " Pages" << std::endl;
				for (auto& elem : exact) {
					std::cout << IDs[elem] << " " << authors[elem] << " " << bookNames[elem] << " " << pages[elem] << std::endl;
				}
			}
			else
				std::cout << "Ничего не найдено..." << std::endl;
			break;
		}
		case 3: {
			std::vector<int> coincidence;
			std::vector<int> exact;
			std::string book;
			std::cout << "Введите название книги: ";
			std::cin.ignore();
			std::getline(std::cin, book);
			findingCoincidence(book, bookNames, exact, coincidence);
			if (exact.size() == 0 && coincidence.size() != 0) {
				for (auto& elem : coincidence) {
					std::cout << IDs[elem] << " " << authors[elem] << " " << bookNames[elem] << " " << pages[elem] << std::endl;
				}
			}
			else if (exact.size() != 0) {
				std::cout << "По вашему запросу найдено:" << std::endl;
				std::cout << "ID" << " Author" << " Title" << " Pages" << std::endl;
				for (auto& elem : exact) {
					std::cout << IDs[elem] << " " << authors[elem] << " " << bookNames[elem] << " " << pages[elem] << std::endl;
				}
			}
			else
				std::cout << "Ничего не найдено..." << std::endl;
			break;
		}
		case 4: {
			int page;
			std::vector<int> exact;
			std::cout << "Введите количество страниц: ";
			std::cin >> page;
			for (int i{ 0 }; i < pages.size(); i++) {
				if (pages[i] == page)
					exact.push_back(i);
			}
			if (exact.size() > 0)
				for (auto& elem : pages) {
					std::cout << "По вашему запросу найдено:" << std::endl;
					std::cout << IDs[elem] << " " << authors[elem] << " " << bookNames[elem] << " " << pages[elem] << std::endl;
				}
			else
				std::cout << "Ничего не найдено..." << std::endl;
			break;
		}
		default:
			std::cout << "Некорректное число!" << std::endl;
			break;
		}
	}

	void Editing() {
		int choosing;
		std::cout << "Вы можете найти необходимую для редактирования запись по:" << std::endl;
		std::cout << "1 - ID;" << std::endl;
		std::cout << "2 - Автору;" << std::endl;
		std::cout << "3 - Названию книги;" << std::endl;
		std::cout << "4 - Количеству страниц;" << std::endl;
		std::cout << "0 - ВЫХОД." << std::endl;
		std::cout << "Выберите вариант: ";
		std::cin >> choosing;
		switch (choosing) {
		case 1: {
			std::string id;
			std::cout << "Введите ID: ";
			std::cin >> id;
			if (std::stoi(id) <= IDs.size()) {
				std::cout << "Ваши данные:" << std::endl;
				std::cout << "Author" << " Title" << " Pages" << std::endl;
				std::cout << authors[std::stoi(id) - 1] << " " << bookNames[std::stoi(id) - 1] << " " << pages[std::stoi(id) - 1] << std::endl;
				toChange(std::stoi(id));
			}
			else
				std::cout << "Некорректный ID." << std::endl;
			break;
		}
		case 2: {
			std::vector<int> coincidence;
			std::vector<int> exact;
			std::string author;
			std::cout << "Введите автора: ";
			std::cin.ignore();
			std::getline(std::cin, author);
			findingCoincidence(author, authors, exact, coincidence); //МОЖНО СДЕЛАТЬ ЧЕРЕЗ BOOL
			if (exact.size() == 0 && coincidence.size() != 0) {
				std::cout << "По вашему запросу ничего не найдено." << std::endl;
				std::cout << "Похожие авторы: " << std::endl;
				forEditing(coincidence);
			}
			else if (exact.size() != 0) {
				std::cout << "По вашему запросу найдено:" << std::endl;
				forEditing(exact);
			}
			else
				std::cout << "Ничего не найдено..." << std::endl;
			break;
		}
		case 3: {
			std::vector<int> coincidence;
			std::vector<int> exact;
			std::string book;
			std::cout << "Введите название книги: ";
			std::cin.ignore();
			std::getline(std::cin, book);
			findingCoincidence(book, bookNames, exact, coincidence);
			if (exact.size() == 0 && coincidence.size() != 0) {
				std::cout << "По вашему запросу ничего не найдено." << std::endl;
				std::cout << "Похожие книги: " << std::endl;
				forEditing(coincidence);
			}
			else if (exact.size() != 0) {
				std::cout << "По вашему запросу найдено:" << std::endl;
				forEditing(exact);
			}
			else
				std::cout << "Ничего не найдено..." << std::endl;
			break;
		}
		case 4: {
			int page;
			std::vector<int> exact;
			std::cout << "Введите количество страниц: ";
			std::cin >> page;
			for (int i{ 0 }; i < pages.size(); i++) {
				if (pages[i] == page)
					exact.push_back(i);
			}
			if (exact.size() > 0)
				forEditing(exact);
			else
				std::cout << "Ничего не найдено..." << std::endl;
			break;
		}
		default:
			std::cout << "Некорректное число!" << std::endl;
			break;
		}
	}
};

int main()
{	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);

	std::string path1 = "1TASK.txt";
	std::string path2 = "2TASK.txt";
	std::string path2bin = "2TASKbin.bin";
	std::string path3 = "3TASK.txt";
	std::cout << "TASK 1." << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	task1(path1);
	std::cout << "TASK 2." << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	task2(path2, path2bin);
	std::cout << "TASK 3." << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	std::fstream file;
	file.open(path3, std::ios_base::in | std::ios_base::app);
	try {
		if (!file.is_open())
			throw std::string("File wasnt opened");
	}
	catch (std::string& exception) {
		std::cout << exception << std::endl;
		return 0;
	}
	Catalog cat(file);
	std::cout << "КАТАЛОГ:" << std::endl;
	cat.GetInfo();
	std::cout << "Имеются следующие операции:" << std::endl;
	std::cout << "1 - Показать каталог." << std::endl;
	std::cout << "2 - Добавить новую книгу в каталог." << std::endl;
	std::cout << "3 - Удалить книгу из каталога." << std::endl;
	std::cout << "4 - Найти книгу в каталоге." << std::endl;
	std::cout << "5 - Редактировать позицию каталога." << std::endl;
	std::cout << "0 - ВЫХОД" << std::endl;
	int choice = 1;
	while (choice != 0) {
		std::cout << "Введите число:" << std::endl;
		std::cin >> choice;
		switch (choice) {
		case 0:
			std::cout << "GOODBYE!" << std::endl;
			break;
		case 1:
			cat.GetInfo();
			std::cout << "0 - ВЫХОД" << std::endl;
			break;
		case 2:
			std::cin.ignore();
			cat.AddingNew();
			std::cout << "0 - ВЫХОД" << std::endl;
			break;
		case 3:
			std::cin.ignore();
			cat.Deleting();
			std::cout << "0 - ВЫХОД" << std::endl;
			break;
		case 4:
			std::cin.ignore();
			cat.Finding();
			std::cout << "0 - ВЫХОД" << std::endl;
			break;
		case 5:
			std::cin.ignore();
			cat.Editing();
			std::cout << "0 - ВЫХОД" << std::endl;
			break;
		default:
			std::cout << "Некорректная цифра!" << std::endl;
			std::cout << "0 - ВЫХОД" << std::endl;
			break;
		}
	}
	
	return 0;
}