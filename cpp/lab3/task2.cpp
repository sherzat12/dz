// Задание 2. Даны натуральные числа n, q1, ..., qn.
// Найти те члены qi последовательности q1, ..., qn, которые:
//   а) являются удвоенными нечетными числами;
//   б) при делении на 7 дают остаток 1, 2 или 5;
//   в) обладают тем свойством, что корни уравнения x^2 + 3*qi - 5 = 0
//      действительны и положительны.
//
// ВНИМАНИЕ: уравнение в п. в) на фото читается неоднозначно. Здесь оно записано
// как x^2 + b*x + c = 0 с b = 0 и c = 3*qi - 5. Если в задании другое уравнение
// (например, с членом 3*qi*x), поменяйте значения b и c в функции main.
#include <iostream>

// Корни x^2 + b*x + c = 0 действительны и оба положительны:
// D >= 0, сумма корней (-b) > 0, произведение корней c > 0.
bool rootsRealAndPositive(long long b, long long c) {
    long long d = b * b - 4 * c;
    return d >= 0 && -b > 0 && c > 0;
}

int main() {
    int n;
    std::cout << "Введите n: ";
    std::cin >> n;
    std::cout << "Введите " << n << " натуральных чисел: ";

    // Результаты собираем по пунктам и выводим после чтения всех чисел
    const int MAX = 1000;
    long long qa[MAX], qb[MAX], qv[MAX];
    int na = 0, nb = 0, nv = 0;

    for (int i = 0; i < n && i < MAX; ++i) {
        long long q;
        std::cin >> q;

        if (q % 2 == 0 && (q / 2) % 2 != 0) qa[na++] = q;          // а) 2 * нечетное
        long long r = q % 7;
        if (r == 1 || r == 2 || r == 5) qb[nb++] = q;               // б) остаток 1, 2 или 5

        long long b = 0, c = 3 * q - 5;                              // в) x^2 + 3q - 5 = 0
        if (rootsRealAndPositive(b, c)) qv[nv++] = q;
    }

    auto print = [](const char* title, const long long* v, int cnt) {
        std::cout << title;
        if (cnt == 0) std::cout << "таких членов нет";
        for (int i = 0; i < cnt; ++i) std::cout << v[i] << ' ';
        std::cout << "\n";
    };
    print("а) удвоенные нечетные: ", qa, na);
    print("б) остаток 1, 2 или 5 при делении на 7: ", qb, nb);
    print("в) корни действительны и положительны: ", qv, nv);
    return 0;
}
