#include <iostream>
#include <vector>
#include <string>
#include "3.h"
#include "2.h"
int main()
{
    setlocale(LC_ALL, "RU");
    std::vector<int> values = { 254, 0 , 0 };
    std::vector<std::string> names = { "РАЗ", "TWO", "THREE" };
    /*std::cout << mean(values) << std::endl;
    std::cout << median(values) << std::endl;
    std::cout << moda(values) << std::endl;*/
    by_base(values, names);
    CoctailSort(values);
    //std::cout << by_iter(values, names) << std::endl;
 //   int var;
 //   std::cout << "Choose the number:" << std::endl;
 //   std::cout << "1. Demo:" << std::endl;
 //   std::cout << "2. Random:" << std::endl;
 //   std::cout << "3. Your own choice:" << std::endl;
 //   std::cin >> var >> std::endl;
 //   if (var == 1) {
 //       /**/
//    }
 //   else if (var == 2) {
        /**/
//    }
//    else if (var == 3) {
        /**/
//    }
 //   else
//        std::cout << "There's no choice you've entered. Close the programm and try once again."; 
}