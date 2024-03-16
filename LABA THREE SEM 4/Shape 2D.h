#pragma once
#include "Shape.h"

class Shape2D : public Shape {
private:
    float area = 0;
public:
    float GetArea() { return area; }
    void SetArea(float area) { this->area = area; }

    bool operator > (Shape2D& other) {
        if (area > other.area)
            return true;
        else
            return false;
    }
    bool operator < (Shape2D& other) {
        if (area < other.area)
            return true;
        else
            return false;
    }
    bool operator == (Shape2D& other) {
        if (area == other.area)
            return true;
        else
            return false;
    }
    virtual void CalculateArea() = 0;
};
