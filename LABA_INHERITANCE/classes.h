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

        std::cout << "�������� ��������: " << name << std::endl;
        std::cout << "��� ���������: " << creation_date << std::endl;
        std::cout << "��������: " << owner << std::endl;

    }

    Company(std::string name, int creation_date, std::string owner) :
        name{ name }, creation_date{ creation_date }, owner{ owner }
    {
    }

    Company() : name{ "POLINA ZHAROVA CORP." }, creation_date{ 2023 }, owner{ "Polina Zharova" }
    {
        std::cout << "���������� � �������� ������� �� ���������." << std::endl;
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

        std::cout << "���: " << name << std::endl;
        std::cout << "���: " << gender << std::endl;
        std::cout << "�������: " << age << std::endl;
        std::cout << "����� ����������: " << residence << std::endl;

    }

    Employee(std::string Cname, int creation_date, std::string owner,
        std::string name, std::string gender, int age, std::string residence) : Company(Cname, creation_date, owner)
    {
        this->name = name;
        this->gender = gender;
        this->residence = residence;
    }

    Employee() :
        name{ "���� ������" }, gender{ "�" }, age{ 30 }, residence{ "�������" }
    {
        std::cout << "���������� � ���������� ������� �� ���������." << std::endl;
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
        std::cout << "���������� � �� ������� �� ���������." << std::endl;
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

        std::cout << "��������������� �����: " << registration_number << std::endl;
        std::cout << "����� ����: " << brand << std::endl;
        std::cout << "��� ������������: " << release_year << std::endl;
        std::cout << "����: " << price << std::endl;

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
        std::cout << "���������� � �������� ���������� ������� �� ���������." << std::endl;
    }


    void load_capacity_category() {

    }

    void horses_to_kilowatts() {

    }

    void getTruckInfo() {

        std::cout << "�����: " << mass << " ��" << std::endl;
        std::cout << "����������������: " << load_capacity << " ��" << std::endl;
        std::cout << "�.�.: " << horse_power << std::endl;

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
        transmission{ "��������������" }, price_category{ "����" }, color{ "�����" }
    {
        std::cout << "���������� � �������� ���������� ������� �� ���������." << std::endl;
    }


    void getCarInfo() {

        std::cout << "�����������: " << transmission << std::endl;
        std::cout << "������� ���������: " << price_category << std::endl;
        std::cout << "����: " << color << std::endl;
    }


    void getallInfo() {

        getCompanyInfo();
        getEmployeeInfo();
        getVehicleInfo();
        getCarInfo();

    }

};