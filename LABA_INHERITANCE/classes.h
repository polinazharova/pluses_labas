#pragma once
#include <iostream>
#include <string>
#include <vector>

//класс грузовых автомобилей
class Truck {
private:
    //атрибуты
    int mass;
    double load_capacity;
    double horse_power;

public:
    //конструкторы, используется из которых по факту толькой дефолтный
    //я хотела придумать какую-нибудь реализацию с использованием конструкторов, но пока что не знаю как
    //так что во всех классах конструкторы не играют роли (кроме дефолтных)
    Truck(int mass, double load_capacity, double horse_power) : mass(mass), load_capacity(load_capacity), horse_power(horse_power)
    {
    }

    Truck() : mass(0), load_capacity(0), horse_power(0)
    {
    }

    //сеттеры геттеры
    void getTruckInfo() {

        std::cout << "Масса: " << mass << " кг" << std::endl;
        std::cout << "Грузоподъемность: " << load_capacity << " кг" << std::endl;
        std::cout << "Л.С.: " << horse_power << std::endl;

    }

    void setTruckInfo() {

        int mass;
        double load_capacity, horse_power;

        std::cout << "Масса: ";
        std::cin >> mass;
        this->mass = mass;

        std::cout << "Грузоподъемность: ";
        std::cin >> load_capacity;
        this->load_capacity = load_capacity;
        std::cout << "Л.С.: ";

        std::cin >> horse_power;
        this->horse_power = horse_power;
        std::cin.ignore();

    }
};

//класс легковых автомобилей
class Car{
private:
    //атрибуты
    std::string transmission;
    std::string price_category;
    std::string color;

public:
    //конструкторы
    Car(std::string transmission, std::string price_category, std::string color) : 
        transmission{ transmission }, price_category{ price_category }, color{ color }
    {
    }

    Car() : transmission{ "NONE" }, price_category{ "NONE" }, color{ "NONE" }
    {
    }

    //сеттеры геттеры
    void getCarInfo() {

        std::cout << "Трансмиссия: " << transmission << std::endl;
        std::cout << "Ценовая категория: " << price_category << std::endl;
        std::cout << "Цвет: " << color << std::endl;

    }

    void setCarInfo() {

        std::string transmission, price_category, color;

        std::cout << "Трансмиссия: ";
        std::cin >> transmission;
        this->transmission = transmission;

        std::cout << "Ценовая категория: ";
        std::cin >> price_category;
        this->price_category = price_category;

        std::cin.ignore();
        std::cout << "Цвет: ";
        std::getline(std::cin, color);
        this->color = color;
    }
   
};

//класс транспорта, который является наследником классов легкового и грузового автомобилей
class Vehicle : public Car, public Truck {
private:
    //атрибуты
    std::string registration_number;
    std::string brand;
    int release_year;
    int price;

public:

    Vehicle(std::string registration_number, std::string brand, int release_year, int price) :
        registration_number{ registration_number }, brand{ brand }, release_year{ release_year }, price{ price }
    {
    }

    Vehicle() :
        registration_number{ "A117VO" }, brand{ "BMW" }, release_year{ 2017 }, price{ 1000000 }
    {
    }

    //сеттеры и геттеры
    void setVehicleRegnum(std::string registration_number) {
        this->registration_number = registration_number;
    }
    void setVehicleBrand(std::string brand) {
        this->brand = brand;
    }
    void setVehicleYear(int release_year) {
        this->release_year = release_year;
    }
    void setVehiclePrice(int price) {
        this->price = price;
    }

    int getVehiclePrice() { return price; }


    void getVehicleInfo() {

        std::cout << "Регистрационный номер: " << registration_number << std::endl;
        std::cout << "Марка авто: " << brand << std::endl;
        std::cout << "Год производства: " << release_year << std::endl;
        std::cout << "Цена: " << price << std::endl;

    }
    
    void setVehicleInfo() {

        std::string registration_number, brand;
        int release_year, price;

        std::cout << "Регистрационный номер: ";
        std::cin >> registration_number;
        this->registration_number = registration_number;

        std::cout << "Марка авто: ";
        std::cin >> brand;
        this->brand = brand;

        std::cout << "Год выпуска: ";
        std::cin >> release_year;
        this->release_year = release_year;

        std::cout << "Цена: ";
        std::cin >> price;
        this->price = price;

    }
        
    

};

//класс сотрудников, который включает в себя объект класса транспортного средства (имеет связь с другим классом)
class Employee {

private:
    //атрибуты
    std::string name;
    std::string gender;
    int age;
    std::string residence;
    Vehicle v;

public:
    //сеттеры и геттеры
     void setEmployeename(std::string name) {
         this->name = name;
     }
     void setEmployeeGender(std::string gender) {
         this->gender = gender;
     }
     void setEmployeeAge(int age) {
         this->age = age;
     }
     void setEmployeeRes(std::string residence) {
         this->residence = residence;
     }
     std::string getEmployeeName() { return name; }

     void setEmployeeInfo() {

         std::string name, gender, residence;
         int age;

         std::cin.ignore();
         std::cout << "Имя сотрудника: ";
         std::getline(std::cin, name);
         this->name = name;

         std::cout << "Пол: ";
         std::cin >> gender;
         this->gender = gender;

         std::cin.ignore();
         std::cout << "Место жительства: ";
         std::getline(std::cin, residence);
         this->residence = residence;

         std::cout << "Возраст: ";
         std::cin >> age;
         this->age = age;

     }
     void getEmployeeInfo() {

         std::cout << "Имя: " << name << std::endl;
         std::cout << "Пол: " << gender << std::endl;
         std::cout << "Возраст: " << age << std::endl;
         std::cout << "Место жительства: " << residence << std::endl;

     }

     //конструкторы
     Employee(std::string name, std::string gender, int age, std::string residence) :
         name{ name }, gender{ gender }, age{ age }, residence{ residence }
       {
       }

     Employee() : name{ "Иван Иванов" }, gender{ "М" }, age{ 30 }, residence{ "Анадырь" }
       {
       }
      
     //функции, связывающие класс транспорта с этим
     void set_car_info() { v.setCarInfo(); } 
     void set_truck_info() { v.setTruckInfo(); }   
     void set_vehicle_info() { v.setVehicleInfo(); }        
     void get_car_info() { v.getCarInfo(); }      
     void get_truck_info() { v.getTruckInfo(); }       
     void get_vehicle_info() { v.getVehicleInfo(); }
     int v_price() { return v.getVehiclePrice(); }


};

//класс компании, который включает в себя массив объектов класс сотрудник, как бы подразумевая, что в компании множество сотрудников
class Company {
private:
    //атрибуты
    std::string name;
    int creation_date;
    std::string owner;
    int N;
    Employee* e = new Employee[N];

public:
    //сеттеры и геттеры
    void setCompanyName(std::string name) {
        this->name = name;
    }
    void setCompanyCreationDate(int creation_date) {
        this->creation_date = creation_date;
    }
    void setCompanyOwner(std::string owner) {
        this->owner = owner;
    }
    void setCompanyInfo() {

        std::string name, owner;
        int creation_date;

        std::cin.ignore();
        std::cout << "Название компании: ";
        std::getline(std::cin, name);
        this->name = name;

        std::cout << "Дата основания: ";
        std::cin >> creation_date;
        this->creation_date = creation_date;

        std::cin.ignore();
        std::cout << "Имя владельца: ";
        std::getline(std::cin, owner);
        this->owner = owner;

    }
    void getCompanyInfo() {

        std::cout << "Название компании: " << name << std::endl;
        std::cout << "Год основания: " << creation_date << std::endl;
        std::cout << "Владелец: " << owner << std::endl;

    }

    //конструкторы
    Company(int N) : N{ N }
    {
        int choice;
        setCompanyInfo();

        for (int i {0}; i < N; i++) {

            std::cout << "Cотрудник " << i + 1 << std::endl;
            e[i].setEmployeeInfo();

            std::cout << "Вы владеете грузовым (нажмите 1) или легковым автомобилем (нажмите 2)? ";
            std::cin >> choice;

            switch (choice) {
            case 1:
                e[i].set_truck_info();
                break;
            case 2:
                e[i].set_car_info();
                break;
            default:
                if ((1 + rand() % 2) == 1)
                    e[i].set_truck_info();
                else
                    e[i].set_car_info();
                break;
            }
            e[i].set_vehicle_info();     
        }
    }

    Company(std::string name, int creation_date, std::string owner, int N) :
        name{ name }, creation_date{ creation_date }, owner{ owner }, N{ N }
    {
        int choice;
     
        for (int i{ 0 }; i < N; i++) {

            std::cout << "Cотрудник " << i + 1 << std::endl;
            e[i].setEmployeeInfo();

            std::cout << "Вы владеете грузовым (нажмите 1) или легковым автомобилем (нажмите 2)? ";
            std::cin >> choice;

            switch (choice) {
            case 1:
                e[i].set_truck_info();
                break;
            case 2:
                e[i].set_car_info();
                break;
            default:
                if ((1 + rand() % 2) == 1)
                    e[i].set_truck_info();
                else
                    e[i].set_car_info();
                break;
            }
            e[i].set_vehicle_info();
        }
    }

    Company() : name{ "POLINA ZHAROVA CORP." }, creation_date{ 2023 }, owner{ "Polina Zharova" }, N{1}
    {
        getCompanyInfo();
        e[0].getEmployeeInfo();
        e[0].get_vehicle_info();
        e[0].get_car_info();
        e[0].get_truck_info();
    }

    //функция для интерактивности программы
    void thief_finding() {

        std::vector<std::string> suspects;

        for (int i{ 0 }; i < N; i++) {
            if (e[i].v_price() >= 1000000)
                suspects.push_back(e[i].getEmployeeName());
        }

        std::cout << "Есть тут у нас кое-какие подозрения..." << std::endl;

        if (suspects.size() == 0) 
            std::cout << "ШУТКА!!! Подозрений нет :)))" << std::endl;
        else {
            for (int i{ 0 }; i < suspects.size(); i++)
                std::cout << suspects[i] << " ";
            std::cout << std::endl;
        }
   
    }
    //удаление динамического массива
    void deleting() {
        delete[] e;
    }
};