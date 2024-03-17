#include "Square.h"
#include "TriangularPyramide.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Shape.h"
#include "Shape 2D.h"
#include "Shape3D.h"

//-----------------------------SHAPE3D-------------------------------------------------
float Shape3D::GetVolume() { return volume; }
void Shape3D::SetVolume(float volume) { this->volume = volume; }
bool Shape3D::operator > (Shape3D& other) {
    if (volume > other.volume)
        return true;
    else
        return false;
}
bool Shape3D::operator < (Shape3D& other) {
    if (volume < other.volume)
        return true;
    else
        return false;
}
bool Shape3D::operator == (Shape3D& other) {
    if (volume == other.volume)
        return true;
    else
        return false;
}
//-----------------------------T.PYRAMIDE-------------------------------------------------
TriangularPyramide::TriangularPyramide() : height(1 + rand() % 15) {
    SetVolume(0.333 * height * triangle.GetArea());
}
TriangularPyramide::TriangularPyramide(float height) : height(height) {
    SetVolume(0.333 * height * triangle.GetArea());
}

void TriangularPyramide::CalculateVolume() {
    std::cout << "Мой объем - " << GetVolume() << std::endl;
}
void TriangularPyramide::Scale(float scaleFactor) {
    height *= scaleFactor;
    std::cout << "Высота увеличена в " << scaleFactor << " раз." << std::endl;
    triangle.Scale(scaleFactor);
};
std::string TriangularPyramide::GetName() { return "Mrs Треугольная пирамида"; }
void TriangularPyramide::ShowInfo() {
    std::cout << "Я " << GetName() << std::endl;
    CalculateVolume();
    std::cout << "Площадь моего основания - " << triangle.GetArea() << std::endl;
    std::cout << "Моя высота - " << height << std::endl;
}
//-----------------------------CYLINDER---------------------------------------------------
Cylinder::Cylinder() : height(1 + rand() % 15) {
    SetVolume(circle.GetArea() * height);
}
Cylinder::Cylinder(float height) : height(height) {
    SetVolume(circle.GetArea() * height);
}

void Cylinder::Scale(float scaleFactor) {
    height *= scaleFactor;
    std::cout << "Высота цилиндра увеличена в " << scaleFactor << " раз." << std::endl;
    circle.Scale(scaleFactor);
    SetVolume(circle.GetArea() * height);
};
std::string Cylinder::GetName() { return "Mr Цилиндр"; }
void Cylinder::CalculateVolume() {
    std::cout << "Мой объем - " << GetVolume() << std::endl;
}
void Cylinder::ShowInfo() {
    std::cout << "Я " << GetName() << std::endl;
    CalculateVolume();
    std::cout << "Площадь моего основания - " << circle.GetArea() << std::endl;
    std::cout << "Моя высота - " << height << std::endl;
}
//-----------------------------SPHERE---------------------------------------------------
Sphere::Sphere() : radius(1 + rand() % 20) {
    SetVolume((4 / 3) * 3.14 * pow(radius, 3));
}
Sphere::Sphere(float radius) : radius(radius) {
    SetVolume((4 / 3) * 3.14 * pow(radius, 3));
}

void Sphere::Scale(float scaleFactor) {
    radius *= scaleFactor;
    std::cout << "Радиус сферы увеличен в " << scaleFactor << " раз." << std::endl;
    SetVolume((4 / 3) * 3.14 * pow(radius, 3));
}
std::string Sphere::GetName() { return "Ms Сфера"; }
void Sphere::CalculateVolume() {
    std::cout << "Мой объем - " << GetVolume() << std::endl;
}
void Sphere::ShowInfo() {
    std::cout << "Я " << GetName() << std::endl;
    CalculateVolume();
    std::cout << "Мой радиус - " << radius << std::endl;
}