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
    std::cout << "��� ������� - " << GetArea() << std::endl;
}
std::string Square::GetName() { return "Mr �������"; }
void Square::ShowInfo() {
    std::cout << "� " << GetName() << std::endl;
    CalculateArea();
    std::cout << "��� ������� - " << side << std::endl;
}
void Square::Scale(float scaleFactor) {
    side *= scaleFactor;
    std::cout << "������� �������� ��������� � " << scaleFactor << " ���." << std::endl;
    SetArea(side * side);
}


