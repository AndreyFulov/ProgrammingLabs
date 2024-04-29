#include <iostream>
#include "windows.h"

class CircularList {
private:
    struct Node {
        int value;
        Node* next;

        Node(int val, Node* nxt = nullptr) : value(val), next(nxt) {}
    };

    Node* head; // Указатель на начальный узел
    Node* tail; // Указатель на последний узел
    int size;   // Количество элементов в списке

public:
    CircularList() : head(nullptr), tail(nullptr), size(0) {}

    ~CircularList() {
        while (size > 0) {
            remove(1);
        }
    }

    void add(int value) {
        Node* newNode = new Node(value);
        if (size == 0) {
            head = tail = newNode;
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
        size++;
    }

    int remove(int k) {
        Node* current = head;
        Node* prev = tail;

        // Находим k-й узел
        for (int i = 1; i < k; ++i) {
            prev = current;
            current = current->next;
        }

        int removedValue = current->value;

        if (size == 1) {
            head = tail = nullptr;
        } else {
            if (current == head) {
                head = head->next;
            }
            if (current == tail) {
                tail = prev;
            }
            prev->next = current->next;
        }

        delete current;
        size--;

        return removedValue;
    }

    bool empty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }
};

void josephus(int N, int k) {
    CircularList list;

    // Заполняем список
    for (int i = 1; i <= N; i++) {
        list.add(i);
    }

    std::cout << "Порядок удаления ребят из круга: ";
    int currentIndex = 1;
    while (!list.empty()) {
        currentIndex = (currentIndex + k - 1) % list.getSize();
        if (currentIndex == 0) currentIndex = list.getSize(); // Если k % N == 0
        int removed = list.remove(currentIndex);
        std::cout << removed << " ";
    }
    std::cout << std::endl;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int N, k;
    std::cout << "Введите количество ребят (N): ";
    std::cin >> N;
    std::cout << "Введите номер шага (k): ";
    std::cin >> k;

    josephus(N, k);

    return 0;
}
