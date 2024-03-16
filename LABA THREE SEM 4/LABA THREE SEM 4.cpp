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
    void CalculateArea() { std::cout << "Площадь квадрата: " << side * side << std::endl; }
};




class TriangularPyramide : public Shape3D {
private:
    class Triangle : public Shape2D {
    private:
        float base;
        float height;
    public:
        void CalculateArea() { 
            SetArea(0.5 * base * height);
            std::cout << "Моя площадь: " << GetArea() << std::endl;
        }
        std::string GetName() { return "Треугольник"; }
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
            /*std::cout << "Площадь увеличилась в " << scaleFactor * scaleFactor << " раз." << std::endl;*/
        }
    };
    float height;
    Triangle triangle;
    
public:
    void CalculateVolume() {
        SetVolume((1 / 3) * height * triangle.GetArea());
        std::cout << "Мой объем: " << GetVolume() << std::endl;
    }
    void Scale(float scaleFactor) {
        height *= scaleFactor;
        std::cout << "Высота увеличена в " << scaleFactor << " раз." << std::endl;
        triangle.Scale(scaleFactor);
    };
    virtual std::string GetName() { return "Треугольная пирамида"; }
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
        void CalculateArea() { std::cout << "Площадь круга: " << 3.14 * radius * radius << std::endl; }
    };

    float height;
};

class Sphere : public Shape3D {
private:
    float radius;
};

int main()
{
    std::cout << "Hello World!\n";
}


