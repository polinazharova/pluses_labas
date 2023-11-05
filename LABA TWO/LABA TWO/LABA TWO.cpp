#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include "3.h"
#include "2.h"


int user_random(std::vector<int> v1, std::vector<std::string> v2);
int erased(std::vector<int>& v1, std::vector<std::string>& v2);
int added(std::vector<int>& v1, std::vector<std::string>& v2);
int choice_adderase(std::vector<int>& v1, std::vector<std::string>& v2);
int user_demo(std::vector<int> v1, std::vector<std::string> v2);
int user_input(std::vector<int> v1, std::vector<std::string> v2);

int main()
{
   
    srand(time(NULL));
    
    std::vector<int> values;
    std::vector<std::string> names;
    
    int user_choice;
  
    std::cout << "Hello! Could you choose what kind of analyzing you'd like? Put in the number of it." << std::endl;
    std::cout << "1. Demo analysis on default input values." << std::endl;
    std::cout << "2. Random values analysis (you're gonna choose the size)." << std::endl;
    std::cout << "3. User's input values (you should put in your own data)" << std::endl;
    std::cout << "Your choice is ";
    std::cin >> user_choice;

    switch (user_choice) {
        case 1:
            user_demo(values, names);
            break;
        case 2:
            user_random(values, names);
            break;
        case 3:
            user_input(values, names);
            break;
        default:
            std::cout << "There's no option you've choosen. Start the programm again and try once more." << std::endl;
            break;
    }
  
    return 0;
}


//tak mi generiruem slovar' imen
std::vector<std::string> dictionary() {
    std::vector<std::string> names_dict(200);

    std::ifstream fin;
    try {
        fin.open("NAMES.txt", std::ios_base::in);
    }
    catch (const std::exception& ex) {
        std::cout << "File opening error."<<std::endl;
            return names_dict;
    }

    for (int i{ 0 }; i < names_dict.size(); i++)
        getline(fin, names_dict[i]);

    fin.close();
    return names_dict;
}


//funkcii kotorie rabotayut ishodya iz togo chto viberet user
int user_demo(std::vector<int> v1, std::vector<std::string> v2) {
    v1 = { 100, 100, 100, 90, 30, 80, 90, 70, 75, 51 };
    v2 = { "Polina","Margarita","Anastasia","Svetlana","Denis","Artem","Konstantin","Yulia","Lyubov","Valeria" };
    
    range_based(v1, v2);
    mean(v1);
    median(v1);
    moda(v1,v2);
    choice_adderase(v1, v2);
    
    return 0;
}
int user_random(std::vector<int> v1, std::vector<std::string> v2) {
    int N;
    
    std::cout << "Put the amount of people to analyze their marks: ";
    std::cin >> N;
    std::cout << std::endl;


    if (N <= 40 && N > 0) {
        v1.resize(N);
        v2.resize(N);

        for (int i{ 0 }; i < N; i++)
            v1[i] = rand() % 101;

        for (int i{ 0 }; i < N; i++)
            v2[i] = dictionary()[rand() % 200];

        while (!moda_names(v2)) {
            v2.clear();
            v2.resize(N);
            for (int i{ 0 }; i < N; i++)
                v2[i] = dictionary()[rand() % 200];
        }
    }
    else if (N > 40 && N < 201) {
        v1.resize(N);
        v2.resize(N);
        int i = 0;
        while (true) {
            i = (rand() % 201) - N;
            if (i >= 0)
                break;
        }

        for (int j{ 0 }; j < N; j++) {
            v2[j] = dictionary()[i];
            i++;
        }
        for (int i{ 0 }; i < N; i++)
            v1[i] = rand() % 101;
    }

   range_based(v1, v2);
   mean(v1);
   median(v1);
   moda(v1, v2);
   choice_adderase(v1, v2);

        return 0;
}
int user_input(std::vector<int> v1, std::vector<std::string> v2) {
    
    std::string add_name;
    int mark;
    
    while (1) {
        
            std::cout << "Enter a name and its mark to add them: " << std::endl;
            std::cout << "To stop entering write STOP" << std::endl;
            std::cout << "Name: ";
            std::cin >> add_name;
            
            if (add_name != "STOP") {
            for (int i{ 0 }; i < v2.size(); i++) {
                if (v2[i] == add_name) {
                    std::cout << "The names must be different for the programm to work correctly. Try again." << std::endl;
                    return 0;
                }
            }
            std::cout << "Mark: ";
            std::cin >> mark;
           
            try {
                (mark >= 0 && mark <= 100) == true;
            }
            catch(const std::exception& ex){
                std::cout << "A mark must be a number ranged 0-100. Run the programm again to try one more time.";
                return 0;
            }

            
            v2.push_back(add_name);
            v1.push_back(mark);
        }
        else
            break;
    }
    
    by_base(v1, v2);
    mean(v1);
    median(v1);
    moda(v1, v2);
    choice_adderase(v1, v2);

    return 0;
}


//funkcii dlya dobavleniya i udaleniya elementov
int choice_adderase(std::vector<int>& v1, std::vector<std::string>& v2) {
    int user_choice;
    std::cout << "You can also delete a name-mark pair or add a new one: " << std::endl;
    std::cout << "1. Delete or add a pair." << std::endl;
    std::cout << "2. Close the programm." << std::endl;
    std::cout << "You're choosing: ";
    std::cin >> user_choice;
    if (user_choice == 1) {
        while (true) {
            std::cout << "You'd like to add or delete a pair? To close the programm write any other symbol: " << std::endl;
            std::cout << "1. Delete" << "\t" << "2. Add" << std::endl;
            std::cout << " Your choice is: ";
            std::cin >> user_choice;

            if (user_choice == 1)
                erased(v1, v2);
            else if (user_choice == 2)
                added(v1, v2);
            else {
                std::cout << "Thanks for using our programm! To get new analysis run it once again.";
                break;
            }
        }
    }
    else
        std::cout << "Thanks for using our programm! To get new analysis run it once again.";


    return 0;
}
int erased(std::vector<int> &v1, std::vector<std::string> &v2) {
    std::cout << "Choose a name to delete it and its mark: ";
    std::string del_name;
    std::cin >> del_name;

    std::vector<int>::iterator iter = v1.begin();
    for (std::vector<std::string>::iterator i = v2.begin(); i != v2.end(); i++) {
        if (del_name == *i) {
            v2.erase(i);
            v1.erase(iter);
            break;
        }
        std::advance(iter, 1);
    }
    by_base(v1, v2);
    mean(v1);
    median(v1);
    moda(v1,v2);
    

    return 0;
}
int added(std::vector<int>& v1, std::vector<std::string>& v2) {
    std::cout << "Enter a name and its mark to add them: " << std::endl;
    
    std::string add_name;
    int mark;
   
    std::cout << "Name: ";
    std::cin >> add_name;
    
    for (int i{ 0 }; i < v2.size(); i++) {
        if (v2[i] == add_name) {
            std::cout << "The names must be different for the programm to work correctly. Try again." << std::endl;
            return 0;
        }
    }
    std::cout << "Mark: ";
    std::cin >> mark;
    v2.push_back(add_name);
    v1.push_back(mark);

    by_base(v1, v2);
    mean(v1);
    median(v1);
    moda(v1,v2);

    return 0;
}