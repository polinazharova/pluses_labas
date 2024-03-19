#include "Matrix.h"

template <typename T>
unsigned int notFirstMax(T* array, unsigned int size) {
    if (size <= 1) {
        std::cout << "There is no second maximum!" << std::endl;
        return 0;
    }
    else {
        unsigned int firstPosition = 0;
        unsigned int secondPosition = 0;
        for (unsigned int i{ 1 }; i < size; i++) {
            if (array[i] > array[firstPosition]) {
                secondPosition = firstPosition;
                firstPosition = i;
            }
            if (array[i] < array[firstPosition] && array[i] > array[secondPosition]) {
                secondPosition = i;
            }
            
        }
        return secondPosition;
    }

}

class Vector {
    std::string str[3];
};

int main()
{
    srand(time(NULL));
    /* double data[5] = {2.1, 2.3, 3.5, 3.7, 3.6};
    std::cout << notFirstMax(data, 5);*/

    Matrix<float> rand;
    Matrix<float> randw2;

    rand.filling();
    randw2.filling();
    rand << "  |  ";
    std::cout << std::endl;
    randw2 << "  |  ";
    std::cout << std::endl;
    Matrix<float>& res = rand + randw2;

    res << "  |  ";

    delete &res;
   
}

