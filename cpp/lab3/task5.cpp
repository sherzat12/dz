// Задание 5. Даны натуральные числа n, p, целые числа a1, ..., an.
// Получить произведение членов последовательности, кратных p.
#include <iostream>

int main() {
    int n;
    long long p;
    std::cout << "Введите n и p: ";
    std::cin >> n >> p;

    long long product = 1;
    bool found = false;
    std::cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; ++i) {
        long long a;
        std::cin >> a;
        if (a % p == 0) {
            product *= a;
            found = true;
        }
    }

    if (found)
        std::cout << "Произведение членов, кратных " << p << ": " << product << "\n";
    else
        std::cout << "Членов, кратных " << p << ", нет\n";
    return 0;
}
