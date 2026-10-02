#include <iostream>
#include <vector>
#include <cmath>

bool analyze_ast(const std::vector<double>& nodes, double precision = 1e-06) {
    for (double node : nodes) {
        if (std::abs(node - std::round(node * 1e6) / 1e6) < precision) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<double> data = {3.1415926535, 2.7182818284, 1.4142135623, 1.6180339887};
    bool result = analyze_ast(data);
    std::cout << result << std::endl;
    return 0;
}