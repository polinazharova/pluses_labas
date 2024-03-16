#include "Square.h"
#include "TriangularPyramide.h"
#include "Sphere.h"
#include "Cylinder.h"

void comparison2D(Shape2D& first, Shape2D& second) {
    unsigned int money;
    std::cout << first.GetName() << " VS " << second.GetName() << std::endl;
    first.ShowInfo();
    second.ShowInfo();
    if (first > second) {
        money = 0 + rand() % 4;
        if (money == 3) {
            std::cout << "OOOPS...Кажется бой подкупили..." << std::endl;
            second.Scale(100000);
            second.ShowInfo();
            std::cout << second.GetName() << " WON!" << std::endl;
            std::cout << first.GetName() << " LOST!" << std::endl;
        }
        else {
            std::cout << first.GetName() << " WON!" << std::endl;
            std::cout << second.GetName() << " LOST!" << std::endl;
        }
    }
    else if (first == second)
        std::cout << "THE FRIENDSHIP WON!" << std::endl;
    else {
        std::cout << second.GetName() << " WON!" << std::endl;
        std::cout << first.GetName() << " LOST!" << std::endl;
    }
}
void comparison3D(Shape3D& first, Shape3D& second) {
    std::cout << first.GetName() << " VS " << second.GetName() << std::endl;
    first.ShowInfo();
    second.ShowInfo();
    if (first > second) {
        std::cout << first.GetName() << " WON!" << std::endl;
        std::cout << second.GetName() << " LOST!" << std::endl;
    }
    else if (first == second)
        std::cout << "THE FRIENDSHIP WON!" << std::endl;
    else {
        std::cout << second.GetName() << " WON!" << std::endl;
        std::cout << first.GetName() << " LOST!" << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    Square square;
    TriangularPyramide tryPyr;
    Cylinder cylinder;
    Sphere sphere;
    std::cout << "У нас есть:" << std::endl;
    std::cout << "2D:" << std::endl;
    std::cout << square.GetName() << std::endl;
    std::cout << tryPyr.triangle.GetName() << std::endl;
    std::cout << cylinder.circle.GetName() << std::endl;
    std::cout << "3D:" << std::endl;
    std::cout << tryPyr.GetName() << std::endl;
    std::cout << cylinder.GetName() << std::endl;
    std::cout << sphere.GetName() << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cout << "2D RANDOM COMPARISON!!!" << std::endl;
    std::cout << "1 - SQUARE, CIRCLE." << std::endl;
    std::cout << "2 - TRIANGLE, CIRCLE." << std::endl;
    std::cout << "3 - TRIANGLE, SQUARE." << std::endl;
    unsigned int random;
    std::cout << "CHOOSE A FIGHT:" << std::endl;
    std::cin >> random;

    switch (random) {
    case 1:
        comparison2D(square, cylinder.circle);
        break;
    case 2:
        comparison2D(tryPyr.triangle, cylinder.circle);
        break;
    case 3:
        comparison2D(tryPyr.triangle, square);
        break;
    }
    std::cout << "---------------------------------" << std::endl;
    std::cout << "3D RANDOM COMPARISON!!!" << std::endl;
    std::cout << "1 - TRIANGULAR PYRAMIDE, CYLINDER." << std::endl;
    std::cout << "2 - SPHERE, TRIANGULAR PYRAMIDE." << std::endl;
    std::cout << "3 - CYLINDER, SPHERE." << std::endl;
    std::cout << "CHOOSE A FIGHT:" << std::endl;
    std::cin >> random;

    switch (random) {
    case 1:
        comparison3D(tryPyr, cylinder);
        break;
    case 2:
        comparison3D(sphere, tryPyr);
        break;
    case 3:
        comparison3D(cylinder, sphere);
        break;
    }
}


