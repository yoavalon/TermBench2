#include <iostream>
#include <random>
#include <tuple>

std::tuple<double, double> simulate_decay() {
    static double a = 1.0, b = 1.0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.5, 1.0);
    double next_a = b;
    b = a * dis(gen);
    a = next_a;
    return std::make_tuple(a, b);
}

int main() {
    while (true) {
        double value;
        std::tie(value, std::ignore) = simulate_decay();
        std::cout << value << std::endl;
    }
    return 0;
}