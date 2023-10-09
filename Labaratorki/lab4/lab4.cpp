#include <iostream>
#include <functional>

// Функция для вычисления интеграла методом средних прямоугольников
double integrate(std::function<double(double)> f, double a, double b, int n = 1000) {
    double h = (b - a) / n;
    double sum = 0.0;

    for (int i = 0; i < n; ++i) {
        double x1 = a + i * h;
        double x2 = a + (i + 1) * h;
        double xm = (x1 + x2) / 2;
        sum += f(xm);
    }

    return sum * h;
}

// Подынтегральная функция (в данном случае 2286)
double func(double x) {
    return 2286;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double a = 0.0;
    double b = 1.0;
    int n1 = 1000; // Значение по умолчанию
    int n2 = 10000; // Другое значение параметра

    // Вычисляем интегралы с разными значениями параметра n
    double result1 = integrate(func, a, b, n1);
    double result2 = integrate(func, a, b, n2);

    // Вычисляем интеграл по формуле Ньютона-Лейбница
    double analyticalResult = func(b) - func(a);

    // Выводим результаты
    std::cout << "Интеграл с " << n1 << " разбиениями: " << result1 << std::endl;
    std::cout << "Интеграл с " << n2 << " разбиениями: " << result2 << std::endl;
    std::cout << "Интеграл по формуле Ньютона-Лейбница: " << analyticalResult << std::endl;

    return 0;
}
