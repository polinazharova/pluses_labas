﻿#include "classes.h"

//не совсем поняла задание, поэтому, может, выполнила не полностью так, как требовалось, но старалась...

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    int choice;

    //предисловие
    std::cout << "Здравствуйте! Нами было проведено расследование, в котором было выяснено," << std::endl;
    std::cout << "что какой-то сотрудник одной из наших дочерних компаний крадет канцелярию с рабочего места." << std::endl;
    std::cout << "Теперь каждый работник всех принадлежащих нам организаций обязан ввести данные о себе, о том," << std::endl;
    std::cout << "в какой именно из наших компаний он работает, а также - самое главное - данные о своем транспортном средстве." << std::endl;
    std::cout << "Да, именно по тому, на какой машине вы ездите, мы определим, вы ли своровали в прошлом месяце 7 ручек и пачку бумаги или нет." << std::endl;
    std::cout << "Вы пришли группой, поэтому просто введите информацию о своей компании и каждый требуемые данные." << std::endl;
    std::cout << "Вы можете посмотреть демонстрационный вариант с автоматически сгенерированными значениями," << std::endl;
    std::cout << "чтобы увидеть, какая информация нам требуется. " << std::endl<<std::endl;
    std::cout << "1 - посмотреть демонстрационный вариант, 2 - начать вписывать свои данные. Ваш выбор: ";

    std::cin >> choice;
    switch (choice)
    {
    case 1:
    {
        Company c;
        c.deleting();
        break;
    }

    case 2:
    {   
        std::cout << "WARNING! если при нажатии Enter происход переход на новую строку, но не появляется текст,";
        std::cout << "то нажмите Enter еще раз, ничего больше не вводя." << std::endl;

        int N;
        std::cout << "Сколько человек вы собираетесь записать? ";
        std::cin >> N;

        if (N <= 0)
            N = 3;

        Company c(N);
        std::cout << "А щас мы предоставим список людей, у которых в ближайшее время устроим обыск" << std::endl;
        std::cout << "в надежде вернуть бумагу и ручки, принадлежащие нашей корпорации." << std::endl;
        c.thief_finding();

        c.deleting();
        break;
    }
    default:
        std::cout << "Такого варианта не было.";
        break;
    }

    return 0;

}

