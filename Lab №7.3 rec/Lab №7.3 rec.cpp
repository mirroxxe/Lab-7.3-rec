#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

// функція для обчислення суми елементів стовпця
int colSum(int* column, int k, int i = 0, int sum = 0) {
    if (i == k) return sum;
    sum += column[i];
    return colSum(column, k, i + 1, sum);
}

// функція для обчислення суми елементів у стовпцях з від'ємними елементами
int sumOfColumnsWithNegativeElements(int** matrix, int k, int n, int j = 0, int sum = 0) {
    if (j == n) return sum;

    bool hasNegative = false;

    for (int i = 0; i < k; ++i) {
        if (matrix[j][i] < 0) {
            hasNegative = true;
            break;
        }
    }

    if (hasNegative) {
        sum += colSum(matrix[j], k);
    }

    return sumOfColumnsWithNegativeElements(matrix, k, n, j + 1, sum);
}

// функція для виводу матриці
void printMatrix(int** matrix, int k, int n, int i = 0, int j = 0) {
    if (i == k) return;
    if (j == n) {
        std::cout << "\n";
        return printMatrix(matrix, k, n, i + 1);
    }
    std::cout << std::setw(5) << matrix[j][i] << " ";
    printMatrix(matrix, k, n, i, j + 1);
}

int main() {
    srand(time(0));

    int k, n;
    std::cout << "Print rows size (k): ";
    std::cin >> k;
    std::cout << "Print cols size (n): ";
    std::cin >> n;

    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[k];
    }

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[j][i] = rand() % 100 - 50;
        }
    }

    std::cout << "Original matrix:\n";
    printMatrix(matrix, k, n);

    int sum = sumOfColumnsWithNegativeElements(matrix, k, n);

    std::cout << "Sum of elements in cols with negative elements: " << sum << "\n";

    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
