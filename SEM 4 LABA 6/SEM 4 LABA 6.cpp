#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


int vector_creation(std::vector <int>& vec) {
    std::fstream file;

    int choice;
    std::cout << "РАБОТА С ФАЙЛОМ:" << std::endl;
    std::cout << "1 - считать в вектор (если есть данные в файле)." << std::endl;
    std::cout << "2 - записать в файл данные и считать их оттуда в вектор." << std::endl;
    std::cout << "Введите цифру: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        file.open("vector.txt", std::ios_base::in);

        try {
            if (!file.is_open())
                throw std::string("File was not opened!");
        }
        catch (std::string& ex) {
            std::cout << ex << std::endl;
            abort();
            return 0;
        }

        while (!file.eof()) {
            int num;
            file >> num;
            vec.push_back(num);
        }
        vec.pop_back();

        if (vec.size() == 0) {
            std::cout << "В файле ничего нет..." << std::endl;
            abort();
        }
        break;
    case 2:
        file.open("vector.txt", std::ios_base::out | std::ios_base::in);
        try {
            if (!file.is_open())
                throw std::string("File was not opened!");
        }
        catch (std::string& ex) {
            std::cout << ex << std::endl;
            abort();
            return 0;
        }

        std::cout << "Введите размер вектора: ";
        unsigned int size;
        std::cin >> size;
        for (int i{ 0 }; i < size; i++) {
            int num = rand() % 30;
            file << num << " ";
        }

        file.seekg(0);
        while (!file.eof()) {
            int num;
            file >> num;
            vec.push_back(num);
        }
        vec.pop_back();
        break;
    default:
        std::cout << "Такого варианта не было..." << std::endl;
        abort();
        break;
    }

    /*int errors{ 0 };*/
    file.close();
    return 1;
}

void show(std::vector <int>& vec) {
    for (int& elem : vec)
        std::cout << elem << " ";
    std::cout << std::endl;
}

void changing(std::vector <int>& vec) {
    std::cout << std::endl << "===================================" << std::endl;
    std::cout << "YOUR VECTOR IS:" << std::endl;
    show(vec);

    std::reverse(vec.begin(), vec.end());
    std::cout << "===================================" << std::endl;
    std::cout << "REVERSED:" << std::endl;
    show(vec);

    std::cout << "===================================" << std::endl;
    std::cout << "MIN ELEMENT - " << *std::min_element(vec.begin(), vec.end()) << std::endl;
    std::cout << "MAX ELEMENT - " << *std::max_element(vec.begin(), vec.end()) << std::endl;

    vec.erase(std::remove_if(vec.begin(), vec.end(), [](const int& p) {
        return p % 2 == 0;
        }), vec.end());
    std::cout << "===================================" << std::endl;
    std::cout << "WITHOUT EVEN ELEMENTS:" << std::endl;
    show(vec);

    std::sort(vec.begin(), vec.end());
    std::cout << "===================================" << std::endl;
    std::cout << "SORTED:" << std::endl;
    show(vec);

    int elem;
    std::cout << "===================================" << std::endl;
    std::cout << "Введите элемент для добавления в вектор: ";
    std::cin >> elem;
    vec.insert(std::lower_bound(vec.begin(), vec.end(), elem), elem);
    std::cout << "WITH ADDED ELEMENT:" << std::endl;
    show(vec);

    std::cout << "===================================" << std::endl;
    std::cout << "INDEX OF THE ELEMENT - " << std::distance(vec.begin(), std::find(vec.begin(), vec.end(), elem)) << std::endl;

    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    std::cout << "===================================" << std::endl;
    std::cout << "ONLY UNIQUE ELEMENTS:" << std::endl;
    show(vec);

    vec.clear();
    std::cout << std::endl;
}


int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    std::vector <int> vec;
    vector_creation(vec);
    changing(vec);

    std::cout << "Хотите ли вы еще создать вектор?" << std::endl;
    std::cout << "1 - да." << std::endl;
    std::cout << "Любая другая клавиша - ВЫХОД." << std::endl;
    std::cout << "Ваш выбор: ";
    int choice;
    std::cin >> choice;
    while (choice == 1) {
        vector_creation(vec);
        changing(vec);

        std::cout << "Хотите ли вы еще создать вектор?" << std::endl;
        std::cout << "1 - да." << std::endl;
        std::cout << "Любая другая клавиша - ВЫХОД." << std::endl;
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
    }

    std::cout << std::endl << "GOODBYE!" << std::endl;
    return 0;
}


