#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

struct Client {
    std::string fullName;
    std::string accountNumber;
    double balance;
    std::string lastModifiedDate;
};

// Функция для чтения данных из файла и заполнения массива структур
std::vector<Client> readClientsFromFile(const std::string& filename) {
    std::vector<Client> clients;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return clients;
    }

    Client client;
    while (file >> client.fullName >> client.accountNumber >> client.balance >> client.lastModifiedDate) {
        clients.push_back(client);
    }

    file.close();
    return clients;
}

// Функция для подсчета количества клиентов с балансом больше заданной суммы и последним посещением в заданном месяце
int countClientsWithBalanceAndDate(const std::vector<Client>& clients, double targetBalance, const std::string& targetMonth) {
    int count = 0;
    for (const auto& client : clients) {
        if (client.balance > targetBalance) {
            std::string clientMonth = client.lastModifiedDate.substr(3, 2); // Получаем месяц из даты последнего изменения
            if (clientMonth == targetMonth) {
                count++;
            }
        }
    }
    return count;
}

// Функция для вывода фамилий клиентов с балансом больше заданной суммы и последним посещением в заданном месяце
void printClientsWithBalanceAndDate(const std::vector<Client>& clients, double targetBalance, const std::string& targetMonth) {
    std::vector<std::string> names;
    for (const auto& client : clients) {
        if (client.balance > targetBalance) {
            std::string clientMonth = client.lastModifiedDate.substr(3, 2); // Получаем месяц из даты последнего изменения
            if (clientMonth == targetMonth) {
                names.push_back(client.fullName);
            }
        }
    }

    // Сортировка фамилий по алфавиту
    std::sort(names.begin(), names.end());

    // Вывод фамилий
    for (const auto& name : names) {
        std::cout << name << std::endl;
    }
}

int main() {

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    std::string filename = "clients.txt"; // Имя файла с данными о клиентах
    double targetBalance; // Баланс для сравнения
    std::string targetMonth; // Месяц для сравнения

    std::cout << "Введите сумму для сравнения: ";
    std::cin >> targetBalance;
    std::cout << "Введите месяц для сравнения (в формате MM): ";
    std::cin >> targetMonth;

    std::vector<Client> clients = readClientsFromFile(filename);

    if (!clients.empty()) {
        int count = countClientsWithBalanceAndDate(clients, targetBalance, targetMonth);
        std::cout << "Количество клиентов с балансом больше " << targetBalance << " и посещавших банк в " << targetMonth << " месяце: " << count << std::endl;
        std::cout << "Фамилии клиентов в алфавитном порядке:" << std::endl;
        printClientsWithBalanceAndDate(clients, targetBalance, targetMonth);
    } else {
        std::cout << "Ошибка чтения данных из файла." << std::endl;
    }

    return 0;
}
