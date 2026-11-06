
#include <iostream>
#include <chrono>

bool Unique(const int A[], int n, long long& op_count) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            op_count++;
            if (A[i] == A[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int sizes[] = {1000, 2000, 4000, 8000, 16000};

    for (int n : sizes) {
        int* A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = i;
        }
        long long op_count = 0;
        auto start = std::chrono::steady_clock::now();
        bool result = Unique(A, n, op_count);
        auto stop = std::chrono::steady_clock::now();
        auto elapsed =
            std::chrono::duration_cast<std::chrono::microseconds >(stop - start).count();

        std::cout << "N = " << n << "\tOperations = " << op_count << "\tTime = " << elapsed << " us\n";
        delete[] A;
    }

    return 0;
}




