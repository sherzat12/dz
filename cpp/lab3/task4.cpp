// Задание 4. Даны натуральное число n, целые числа a1, ..., an.
// Найти количество и сумму тех членов данной последовательности,
// которые делятся на 5 и не делятся на 7.
#include <iostream>

int main() {
    int n;
    std::cout << "Введите n: ";
    std::cin >> n;

    int count = 0;
    long long sum = 0;
    std::cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; ++i) {
        long long a;
        std::cin >> a;
        if (a % 5 == 0 && a % 7 != 0) {
            ++count;
            sum += a;
        }
    }

    std::cout << "Количество: " << count << "\n";
    std::cout << "Сумма: " << sum << "\n";
    return 0;
}
