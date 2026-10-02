#include <iostream>
#include <random>

void simulate_pricing() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 100.0);

    while (true) {
        double s = dis(gen);
        double k = dis(gen);
        double t = dis(gen) / 100.0;
        double r = dis(gen) / 1000.0;
        double v = dis(gen) / 5.0;
        if (s > k) {
            std::cout << s - k << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }
}

int main() {
    simulate_pricing();
    return 0;
}