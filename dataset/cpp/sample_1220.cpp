#include <iostream>
#include <random>
#include <vector>

double run_simulation() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    std::vector<double> a(100);
    std::vector<double> b(100);

    for (int i = 0; i < 100; ++i) {
        a[i] = dis(gen);
        b[i] = dis(gen);
    }

    double p_value = dis(gen);
    if (p_value < 0.05) {
        return 1.0;
    }
    return 0.0;
}

int main() {
    for (int _ = 0; _ < 10; ++_) {
        if (run_simulation() == 1.0) {
            break;
        }
    }
    return 0;
}