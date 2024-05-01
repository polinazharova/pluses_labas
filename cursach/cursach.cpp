#include <iostream>
#include <vector>
#include <iomanip>
#include "Windows.h"
#include <conio.h>

class Character {
private:
    int positionX1;
    int positionX2;
    int positionY;
    int positionX1_prev{0};
    int positionX2_prev{0};
    int positionY_prev{0};
public:
    int getX1() { return positionX1; }
    int getX2() { return positionX2; }
    int getY() { return positionY; }
    int getPrevX1() { return positionX1_prev; }
    int getPrevX2() { return positionX2_prev; }
    int getPrevY() { return positionY_prev; }

    void setX1(int X1) {
        if (X1 > 1 && X1 < 29)
            this->positionX1 = X1;
    }
    void setX2(int X2) {
        if (X2 > 2 && X2 < 30)
            this->positionX2 = X2;
    }
    void setY(int Y) {
        if (Y >= 1 && Y < 30)
            this->positionY = Y;
    }
    void setPrevPos(int positionX1_prev, int positionX2_prev, int positionY_prev) {
        this->positionX1_prev = positionX1_prev;
        this->positionX2_prev = positionX2_prev;
        this->positionY_prev = positionY_prev;
    }

};

class Prey : public Character {
public:
    Prey() {
        setX1(10); setX2(11), setY(5);
    }

    void npcActing() {
        int temp1 = -1 + rand() % 3;
        int temp2 = -1 + rand() % 3;
        while (temp1 == 0 && temp2 == 0) {
            temp1 = -1 + rand() % 3;
            temp2 = -1 + rand() % 3;
        }
     
        setX1(getX1() + temp1);
        setX2(getX2() + temp1);
        setY(getY() + temp2);
    }
};

class Predator : public Character {
private:
    Prey& prey;
public:
    Predator(Prey& prey) : prey(prey) {
        setX1(15); setX2(16), setY(9);
    }

    void npcActing() {
        if (prey.getX1() != getX1() && prey.getX1() != getX2() && prey.getY() != getY()) {
            int temp = rand() % 2;
            switch (temp) {
            case 0: 
                if (prey.getX1() < getX1()) {
                    setX1((getX1()) - 1);
                    setX2((getX2()) - 1);
                }
                else {
                    setX1((getX1()) + 1);
                    setX2((getX2()) + 1);
                }
            case 1: 
                if (prey.getY() < getY())
                    setY((getY()) - 1);
                else
                    setY((getY()) + 1);
            }
        }
        else if (prey.getX1() == getX1() && prey.getX1() == getX2()) {
            if (prey.getY() < getY())
                setY((getY()) - 1);
            else
                setY((getY()) + 1);
        }
        else {
            if (prey.getX1() < getX1()) {
                setX1((getX1()) - 1);
                setX2((getX2()) - 1);
            }
            else {
                setX1((getX1()) + 1);
                setX2((getX2()) + 1);
            }
        }
    }
};

class Arena {
private:
    int side;
    char border;
    std::vector<std::vector<char>> arena;
    Predator* pred;
    Prey* prey;
    bool GameOver = false;
public:
    Arena(Predator* pred, Prey* prey) : side{27}, border('='), arena(side), pred(pred), prey(prey) {
        for (int i{ 0 }; i < side; i++) {
            if (i == 0 || i == (side) - 1) {
                arena[i].resize(side * 2, border);
            }
            else {
                arena[i].resize(side * 2);
                for (int j{ 0 }; j < side * 2; j++) {
                    if (j == 0 || j == (side * 2) - 1)
                        arena[i][j] = '|';
                    else
                        arena[i][j] = ' ';
                }
            }
        }
    }

    void arenaShow() {
        for (int i{ 0 }; i < side; i++) {
            for (int j{ 0 }; j < side * 2; j++) {
                if (j == 0 && i != 0 && i != side - 1)
                    std::cout << std::setw(5) << std::right << i;
                else if (j == 0)
                    std::cout << std::setw(5) << std::right << "";
                std::cout << arena[i][j];
            }
            std::cout << std::endl;
            if (i == side - 1) {
                for (int j{ 0 }; j < side * 2; j++) {
                    if (j == 0 || j == (side * 2) - 1)
                        std::cout << std::setw(6) << std::left << "";
                    else if (j == 1)
                        std::cout << " ";
                    else if (j % 2 != 0)
                        std::cout << std::setw(2) << std::left << j / 2;
                    else
                        std::cout << "";
                }
                std::cout << std::endl;
            }
        }
        arena[(*prey).getY()][(*prey).getX1()] = ' ';
        arena[(*prey).getY()][(*prey).getX2()] = ' ';
        arena[(*pred).getY()][(*pred).getX1()] = ' ';
        arena[(*pred).getY()][(*pred).getX2()] = ' ';
    }

    void setPreyOnArena() {
        arena[(*prey).getY()][(*prey).getX1()] = '*';
        arena[(*prey).getY()][(*prey).getX2()] = '*';
    }
    void setPredatorOnArena() {
        arena[(*pred).getY()][(*pred).getX1()] = '(';
        arena[(*pred).getY()][(*pred).getX2()] = ')';
    }

    bool ifGameisOver() {
        if ((*prey).getX1() == (*pred).getX1() || (*prey).getY() == (*pred).getY())
            return true;
    }
};

class Point2D : public Character {
private:
    Prey& prey;
    Predator& pred;
public:
    Point2D(Predator& pred, Prey& prey) : prey(prey), pred(pred) {}

    void playerPreyActing() {
        int hit = _getch();
        std::cout << hit << '\n';
        switch (hit) {
        case 119: //W
            prey.setY(prey.getY() - 1);
            break;
        case 115: //S
            prey.setY(prey.getY() + 1);
            break;
        case 97: //A
            prey.setX1(prey.getX1() - 1);
            prey.setX2(prey.getX2() - 1);
            break;
        case 100: //D
            prey.setX1(prey.getX1() + 1);
            prey.setX2(prey.getX2() + 1);
            break;
        case 101: //E
            prey.setY(prey.getY() - 1);
            prey.setX1(prey.getX1() + 1);
            prey.setX2(prey.getX2() + 1);
            break;
        case 113: //Q
            prey.setY(prey.getY() - 1);
            prey.setX1(prey.getX1() - 1);
            prey.setX2(prey.getX2() - 1);
            break;
        case 99: //C
            prey.setY(prey.getY() + 1);
            prey.setX1(prey.getX1() + 1);
            prey.setX2(prey.getX2() + 1);
            break;
        case 122: //Z
            prey.setY(prey.getY() + 1);
            prey.setX1(prey.getX1() - 1);
            prey.setX2(prey.getX2() - 1);
            break;
        }
    }

    void playerPredActing() {
        int hit = _getch();
        std::cout << hit << '\n';
        switch (hit) {
        case 119: //W
            pred.setY(pred.getY() - 1);
            break;
        case 115: //S
            pred.setY(pred.getY() + 1);
            break;
        case 97: //A
            pred.setX1(pred.getX1() - 1);
            pred.setX2(pred.getX2() - 1);
            break;
        case 100: //D
            pred.setX1(pred.getX1() + 1);
            pred.setX2(pred.getX2() + 1);
            break;
        }
    }


};


int main()
{
    setlocale(LC_ALL, "rus");
    std::string new_game = R"(__| |___________________________________________________________| |__
__   ___________________________________________________________   __
  | |                                                           | |  
  | | ______  _______ _  _  _     ______        ______  _______ | |  
  | ||  ___ \(_______) || || |   / _____)  /\  |  ___ \(_______)| |  
  | || |   | |_____  | || || |  | /  ___  /  \ | | _ | |_____   | |  
  | || |   | |  ___) | ||_|| |  | | (___)/ /\ \| || || |  ___)  | |  
  | || |   | | |_____| |___| |  | \____/| |__| | || || | |_____ | |  
  | ||_|   |_|_______)\______|   \_____/|______|_||_||_|_______)| |  
__| |___________________________________________________________| |__
__   ___________________________________________________________   __
  | |                                                           | |  )";

    for (int i{ 0 }; i < new_game.size(); i++) {
        if (new_game[i] == '\n') {
            Sleep(10);
        }
        std::cout << new_game[i];
    }
    system("cls");
    for (int i{ 0 }; i < 3; i++) {
        std::cout << new_game << std::endl;
        Sleep(500);
        system("cls");
    }


    Prey prey;
    Predator pr(prey);
    Arena ar(&pr, &prey);
    Point2D ddd(pr, prey);
    ar.setPredatorOnArena();
    ar.setPreyOnArena();
    ar.arenaShow();

    std::cout << "Выберите кол-во ходов: 1, 2, 3 (нажмите клавишу)\n";
    int hit = _getch();
    switch (hit) {
    case 49: //1
        std::cout << "ХОДИТЕ!\n";
        ddd.playerPredActing();
        system("cls");
        ar.setPredatorOnArena();
        ar.setPreyOnArena();
        ar.arenaShow();
        break;
    case 50: //2
        for (int i{ 0 }; i < 2; i++) {
            std::cout << "ХОДИТЕ!\n";
            ddd.playerPredActing();
            system("cls");
            ar.setPredatorOnArena();
            ar.setPreyOnArena();
            ar.arenaShow();
        }
        break;
    case 51: //3
        for (int i{ 0 }; i < 3; i++) {
            std::cout << "ХОДИТЕ!\n";
            ddd.playerPredActing();
            system("cls");
            ar.setPredatorOnArena();
            ar.setPreyOnArena();
            ar.arenaShow();
        }
        break;
    }


    ar.setPredatorOnArena();
    ar.setPreyOnArena();
    ar.arenaShow();
    ddd.playerPreyActing();
    pr.npcActing();
    system("cls");
    Sleep(0);
    ar.setPredatorOnArena();
    ar.setPreyOnArena();
    ar.arenaShow();
    ddd.playerPreyActing();
    pr.npcActing();
    system("cls");
    Sleep(0);
    ar.setPredatorOnArena();
    ar.setPreyOnArena();
    ar.arenaShow();
    ddd.playerPreyActing();
    pr.npcActing();
    ar.setPredatorOnArena();
    ar.setPreyOnArena();
    ar.arenaShow();
    ddd.playerPreyActing();
    pr.npcActing();
    ar.setPredatorOnArena();
    ar.setPreyOnArena();
    ar.arenaShow();
    ddd.playerPreyActing();
    pr.npcActing();
    ar.setPredatorOnArena();
    ar.setPreyOnArena();
    ar.arenaShow();
    ddd.playerPreyActing();
    pr.npcActing();
    ar.setPredatorOnArena();
    ar.setPreyOnArena();
    ar.arenaShow();
    ddd.playerPreyActing();
    pr.npcActing();
    ar.setPredatorOnArena();
    ar.setPreyOnArena();
    ar.arenaShow();
    ddd.playerPreyActing();
    pr.npcActing();
    ar.setPredatorOnArena();
    ar.setPreyOnArena();
    ar.arenaShow();


    /*ddd.playerPreyActing();*/
    /*while (ar.ifGameisOver()) {
        pr.npcActing();
        ddd.playerPreyActing();
        ar.setPredatorOnArena();
        ar.setPreyOnArena();
        ar.arenaShow();
        Sleep(1000);
        system("cls");
        Sleep(1000);
        
    }*/
   
    std::string lost = R"(::::::::::::::::::::::::::::::::::::::::::::::::::
::::::::::::::::::::::::::::::::::::::::::::::::::
::       ___           __    ___  __  _____  _  ::
::/\_/\ /___\/\ /\    / /   /___\/ _\/__   \/ \ ::
::\_ _///  // / \ \  / /   //  //\ \   / /\/  / ::
:: / \/ \_//\ \_/ / / /___/ \_// _\ \ / / /\_/  ::
:: \_/\___/  \___/  \____/\___/  \__/ \/  \/    ::
::                                              ::
::::::::::::::::::::::::::::::::::::::::::::::::::
::::::::::::::::::::::::::::::::::::::::::::::::::)";

    for (int i{ 0 }; i < lost.size(); i++) {
        if (lost[i] == '\n') {
            Sleep(10);
        }
        Sleep(1);
        std::cout << lost[i];
    }
 


   
    return 0;
}

