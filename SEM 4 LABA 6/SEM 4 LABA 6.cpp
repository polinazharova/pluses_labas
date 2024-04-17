#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

int vector_creation(std::vector <int>& vec, const std::string& filename) {
    std::fstream file;

    std::cout << "РАБОТА С ФАЙЛОМ:" << std::endl;
    std::cout << "1 - считать в вектор (если есть данные в файле)." << std::endl;
    std::cout << "2 - записать в файл данные и считать их оттуда в вектор." << std::endl;
    for (int errors{ 2 }; errors >= 0; errors--) {
        std::cout << "Введите цифру: ";
        std::string tmp;
        int choice;
        std::getline(std::cin, tmp);

        try {
            choice = std::stoi(tmp);
        }
        catch (std::exception& ex) {
            choice = 0;
        }

        switch (choice) {
        case 1: {
            file.open(filename, std::ios_base::in);

            try {
                if (!file.is_open())
                    throw std::exception("File was not opened!");
            }
            catch (std::exception& ex) {
                std::cout << ex.what() << std::endl;
                return 0;
            }

            std::string tmp;
            while (std::getline(file, tmp)) {
                std::string tmp1;
                for (int i{ 0 }; i < tmp.size(); i++) {
                    if (tmp[i] >= 48 && tmp[i] <= 57) 
                        tmp1 += tmp[i];
                    if (tmp[i] < 48 || tmp[i] > 57 || i == tmp.size() - 1) {
                        int num;
                        try {
                            num = std::stoi(tmp1);
                            tmp1 = "";
                            vec.push_back(num);
                        }
                        catch (std::exception& ex) {
                            std::cout << std::endl << "The number is invalid. It will be randomized" << std::endl;
                            num = 1 + rand() % 30;
                            vec.push_back(num);
                            tmp1 = "";
                        }
                    }
                }
            }

            if (vec.size() == 0) {
                std::cout << "В файле ничего нет..." << std::endl;
                return 0;
            }

            errors = 0;
            break;
        }
        case 2: {
            file.open(filename, std::ios_base::out);
            try {
                if (!file.is_open())
                    throw std::string("File was not opened!");
            }
            catch (std::string& ex) {
                std::cout << ex << std::endl;
                return 0;
            }

            std::cout << "Введите размер вектора: ";
            std::string tmp;
            getline(std::cin, tmp);
            int size;

            try {
                size = std::stoi(tmp);
                if (size <= 0)
                    throw std::string("The size must be > 0!");
            }
            catch (std::exception& ex) {
                std::cout << std::endl << "The size must be a number. It will be randomized" << std::endl;
                size = 1 + rand() % 15;
                std::cout << "The size is " << size << std::endl;
            }
            catch (std::string& ex) {
                std::cout << std::endl << ex << " It will be randomized" << std::endl;
                size = 1 + rand() % 15;
                std::cout << "The size is " << size << std::endl;
            }

            for (int i{ 0 }; i < size; i++) {
                int num = rand() % 30;
                file << num << " ";
            }

            file.close();

            file.open(filename, std::ios_base::in);
            try {
                if (!file.is_open())
                    throw std::string("File was not opened!");
            }
            catch (std::string& ex) {
                std::cout << ex << std::endl;
                return 0;
            }
            while (!file.eof()) {
                int num;
                file >> num;
                vec.push_back(num);
            }
            vec.pop_back();

            errors = 0;
            break;
        }
        default:
            std::cout << "Такого варианта не было..." << std::endl;
            std::cout << "Осталось попыток: " << errors << std::endl << std::endl;
            if (errors == 0) {
                std::cout << "Попытки исчерпаны. По умолчанию выбран вариант 2" << std::endl;
                file.open(filename, std::ios_base::out);
                try {
                    if (!file.is_open())
                        throw std::string("File was not opened!");
                }
                catch (std::string& ex) {
                    std::cout << ex << std::endl;
                    return 0;
                }

                std::cout << "Введите размер вектора: ";
                std::string tmp;
 
                getline(std::cin, tmp);
                int size;
                try {
                    size = std::stoi(tmp);
                    if (size <= 0)
                        throw std::string("The size must be > 0!");
                }
                catch (std::exception& ex) {
                    std::cout << std::endl << "The size must be a number. It will be randomized" << std::endl;
                    size = 1 + rand() % 15;
                    std::cout << "The size is " << size << std::endl;
                }
                catch (std::string& ex) {
                    std::cout << std::endl << ex << " It will be randomized" << std::endl;
                    size = 1 + rand() % 15;
                    std::cout << "The size is " << size << std::endl;
                }

                for (int i{ 0 }; i < size; i++) {
                    int num = rand() % 30;
                    file << num << " ";
                }

                file.close();

                file.open(filename, std::ios_base::in);
                try {
                    if (!file.is_open())
                        throw std::string("File was not opened!");
                }
                catch (std::string& ex) {
                    std::cout << ex << std::endl;
                    return 0;
                }
                while (!file.eof()) {
                    int num;
                    file >> num;
                    vec.push_back(num);
                }
                vec.pop_back();
            }
            break;
        }
    }

    file.close();
    return 1;
}

void changing(std::vector <int>& vec) {
    std::cout << std::endl << "===================================" << std::endl;
    std::cout << "YOUR VECTOR IS:" << std::endl;
    std::cout << "[ ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "]" << std::endl;

    std::reverse(vec.begin(), vec.end());
    std::cout << "===================================" << std::endl;
    std::cout << "REVERSED:" << std::endl;
    std::cout << "[ ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "]" << std::endl;

    std::cout << "===================================" << std::endl;
    std::cout << "MIN ELEMENT - " << *std::min_element(vec.begin(), vec.end()) << std::endl;
    std::cout << "MAX ELEMENT - " << *std::max_element(vec.begin(), vec.end()) << std::endl;

    vec.erase(std::remove_if(vec.begin(), vec.end(), [](const int& p) {
        return p % 2 == 0;
        }), vec.end());
    std::cout << "===================================" << std::endl;
    std::cout << "WITHOUT EVEN ELEMENTS:" << std::endl;
    std::cout << "[ ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "]" << std::endl << std::endl;

    std::cout << "Which way the vector should be sorted?" << std::endl;
    std::cout << "1 - Ascending order" << std::endl;
    std::cout << "2 - Descinding order" << std::endl;
    std::cout << "Put in your choice: " << std::endl;
    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::sort(vec.begin(), vec.end());
        break;
    case 2:
        std::sort(vec.rbegin(), vec.rend());
        break;
    default:
        std::cout << "The vector will be sorted in ascending order" << std::endl;
        std::sort(vec.begin(), vec.end());
        std::cout << std::endl;
        break;
    }

    std::cout << "===================================" << std::endl;
    std::cout << "SORTED:" << std::endl;
    std::cout << "[ ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "]" << std::endl;

    std::string tmp;
    std::cout << "===================================" << std::endl;
    std::cout << "Введите элемент для добавления в вектор: ";
    std::cin.ignore();
    std::getline(std::cin, tmp);
    int elem;

    try {
        /*if (typeid(elem).name() != int)
            throw std::exception("Wrong data type!");*/
       /* std::cout << typeid(elem).name() << std::endl;*/
        elem = std::stoi(tmp);
    }
    catch (std::exception& ex) {
        std::cout << std::endl << "Invalid number. The element will be randomized" << std::endl;
        elem = rand() % 30;
        std::cout << "The element is " << elem << std::endl << std::endl;
    }

    if (choice != 2) {
        vec.insert(std::lower_bound(vec.begin(), vec.end(), elem), elem);
        std::cout << "WITH ADDED ELEMENT:" << std::endl;
        std::cout << "[ ";
        std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << "]" << std::endl;
    }
    else {
        vec.insert(std::lower_bound(vec.rbegin(), vec.rend(), elem).base(), elem);
        std::cout << "WITH ADDED ELEMENT:" << std::endl;
        std::cout << "[ ";
        std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << "]" << std::endl;
    }

    std::cout << "===================================" << std::endl;
    std::cout << "INDEX OF THE ELEMENT - " << std::distance(vec.begin(), std::find(vec.begin(), vec.end(), elem)) << std::endl;

    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    std::cout << "===================================" << std::endl;
    std::cout << "ONLY UNIQUE ELEMENTS:" << std::endl;
    std::cout << "[ ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "]" << std::endl;

    vec.clear();
    std::cout << std::endl;
}


int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    std::string filename = "vector.txt";
    std::vector <int> vec;

    if (vector_creation(vec, filename))
        changing(vec);
    else
        return -1;
    
    std::cout << "Хотите ли вы еще создать вектор?" << std::endl;
    std::cout << "1 - да." << std::endl;
    std::cout << "Любая другая клавиша - ВЫХОД." << std::endl;
    std::cout << "Ваш выбор: ";

    std::string str;
    std::getline(std::cin, str);

    while (str == "1") {
        if (vector_creation(vec, filename))
            changing(vec);
        else
            return -1;

        std::cout << "Хотите ли вы еще создать вектор?" << std::endl;
        std::cout << "1 - да." << std::endl;
        std::cout << "Любая другая клавиша - ВЫХОД." << std::endl;
        std::cout << "Ваш выбор: ";
        std::getline(std::cin, str);
    }

    std::cout << std::endl << "GOODBYE!" << std::endl;
    return 0;
}


