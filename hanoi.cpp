#include <iostream>
#include <chrono>
#include <windows.h>
using namespace std;
using namespace std::chrono;

long long moveCount = 0;

void hanoi(int n, char from, char to, char aux) {
    if (n == 0) return;

    hanoi(n - 1, from, aux, to);

    moveCount++;
    cout << "Ход " << moveCount << ": диск " << n << " перемещён со стержня "
        << from << " на стержень " << to << endl;

    hanoi(n - 1, aux, to, from);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int n;
    cout << "Введите количество дисков: ";
    cin >> n;

    auto start = high_resolution_clock::now();
    hanoi(n, 'A', 'C', 'B');
    auto end = high_resolution_clock::now();

    duration<double> elapsed = end - start;

    cout << endl;
    cout << "Количество ходов: " << moveCount << endl;
    cout << "Время выполнения на этом компьютере: " << elapsed.count() << " секунд" << endl;

    cout << "Нажмите Enter для выхода...";
    cin.ignore();
    cin.get();

    return 0;
}