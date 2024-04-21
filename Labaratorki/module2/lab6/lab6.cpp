#include <iostream>
#include <list>

void josephus(int n, int k) {
    // Создаем список для хранения номеров ребят
    std::list<int> circle;

    // Заполняем список номерами ребят от 1 до N
    for (int i = 1; i <= n; ++i) {
        circle.push_back(i);
    }

    // Итератор, указывающий на начало списка
    std::list<int>::iterator it = circle.begin();

    // Пока список не опустеет
    while (!circle.empty()) {
        // Перемещаем итератор на k-1 шагов вперед
        for (int i = 0; i < k - 1; ++i) {
            if (it == circle.end()) {
                // Если достигли конца списка, переходим к началу
                it = circle.begin();
            }
            ++it;
        }

        // Выводим номер удаляемого ребенка
        std::cout << *it << " ";

        // Удаляем ребенка из списка
        it = circle.erase(it);

        // Если достигли конца списка, переходим к началу
        if (it == circle.end()) {
            it = circle.begin();
        }
    }
}

int main() {
    int N, k;
    std::cout << "Введите количество ребят (N): ";
    std::cin >> N;
    std::cout << "Введите номер шага (k): ";
    std::cin >> k;

    std::cout << "Порядок удаления ребят из круга: ";
    josephus(N, k);
    std::cout << std::endl;

    return 0;
}
