#pragma once
#include "Shape.h"

class Shape2D : public Shape {
private:
    float area = 0;
public:
    float GetArea();
    void SetArea(float area);

    bool operator > (Shape2D& other);
    bool operator < (Shape2D& other);
    bool operator == (Shape2D& other);
    virtual void CalculateArea() = 0;
};
