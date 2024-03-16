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
        std::cout << "��� ������� - " << GetArea() << std::endl;
    }
    std::string GetName() { return "Mr �������"; }
    void ShowInfo() {
        std::cout << "� " << GetName() << std::endl;
        CalculateArea();
        std::cout << "��� ������� - " << side << std::endl;
    }
    void Scale(float scaleFactor) {
        side *= scaleFactor;
        std::cout << "������� �������� ��������� � " << scaleFactor << " ���." << std::endl;
        SetArea(side * side);
    }
};