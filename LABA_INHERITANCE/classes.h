#pragma once
#include <iostream>
#include <string>
#include <vector>

//����� �������� �����������
class Truck {
private:
    //��������
    int mass;
    double load_capacity;
    double horse_power;

public:
    //������������, ������������ �� ������� �� ����� ������� ���������
    //� ������ ��������� �����-������ ���������� � �������������� �������������, �� ���� ��� �� ���� ���
    //��� ��� �� ���� ������� ������������ �� ������ ���� (����� ���������)
    Truck(int mass, double load_capacity, double horse_power) : mass(mass), load_capacity(load_capacity), horse_power(horse_power)
    {
    }

    Truck() : mass(0), load_capacity(0), horse_power(0)
    {
    }

    //������� �������
    void getTruckInfo() {

        std::cout << "�����: " << mass << " ��" << std::endl;
        std::cout << "����������������: " << load_capacity << " ��" << std::endl;
        std::cout << "�.�.: " << horse_power << std::endl;

    }

    void setTruckInfo() {

        int mass;
        double load_capacity, horse_power;

        std::cout << "�����: ";
        std::cin >> mass;
        this->mass = mass;

        std::cout << "����������������: ";
        std::cin >> load_capacity;
        this->load_capacity = load_capacity;
        std::cout << "�.�.: ";

        std::cin >> horse_power;
        this->horse_power = horse_power;
        std::cin.ignore();

    }
};

//����� �������� �����������
class Car{
private:
    //��������
    std::string transmission;
    std::string price_category;
    std::string color;

public:
    //������������
    Car(std::string transmission, std::string price_category, std::string color) : 
        transmission{ transmission }, price_category{ price_category }, color{ color }
    {
    }

    Car() : transmission{ "NONE" }, price_category{ "NONE" }, color{ "NONE" }
    {
    }

    //������� �������
    void getCarInfo() {

        std::cout << "�����������: " << transmission << std::endl;
        std::cout << "������� ���������: " << price_category << std::endl;
        std::cout << "����: " << color << std::endl;

    }

    void setCarInfo() {

        std::string transmission, price_category, color;

        std::cout << "�����������: ";
        std::cin >> transmission;
        this->transmission = transmission;

        std::cout << "������� ���������: ";
        std::cin >> price_category;
        this->price_category = price_category;

        std::cin.ignore();
        std::cout << "����: ";
        std::getline(std::cin, color);
        this->color = color;
    }
   
};

//����� ����������, ������� �������� ����������� ������� ��������� � ��������� �����������
class Vehicle : public Car, public Truck {
private:
    //��������
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

    //������� � �������
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

        std::cout << "��������������� �����: " << registration_number << std::endl;
        std::cout << "����� ����: " << brand << std::endl;
        std::cout << "��� ������������: " << release_year << std::endl;
        std::cout << "����: " << price << std::endl;

    }
    
    void setVehicleInfo() {

        std::string registration_number, brand;
        int release_year, price;

        std::cout << "��������������� �����: ";
        std::cin >> registration_number;
        this->registration_number = registration_number;

        std::cout << "����� ����: ";
        std::cin >> brand;
        this->brand = brand;

        std::cout << "��� �������: ";
        std::cin >> release_year;
        this->release_year = release_year;

        std::cout << "����: ";
        std::cin >> price;
        this->price = price;

    }
        
    

};

//����� �����������, ������� �������� � ���� ������ ������ ������������� �������� (����� ����� � ������ �������)
class Employee {

private:
    //��������
    std::string name;
    std::string gender;
    int age;
    std::string residence;
    Vehicle v;

public:
    //������� � �������
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
         std::cout << "��� ����������: ";
         std::getline(std::cin, name);
         this->name = name;

         std::cout << "���: ";
         std::cin >> gender;
         this->gender = gender;

         std::cin.ignore();
         std::cout << "����� ����������: ";
         std::getline(std::cin, residence);
         this->residence = residence;

         std::cout << "�������: ";
         std::cin >> age;
         this->age = age;

     }
     void getEmployeeInfo() {

         std::cout << "���: " << name << std::endl;
         std::cout << "���: " << gender << std::endl;
         std::cout << "�������: " << age << std::endl;
         std::cout << "����� ����������: " << residence << std::endl;

     }

     //������������
     Employee(std::string name, std::string gender, int age, std::string residence) :
         name{ name }, gender{ gender }, age{ age }, residence{ residence }
       {
       }

     Employee() : name{ "���� ������" }, gender{ "�" }, age{ 30 }, residence{ "�������" }
       {
       }
      
     //�������, ����������� ����� ���������� � ����
     void set_car_info() { v.setCarInfo(); } 
     void set_truck_info() { v.setTruckInfo(); }   
     void set_vehicle_info() { v.setVehicleInfo(); }        
     void get_car_info() { v.getCarInfo(); }      
     void get_truck_info() { v.getTruckInfo(); }       
     void get_vehicle_info() { v.getVehicleInfo(); }
     int v_price() { return v.getVehiclePrice(); }


};

//����� ��������, ������� �������� � ���� ������ �������� ����� ���������, ��� �� ������������, ��� � �������� ��������� �����������
class Company {
private:
    //��������
    std::string name;
    int creation_date;
    std::string owner;
    int N;
    Employee* e = new Employee[N];

public:
    //������� � �������
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
        std::cout << "�������� ��������: ";
        std::getline(std::cin, name);
        this->name = name;

        std::cout << "���� ���������: ";
        std::cin >> creation_date;
        this->creation_date = creation_date;

        std::cin.ignore();
        std::cout << "��� ���������: ";
        std::getline(std::cin, owner);
        this->owner = owner;

    }
    void getCompanyInfo() {

        std::cout << "�������� ��������: " << name << std::endl;
        std::cout << "��� ���������: " << creation_date << std::endl;
        std::cout << "��������: " << owner << std::endl;

    }

    //������������
    Company(int N) : N{ N }
    {
        int choice;
        setCompanyInfo();

        for (int i {0}; i < N; i++) {

            std::cout << "C�������� " << i + 1 << std::endl;
            e[i].setEmployeeInfo();

            std::cout << "�� �������� �������� (������� 1) ��� �������� ����������� (������� 2)? ";
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

            std::cout << "C�������� " << i + 1 << std::endl;
            e[i].setEmployeeInfo();

            std::cout << "�� �������� �������� (������� 1) ��� �������� ����������� (������� 2)? ";
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

    //������� ��� ��������������� ���������
    void thief_finding() {

        std::vector<std::string> suspects;

        for (int i{ 0 }; i < N; i++) {
            if (e[i].v_price() >= 1000000)
                suspects.push_back(e[i].getEmployeeName());
        }

        std::cout << "���� ��� � ��� ���-����� ����������..." << std::endl;

        if (suspects.size() == 0) 
            std::cout << "�����!!! ���������� ��� :)))" << std::endl;
        else {
            for (int i{ 0 }; i < suspects.size(); i++)
                std::cout << suspects[i] << " ";
            std::cout << std::endl;
        }
   
    }
    //�������� ������������� �������
    void deleting() {
        delete[] e;
    }
};