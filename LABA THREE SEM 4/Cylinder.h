#pragma once
#include "Shape 2D.h"
#include "Shape3D.h"

class Cylinder : public Shape3D {
private:
    class Circle : public Shape2D {
    private:
        float radius;
    public:
        Circle() : radius(1 + rand() % 15) {
            SetArea(3.14 * radius * radius);
        }
        Circle(float radius) : radius(radius) {
            SetArea(3.14 * radius * radius);
        }
        ~Circle() {}

        void CalculateArea() {
            std::cout << "Моя площадь - " << GetArea() << std::endl;
        }
        std::string GetName() { return "Mr Круг"; }
        void ShowInfo() {
            std::cout << "Я " << GetName() << std::endl;
            CalculateArea();
            std::cout << "Мой радиус - " << radius << std::endl;
        }
        void Scale(float scaleFactor) {
            radius *= scaleFactor;
            std::cout << "Радиус круга увеличен в " << scaleFactor << " раз." << std::endl;
            SetArea(3.14 * radius * radius);
        }
    };
    float height;

public:
    Circle circle;
    Cylinder();
    Cylinder(float height);

    void Scale(float scaleFactor);
    std::string GetName();
    void CalculateVolume();
    void ShowInfo();
};

