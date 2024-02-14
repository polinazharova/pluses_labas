#include <iostream>


class Dispenser {
private:

    class CashRegister {
    public:

        int cash;
        int candyprice;
        int chipprice;
        int gumprice;
        int cookieprice;

        void addCash(int cash) {
            this->cash += cash;
        }
        int getCash() { return cash; }

        CashRegister() :cash(0), candyprice(3), chipprice(10), gumprice(1), cookieprice(5) {}
        ~CashRegister() { std::cout << "DESCTRUCTION." << std::endl; }
    };

    CashRegister casher;

    int candies;
    int chips;
    int gums;
    int cookies;

public:

    Dispenser() : candies(100), chips(100), gums(100), cookies(100) {
    }
    ~Dispenser() { std::cout << "DESCTRUCTION." << std::endl; }

    int getCash() { return casher.getCash(); }


    void showing() {
        std::cout << "Candies: " << candies << std::endl;
        std::cout << "Chips: " << chips << std::endl;
        std::cout << "Gums: " << gums << std::endl;
        std::cout << "Cookies: " << cookies << std::endl;

    }
    void prices() {
        std::cout << "Candies price: " << casher.candyprice << std::endl;
        std::cout << "Chips price: " << casher.chipprice << std::endl;
        std::cout << "Gums price: " << casher.gumprice << std::endl;
        std::cout << "Cookies price: " << casher.cookieprice << std::endl;

    }

    void makeSell() {
        int choice;
        std::cout << "1 - cookie." << std::endl;
        std::cout << "2 - chips." << std::endl;
        std::cout << "3 - gum." << std::endl;
        std::cout << "4 - candie." << std::endl;
        std::cin >> choice;

        switch (choice) {
        case 1:
            if (cookies == 0) {
                std::cout << "Out of stock!" << std::endl;
                break;
            }
            std::cout << "Put your amount of money: ";
            std::cin >> choice;
            if (choice < casher.cookieprice) {
                std::cout << "Not enough money to buy it!" << std::endl;
                break;
            }
            else if (choice > casher.cookieprice) {
                cookies -= 1;
                casher.addCash(casher.cookieprice);
                std::cout << "Here's your change: " << choice - casher.cookieprice << " dollars" << std::endl;
                break;
            }
            else {
                cookies -= 1;
                casher.addCash(casher.cookieprice);
                std::cout << "SOLD!" << std::endl;
                break;
            }
        case 2:
            if (chips == 0) {
                std::cout << "Out of stock!" << std::endl;
                break;
            }
            std::cout << "Put your amount of money: ";
            std::cin >> choice;
            if (choice < casher.chipprice) {
                std::cout << "Not enough money to buy it!" << std::endl;
                break;
            }
            else if (choice > casher.chipprice) {
                cookies -= 1;
                casher.addCash(casher.chipprice);
                std::cout << "Here's your change: " << choice - casher.chipprice << " dollars" << std::endl;
                break;
            }
            else {
                chips -= 1;
                casher.addCash(casher.chipprice);
                std::cout << "SOLD!" << std::endl;
                break;
            }
        case 3:
            if (gums == 0) {
                std::cout << "Out of stock!" << std::endl;
                break;
            }
            std::cout << "Put your amount of money: ";
            std::cin >> choice;
            if (choice < casher.gumprice) {
                std::cout << "Not enough money to buy it!" << std::endl;
                break;
            }
            else if (choice > casher.gumprice) {
                cookies -= 1;
                casher.addCash(casher.gumprice);
                std::cout << "Here's your change: " << choice - casher.gumprice << " dollars" << std::endl;
                break;
            }
            else {
                gums -= 1;
                casher.addCash(casher.gumprice);
                std::cout << "SOLD!" << std::endl;
                break;
            }
        case 4:
            if (candies == 0) {
                std::cout << "Out of stock!" << std::endl;
                break;
            }
            std::cout << "Put your amount of money: ";
            std::cin >> choice;
            if (choice != casher.candyprice) {
                std::cout << "Not enough money to buy it!" << std::endl;
                break;
            }
            else if (choice > casher.candyprice) {
                cookies -= 1;
                casher.addCash(casher.candyprice);
                std::cout << "Here's your change: " << choice - casher.candyprice << " dollars" << std::endl;
                break;
            }
            else {
                candies -= 1;
                casher.addCash(casher.candyprice);
                std::cout << "SOLD!" << std::endl;
                break;
            }
        default:
            std::cout << "No such choice" << std::endl;
            break;
        }
    }
};

int main()
{
    Dispenser item;
    std::cout << "Now we have " << item.getCash() << " dollars" << std::endl;
    item.showing();
    item.prices();
    item.makeSell();
    std::cout << "Now we have " << item.getCash() << " dollars" << std::endl;
    item.showing();
    return 0;
}