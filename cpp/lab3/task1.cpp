// Задание 1. Даны натуральные числа n, a1, ..., an.
// Определить количество членов ak последовательности a1, ..., an:
//   а) являющихся нечетными числами;
//   б) кратных 3 и не кратных 5;
//   в) являющихся квадратами четных чисел;
//   е) имеющих четные порядковые номера и являющихся нечетными числами.
#include <cmath>
#include <iostream>

// true, если x = k*k для некоторого четного k
bool isSquareOfEven(long long x) {
    long long k = static_cast<long long>(std::llround(std::sqrt(static_cast<double>(x))));
    return k * k == x && k % 2 == 0;
}

int main() {
    int n;
    std::cout << "Введите n: ";
    std::cin >> n;

    int countA = 0, countB = 0, countV = 0, countE = 0;
    std::cout << "Введите " << n << " натуральных чисел: ";
    for (int i = 1; i <= n; ++i) {
        long long a;
        std::cin >> a;
        if (a % 2 != 0) ++countA;                    // а) нечетные
        if (a % 3 == 0 && a % 5 != 0) ++countB;      // б) кратны 3 и не кратны 5
        if (isSquareOfEven(a)) ++countV;             // в) квадраты четных чисел
        if (i % 2 == 0 && a % 2 != 0) ++countE;      // е) четный номер и нечетное значение
    }

    std::cout << "а) нечетных: " << countA << "\n";
    std::cout << "б) кратных 3 и не кратных 5: " << countB << "\n";
    std::cout << "в) квадратов четных чисел: " << countV << "\n";
    std::cout << "е) с четным номером и нечетных: " << countE << "\n";
    return 0;
}
