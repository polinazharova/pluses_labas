#pragma once
#include <iostream>

class Matrix {
private:
    unsigned int m;
    unsigned int n;
    int** data = new int* [n];

public:

    Matrix();

    Matrix(unsigned int n, unsigned int m);

    ~Matrix();

    unsigned int getStr();
    unsigned int getRow();

    friend std::ostream& operator << (std::ostream& os, Matrix& matrix);
    friend std::istream& operator >> (std::istream& is, Matrix& matrix);

    void filling();

    int& operator [] (unsigned int num);

    Matrix& operator + (const Matrix& other);

    Matrix& operator - (const Matrix& other);

    Matrix& operator * (Matrix& other);

    void operator += (Matrix& other);

    void operator -= (Matrix& other);

    bool operator == (Matrix& other);

    bool operator != (Matrix& other);

    friend void binaryWriting(std::fstream& file, Matrix& matrix);
};