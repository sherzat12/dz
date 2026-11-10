// Задание 3. Даны целые числа a1, ..., a50.
// Получить сумму тех чисел данной последовательности, которые:
//   а) кратны 5;
//   б) нечетны и отрицательны;
//   в) удовлетворяют условию |ai| < i^2.
#include <cstdlib>
#include <iostream>

int main() {
    const int N = 50;
    long long sumA = 0, sumB = 0, sumV = 0;

    std::cout << "Введите " << N << " целых чисел: ";
    for (int i = 1; i <= N; ++i) {
        long long a;
        std::cin >> a;
        if (a % 5 == 0) sumA += a;                                   // а) кратны 5
        if (a % 2 != 0 && a < 0) sumB += a;                          // б) нечетные и отрицательные
        if (std::llabs(a) < static_cast<long long>(i) * i) sumV += a; // в) |ai| < i^2
    }

    std::cout << "а) сумма кратных 5: " << sumA << "\n";
    std::cout << "б) сумма нечетных отрицательных: " << sumB << "\n";
    std::cout << "в) сумма чисел с |ai| < i^2: " << sumV << "\n";
    return 0;
}
