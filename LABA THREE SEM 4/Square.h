#pragma once
#include "Shape 2D.h"

class Square : public Shape2D {
private:
    float side;
public:
    Square() : side(3) {
        SetArea(side * side);
    }
    Square(float side) : side(side) {
        SetArea(side * side);
    }
    ~Square() {}

    void CalculateArea() {
        std::cout << "Моя площадь - " << GetArea() << std::endl;
    }
    std::string GetName() { return "Mr Квадрат"; }
    void ShowInfo() {
        std::cout << "Я " << GetName() << std::endl;
        CalculateArea();
        std::cout << "Моя сторона - " << side << std::endl;
    }
    void Scale(float scaleFactor) {
        side *= scaleFactor;
        std::cout << "Сторона квадрата увеличена в " << scaleFactor << " раз." << std::endl;
        SetArea(side * side);
    }
};