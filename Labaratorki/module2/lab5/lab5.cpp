#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "windows.h"

template<typename T>
class Array {
private:
    T* data;
    size_t size;

public:
    // Конструктор по умолчанию
    Array() : data(nullptr), size(0) {}

    // Конструктор с параметрами
    Array(size_t size) : size(size) {
        data = new T[size];
    }

    // Конструктор копирования
    Array(const Array& other) : size(other.size) {
        data = new T[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Деструктор
    ~Array() {
        delete[] data;
    }

    // Оператор присваивания
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new T[size];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Оператор индексирования
    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }

    // Ввод из потока
    void read(std::istream& is) {
        for (size_t i = 0; i < size; ++i) {
            is >> data[i];
        }
    }

    // Вывод в поток
    void print(std::ostream& os) const {
        for (size_t i = 0; i < size; ++i) {
            if (i > 0) os << ", ";
            os << data[i];
        }
        os << std::endl;
    }

    // Метод обработки массива
    void process() {
        std::cout << "Обработка массива..." << std::endl;
    }

    // Размер массива
    size_t getSize() const {
        return size;
    }

    // Изменить размер массива
    void resize(size_t newSize) {
        T* newData = new T[newSize];
        size_t minSize = (newSize > size) ? size : newSize;
        for (size_t i = 0; i < minSize; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        size = newSize;
    }
};

void reverseArray(std::string& line) {
    std::istringstream iss(line);
    std::string number;
    Array<std::string> array(100); // Примерный размер
    size_t count = 0;

    // Чтение и разделение строк
    while (getline(iss, number, ',')) {
        array[count++] = number;
        if (count == array.getSize()) {
            array.resize(count * 2);
        }
    }

    // Уменьшение размера массива до реального количества элементов
    array.resize(count);

    // Вывод в обратном порядке
    for (size_t i = count; i > 0; --i) {
        std::cout << array[i-1];
        if (i > 1) std::cout << ",";
    }
    std::cout << std::endl;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    std::string line;
    std::ifstream file("numbers.txt");

    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла." << std::endl;
        return 1;
    }

    while (getline(file, line)) {
        reverseArray(line);
    }

    file.close();
    return 0;
}
