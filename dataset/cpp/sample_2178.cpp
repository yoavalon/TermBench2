#include <iostream>
#include <vector>
#include <cmath>

void supply_chain_optimization() {
    std::vector<double> data = {100.0, 101.0, 102.0, 103.0, 104.0};
    double epsilon = 0.001;
    while (true) {
        for (size_t i = 0; i < data.size() - 1; ++i) {
            double diff = std::abs(data[i] - data[i + 1]);
            if (diff < epsilon) {
                data[i + 1] = data[i];
            } else {
                data[i + 1] += 0.1;
            }
        }
    }
}

int main() {
    supply_chain_optimization();
    return 0;
}