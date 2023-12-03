#include <iostream>
#include <string>

class Company {
private:

    std::string Cname;
    int creation_date;
    std::string owner;

public:


    void setCompanyName(std::string Cname) {
        this->Cname = Cname;
    }
    void setCompanyCreationDate(int creation_date) {
        this->creation_date = creation_date;
    }
    void setCompanyOwner(std::string owner) {
        this->owner = owner;
    }

    void getCompanyInfo() {

        std::cout << "Название компании: " << Cname << std::endl;
        std::cout << "Год основания: " << creation_date << std::endl;
        std::cout << "Владелец: " << owner << std::endl;

    }

    Company(std::string name, int creation_date, std::string owner) :
        Cname{ Cname }, creation_date{ creation_date }, owner{ owner }
    {
    }

    Company() : Cname{ "POLINA ZHAROVA CORP." }, creation_date{ 2023 }, owner{ "Polina Zharova" }
    {
    }
    void Cset_all();
};

void Company::Cset_all() {

    std::string Cname;
    std::cout << "Введите название компании: ";
    std::getline(std::cin, Cname);
    setCompanyName(Cname);

    int creation_date;
    std::cout << "Введите год основания компании: ";
    std::cin >> creation_date;
    setCompanyCreationDate(creation_date);

    std::string owner;
    std::cout << "Введите имя и фамилию владельца: ";
    std::getline(std::cin, owner);
    setCompanyOwner(owner);

}


class Employee : public Company {

private:

    std::string Ename;
    std::string gender;
    int age;
    std::string residence;

public:

    void setEmployeeName(std::string Ename) {
        this->Ename = Ename;
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


    void getPersonInfo() {

        std::cout << "Имя: " << Ename << std::endl;
        std::cout << "Пол: " << gender << std::endl;
        std::cout << "Возраст: " << age << std::endl;
        std::cout << "Место жительства: " << residence << std::endl;

    }

    Employee(std::string Ename, std::string gender, int age, std::string residence) :
        Ename{ Ename }, gender{ gender }, age{ age }, residence{ residence }
    {
    }

    Employee() :
        Ename{ "Иван Иванов"}, gender{ "М" }, age{ 30 }, residence{ "Анадырь" }
    {
    }

    void Eset_all();
};

void Employee::Eset_all() {

    std::string Ename;
    std::cout << "Введите имя и фамилию: ";
    std::getline(std::cin, Ename);
    setEmployeeName(Ename); 

    std::string gender;
    std::cout << "Введите пол: ";
    std::cin >> gender;
    setEmployeeGender(gender);

    int age;
    std::cout << "Введите возраст: ";
    std::cin >> age;
    setEmployeeAge(age);

    std::string residence;
    std::cout << "Введите место жительства: ";
    std::getline(std::cin, residence);
    setEmployeeRes(residence);

}


class Vehicle : public Employee {
private:

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
        registration_number{ "A117VO" }, brand{ "BMW" }, release_year{ 2017 }, price { 1000000 }
    {
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

    void Vset_all();

};

void Vehicle::Vset_all() {

    std::string registration_number;
    std::cout << "Введите регистрационный номер машины: ";
    std::cin >> registration_number;
    setVehicleRegnum(registration_number);

    std::string brand;
    std::cout << "Введите марку машины: ";
    std::cin >> brand;
    setVehicleBrand(brand);

    int release_year;
    std::cout << "Введите год выпуска машины: ";
    std::cin >> release_year;
    setVehicleYear(release_year);

    int price;
    std::cout << "Введите цену машины: ";
    std::cin >> price;
    setVehiclePrice(price);

}


class Truck : public Vehicle {
private:

    double mass;
    double load_capacity;
    double horse_power;

public:

    Truck(double mass, double load_capacity, double horse_power) :
        mass{ mass }, load_capacity{ load_capacity }, horse_power{ horse_power } 
    {
        Vset_all();
        Eset_all();
        Cset_all();
    }

    //Truck() : mass{ 7000 + (rand() % 3000)}, load_capacity{2500 + (rand() % 1500)}, horse_power{200 + (rand() % 51)}
    //{
    //    Vset_all();
    //    Eset_all();
    //    Cset_all();
    //}
    
    void change() {
        Vset_all();
        Eset_all();
        Cset_all();
    }

    void load_capacity_category() {

    }

    void horses_to_kilowatts() {

    }

    void getTruckInfo() {

        std::cout << "Масса: " << mass << " кг" << std::endl;
        std::cout << "Грузоподъемность: " << load_capacity << " кг" << std::endl;
        std::cout << "Л.С.: " << horse_power  << std::endl;

    }
};

class Car : public Vehicle {
private:

    std::string transmission;
    std::string price_category;
    std::string color;

public:
    
    Car(std::string transmission, std::string price_category, std::string color) : 
        transmission{ transmission }, price_category{ price_category }, color{ color }
    {
    }

    Car() :
        transmission{ "Автоматическая" }, price_category{ "Люкс" }, color{ "Синий" }
    {
    }

    void change() {
        Vset_all();
        Eset_all();
        Cset_all();
    }

    void getCarInfo() {

        std::cout << "Трансмиссия: " << transmission << std::endl;
        std::cout << "Ценовая категория: " << price_category << std::endl;
        std::cout << "Цвет: " << color << std::endl;
    }

};





int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    Car c;
}

