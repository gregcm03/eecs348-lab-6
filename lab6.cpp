#include <iostream>
#include <fstream>  

const int MAX_SIZE = 100;


void reading(int matrix[MAX_SIZE][MAX_SIZE], int& size, std::ifstream& inputFile);  
void printing(const int matrix[MAX_SIZE][MAX_SIZE], int size);
void adding(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void multiplying(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void subtracting(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

int main() {
    int size;

    std::ifstream inputFile("matrix_input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the input file." << std::endl;
        return 1;
    }

    inputFile >> size; // This is to read the size from the file

    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int resultMatrix[MAX_SIZE][MAX_SIZE];
    std::cout << "Gregory Markose" << std::endl;
    std::cout << "Lab #6: Matrix manipulation" << std::endl;
    std::cout << "Matrix A:" << std::endl;
    reading(matrixA, size, inputFile); // Passing the inputFile as a parameter
    printing(matrixA, size);

    std::cout << "Matrix B:" << std::endl;
    reading(matrixB, size, inputFile); // Passing the inputFile as a parameter
    printing(matrixB, size);

    // Adding both matrices (A+B)
    adding(matrixA, matrixB, resultMatrix, size);
    std::cout << "Matrix Sum (A + B):" << std::endl;
    printing(resultMatrix, size);

    // Multiplying both matrices (A*B)
    multiplying(matrixA, matrixB, resultMatrix, size);
    std::cout << "Matrix Product (A * B):" << std::endl;
    printing(resultMatrix, size);

    // Subtracting matrix A from matrix B
    subtracting(matrixA, matrixB, resultMatrix, size);
    std::cout << "Matrix Difference (A - B):" << std::endl;
    printing(resultMatrix, size);

    inputFile.close(); 

    return 0;
}

// All the functions

// This is the funtion to read the input file
void reading(int matrix[MAX_SIZE][MAX_SIZE], int& size, std::ifstream& inputFile) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            inputFile >> matrix[i][j];  
        }
    }
}

// This function will print the matrices
void printing(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << "  " << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

// This function will add both the matrices
void adding(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// This function will multiply both matrices
void multiplying(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// This function will subtract both the matrices
void subtracting(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}
