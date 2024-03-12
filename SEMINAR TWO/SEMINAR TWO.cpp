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
        for (int i{ 0 }; i < n; i++) 
            delete [] data[i];
        delete[] data;
    }

    void Filling() {
        for (int i{ 0 }; i < n; i++) {
            for (int j{ 0 }; j < m; j++) 
                data[i][j] = rand() % 10;
            
        }
    }

    void operator [] (int num) {
        if (num > n * m || num < 0)
            std::cout << "ERROR! INDEX IS NOT EXISTED!" << std::endl;
        else {
            std::cout << data[0][0] << std::endl;
            std::cout << "Would you like to chat that element?" << std::endl;

        }
    }
    
    void operator << (Matrix& matrix) {
        std::cout << "Your matrix is: " << std::endl;
        for (int i{ 0 }; i < n; i++) {
            for (int j{ 0 }; j < m; j++)
                std::cout << data[i][j] << " ";
            std::cout << std::endl;
        }
    }

    void operator + (Matrix& other) {
        if (n != other.n || m != other.m)
            std::cout << "CANNOT BE DONE. MATRIXES STRINGS OR COLLUMNS AREN'T EQUAL!" << std::endl;
        else {
            std::cout << "Your summary matrix is: " << std::endl;
            for (int i{ 0 }; i < n; i++) {
                for (int j{ 0 }; j < m; j++)
                    std::cout << data[i][j] + other.data[i][j] << " ";
                std::cout << std::endl;
            }
        }
    }


    void operator - (Matrix& other) {
        if (n != other.n || m != other.m)
            std::cout << "CANNOT BE DONE. MATRIXES STRINGS OR COLLUMNS AREN'T EQUAL!" << std::endl;
        else {
            std::cout << "Your substracted matrix is: " << std::endl;
            for (int i{ 0 }; i < n; i++) {
                for (int j{ 0 }; j < m; j++)
                    std::cout << data[i][j] - other.data[i][j] << " ";
                std::cout << std::endl;
            }
        }
    }

    void operator * (Matrix& other) {
        if (m != other.n)
            std::cout << "CANNOT BE DONE!" << std::endl;
        else {
            int temp{ 0 };
            std::cout << "Your multiplied matrix is: " << std::endl;
            for (int i{ 0 }; i < n; i++) {
                for (int j{ 0 }; j < m; j++) {
                        temp += data[i][j] * other.data[j][i];
                        if (j == m - 1) {
                            std::cout << temp << " ";
                            temp = 0;
                            break;
                        }
                }
                std::cout << std::endl;
            }
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

    Matrix m;
    Matrix s(3,5);
    m.Filling();
    s.Filling();
    //m << m;
    //s << s;
    m * s;
    //std::cout << (m == s) << std::endl;
    /*m << m;
    s << s;
    m + s;
    m << m;
    s << s;*/
 
}


