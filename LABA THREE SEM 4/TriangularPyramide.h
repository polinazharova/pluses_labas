#pragma once
#include "Shape 2D.h"
#include "Shape3D.h"

class TriangularPyramide : public Shape3D {
private:
    class Triangle : public Shape2D {
    private:
        float base;
        float height;
    public:
        Triangle() : base(1 + rand() % 10), height(1 + rand() % 10) {
            SetArea(0.5 * base * height);
        }
        Triangle(float base, float height) : base(base), height(height) {
            SetArea(0.5 * base * height);
        }
        ~Triangle() {}

        void CalculateArea() {
            std::cout << "Моя площадь - " << GetArea() << std::endl;
        }
        std::string GetName() { return "Mr Треугольник"; }
        void ShowInfo() {
            std::cout << "Я " << GetName() << std::endl;
            CalculateArea();
            std::cout << "Мое основание - " << base << std::endl;
            std::cout << "Моя высота - " << height << std::endl;
        }
        void Scale(float scaleFactor) {
            base *= scaleFactor;
            height *= scaleFactor;
            std::cout << "Элементы треугольника увеличены в " << scaleFactor << " раз." << std::endl;
            SetArea(0.5 * base * height);
        }
    };
    float height;
public:
    Triangle triangle;
    TriangularPyramide();
    TriangularPyramide(float height);

    void CalculateVolume();
    void Scale(float scaleFactor);
    std::string GetName();
    void ShowInfo();
};
