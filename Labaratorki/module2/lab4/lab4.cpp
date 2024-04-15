#include <iostream>
#include <cmath>
#include <stdexcept>

class Triangle {
private:
    double sides[3];  // Стороны треугольника
    double angles[3]; // Углы треугольника в градусах

public:
    // Конструктор с проверками сторон и углов
    Triangle(double a, double b, double c, double alpha, double beta, double gamma) {
        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || b + c <= a || c + a <= b || 
            alpha <= 0 || beta <= 0 || gamma <= 0 || alpha + beta + gamma != 180) {
            throw std::invalid_argument("Некорректные размеры сторон или углов треугольника.");
        }
        sides[0] = a;
        sides[1] = b;
        sides[2] = c;
        angles[0] = alpha;
        angles[1] = beta;
        angles[2] = gamma;
    }

    // Оператор для доступа к сторонам и углам по индексу
    double operator[](int index) const {
        if (index < 0 || index > 5) {
            throw std::out_of_range("Индекс вне диапазона");
        }
        if (index < 3) return sides[index]; // Возвращает сторону
        else return angles[index - 3];      // Возвращает угол
    }

    // Оператор сравнения треугольников
    bool operator==(const Triangle& other) const {
        for (int i = 0; i < 3; i++) {
            if (sides[i] != other.sides[i] || angles[i] != other.angles[i]) return false;
        }
        return true;
    }

    bool operator!=(const Triangle& other) const {
        return !(*this == other);
    }

    // Переопределение оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Triangle& t) {
        os << "Треугольник со сторонами: a=" << t.sides[0] << ", b=" << t.sides[1] << ", c=" << t.sides[2]
           << ", углы: α=" << t.angles[0] << ", β=" << t.angles[1] << ", γ=" << t.angles[2];
        return os;
    }

    // Вычисление периметра
    double operator+() const {
        return sides[0] + sides[1] + sides[2];
    }

    // Вычисление площади треугольника
    double area() const {
        double s = +*this / 2;  // Полупериметр
        return sqrt(s * (s - sides[0]) * (s - sides[1]) * (s - sides[2]));
    }

    // Определение типа треугольника
    std::string type() const {
        bool hasRightAngle = (angles[0] == 90 || angles[1] == 90 || angles[2] == 90);
        if (sides[0] == sides[1] && sides[1] == sides[2])
            return "Равносторонний";
        else if (hasRightAngle)
            return "Прямоугольный";
        else if (sides[0] == sides[1] || sides[1] == sides[2] || sides[0] == sides[2])
            return "Равнобедренный";
        return "Разносторонний";
    }
};

int main() {
    double a, b, c, alpha, beta, gamma;

    std::cout << "Введите стороны треугольника a, b, c и углы α, β, γ (в градусах): ";
    std::cin >> a >> b >> c >> alpha >> beta >> gamma;

    try {
        Triangle t(a, b, c, alpha, beta, gamma);
        std::cout << t << std::endl;
        std::cout << "Периметр: " << +t << std::endl;
        std::cout << "Площадь: " << t.area() << std::endl;
        std::cout << "Тип: " << t.type() << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Ошибка при создании треугольника: " << e.what() << std::endl;
    }}