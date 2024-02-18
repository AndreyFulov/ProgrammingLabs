#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

int main() {
    setlocale(LC_ALL, "Russian");
    std::string filename;
    char userChar;

    // Запрашиваем имя файла и символ с клавиатуры
    std::cout << "Введите имя файла: ";
    std::cin >> filename;

    std::cout << "Введите символ: ";
    std::cin >> userChar;

    // Открываем файл
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл " << filename << std::endl;
        return 1;
    }

    // Чтение строки из файла в символьный массив
    std::string fileContents;
    std::getline(file, fileContents);

    // Разделяем символы больше и меньше введенного символа
    std::vector<char> greaterChars;
    std::vector<char> smallerChars;

    for (char c : fileContents) {
        if (c > userChar) {
            greaterChars.push_back(c);
        }
        else if (c < userChar) {
            smallerChars.push_back(c);
        }
    }

    // Объединяем символы в одну строку
    std::string resultString;
    for (char c : greaterChars) {
        resultString += c;
    }

    for (char c : smallerChars) {
        resultString += c;
    }

    // Выводим исходную и преобразованную строки
    std::cout << "Исходная строка из файла: " << fileContents << std::endl;
    std::cout << "Преобразованная строка: " << resultString << std::endl;
    system("pause");

    // Закрываем файл
    file.close();

    return 0;
}
