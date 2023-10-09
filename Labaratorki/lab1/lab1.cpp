#include <iostream>
#include <sstream>

int main() {
    setlocale(LC_ALL, "Russian");
    const int n = 5; // Размерность матрицы 5x5
    int Z[n][n]; // Объявляем матрицу размером 5x5

    // Заполняем матрицу
    std::cout << "Введите элементы матрицы " << n << "x" << n << " (каждая строка через пробел):\n";
    for (int i = 0; i < n; ++i) {
        std::string input;
        std::getline(std::cin, input);
        std::istringstream iss(input);

        for (int j = 0; j < n; ++j) {
            if (!(iss >> Z[i][j])) {
                std::cout << "Ошибка ввода. Пожалуйста, введите " << n << " элементов в строке.\n";
                return 1; // Выход с ошибкой
            }
        }
    }

    // Вычисляем сумму элементов в строках с нулевым элементом на главной диагонали
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (Z[i][i] == 0) {
            for (int j = 0; j < n; ++j) {
                sum += Z[i][j];
            }
        }
    }

    // Заменяем элементы на главной диагонали суммой
    for (int i = 0; i < n; ++i) {
        if (Z[i][i] == 0) {
            Z[i][i] = sum;
        }
    }

    // Выводим исходную и преобразованную матрицы
    std::cout << "Исходная матрица:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << Z[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}