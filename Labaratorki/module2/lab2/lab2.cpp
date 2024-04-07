#include <iostream>
#include <cstdlib> // Для использования функций rand() и srand()
#include <ctime>   // Для использования функции time()

class Pair {
private:
    int first;
    int second;

public:
    Pair(int f, int s) : first(f), second(s) {
        std::cout << "Конструктор вызван" << std::endl;
    }

    ~Pair() {
        std::cout << "Деструктор вызван" << std::endl;
    }

    void Display() {
        std::cout << "first: " << first << ", second: " << second << std::endl;
    }
};

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    // Инициализируем генератор случайных чисел
    srand(time(0));

    // Генерируем случайные значения для первой пары
    int first1 = rand() % 100;
    int second1 = rand() % 100;

    // Генерируем случайные значения для второй пары
    int first2 = rand() % 100;
    int second2 = rand() % 100;

    Pair pair1(first1, second1);
    Pair pair2(first2, second2);

    std::cout << "Первая пара:" << std::endl;
    pair1.Display();

    std::cout << "Вторая пара:" << std::endl;
    pair2.Display();

    return 0;
}
