#pragma once
#include <iostream>
#include <string>

class Company {
private:

    std::string name;
    int creation_date;
    std::string owner;

public:


    void setCompanyName(std::string name) {
        this->name = name;
    }
    void setCompanyCreationDate(int creation_date) {
        this->creation_date = creation_date;
    }
    void setCompanyOwner(std::string owner) {
        this->owner = owner;
    }

    void getCompanyInfo() {

        std::cout << "Название компании: " << name << std::endl;
        std::cout << "Год основания: " << creation_date << std::endl;
        std::cout << "Владелец: " << owner << std::endl;

    }

    Company(std::string name, int creation_date, std::string owner) :
        name{ name }, creation_date{ creation_date }, owner{ owner }
    {
    }

    Company() : name{ "POLINA ZHAROVA CORP." }, creation_date{ 2023 }, owner{ "Polina Zharova" }
    {
        std::cout << "Информация о компании выбрана по умолчанию." << std::endl;
    }

};

class Employee : public Company {

private:

    std::string name;
    std::string gender;
    int age;
    std::string residence;

public:

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


    void getEmployeeInfo() {

        std::cout << "Имя: " << name << std::endl;
        std::cout << "Пол: " << gender << std::endl;
        std::cout << "Возраст: " << age << std::endl;
        std::cout << "Место жительства: " << residence << std::endl;

    }

    Employee(std::string Cname, int creation_date, std::string owner,
        std::string name, std::string gender, int age, std::string residence) : Company(Cname, creation_date, owner)
    {
        this->name = name;
        this->gender = gender;
        this->residence = residence;
    }

    Employee() :
        name{ "Иван Иванов" }, gender{ "М" }, age{ 30 }, residence{ "Анадырь" }
    {
        std::cout << "Информация о сотруднике выбрана по умолчанию." << std::endl;
    }


};

class Vehicle : public Employee {
private:

    std::string registration_number;
    std::string brand;
    int release_year;
    int price;

public:

    Vehicle(std::string registration_number, std::string brand, int release_year, int price,
        std::string Cname, int creation_date, std::string owner, std::string Ename,
        std::string gender, int age, std::string residence) : Employee(Cname, creation_date, owner, Ename,
            gender, age, residence)

    {
        this->registration_number = registration_number;
        this->brand = brand;
        this->release_year = release_year;
        this->price = price;
    }

    Vehicle() :
        registration_number{ "A117VO" }, brand{ "BMW" }, release_year{ 2017 }, price{ 1000000 }
    {
        std::cout << "Информация о ТС выбрана по умолчанию." << std::endl;
    }


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

    void getVehicleInfo() {

        std::cout << "Регистрационный номер: " << registration_number << std::endl;
        std::cout << "Марка авто: " << brand << std::endl;
        std::cout << "Год производства: " << release_year << std::endl;
        std::cout << "Цена: " << price << std::endl;

    }

};

class Truck : public Vehicle {
private:

    double mass;
    double load_capacity;
    double horse_power;

public:

    Truck(double mass, double load_capacity, double horse_power, std::string Cname, int creation_date, std::string owner,
        std::string registration_number, std::string brand, int release_year, int price,
        std::string Ename, std::string gender, int age, std::string residence) : Vehicle(registration_number, brand, release_year, price, Cname,
            creation_date, owner, Ename, gender, age, residence)
    {
        this->mass = mass;
        this->load_capacity = load_capacity;
        this->horse_power = horse_power;
    }

    Truck() : mass(3000 + rand() % 5001), load_capacity(1000 + rand() % 2501), horse_power(210 + rand() % 51)
    {
        std::cout << "Информация о грузовом автомобиле выбрана по умолчанию." << std::endl;
    }


    void load_capacity_category() {

    }

    void horses_to_kilowatts() {

    }

    void getTruckInfo() {

        std::cout << "Масса: " << mass << " кг" << std::endl;
        std::cout << "Грузоподъемность: " << load_capacity << " кг" << std::endl;
        std::cout << "Л.С.: " << horse_power << std::endl;

    }

    void getallInfo() {

        getCompanyInfo();
        getEmployeeInfo();
        getVehicleInfo();
        getTruckInfo();

    }
};

class Car : public Vehicle {
private:

    std::string transmission;
    std::string price_category;
    std::string color;

public:

    Car(std::string transmission, std::string price_category, std::string color,
        std::string Cname, int creation_date, std::string owner,
        std::string registration_number, std::string brand, int release_year, int price,
        std::string Ename, std::string gender, int age, std::string residence) : Vehicle(registration_number, brand, release_year, price, Cname,
            creation_date, owner, Ename, gender, age, residence)

    {
        this->transmission = transmission;
        this->price_category = price_category;
        this->color = color;
    }

    Car() :
        transmission{ "Автоматическая" }, price_category{ "Люкс" }, color{ "Синий" }
    {
        std::cout << "Информация о грузовом автомобиле выбрана по умолчанию." << std::endl;
    }


    void getCarInfo() {

        std::cout << "Трансмиссия: " << transmission << std::endl;
        std::cout << "Ценовая категория: " << price_category << std::endl;
        std::cout << "Цвет: " << color << std::endl;
    }


    void getallInfo() {

        getCompanyInfo();
        getEmployeeInfo();
        getVehicleInfo();
        getCarInfo();

    }

};