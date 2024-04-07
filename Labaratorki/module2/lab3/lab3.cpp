#include <iostream>

class Pair {
protected:
    int first;
    int second;

public:
    Pair(int f, int s) : first(f), second(s) {}

    void setFirst(int f) {
        first = f;
    }

    void setSecond(int s) {
        second = s;
    }

    int getProduct() const {
        return first * second;
    }
};

class Rectangle : public Pair {
public:
    Rectangle(int length, int width) : Pair(length, width) {}

    int getPerimeter() const {
        return 2 * (first + second);
    }

    int getArea() const {
        return first * second;
    }
};

int main() {
    Rectangle rect(5, 4);

    std::cout << "Произведение чисел в прямоугольнике: " << rect.getProduct() << std::endl;
    std::cout << "Периметр прямоугольника: " << rect.getPerimeter() << std::endl;
    std::cout << "Площадь прямоугольника: " << rect.getArea() << std::endl;

    return 0;
}
