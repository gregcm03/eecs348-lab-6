#include <iostream>
#include <fstream>  // Include this header for file handling

const int MAX_SIZE = 100;

// Function prototypes
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int& size, std::ifstream& inputFile);  // Add std::ifstream argument
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size);
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

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
    readMatrix(matrixA, size, inputFile); // Passing the inputFile as a parameter
    printMatrix(matrixA, size);

    std::cout << "Matrix B:" << std::endl;
    readMatrix(matrixB, size, inputFile); // Passing the inputFile as a parameter
    printMatrix(matrixB, size);

    // Adding both matrices (A+B)
    addMatrices(matrixA, matrixB, resultMatrix, size);
    std::cout << "Matrix Sum (A + B):" << std::endl;
    printMatrix(resultMatrix, size);

    // Multiplying both matrices (A*B)
    multiplyMatrices(matrixA, matrixB, resultMatrix, size);
    std::cout << "Matrix Product (A * B):" << std::endl;
    printMatrix(resultMatrix, size);

    // Subtracting matrix A from matrix B
    subtractMatrices(matrixA, matrixB, resultMatrix, size);
    std::cout << "Matrix Difference (A - B):" << std::endl;
    printMatrix(resultMatrix, size);

    inputFile.close(); // Close the input file

    return 0;
}


// This is the funtion to read the input file

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int& size, std::ifstream& inputFile) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            inputFile >> matrix[i][j];  // Read from the input file
        }
    }
}

// This function will print the matrices
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << "  " << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

// This function will add both the matrices
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// This function will multiply both matrices
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
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
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}
