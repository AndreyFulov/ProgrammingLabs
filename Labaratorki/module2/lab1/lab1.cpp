#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include "windows.h"

struct Client {
    std::string fullName;
    std::string accountNumber;
    double balance;
    std::string lastVisit;
};

// Функция для считывания данных из файла
std::vector<Client> readClientsFromFile(const std::string& filename) {
    std::vector<Client> clients;
    std::ifstream file(filename);
    std::string line;
    
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Client client;
        std::string balance, lastVisit;
        
        // Считываем ФИО в кавычках
        std::getline(iss, client.fullName, '"');  // Пропустить первую кавычку
        std::getline(iss, client.fullName, '"');  // Считать ФИО до следующей кавычки
        iss >> client.accountNumber >> client.balance >> client.lastVisit;

        clients.push_back(client);
    }
    
    return clients;
}

// Функция для вывода клиентов, удовлетворяющих условиям
void printClients(const std::vector<Client>& clients, double amount, const std::string& currentDate) {
    std::string currentMonth = currentDate.substr(0, 7); // "YYYY-MM"
    std::vector<std::string> eligibleClients;
    
    for (const auto& client : clients) {
        if (client.balance > amount && client.lastVisit.substr(0, 7) == currentMonth) {
            eligibleClients.push_back(client.fullName);
        }
    }
    
    std::sort(eligibleClients.begin(), eligibleClients.end());
    
    for (const auto& name : eligibleClients) {
        std::cout << name << std::endl;
    }
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    std::string filename = "clients.txt";
    double amount;
    std::string currentDate;
    
    std::cout << "Введите сумму: ";
    std::cin >> amount;
    std::cout << "Введите текущую дату (формат YYYY-MM-DD): ";
    std::cin >> currentDate;

    std::vector<Client> clients = readClientsFromFile(filename);
    printClients(clients, amount, currentDate);

    return 0;
}
