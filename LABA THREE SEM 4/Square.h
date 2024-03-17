#pragma once
#include "Shape 2D.h"

class Square : public Shape2D {
private:
    float side;
public:
    Square();
    Square(float side);
    ~Square();

    void CalculateArea();
    std::string GetName();
    void ShowInfo();
    void Scale(float scaleFactor);
};