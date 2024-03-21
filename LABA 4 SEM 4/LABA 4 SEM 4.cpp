#include "Matrix.h"

template <typename T>
unsigned int notFirstMax(T* array, unsigned int size) {
    std::cout << "Массив: " << std::endl;
    for (int i{ 0 }; i < size; i++) {
        array[i] = (T)(rand() % 210) / 21;
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    if (size <= 1) {
        std::cout << "There is no second maximum!" << std::endl;
        return 0;
    }
    else {
        unsigned int firstPosition = 0;
        unsigned int secondPosition = 0;
        for (unsigned int i{ 1 }; i < size; i++) {
            if (array[i] > array[firstPosition]) {
                secondPosition = firstPosition;
                firstPosition = i;
            }
            if (array[i] < array[firstPosition] && array[i] > array[secondPosition]) {
                secondPosition = i;
            }
            
        }
        return secondPosition;
    }

}

template <typename T>
class Vector {
private:
    T* data = new T[3];
public:
    Vector() {
        for (int i{ 0 }; i < 3; i++) {
            data[i] = (T)(rand() % 210) / 21;
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    ~Vector() {
        delete[] data;
    }
    T operator * (const Vector& other) {
        T sum{0};
        for (int i{ 0 }; i < 3; i++) 
            sum += data[i] * other.data[i];
        return sum;
    }
    void operator & (const Vector& other) {
        std::cout << "i(" << (data[1] * other.data[2]) - (data[2] * other.data[1]) << ") + ";
        std::cout << "j(" << (data[2] * other.data[0]) - (data[0] * other.data[2]) << ") + ";
        std::cout << "k(" << (data[0] * other.data[1]) - (data[1] * other.data[0]) << ")" << std::endl;
    }
};

int main()
{   
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    std::cout << "1. Второй максимум в массиве: " << std::endl;
    std::cout << "Введите размер массива: " << std::endl;
    int N;
    std::cin >> N;
    std::cout << "Выберите тип данных в массиве: " << std::endl;
    std::cout << "1 - int" << std::endl;
    std::cout << "2 - float" << std::endl;
    std::cout << "3 - double" << std::endl;
    int choice;
    std::cin >> choice;
    switch (choice) {
    case 1: {
        int* array = new int[N];
        std::cout << "Индекс второго максимума: " << notFirstMax(array, N) << std::endl;
        delete[] array;
        break;
    }
    case 2: {
        float* array = new float[N];
        std::cout << "Индекс второго максимума: " << notFirstMax(array, N) << std::endl;
        delete[] array;
        break;
    }
    case 3: {
        double* array = new double[N];
        std::cout << "Индекс второго максимума: " << notFirstMax(array, N) << std::endl;
        delete[] array;
        break;
    }
    default:
        std::cout << "WRONG!" << std::endl;
        break;
    }
    
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "2. Матрицы: " << std::endl;
    std::cout << "Выберите тип данных в матрице: " << std::endl;
    std::cout << "1 - int" << std::endl;
    std::cout << "2 - float" << std::endl;
    std::cout << "3 - double" << std::endl;
    choice;
    std::cin >> choice;
    switch (choice) {
    case 1: {
        Matrix<int> one;
        Matrix<int> two;
        one.filling();
        two.filling();
        std::cout << "THE FIRST MATRIX: " << std::endl;
        one << "  |  ";
        std::cout << "THE SECOND MATRIX: " << std::endl;
        two << "  |  ";
        std::cout << std::endl;
        break;
    }
    case 2: {
        Matrix<float> one;
        Matrix<float> two;
        one.filling();
        two.filling();
        std::cout << "THE FIRST MATRIX: " << std::endl;
        one << "  |  ";
        std::cout << "THE SECOND MATRIX: " << std::endl;
        two << "  |  ";
        std::cout << std::endl;
        break;
    }
    case 3: {
        Matrix<double> one;
        Matrix<double> two;
        one.filling();
        two.filling();
        std::cout << "THE FIRST MATRIX: " << std::endl;
        one << "  |  ";
        std::cout << "THE SECOND MATRIX: " << std::endl;
        two << "  |  ";
        std::cout << std::endl;
        break;
    }
    default:
        std::cout << "WRONG!" << std::endl;
        break;
    }
    
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "3. Векторы: " << std::endl;
    std::cout << "Выберите тип данных в векторе: " << std::endl;
    std::cout << "1 - int" << std::endl;
    std::cout << "2 - float" << std::endl;
    std::cout << "3 - double" << std::endl;
    choice;
    std::cin >> choice;
    switch (choice) {
    case 1: {
        std::cout << "Первый вектор: " << std::endl;
        Vector<int> one;
        std::cout << "Второй вектор: " << std::endl;
        Vector<int> two;
        std::cout << "Скалярное произведение: " << one * two << std::endl;
        one& two;
        break;
    }
    case 2: {
        std::cout << "Первый вектор: " << std::endl;
        Vector<float> one;
        std::cout << "Второй вектор: " << std::endl;
        Vector<float> two;
        std::cout << "Скалярное произведение: " << one * two << std::endl;
        one& two;
        break;
    }
    case 3: {
        std::cout << "Первый вектор: " << std::endl;
        Vector<double> one;
        std::cout << "Второй вектор: " << std::endl;
        Vector<double> two;
        std::cout << "Скалярное произведение: " << one * two << std::endl;
        one& two;
        break;
    }
    default:
        std::cout << "WRONG NUMBER!" << std::endl;
        break;
    }
    return 0;
}

