#include <iostream>

class Matrix {
private:
    unsigned int m;
    unsigned int n;
    int **data = new int*[n];

public:
    Matrix() : n(3), m(3) 
    {
        for (int i{ 0 }; i < n; i++) 
            data[i] = new int[m];
        
    }
    Matrix(unsigned int n, unsigned int m) : n(n), m(m)
    {
        for (int i{ 0 }; i < n; i++)
            data[i] = new int[m];

    }

    ~Matrix() {
        std::cout << "Destruction." << std::endl;
        for (int i{ 0 }; i < n; i++) {
            delete[] data[i];
            data[i] = nullptr;
        }
        delete[] data;
        data = nullptr;
    }

    void filling() {
        int choice;
        std::cout << "Choose what to fill the matrix with: " << std::endl;
        std::cout << "1 - RANDOM FILLING." << std::endl;
        std::cout << "2 - UNIT FILLING." << std::endl;
        std::cout << "3 - CUSTOM FILLING." << std::endl;
        std::cin >> choice;
        switch (choice) {
        case 1:
            for (int i{ 0 }; i < n; i++) {
                for (int j{ 0 }; j < m; j++)
                    data[i][j] = rand() % 10;
            }
            break;
        case 2:
            for (int i{ 0 }; i < n; i++) {
                for (int j{ 0 }; j < m; j++) {
                    if (j == i)
                        data[i][j] = 1;
                    else
                        data[i][j] = 0;

                }
            }
            break;
        case 3: {
            unsigned int element;
            for (int i{ 0 }; i < n; i++) {
                for (int j{ 0 }; j < m; j++) {
                    std::cout << "Put in the element of " << i + 1 << " row " << j + 1 << " column: ";
                    std::cin >> element;
                    data[i][j] = element;
                }
            }
            break;
        }

        default:
            std::cout << "There was no such choice. The numbers will be randomized.";
            for (int i{ 0 }; i < n; i++) {
                for (int j{ 0 }; j < m; j++)
                    data[i][j] = rand() % 10;
            }
            break;
        }
    }

    int& operator [] (unsigned int num) {
        if (num >= n * m || num < 0)
            std::cout << "ERROR! INDEX IS NOT EXISTED!" << std::endl;
        else {
            return data[num/m][num%m];
        }
    }
    
    void operator << (std::string gap) {
        for (int i{ 0 }; i < n; i++) {
            for (int j{ 0 }; j < m; j++)
                std::cout << data[i][j] << gap;
            std::cout << std::endl;
        }
    }

    Matrix& operator + (const Matrix& other) {
        if (n != other.n || m != other.m)
            std::cout << "CANNOT BE DONE. MATRIXES STRINGS OR COLLUMNS AREN'T EQUAL!" << std::endl;
        else {
            Matrix* demo = new Matrix(n,m);
            for (int i{ 0 }; i < n; i++) {
                for (int j{ 0 }; j < m; j++)
                    (*demo).data[i][j] = data[i][j] + other.data[i][j];
            }
            return *demo;
        }
    }


    Matrix& operator - (const Matrix& other) {
        if (n != other.n || m != other.m)
            std::cout << "CANNOT BE DONE. MATRIXES STRINGS OR COLLUMNS AREN'T EQUAL!" << std::endl;
        else {
            Matrix* demo = new Matrix(n,m);
            for (int i{ 0 }; i < n; i++) {
                for (int j{ 0 }; j < m; j++)
                    (*demo).data[i][j] = data[i][j] - other.data[i][j];
            }
            return *demo;
        }
    }

    Matrix& operator * (Matrix& other) {
        if (m != other.n)
            std::cout << "CANNOT BE DONE!" << std::endl;
        else {
            Matrix* demo = new Matrix(n, other.m);
            unsigned int temp{ 0 };
            for (int i{ 0 }; i < m; i++) {
                for (int j{ 0 }; j < m; j++) {
                    for (int k{ 0 }; k < m; k++) {
                        temp += data[j][k] * other.data[k][i];
                    }
                    (*demo).data[j][i] = temp;
                    temp = 0;
                }
           }
            std::cout << demo << std::endl;
            return *demo;
        }
    }

    void operator += (Matrix& other) {
        if (n != other.n || m != other.m)
            std::cout << "CANNOT BE DONE. MATRIXES STRINGS OR COLLUMNS AREN'T EQUAL!" << std::endl;
        else {
            for (int i{ 0 }; i < n; i++) {
                for (int j{ 0 }; j < m; j++)
                    data[i][j] += other.data[i][j];
            }
        }
    }

    void operator -= (Matrix& other) {
        if (n != other.n || m != other.m)
            std::cout << "CANNOT BE DONE. MATRIXES STRINGS OR COLLUMNS AREN'T EQUAL!" << std::endl;
        else {
            for (int i{ 0 }; i < n; i++) {
                for (int j{ 0 }; j < m; j++)
                    data[i][j] -= other.data[i][j];
            }
        }
    }

    bool operator == (Matrix& other) {
        if (n != other.n || m != other.m)
            std::cout << "CANNOT BE DONE. MATRIXES STRINGS OR COLLUMNS AREN'T EQUAL!" << std::endl;
        else {
            for (int i{ 0 }; i < n; i++) {
                for (int j{ 0 }; j < m; j++) {
                    if (data[i][j] != other.data[i][j])
                        return false;
                }
            }
            return true;
        }
    }

    bool operator != (Matrix& other) {
        if (n != other.n || m != other.m)
            std::cout << "CANNOT BE DONE. MATRIXES STRINGS OR COLLUMNS AREN'T EQUAL!" << std::endl;
        else {
            for (int i{ 0 }; i < n; i++) {
                for (int j{ 0 }; j < m; j++) {
                    if (data[i][j] != other.data[i][j])
                        return true;
                }
            }
            return false;
        }
    }
};
    
    

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");

    Matrix m;
    Matrix s;
    m.filling();
    m[3] = 3;
    m << " ";
    /*m[11];*/
   // s.filling();
   // Matrix& ms = m * s;

   // std::cout << &ms << std::endl;
   ///* ms << "|";*/
   // delete &ms;
  
}


