#include "Matrix.h"

Matrix::Matrix() : n(3), m(3)
{
    for (int i{ 0 }; i < n; i++)
        data[i] = new int[m];
}

Matrix::Matrix(unsigned int n, unsigned int m) : n(n), m(m)
{
    for (int i{ 0 }; i < n; i++)
        data[i] = new int[m];
}

Matrix::~Matrix() {
    std::cout << "Destruction." << std::endl;
    for (int i{ 0 }; i < n; i++) {
        delete[] data[i];
        data[i] = nullptr;
    }
    delete[] data;
    data = nullptr;
}

unsigned int Matrix::getStr() { return n; }
unsigned int Matrix::getRow() { return m; }

void Matrix::filling() {
    int choice;
    std::cout << "Choose what to fill the matrix with: " << std::endl;
    std::cout << "1 - RANDOM FILLING." << std::endl;
    std::cout << "2 - UNIT FILLING." << std::endl;
    std::cout << "3 - CUSTOM FILLING." << std::endl;
    std::cout << "Your choice is: ";
    std::cin >> choice;
    switch (choice) {
    case 1:
        for (int i{ 0 }; i < n; i++) {
            for (int j{ 0 }; j < m; j++)
                data[i][j] = rand() % 10;
        }
        break;
    case 2:
        for (int i{ 0 }; i < n; i++) {
            for (int j{ 0 }; j < m; j++) {
                if (j == i)
                    data[i][j] = 1;
                else
                    data[i][j] = 0;

            }
        }
        break;
    case 3: {
        int element;
        for (int i{ 0 }; i < n; i++) {
            for (int j{ 0 }; j < m; j++) {
                std::cout << "Put in the element of " << i + 1 << " row " << j + 1 << " column: ";
                std::cin >> element;
                data[i][j] = element;
            }
        }
        break;
    }

    default:
        std::cout << "There was no such choice. The numbers will be randomized." << std::endl;
        for (int i{ 0 }; i < n; i++) {
            for (int j{ 0 }; j < m; j++)
                data[i][j] = rand() % 10;
        }
        break;
    }
}

int& Matrix::operator [] (unsigned int num) {
    if (num < (n * m) && num >= 0)
        return data[num / m][num % m];
    else
        throw std::string{ "ERROR! INDEX IS NOT EXISTED!" };
}

void Matrix::operator << (std::string gap) {
    for (int i{ 0 }; i < n; i++) {
        for (int j{ 0 }; j < m; j++)
            std::cout << data[i][j] << gap;
        std::cout << std::endl;
    }
}

Matrix& Matrix::operator + (const Matrix& other) {
    if (n != other.n || m != other.m)
        std::cout << "CANNOT BE DONE. MATRIXES STRINGS OR COLLUMNS AREN'T EQUAL!" << std::endl;
    else {
        Matrix* demo = new Matrix(n, m);
        for (int i{ 0 }; i < n; i++) {
            for (int j{ 0 }; j < m; j++)
                (*demo).data[i][j] = data[i][j] + other.data[i][j];
        }
        return *demo;
    }
}

Matrix& Matrix::operator - (const Matrix& other) {
    if (n != other.n || m != other.m)
        std::cout << "CANNOT BE DONE. MATRIXES STRINGS OR COLLUMNS AREN'T EQUAL!" << std::endl;
    else {
        Matrix* demo = new Matrix(n, m);
        for (int i{ 0 }; i < n; i++) {
            for (int j{ 0 }; j < m; j++)
                (*demo).data[i][j] = data[i][j] - other.data[i][j];
        }
        return *demo;
    }
}

Matrix& Matrix::operator * (Matrix& other) {
    if (m != other.n)
        std::cout << "CANNOT BE DONE!" << std::endl;
    else {
        Matrix* demo = new Matrix(n, other.m);
        unsigned int temp{ 0 };
        for (int i{ 0 }; i < m; i++) {
            for (int j{ 0 }; j < m; j++) {
                for (int k{ 0 }; k < m; k++) {
                    temp += data[j][k] * other.data[k][i];
                }
                (*demo).data[j][i] = temp;
                temp = 0;
            }
        }
        return *demo;
    }
}

void Matrix::operator += (Matrix& other) {
    if (n != other.n || m != other.m)
        std::cout << "CANNOT BE DONE. MATRIXES STRINGS OR COLLUMNS AREN'T EQUAL!" << std::endl;
    else {
        for (int i{ 0 }; i < n; i++) {
            for (int j{ 0 }; j < m; j++)
                data[i][j] += other.data[i][j];
        }
    }
}

void Matrix::operator -= (Matrix& other) {
    if (n != other.n || m != other.m)
        std::cout << "CANNOT BE DONE. MATRIXES STRINGS OR COLLUMNS AREN'T EQUAL!" << std::endl;
    else {
        for (int i{ 0 }; i < n; i++) {
            for (int j{ 0 }; j < m; j++)
                data[i][j] -= other.data[i][j];
        }
    }
}

bool Matrix::operator == (Matrix& other) {
    if (n != other.n || m != other.m)
        std::cout << "CANNOT BE DONE. MATRIXES STRINGS OR COLLUMNS AREN'T EQUAL!" << std::endl;
    else {
        for (int i{ 0 }; i < n; i++) {
            for (int j{ 0 }; j < m; j++) {
                if (data[i][j] != other.data[i][j])
                    return false;
            }
        }
        return true;
    }
}

bool Matrix::operator != (Matrix& other) {
    if (n != other.n || m != other.m)
        std::cout << "CANNOT BE DONE. MATRIXES STRINGS OR COLLUMNS AREN'T EQUAL!" << std::endl;
    else {
        for (int i{ 0 }; i < n; i++) {
            for (int j{ 0 }; j < m; j++) {
                if (data[i][j] != other.data[i][j])
                    return true;
            }
        }
        return false;
    }
}