#pragma once
#include "Shape.h"

class Shape3D : public Shape {
private:
    float volume = 0;
public:
    float GetVolume();
    void SetVolume(float volume);
    bool operator > (Shape3D& other);
    bool operator < (Shape3D& other);
    bool operator == (Shape3D& other);
    virtual void CalculateVolume() = 0;
};
