#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "3.h"
#include "2.h"
#include "demo.h"
int user_random(std::vector<int> v1);
int main()
{
    std::vector<int> values;
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    /*std::vector<int> values = {10, 9, 8 , 7, 6 , 5, 4 , 3 ,2 ,1,0 };*/
    /*std::vector<int> values;*/
    std::vector<std::string> names = { "РАЗ", "TWO", "THREE" };
    /*std::cout << CoctailSort(values);*/
    user_random(values);

     /*by_base(values);*/
    return 0;
}



int user_random(std::vector<int> v1) {
    int N;
    std::cin >> N;
    v1.resize(N);
    for (int i{ 0 }; i < N; i++)
        v1[i] = rand() % 100;
    by_base(v1);
        return 0;
}