#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include "3.h"
#include "2.h"
#include "demo.h"
std::vector<std::string> names_dict(200);
int user_random(std::vector<int> v1, std::vector<std::string> v2);

int main()
{
    srand(time(NULL));
    std::vector<int> values = {1,2,3,1,2,3,1,2,3,1};
    std::vector<std::string> names;
  
  /*  moda(values)*/;
   /* user_random(values, names);*/
  
  user_random(values, names);
   

    
    
    /*std::vector<int> values = {10, 9, 8 , 7, 6 , 5, 4 , 3 ,2 ,1,0 };*/
    /*std::vector<int> values;*/
    /*std::vector<std::string> names = { "РАЗ", "TWO", "THREE" };*/
    /*std::cout << CoctailSort(values);*/


     /*by_base(values);*/
    return 0;
}

std::vector<std::string> dictionary() {
    std::vector<std::string> names_dict(200);

    std::ifstream fin;
    fin.open("NAMES.txt", std::ios_base::in);

    for (int i{ 0 }; i < names_dict.size(); i++)
        getline(fin, names_dict[i]);


    fin.close();
    return names_dict;
}


int user_random(std::vector<int> v1, std::vector<std::string> v2) {
    
    int N;
    std::cin >> N;


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

        return 0;
}