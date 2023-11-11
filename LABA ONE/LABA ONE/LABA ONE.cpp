#include "1.h"
#include "2.h"
#include "extra task.h"

int main(){

    /*
    1) strlen - str.size();
    2) strcpy - strcpy(kogo, kuda) ili str.copy(string);
    3) strcmp - strcmp(s1,s2);
    4) strcat - strcat(s1,s2);
    5) someString[index] - someString[index];
    6) ANALOGOV NET - push_back
    7) ANALOGOV NET - pop_back

    v C stroki - eto standartnie massivi char, v C++ po suti tozhe, no ih usovershenstvovali, opredelili v otdelniy tip dannih
    i uprostili rabotu s nimi.
    */

  
    std::cout << "Put your string to be sorted: ";
    std::string init_str;
    std::getline(std::cin, init_str);
    line_sorting(init_str);
  


    /*
        1) int* ptr = (int*)malloc(sizeof(int)) - int* ptr = new int;
        2) int* ptrArr = (int*)malloc(sizeof(int) * N) - int** ptrArr = new int* [];
        3) free(ptr) - delete ptr;
        4) free(ptrArr) - delete[] ptrArr;

        v C++ neobhodimo osvobozhdat' dinamicheskeyu pamyat', esli ona videlyaetsya napramuyu vami, 
        esli popitat'sya ochistit' ne prinadlezhashuyu vam oblast' pamyati, to budet oshibka,
        programma ne buder rabotat' korrektno.
    */


    std::cout << "Put your number of strings in Fibonacci triangle: ";
    int str_amount;
    std::cin >> str_amount;
    fib_triangle(str_amount);

    bank();

    return 0;
    }



