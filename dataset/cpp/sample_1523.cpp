#include <iostream>
#include <vector>
#include <random>

void simulate_thermo_state() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    std::vector<double> a(10);
    for (int i = 0; i < 10; ++i) {
        a[i] = dis(gen);
    }

    while (true) {
        std::vector<double> b(10);
        for (int i = 0; i < 10; ++i) {
            b[i] = dis(gen);
        }

        double dot_product = 0.0;
        for (int i = 0; i < 10; ++i) {
            dot_product += a[i] * b[i];
        }

        a = std::vector<double>(10, dot_product);
    }
}

int main() {
    simulate_thermo_state();
    return 0;
}