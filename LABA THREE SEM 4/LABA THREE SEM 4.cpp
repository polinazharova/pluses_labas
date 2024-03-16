#include <iostream>

class Shape {
public:
    virtual void Scale(float scaleFactor) = 0;
    virtual void ShowInfo() = 0;
    virtual std::string GetName() = 0;
};

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
    bool operator < (Shape3D& other){
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

class Square : public Shape2D {
private:
    float side;
public:
    void CalculateArea() {
        std::cout << "Моя площадь: " << GetArea() << std::endl;
    }
    std::string GetName() { return "Mr Квадрат"; }
    void ShowInfo() {
        std::cout << "Я " << GetName() << std::endl;
        CalculateArea();
        std::cout << "Моя сторона - " << side << std::endl;
    }
    void Scale(float scaleFactor) {
        side *= scaleFactor;
        std::cout << "Сторона квадрата увеличена в " << scaleFactor << " раз." << std::endl;
        SetArea(side * side);
    }
};

class TriangularPyramide : public Shape3D {
private:
    class Triangle : public Shape2D {
    private:
        float base;
        float height;
    public:
        Triangle() : base(10), height(5) {
            SetArea(0.5 * base * height);
        }
        Triangle(float base, float height) : base(base), height(height) {
            SetArea(0.5 * base * height);
        }
        ~Triangle() { std::cout << "TRIANGLE DESTRUCTION!" << std::endl; }

        void CalculateArea() { 
            std::cout << "Моя площадь: " << GetArea() << std::endl;
        }
        std::string GetName() { return "Mr Треугольник"; }
        void ShowInfo() {
            std::cout << "Я " << GetName() << std::endl;
            CalculateArea();
            std::cout << "Мое основание - " << base << std::endl;
            std::cout << "Моя высота - " << height << std::endl;
        }
        void Scale(float scaleFactor) {
            base *= scaleFactor;
            height *= scaleFactor;
            std::cout << "Элементы треугольника увеличены в " << scaleFactor << " раз." << std::endl;
            SetArea(0.5 * base * height);
        }
    };
    float height;
    Triangle triangle;
    
public:
    TriangularPyramide() : height(10) {
        SetVolume((1 / 3) * height * triangle.GetArea());
    }
    TriangularPyramide(float height) : height(height) {
        SetVolume((1 / 3) * height * triangle.GetArea());
    }
    ~TriangularPyramide() { std::cout << "TRIANGULAR PYRAMIDE DESTRUCTION!" << std::endl; }

    void CalculateVolume() {
        SetVolume((1 / 3) * height * triangle.GetArea());
        std::cout << "Мой объем: " << GetVolume() << std::endl;
    }
    void Scale(float scaleFactor) {
        height *= scaleFactor;
        std::cout << "Высота увеличена в " << scaleFactor << " раз." << std::endl;
        triangle.Scale(scaleFactor);
    };
    virtual std::string GetName() { return "Mrs Треугольная пирамида"; }
    void ShowInfo() {
        std::cout << "Я " << GetName() << std::endl;
        CalculateVolume();
        std::cout << "Площадь моего основания - " << triangle.GetArea() << std::endl;
        std::cout << "Моя высота - " << height << std::endl;
    }
};

class Cylinder : public Shape3D {
private:
    class Circle : public Shape2D {
    private:
        float radius;
    public:
        Circle() : radius(7) {
            SetArea(3.14 * radius * radius);
        }
        Circle(float radius) : radius(radius) {
            SetArea(3.14 * radius * radius);
        }
        ~Circle() { std::cout << "CIRCLE DESTRUCTION!" << std::endl; }

        void CalculateArea() {
            std::cout << "Моя площадь: " << GetArea() << std::endl;
        }
        std::string GetName() { return "Mr Круг"; }
        void ShowInfo() {
            std::cout << "Я " << GetName() << std::endl;
            CalculateArea();
            std::cout << "Мой радиус - " << radius << std::endl;
        }
        void Scale(float scaleFactor) {
            radius *= scaleFactor;
            std::cout << "Радиус круга увеличен в " << scaleFactor << " раз." << std::endl;
            SetArea(3.14 * radius * radius);
        }
    };
    float height;
    Circle circle;
public:
    Cylinder() : height(10) {
        SetVolume(circle.GetArea() * height);
    }
    Cylinder(float height) : height(height) {
        SetVolume(circle.GetArea() * height);
    }
    ~Cylinder() { std::cout << "CYLINDER DESTRUCTION!" << std::endl; }

    void Scale(float scaleFactor) {
        height *= scaleFactor;
        std::cout << "Высота цилиндра увеличена в " << scaleFactor << " раз." << std::endl;
        circle.Scale(scaleFactor);
        SetVolume(circle.GetArea() * height);
    };
    std::string GetName() { return "Mr Цилиндр"; }
    void CalculateVolume() {
        std::cout << "Мой объем: " << GetVolume() << std::endl;
    }
    void ShowInfo() {
        std::cout << "Я " << GetName() << std::endl;
        CalculateVolume();
        std::cout << "Моя высота - " << height << std::endl;
    }
};

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
    ~Sphere() { std::cout << "SPHERE PYRAMIDE DESTRUCTION!" << std::endl; }
    void Scale(float scaleFactor) {
        radius *= scaleFactor;
        std::cout << "Радиус сферы увеличен в " << scaleFactor << " раз." << std::endl;
        SetVolume((4 / 3) * 3.14 * pow(radius, 3));
    }
    std::string GetName() { return "Ms Сфера"; }
    void CalculateVolume() {
        std::cout << "Мой объем: " << GetVolume() << std::endl;
    }
    void ShowInfo() {
        std::cout << "Я " << GetName() << std::endl;
        CalculateVolume();
        std::cout << "Мой радиус - " << radius << std::endl;
    }
};

int main()
{
  
}


