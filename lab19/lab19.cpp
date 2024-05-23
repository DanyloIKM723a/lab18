#include <iostream>

class Matrix {
private:
    int data[2][3];

public:

    Matrix() {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                data[i][j] = 0;
            }
        }
    }


    Matrix(int arr[2][3]) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                data[i][j] = arr[i][j];
            }
        }
    }


    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return result;
    }


    Matrix operator-(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.data[i][j] = this->data[i][j] - other.data[i][j];
            }
        }
        return result;
    }


    bool operator==(const Matrix& other) const {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (this->data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }


    void print() const {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int arr1[2][3] = { {1, 2, 3}, {4, 5, 6} };
    int arr2[2][3] = { {6, 5, 4}, {3, 2, 1} };

    Matrix mat1(arr1);
    Matrix mat2(arr2);

    std::cout << "Matrix 1:" << std::endl;
    mat1.print();

    std::cout << "Matrix 2:" << std::endl;
    mat2.print();

    Matrix sum = mat1 + mat2;
    std::cout << "Matrix 1 + Matrix 2:" << std::endl;
    sum.print();

    Matrix diff = mat1 - mat2;
    std::cout << "Matrix 1 - Matrix 2:" << std::endl;
    diff.print();

    bool isEqual = mat1 == mat2;
    std::cout << "Matrix 1 == Matrix 2: " << (isEqual ? "True" : "False") << std::endl;

    return 0;
}
