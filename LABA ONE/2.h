#include <iostream>
#include <iomanip>


int fib_triangle(int N) {

    int** arr = new int* [N];

    for (int i{ 0 }; i < N; i++) 
        *(arr + i) = new int[i + 1];
   

    *(*(arr + 0) + 0) = 1;
    *(*(arr + 1) + 0) = 1;
    *(*(arr + 1) + 1) = 1;

    for (int i{ 2 }; i < N; i++) {
        for (int j{ 0 }; j < i + 1; j++) {

            if (j == i) {
                *(*(arr + i) + j) = *(*(arr + (i - 1)) + (j - 1)) + *(*(arr + (i - 2)) + (j - 2));
                continue;
            }

            if (((i - 2) < j) && j != i) {
                *(*(arr + i) + j) = *(*(arr + (i - 1)) + j);
                continue;
            }

            *(*(arr + i) + j) = *(*(arr + (i - 1)) + j) + *(*(arr + (i - 2)) + j);

        }
    }

    for (int i{ 0 }; i < N; i++) {

        if (i > 5 && i < 7)
            std::cout << std::setw(N * 3 - i - 1);
        else if (i > 10 && i <= 15)
            std::cout << std::setw(N * 3 - i - 6);
        else if (i >= 7 && i <= 10)
            std::cout << std::setw(N * 3 - i - 3);
        else if (i > 15)
            std::cout << std::setw(N * 3 - i - 14);
        else
            std::cout << std::setw(N * 3 - i);
       
        for (int j = 0; j < i + 1; j++)
            std::cout << *(*(arr + i) + j) << " ";
        std::cout << std::endl;

    }
    for (int i{ 0 }; i < N; i++) {
        delete[] *(arr+i);
    }

    delete[] arr;

    return 0;
}


