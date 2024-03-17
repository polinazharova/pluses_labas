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

    void filling();

    int& operator [] (unsigned int num);

    void operator << (std::string gap);

    Matrix& operator + (const Matrix& other);


    Matrix& operator - (const Matrix& other);

    Matrix& operator * (Matrix& other);

    void operator += (Matrix& other);

    void operator -= (Matrix& other);

    bool operator == (Matrix& other);

    bool operator != (Matrix& other);
};