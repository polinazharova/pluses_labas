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
            std::cout << "��� ������� - " << GetArea() << std::endl;
        }
        std::string GetName() { return "Mr �����������"; }
        void ShowInfo() {
            std::cout << "� " << GetName() << std::endl;
            CalculateArea();
            std::cout << "��� ��������� - " << base << std::endl;
            std::cout << "��� ������ - " << height << std::endl;
        }
        void Scale(float scaleFactor) {
            base *= scaleFactor;
            height *= scaleFactor;
            std::cout << "�������� ������������ ��������� � " << scaleFactor << " ���." << std::endl;
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
        std::cout << "��� ����� - " << GetVolume() << std::endl;
    }
    void Scale(float scaleFactor) {
        height *= scaleFactor;
        std::cout << "������ ��������� � " << scaleFactor << " ���." << std::endl;
        triangle.Scale(scaleFactor);
    };
    virtual std::string GetName() { return "Mrs ����������� ��������"; }
    void ShowInfo() {
        std::cout << "� " << GetName() << std::endl;
        CalculateVolume();
        std::cout << "������� ����� ��������� - " << triangle.GetArea() << std::endl;
        std::cout << "��� ������ - " << height << std::endl;
    }
};
