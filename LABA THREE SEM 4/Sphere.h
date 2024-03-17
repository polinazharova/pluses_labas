#pragma once
#include "Shape3D.h"

class Sphere : public Shape3D {
private:
    float radius;
public:
    Sphere();
    Sphere(float radius);

    void Scale(float scaleFactor);
    std::string GetName();
    void CalculateVolume();
    void ShowInfo();
};