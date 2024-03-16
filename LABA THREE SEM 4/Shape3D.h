#pragma once
#include "Shape.h"

class Shape3D : public Shape {
private:
    float volume = 0;
public:
    float GetVolume() { return volume; }
    void SetVolume(float volume) { this->volume = volume; }
    bool operator > (Shape3D& other) {
        if (volume > other.volume)
            return true;
        else
            return false;
    }
    bool operator < (Shape3D& other) {
        if (volume < other.volume)
            return true;
        else
            return false;
    }
    bool operator == (Shape3D& other) {
        if (volume == other.volume)
            return true;
        else
            return false;
    }
    virtual void CalculateVolume() = 0;
};
