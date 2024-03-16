#pragma once
#include "Shape 2D.h"
#include "Shape3D.h"

class Cylinder : public Shape3D {
private:
    class Circle : public Shape2D {
    private:
        float radius;
    public:
        Circle() : radius(7) {
            SetArea(3.14 * radius * radius);
        }
        Circle(float radius) : radius(radius) {
            SetArea(3.14 * radius * radius);
        }
        ~Circle() {}

        void CalculateArea() {
            std::cout << "��� ������� - " << GetArea() << std::endl;
        }
        std::string GetName() { return "Mr ����"; }
        void ShowInfo() {
            std::cout << "� " << GetName() << std::endl;
            CalculateArea();
            std::cout << "��� ������ - " << radius << std::endl;
        }
        void Scale(float scaleFactor) {
            radius *= scaleFactor;
            std::cout << "������ ����� �������� � " << scaleFactor << " ���." << std::endl;
            SetArea(3.14 * radius * radius);
        }
    };
    float height;

public:
    Circle circle;
    Cylinder() : height(10) {
        SetVolume(circle.GetArea() * height);
    }
    Cylinder(float height) : height(height) {
        SetVolume(circle.GetArea() * height);
    }
    ~Cylinder() {}

    void Scale(float scaleFactor) {
        height *= scaleFactor;
        std::cout << "������ �������� ��������� � " << scaleFactor << " ���." << std::endl;
        circle.Scale(scaleFactor);
        SetVolume(circle.GetArea() * height);
    };
    std::string GetName() { return "Mr �������"; }
    void CalculateVolume() {
        std::cout << "��� ����� - " << GetVolume() << std::endl;
    }
    void ShowInfo() {
        std::cout << "� " << GetName() << std::endl;
        CalculateVolume();
        std::cout << "������� ����� ��������� - " << circle.GetArea() << std::endl;
        std::cout << "��� ������ - " << height << std::endl;
    }
};

