#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

void calculate_p_values() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);

    while (true) {
        std::vector<double> a(100);
        std::vector<double> b(100);

        for (int i = 0; i < 100; ++i) {
            a[i] = d(gen);
            b[i] = d(gen);
        }

        std::vector<double> permuted_a = a;
        std::vector<double> permuted_b = b;

        std::shuffle(permuted_a.begin(), permuted_a.end(), gen);
        std::shuffle(permuted_b.begin(), permuted_b.end(), gen);

        double t_stat = 0.0;
        double p_val = 0.0;

        std::cout << p_val << std::endl;
    }
}

int main() {
    calculate_p_values();
    return 0;
}