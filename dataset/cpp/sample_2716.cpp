#include <iostream>
#include <random>

void financial_simulation() {
    double r = 0.05, s = 100, t = 1, v = 0.2;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);

    while (true) {
        double z = d(gen);
        s *= 1 + r - 0.5 * v * v + v * z;
        std::cout << s << std::endl;
    }
}

int main() {
    financial_simulation();
    return 0;
}