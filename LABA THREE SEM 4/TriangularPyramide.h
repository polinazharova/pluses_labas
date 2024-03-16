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
        Triangle() : base(10), height(5) {
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
    TriangularPyramide() : height(10) {
        SetVolume(0.333 * height * triangle.GetArea());
    }
    TriangularPyramide(float height) : height(height) {
        SetVolume(0.333 * height * triangle.GetArea());
    }
    ~TriangularPyramide() {}

    void CalculateVolume() {
        std::cout << "Мой объем - " << GetVolume() << std::endl;
    }
    void Scale(float scaleFactor) {
        height *= scaleFactor;
        std::cout << "Высота увеличена в " << scaleFactor << " раз." << std::endl;
        triangle.Scale(scaleFactor);
    };
    virtual std::string GetName() { return "Mrs Треугольная пирамида"; }
    void ShowInfo() {
        std::cout << "Я " << GetName() << std::endl;
        CalculateVolume();
        std::cout << "Площадь моего основания - " << triangle.GetArea() << std::endl;
        std::cout << "Моя высота - " << height << std::endl;
    }
};
