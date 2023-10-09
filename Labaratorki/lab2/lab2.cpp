#include <iostream>

// Функция для выделения памяти и создания матрицы размерности m x n
int** createMatrix(int m, int n) {
    int** matrix = new int* [m];
    for (int i = 0; i < m; ++i) {
        matrix[i] = new int[n];
    }
    return matrix;
}

// Функция для освобождения памяти, выделенной под матрицу
void deleteMatrix(int** matrix, int m) {
    for (int i = 0; i < m; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int m, n;

    std::cout << "Введите количество строк (m): ";
    std::cin >> m;
    std::cout << "Введите количество столбцов (n): ";
    std::cin >> n;

    // Создаем и заполняем матрицу
    int** matrix = createMatrix(m, n);
    std::cout << "Введите элементы матрицы " << m << "x" << n << ":\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    // Найдем строки с минимальным и максимальным элементами
    int minRow = 0, maxRow = 0;
    int minValue = matrix[0][0], maxValue = matrix[0][0];

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] < minValue) {
                minValue = matrix[i][j];
                minRow = i;
            }
            if (matrix[i][j] > maxValue) {
                maxValue = matrix[i][j];
                maxRow = i;
            }
        }
    }

    // Меняем строки местами
    int* tempRow = matrix[minRow];
    matrix[minRow] = matrix[maxRow];
    matrix[maxRow] = tempRow;

    // Выводим исходную и результирующую матрицы
    std::cout << "Исходная матрица:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }

    // Освобождаем память
    deleteMatrix(matrix, m);

    return 0;
}
