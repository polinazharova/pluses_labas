#pragma once
#include "Shape3D.h"

class Sphere : public Shape3D {
private:
    float radius;
public:
    Sphere() : radius(30) {
        SetVolume((4 / 3) * 3.14 * pow(radius, 3));
    }
    Sphere(float radius) : radius(radius) {
        SetVolume((4 / 3) * 3.14 * pow(radius, 3));
    }
    ~Sphere() {}
    void Scale(float scaleFactor) {
        radius *= scaleFactor;
        std::cout << "������ ����� �������� � " << scaleFactor << " ���." << std::endl;
        SetVolume((4 / 3) * 3.14 * pow(radius, 3));
    }
    std::string GetName() { return "Ms �����"; }
    void CalculateVolume() {
        std::cout << "��� ����� - " << GetVolume() << std::endl;
    }
    void ShowInfo() {
        std::cout << "� " << GetName() << std::endl;
        CalculateVolume();
        std::cout << "��� ������ - " << radius << std::endl;
    }
};