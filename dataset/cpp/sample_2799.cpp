#include <iostream>
#include <random>
#include <vector>

void process_sequence() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    while (true) {
        std::vector<int> a(10), b(10);
        int c = 0;

        for (int i = 0; i < 10; ++i) {
            a[i] = dis(gen);
            b[i] = dis(gen);
            c += a[i] * b[i];
        }

        std::cout << c << std::endl;
    }
}

int main() {
    process_sequence();
    return 0;
}