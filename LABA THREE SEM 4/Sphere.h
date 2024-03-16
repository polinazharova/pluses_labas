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
        std::cout << "Радиус сферы увеличен в " << scaleFactor << " раз." << std::endl;
        SetVolume((4 / 3) * 3.14 * pow(radius, 3));
    }
    std::string GetName() { return "Ms Сфера"; }
    void CalculateVolume() {
        std::cout << "Мой объем - " << GetVolume() << std::endl;
    }
    void ShowInfo() {
        std::cout << "Я " << GetName() << std::endl;
        CalculateVolume();
        std::cout << "Мой радиус - " << radius << std::endl;
    }
};