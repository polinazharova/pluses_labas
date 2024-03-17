#include "Square.h"
#include "TriangularPyramide.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Shape.h"
#include "Shape 2D.h"
#include "Shape3D.h"

//-----------------------------SHAPE2D-------------------------------------------------
float Shape2D::GetArea() { return area; }
void Shape2D::SetArea(float area) { this->area = area; }

bool Shape2D::operator > (Shape2D& other) {
    if (area > other.area)
        return true;
    else
        return false;
}
bool Shape2D::operator < (Shape2D& other) {
    if (area < other.area)
        return true;
    else
        return false;
}
bool Shape2D::operator == (Shape2D& other) {
    if (area == other.area)
        return true;
    else
        return false;
}
//-----------------------------------SQUARE----------------------------------------------
Square::Square() : side(1 + rand() % 15) {
    SetArea(side * side);
}
Square::Square(float side) : side(side) {
    SetArea(side * side);
}
Square::~Square() {}

void Square::CalculateArea() {
    std::cout << "Моя площадь - " << GetArea() << std::endl;
}
std::string Square::GetName() { return "Mr Квадрат"; }
void Square::ShowInfo() {
    std::cout << "Я " << GetName() << std::endl;
    CalculateArea();
    std::cout << "Моя сторона - " << side << std::endl;
}
void Square::Scale(float scaleFactor) {
    side *= scaleFactor;
    std::cout << "Сторона квадрата увеличена в " << scaleFactor << " раз." << std::endl;
    SetArea(side * side);
}


