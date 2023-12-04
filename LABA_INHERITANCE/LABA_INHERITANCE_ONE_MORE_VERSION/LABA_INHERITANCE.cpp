#include "classes.h"

//сначала я написала эту программу, она рабочая, но ее архитектура довольно странна... но, наверное, имеет место быть
void car_choosing() {
    std::string transmission, price_category, color, registration_number, brand, Ename, gender, residence, Cname, owner;
    int release_year, price, age, creation_date;

    std::cout << "Трансмиссия: ";
    std::cin >> transmission;

    std::cout << "Ценовая категория: ";
    std::cin >> price_category;

    std::cout << "Цвет: ";
    std::cin >> color;

    std::cout << "Введите регистрационный номер машины: ";
    std::cin >> registration_number;

    std::cout << "Введите марку машины: ";
    std::cin >> brand;

    std::cout << "Введите год выпуска машины: ";
    std::cin >> release_year;

    std::cout << "Введите цену машины: ";
    std::cin >> price;

    std::cin.ignore();
    std::cout << "Введите имя и фамилию владельца машины: ";
    std::getline(std::cin, Ename);

    std::cin.ignore();
    std::cout << "Введите пол владельца машины: ";
    std::cin >> gender;

    std::cout << "Введите возраст владельца машины: ";
    std::cin >> age;

    std::cin.ignore();
    std::cout << "Введите место жительства владельца машины: ";
    std::getline(std::cin, residence);

    std::cin.ignore();
    std::cout << "Введите название компании: ";
    std::getline(std::cin, Cname);
    std::cin.ignore();
    std::cout << "Введите год основания компании: ";
    std::cin >> creation_date;

    std::cin.ignore();
    std::cout << "Введите имя и фамилию владельца компании: ";
    std::getline(std::cin, owner);

    Car c(transmission, price_category, color,
        Cname, creation_date, owner,
        registration_number, brand, release_year, price,
        Ename, gender, age, residence);
}
void truck_choosing() {

    std::string registration_number, brand, Ename, gender, residence, Cname, owner;
    int release_year, price, age, creation_date;
    double mass, load_capacity, horse_power;

    std::cout << "Масса: ";
    std::cin >> mass;


    std::cout << "Грузоподъемность: ";
    std::cin >> load_capacity;


    std::cout << "Л.С.: ";
    std::cin >> horse_power;

    std::cout << "Введите регистрационный номер машины: ";
    std::cin >> registration_number;


    std::cout << "Введите марку машины: ";
    std::cin >> brand;

    std::cout << "Введите год выпуска машины: ";
    std::cin >> release_year;


    std::cout << "Введите цену машины: ";
    std::cin >> price;

    std::cin.ignore();
    std::cout << "Введите имя и фамилию владельца машины: ";
    std::getline(std::cin, Ename);

    std::cin.ignore();
    std::cout << "Введите пол владельца машины: ";
    std::cin >> gender;


    std::cout << "Введите возраст владельца машины: ";
    std::cin >> age;

    std::cin.ignore();
    std::cout << "Введите место жительства владельца машины: ";
    std::getline(std::cin, residence);

    std::cin.ignore();
    std::cout << "Введите название компании: ";
    std::getline(std::cin, Cname);
    std::cin.ignore();
    std::cout << "Введите год основания компании: ";
    std::cin >> creation_date;

    std::cin.ignore();
    std::cout << "Введите имя и фамилию владельца компании: ";
    std::getline(std::cin, owner);

    Truck t(mass, load_capacity, horse_power,
        Cname, creation_date, owner,
        registration_number, brand, release_year, price,
        Ename, gender, age, residence);
}


int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    //предисловие
    std::cout << "Здравствуйте! Нами было проведено расследование, в котором было выяснено," << std::endl;
    std::cout << "что какой-то сотрудник одной из наших дочерних компаний крадет канцелярию с рабочего места." << std::endl;
    std::cout << "Теперь каждый работник всех принадлежащих нам организаций обязан ввести данные о себе, о том," << std::endl;
    std::cout << "в какой именно из наших компаний он работает, а также - самое главное - данные о своем транспортном средстве." << std::endl;
    std::cout << "Да, именно по тому, на какой машине вы ездете, мы определим, вы ли своровали в прошлом месяце 7 ручек и пачку бумаги или нет." << std::endl;
    std::cout << "Вы можете посмотреть демонстрационный вариант с автоматически сгенерированными значениями," << std::endl;
    std::cout << "чтобы увидеть, какая информация нам требуется. " << std::endl<<std::endl;

    int choice;
    std::cout << "Вы можете воспользоваться данными по умолчанию (нажмите 1) или ввести собственные (нажмите 2): ";
    std::cin >> choice;
    
    switch (choice)
    {
    case 1:
        choice = 1 + rand() % 2;
        if (choice == 1) {
            Car c;
            c.getallInfo();
        }
        else{
            Truck t;
            t.getallInfo();
        }
        break;

    case 2:
        std::cout << "Вы владеете легковым автомобилем (нажмите 1) или грузовым (нажмите 2)?";
        std::cin >> choice;
        if (choice == 1) {
            Car c;
            c.getallInfo();
        }
        else if (choice == 2) {
            Truck t;
            t.getallInfo();
        }
        else {
            std::cout << "Такого варианта не было...";
        }
        break;
            
    default:
        std::cout << "Такого варианта не было...";
        break;
    }
   
    return 0;

}

