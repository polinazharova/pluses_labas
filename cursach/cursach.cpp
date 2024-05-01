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
public:
    int getX1() { return positionX1; }
    int getX2() { return positionX2; }
    int getY() { return positionY; }

    void setX1(int X1) {
        if (X1 > 0 && X1 < 52)
            this->positionX1 = X1;
    }
    void setX2(int X2) {
        if (X2 > 1 && X2 < 53)
            this->positionX2 = X2;
    }
    void setY(int Y) {
        if (Y > 0 && Y < 26)
            this->positionY = Y;
    }
};

class Prey : public Character {
public:
    Prey() {
        setX1(14); setX2(15), setY(12);
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
        setX1(36); setX2(37), setY(12);
    }

    void npcActing() {
        if (prey.getX1() != getX1() && prey.getX1() != getX2() && prey.getX2() != getX1() && prey.getY() != getY()) {
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
        else if (prey.getX1() == getX1() || prey.getX1() == getX2() || prey.getX2() == getX1()) {
            if (prey.getY() < getY())
                setY((getY()) - 1);
            else if (prey.getY() > getY())
                setY((getY()) + 1);
        }
        else if (prey.getY() == getY()) {
            if (prey.getX1() < getX1()) {
                setX1((getX1()) - 1);
                setX2((getX2()) - 1);
            }
            else if (prey.getX1() > getX1()) {
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
        if (((*prey).getX1() == (*pred).getX1() || (*prey).getX1() == (*pred).getX2() || (*prey).getX2() == (*pred).getX1()) && (*prey).getY() == (*pred).getY())
            return true;
        else
            return false;
    }
};

class Point2D : public Character {
private:
    Prey& prey;
    Predator& pred;
public:
    Point2D(Predator& pred, Prey& prey) : prey(prey), pred(pred) {}

    void playerPreyActing() {
        bool is_wrong_key = true;
        while (is_wrong_key) {
            int hit = _getch();
            switch (hit) {
            case 119: //W
                is_wrong_key = false;
                prey.setY(prey.getY() - 1);
                break;
            case 115: //S
                is_wrong_key = false;
                prey.setY(prey.getY() + 1);
                break;
            case 97: //A
                is_wrong_key = false;
                prey.setX1(prey.getX1() - 1);
                prey.setX2(prey.getX2() - 1);
                break;
            case 100: //D
                is_wrong_key = false;
                prey.setX1(prey.getX1() + 1);
                prey.setX2(prey.getX2() + 1);
                break;
            case 101: //E
                is_wrong_key = false;
                prey.setY(prey.getY() - 1);
                prey.setX1(prey.getX1() + 1);
                prey.setX2(prey.getX2() + 1);
                break;
            case 113: //Q
                is_wrong_key = false;
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
                is_wrong_key = false;
                prey.setY(prey.getY() + 1);
                prey.setX1(prey.getX1() - 1);
                prey.setX2(prey.getX2() - 1);
                break;
            default:
                std::cout << "Неверно нажатая клавиша." << std::endl;
                break;
            }
            
        }
    }

    void playerPredActing() {
        bool is_wrong_key = true;
        while (is_wrong_key) {
            int hit = _getch();
            switch (hit) {
            case 119: //W
                is_wrong_key = false;
                pred.setY(pred.getY() - 1);
                break;
            case 115: //S
                is_wrong_key = false;
                pred.setY(pred.getY() + 1);
                break;
            case 97: //A
                is_wrong_key = false;
                pred.setX1(pred.getX1() - 1);
                pred.setX2(pred.getX2() - 1);
                break;
            case 100: //D
                is_wrong_key = false;
                pred.setX1(pred.getX1() + 1);
                pred.setX2(pred.getX2() + 1);
                break;
            default:
                std::cout << "Неверно нажатая клавиша." << std::endl;
                break;
            }
        }
    }


};


void lost() {
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
}

void won() {
    std::string won = R"( /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\ 
( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )
 > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ < 
 /\_/\                                            /\_/\ 
( o.o )  __   __ __  _  _   _   _  __  __  _ _   ( o.o )
 > ^ <   \ `v' //__\| || | | | | |/__\|  \| / \   > ^ < 
 /\_/\    `. .'| \/ | \/ | | 'V' | \/ | | ' \_/   /\_/\ 
( o.o )    !_!  \__/ \__/  !_/ \_!\__/|_|\__(_)  ( o.o )
 > ^ <                                            > ^ < 
 /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\  /\_/\ 
( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )( o.o )
 > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ <  > ^ < )";

    for (int i{ 0 }; i < won.size(); i++) {
        if (won[i] == '\n') {
            Sleep(10);
        }
        Sleep(1);
        std::cout << won[i];
    }
}

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

    std::cout << "                                     Cправка:\n";
    std::cout << "                                     Клавиши управления: W,A,S,D,Z,C,Q,E.\n";
    std::cout << "                                     ** - жертва, () - хищник.\n";

    while (true) {
        std::cout << "\n\n\n\n\n\n\n\n\n                                     За кого вы хотите играть?\n                                     1 - хищник, 2 - жертва" << std::endl;
        std::cout << "                                     0 - ВЫХОД.\n";
        std::cout << "                                     Ваш выбор: ";
        int choice;
        std::cin >> choice;
        switch (choice) {
        case 1: {
            int steps = 30;
            while (true) {
                system("cls");
                std::cout << "Осталось шагов: " << steps << std::endl;

                ar.setPredatorOnArena();
                ar.setPreyOnArena();
                ar.arenaShow();

                if (ar.ifGameisOver()) {
                    system("cls");
                    won();
                    system("cls");
                    break;
                }

                if (steps == 0) {
                    system("cls");
                    lost();
                    system("cls");
                    break;
                }
                std::cout << "Выберите кол-во ходов: 1, 2, 3 (нажмите клавишу)\n";
                int hit = _getch();
                bool are_wrong_steps = true;
                while (are_wrong_steps) {
                    int hit = _getch();
                    switch (hit) {
                    case 49: //1
                        are_wrong_steps = false;
                        std::cout << "ХОДИТЕ!\n";
                        ddd.playerPredActing();
                        system("cls");
                        ar.setPredatorOnArena();
                        ar.setPreyOnArena();
                        ar.arenaShow();
                        break;
                    case 50: //2
                        are_wrong_steps = false;
                        for (int i{ 0 }; i < 2; i++) {
                            std::cout << "ХОДИТЕ!\n";
                            ddd.playerPredActing();
                            system("cls");
                            ar.setPredatorOnArena();
                            ar.setPreyOnArena();
                            std::cout << "Осталось шагов хищника: " << 1 - i << std::endl;
                            ar.arenaShow();
                        }
                        break;
                    case 51: //3
                        are_wrong_steps = false;
                        for (int i{ 0 }; i < 3; i++) {
                            std::cout << "ХОДИТЕ!\n";
                            ddd.playerPredActing();
                            system("cls");
                            ar.setPredatorOnArena();
                            ar.setPreyOnArena();
                            std::cout << "Осталось шагов хищника: " << 2 - i << std::endl;
                            ar.arenaShow();
                        }
                        break;
                    default:
                        std::cout << "Неверно нажатая клавиша." << std::endl;
                        break;
                    }
                }

                if (ar.ifGameisOver()) {
                    system("cls");
                    won();
                    system("cls");
                    break;
                }

                prey.npcActing();
                steps--;
            }
            break;
        }
        case 2: {
            int steps = 30;
            while (true) {
                system("cls");

                std::cout << "Осталось шагов: " << steps << std::endl;
                ar.setPredatorOnArena();
                ar.setPreyOnArena();
                ar.arenaShow();

                if (ar.ifGameisOver()) {
                    system("cls");
                    lost();
                    break;
                }

                if (steps == 0) {
                    system("cls");
                    won();
                    break;
                }

                std::cout << "ХОДИТЕ!\n";
                pr.npcActing();
                ddd.playerPreyActing();
                steps--;
            }
            break;
        }
        case 0: {
            system("cls");
            std::string game_over = R"(__| |__________________________________________________________________| |__
__   __________________________________________________________________   __
  | |                                                                  | |  
  | |  ______        ______  _______     _____  _    _ _______ ______  | |  
  | | / _____)  /\  |  ___ \(_______)   / ___ \| |  | (_______|_____ \ | |  
  | || /  ___  /  \ | | _ | |_____     | |   | | |  | |_____   _____) )| |  
  | || | (___)/ /\ \| || || |  ___)    | |   | |\ \/ /|  ___) (_____ ( | |  
  | || \____/| |__| | || || | |_____   | |___| | \  / | |_____      | || |  
  | | \_____/|______|_||_||_|_______)   \_____/   \/  |_______)     |_|| |  
__| |__________________________________________________________________| |__
__   __________________________________________________________________   __
  | |                                                                  | |  )";
            for (int i{ 0 }; i < game_over.size(); i++) {
                if (game_over[i] == '\n') {
                    Sleep(10);
                }
                std::cout << game_over[i];
            }
            system("cls");
            for (int i{ 0 }; i < 3; i++) {
                std::cout << game_over << std::endl;
                Sleep(500);
                system("cls");
            }
            return 0;
            break;
        }
        default: 
            system("cls");
            std::cout << "\n\n\n\n\n\n\n\n\n                                     Некорректный выбор...\n";
            std::cout << "                                     За кого вы хотите играть?\n                                     1 - хищник, 2 - жертва" << std::endl;
            std::cout << "                                     0 - ВЫХОД.\n";
            std::cout << "                                     Ваш выбор: ";
            std::cin >> choice;
            break;
        }
   
    }
    return 0;
}

