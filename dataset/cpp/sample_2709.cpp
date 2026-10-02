#include <iostream>
#include <cmath>
#include <random>

void financial_model() {
    while (true) {
        double s = 100;
        double r = 0.05;
        double t = 1;
        double v = 0.2;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> dis(0, 1);
        double z = dis(gen);
        double st = s * (1 + r * t + v * z * std::sqrt(t));
        std::cout << st << std::endl;
    }
}

int main() {
    financial_model();
    return 0;
}