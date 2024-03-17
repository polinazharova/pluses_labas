#include "Matrix.h"
    
void multiply(Matrix& first, Matrix& second) {
    Matrix& mult = first * second;
    std::cout << "Получившаяся матрица: " << std::endl;
    mult << "  |  ";
    delete& mult;
}
void minus(Matrix& first, Matrix& second) {
    Matrix& subs = first - second;
    std::cout << "Получившаяся матрица: " << std::endl;
    subs << " | ";
    delete& subs;
}
void elemChanging(Matrix& matrix, unsigned int elem) {
    int choice;
    try {
        matrix[elem];
        std::cout << "Ваш элемент: " << matrix[elem] << std::endl;
        std::cout << "Введите элемент на который вы хотите его заменить: ";
        std::cin >> choice;
        matrix[elem] = choice;
        std::cout << "Ваша новая матрица: " << std::endl;
        matrix << " | ";
    }
    catch (std::string& error) {
        std::cout << error << std::endl;
    }
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
   
    Matrix f(5,5);
    Matrix s(5,5);
    std::cout << "Необходимо заполнить две матрицы элементами." << std::endl;
    f.filling();
    s.filling();
    std::cout << "Ваши матрицы: " << std::endl;
    f << " | ";
    std::cout << std::endl;
    s << " | ";
    int choice{1};
    std::cout << "Над ними доступны следующие операции: " << std::endl;
    while (choice != 0) {
        std::cout << "1 - Сложить матрицы." << std::endl;
        std::cout << "2 - Вычесть матрицы." << std::endl;
        std::cout << "3 - Умножить матрицы." << std::endl;
        std::cout << "4 - Выбрать и изменить элемент в каждой из матриц." << std::endl;
        std::cout << "0 - Выход." << std::endl;
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            Matrix& sum = f + s;
            std::cout << "Получившаяся матрица: " << std::endl;
            sum << "  |  ";
            delete& sum;
            break;
        }
        case 2:
            std::cout << "Из какой матрицы мы будем вычитать другую?" << std::endl;
            std::cout << "1 - из первой вторую." << std::endl;
            std::cout << "2 - из второй первую." << std::endl;
            std::cout << "Ваш выбор: ";
            std::cin >> choice;
            switch (choice) {
            case 1:
                minus(f, s);
                break;
            case 2:
                minus(s, f);
                break;
            default:
                std::cout << "Неверно указано число. По умолчанию из первой матрицы вычтется вторая.";
                minus(f, s);
                break;
            }
            break;

        case 3: {
            std::cout << "Какую матрицу на какую будем умножать?" << std::endl;
            std::cout << "1 - первую на вторую." << std::endl;
            std::cout << "2 - вторую на первую." << std::endl;
            std::cout << "Ваш выбор: ";
            std::cin >> choice;
            switch (choice) {
            case 1:
                multiply(f, s);
                break;
            case 2:
                multiply(s, f);
                break;
            default:
                std::cout << "Неверно указано число. По умолчанию первая матрица умножится на вторую.";
                multiply(f, s);
                break;
            }
            break;
        }
        case 4: {
            std::cout << "Выберите индекс элемента первой матрицы(0 - " << (f.getStr() * f.getRow()) - 1 << "): ";
            unsigned int elem;
            std::cin >> elem;
            elemChanging(f, elem);

            std::cout << "Выберите индекс элемента второй матрицы(0 - " << (s.getStr() * s.getRow()) - 1 << "): ";
            std::cin >> elem;
            elemChanging(s, elem);
            break;
        }
        case 0:
            std::cout << "GOODBYE!" << std::endl;
            break;
        default:
            std::cout << "GOODBYE!" << std::endl;
            choice = 0;
            break;
        }
    }
    return 0;
}


