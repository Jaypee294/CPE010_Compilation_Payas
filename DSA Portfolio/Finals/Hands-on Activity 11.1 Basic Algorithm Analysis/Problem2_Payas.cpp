
#include <iostream>
#include <chrono>

long long rpower(long long x, int n, long long& ops) {
    if (n == 0) return 1;
    ops++;
    return x * rpower(x, n - 1, ops);
}
long long brpower(long long x, int n, long long& ops) {
    if (n == 0) return 1;
    long long y = brpower(x, n / 2, ops);
    if (n % 2 == 1) {
        ops += 2;
        return x * y * y;
    }
    ops++;
    return y * y;
}

int main() {
    int sizes[] = {100, 500, 1000, 2000, 4000};

    for (int n : sizes) {
        long long a = 0, b = 0;

        auto start = std::chrono::steady_clock::now();
        rpower(1, n, a);
        auto end = std::chrono::steady_clock::now();
        auto t1 = std::chrono::duration_cast<
            std::chrono::microseconds>(end - start).count();

        start = std::chrono::steady_clock::now();
        brpower(1, n, b);
        end = std::chrono::steady_clock::now();
        auto t2 = std::chrono::duration_cast<
            std::chrono::microseconds>(end - start).count();

        std::cout << "N = " << n << "  rpower Ops = " << a << "  Time = " << t1 << " us\n";
        std::cout << "N = " << n << "  brpower Ops = " << b << "  Time = " << t2 << " us\n";
    }

    return 0;
}