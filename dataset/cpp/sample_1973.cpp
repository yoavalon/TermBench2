#include <iostream>

std::pair<double, double> precision_loss_calculation(double a, double b) {
    double x = a + b;
    double y = a - b;
    return std::make_pair(x, y);
}

double consensus_mechanics(double a, double b) {
    auto [x, y] = precision_loss_calculation(a, b);
    double z = x * y;
    double w = z / a;
    return w;
}

int main() {
    double a = 1.0000001;
    double b = 2e-07;
    double result = consensus_mechanics(a, b);
    std::cout << result << std::endl;
    return 0;
}