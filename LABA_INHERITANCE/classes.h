#pragma once
#include <iostream>
#include <string>
#include <vector>

//КЛАСС ГРУЗОВИКОВ
class Truck {
private:
    //attributes
    int mass;
    double load_capacity;
    double horse_power;

public:
    //вывод в терминал всей информации о грузовике
    void getTruckInfo() {
        std::cout << "Масса: " << mass << " кг" << std::endl;
        std::cout << "Грузоподъемность: " << load_capacity << " кг" << std::endl;
        std::cout << "Л.С.: " << horse_power << std::endl;
    }

    //запись всей информации о грузовике
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
        std::cin.clear();

    }

    //ДЛЯ РАЗНООБРАЗИЯ МЕТОДОВ КЛАССА
    //пробег грузовика
    void mileage() {
        std::cout << "Пробег: " << 0 + rand() % 100000 << " тыс. км." << std::endl;
    }

    //конструкторы, используется из которых по факту толькой дефолтный
    //я хотела придумать какую-нибудь реализацию с использованием конструкторов, но пока что не знаю как
    //так что во всех классах конструкторы не играют роли (кроме дефолтных)
    Truck(int mass, double load_capacity, double horse_power) : mass(mass), load_capacity(load_capacity), horse_power(horse_power) {}

    Truck() : mass(0), load_capacity(0), horse_power(0) {}
};

//КЛАСС ЛЕГКОВЫХ АВТОМОБИЛЕЙ
class Car {
private:
    //attributes
    std::string transmission;
    std::string price_category;
    std::string color;

public:
   
    //вывести всю информацию о легковом авто в терминал
    void getCarInfo() {

        std::cout << "Трансмиссия: " << transmission << std::endl;
        std::cout << "Ценовая категория: " << price_category << std::endl;
        std::cout << "Цвет: " << color << std::endl;

    }
    //записать всю информацию о легковом авто
    void setCarInfo() {

        std::string transmission, price_category, color;

        std::cout << "Трансмиссия: ";
        std::cin >> transmission;
        this->transmission = transmission;

        std::cout << "Ценовая категория: ";
        std::cin >> price_category;
        this->price_category = price_category;

        std::cin.ignore(10000, '\n');
        std::cout << "Цвет: ";
        std::getline(std::cin, color);
        this->color = color;
        std::cin.clear();
    }

    //ДЛЯ РАЗНООБРАЗИЯ МЕТОДОВ КЛАССА
    //когда проводился тех.осмотр
    void technical_inspection() {
        std::cout << "Тех. осмотр авто проводился в " << 2015 + rand() % 9 << " году" << std::endl;
    }

    //constructors
    Car(std::string transmission, std::string price_category, std::string color) :
        transmission{ transmission }, price_category{ price_category }, color{ color } {}

    Car() : transmission{ "NONE" }, price_category{ "NONE" }, color{ "NONE" } {}
};


//КЛАСС ТРАНСПОРТА (в моей архитектуре - наследник классов Car и Truck)
class Vehicle : public Car, public Truck {
private:
    //attributes
    std::string registration_number;
    std::string brand;
    int release_year;
    int price;

public:

    //setters 
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

    //getter
    int getVehiclePrice() { return price; }

    //вывести всю информацию о Т.С. в терминал
    void getVehicleInfo() {

        std::cout << "Регистрационный номер: " << registration_number << std::endl;
        std::cout << "Марка авто: " << brand << std::endl;
        std::cout << "Год производства: " << release_year << std::endl;
        std::cout << "Цена: " << price << std::endl;

    }
    //установить всю информацию о Т.С.
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
        std::cin.clear();
    }

    //ДЛЯ РАЗНООБРАЗИЯ МЕТОДОВ КЛАССА
    //хитрый определитель красоты автомобиля
    void determinant_of_beauty() {
        std::cout << "Сейчас наша нейросеть определит уровень красоты вашего автомобиля." << std::endl;

        int non_tricky_choosing, beautiful = 0, av_beautiful = 0, nonbeautiful = 0;

        for (int i{ 0 }; i < 10; i++) {
            non_tricky_choosing = 1 + rand() % 3;
            switch (non_tricky_choosing)
            {
            case 1:
                beautiful++;
                break;
            case 2:
                av_beautiful++;
                break;
            case 3:
                nonbeautiful++;
                break;
            default:
                break;
            }
       
            if (i == 9) {
                if (beautiful > av_beautiful && beautiful > nonbeautiful)
                    std::cout << "По мнению нашего умного автоматизированного оценивателя автомобилей ваше авто...красиво." << std::endl;
                else if (av_beautiful > nonbeautiful && av_beautiful > beautiful)
                    std::cout << "По мнению нашего умного автоматизированного оценивателя автомобилей ваше авто...среднячок." << std::endl;
                else if (nonbeautiful > av_beautiful && nonbeautiful > beautiful)
                    std::cout << "По мнению нашего умного автоматизированного оценивателя автомобилей ваше авто...некрасиво" << std::endl;
                else
                    std::cout << "Красоту вашего авто невозможно определить... Это ведь вкусовщина! :)" << std::endl;
            }
        }
    }

    //constructors
    Vehicle(std::string registration_number, std::string brand, int release_year, int price) :
        registration_number{ registration_number }, brand{ brand }, release_year{ release_year }, price{ price } {}

    Vehicle() :
        registration_number{ "A117VO" }, brand{ "BMW" }, release_year{ 2017 }, price{ 1000000 } {}

    //т.к. родительские классы у меня car и truck, то конструкторы я делаю для vehicle
    Vehicle(std::string transmission, std::string price_category, std::string color) : Car(transmission, price_category, color),
        registration_number{ "A117VO" }, brand{ "BMW" }, release_year{ 2017 }, price{ 1000000 } {}

    Vehicle(int mass, double load_capacity, double horse_power) : Truck(mass, load_capacity, horse_power),
        registration_number{ "A117VO" }, brand{ "BMW" }, release_year{ 2017 }, price{ 1000000 } {}

    Vehicle(std::string transmission, std::string price_category, std::string color, int mass, double load_capacity, double horse_power) : Truck(mass, load_capacity, horse_power),
        Car(transmission, price_category, color),
        registration_number{ "A117VO" }, brand{ "BMW" }, release_year{ 2017 }, price{ 1000000 } {}
};

//КЛАСС СОТРУДНИКОВ, который включает в себя объект класса транспорта
//то есть у каждого сотрудника есть свое транспортное средство
class Employee {

private:
    //attributes
    std::string name;
    std::string gender;
    int age;
    std::string residence;
    Vehicle v;

public:
    //setters
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

    //getter
    std::string getEmployeeName() { return name; }

    //установить всю информацию о сотруднике
    void setEmployeeInfo() {

        std::string name, gender, residence;
        int age;

        std::cin.ignore(10000, '\n');
        std::cout << "Имя сотрудника: ";
        std::getline(std::cin, name);
        this->name = name;
        std::cin.clear();

        std::cout << "Пол: ";
        std::cin >> gender;
        this->gender = gender;

        std::cin.ignore();
        std::cout << "Место жительства: ";
        std::getline(std::cin, residence);
        this->residence = residence;
        std::cin.clear();

        std::cout << "Возраст: ";
        std::cin >> age;
        this->age = age;
        std::cin.clear();

    }
    //вывести всю информацию о сотруднике в терминал
    void getEmployeeInfo() {

        std::cout << "Имя: " << name << std::endl;
        std::cout << "Пол: " << gender << std::endl;
        std::cout << "Возраст: " << age << std::endl;
        std::cout << "Место жительства: " << residence << std::endl;

    }
    
    //функции, связывающие методы класса vehicle с этим классом
    void set_car_info() { v.setCarInfo(); }
    void set_truck_info() { v.setTruckInfo(); }
    void set_vehicle_info() { v.setVehicleInfo(); }
    void get_car_info() { v.getCarInfo(); }
    void get_truck_info() { v.getTruckInfo(); }
    void get_vehicle_info() { v.getVehicleInfo(); }
    int v_price() { return v.getVehiclePrice(); }
    void determinant_of_beauty() { v.determinant_of_beauty(); }


    //ДЛЯ РАЗНООБРАЗИЯ МЕТОДОВ КЛАССА
    //определяем настроение человека по стоимости его машины
    void mood_determinant() {
        if (v_price() <= 500000)
            std::cout << "Этот человек, кажется, не в настроении..." << std::endl;
        else if (v_price() > 500000 && v_price() < 1000000)
            std::cout << "Этот человек, кажется, сохраняет спокойствие... или пытается его сохранить." << std::endl;
        else if (v_price() >= 1000000)
            std::cout << "Этот человек, кажется, вполне доволен... а кто не был бы доволен, имея дома бесплатную пачку бумаги и 7 ручек?" << std::endl;
    }

    //constructors
    Employee(std::string name, std::string gender, int age, std::string residence) :
        name{ name }, gender{ gender }, age{ age }, residence{ residence } {}

    Employee() : name{ "Иван Иванов" }, gender{ "М" }, age{ 30 }, residence{ "Анадырь" } {}

};

//КЛАСС КОМПАНИИ, включающий в себя массив объектов класса Employee,
//то есть у компании не один сотрудник
class Company {
private:
    //attributes
    std::string name;
    int creation_date;
    std::string owner;
    int N;
    Employee* e = new Employee[N];

public:
    //setters
    void setCompanyName(std::string name) {
        this->name = name;
    }
    void setCompanyCreationDate(int creation_date) {
        this->creation_date = creation_date;
    }
    void setCompanyOwner(std::string owner) {
        this->owner = owner;
    }

    //getter
    int getN() { return N; }

    //записать всю информацию о компании
    void setCompanyInfo() {

        std::string name, owner;
        int creation_date;

        std::cin.ignore(10000, '\n');
        std::cout << "Название компании: ";
        std::getline(std::cin, name);
        this->name = name;
        std::cin.clear();

        std::cout << "Дата основания: ";
        std::cin >> creation_date;
        this->creation_date = creation_date;
        std::cin.clear();

        std::cin.ignore(10000, '\n');
        std::cout << "Имя владельца: ";
        std::getline(std::cin, owner);
        this->owner = owner;
        std::cin.clear();

    }
    //вывести всю информацию о коспании в терминал
    void getCompanyInfo() {
        std::cout << "Название компании: " << name << std::endl;
        std::cout << "Год основания: " << creation_date << std::endl;
        std::cout << "Владелец: " << owner << std::endl;
    }

    //перенесение методов класса Vehicle в класс Company (через класс Employee)
    void determinant_of_beauty(int i) { e[i - 1].determinant_of_beauty(); }
    void mood_determinant(int i) { e[i - 1].mood_determinant(); }


    //ДЛЯ РАЗНООБРАЗИЯ МЕТОДОВ КЛАССА
    //вычисление того, кто крадет канцелярию
    void thief_finding() {
        std::cout << "Есть тут у нас кое-какие подозрения..." << std::endl;

        int count_suspects = 0;
        for (int i{ 0 }; i < N; i++) {
            if (e[i].v_price() >= 1000000) {
                count_suspects++;
                std::cout << e[i].getEmployeeName() << " ";
            }
        }
        if (count_suspects == 0)
            std::cout << "ШУТКА!!! Подозрений нет :)))" << std::endl;
        else
            std::cout << std::endl;
    }

    //средний уровень зарплат по компании
    void average_salary() {
        std::cout << "Средний уровень зарплат по компании - " << 19242 + rand() % 150000 << std::endl;
    }

    //dynamic massiv deleting
    void deleting() { delete[] e; }

    //constructors
    Company(int N) : N{ N }
    {
        int choice;
        setCompanyInfo();
        for (int i{ 0 }; i < N; i++) {
            std::cout << "Cотрудник " << i + 1 << std::endl;
            std::cout << "=================================================================================================================================" << std::endl;
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
            std::cout << "=================================================================================================================================" << std::endl;
            std::cin.clear();
        }
    }

    Company(std::string name, int creation_date, std::string owner, int N) :
        name{ name }, creation_date{ creation_date }, owner{ owner }, N{ N }
    {
        int choice;

        for (int i{ 0 }; i < N; i++) {
            std::cout << "Cотрудник " << i + 1 << std::endl;
            std::cout << "=================================================================================================================================" << std::endl;
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
            std::cout << "=================================================================================================================================" << std::endl;
            std::cin.clear();
        }
    }

    Company() : name{ "POLINA ZHAROVA CORP." }, creation_date{ 2023 }, owner{ "Polina Zharova" }, N{ 1 }
    {
        std::cout << "=================================================================================================================================" << std::endl;
        getCompanyInfo();
        e[0].getEmployeeInfo();
        e[0].get_vehicle_info();
        e[0].get_car_info();
        e[0].get_truck_info();
        std::cout << "=================================================================================================================================" << std::endl;
    }
};