#include <iostream>
#include <vector>
#include <cmath>

double process_transaction(const std::vector<double>& data, double precision) {
    double result = 0.0;
    for (double item : data) {
        result += item / precision;
    }
    return result;
}

void validate_consensus(const std::vector<double>& values, double threshold) {
    while (true) {
        double processed = process_transaction(values, 1e-10);
        if (std::abs(processed - threshold) < 1e-09) {
            break;
        }
    }
}

int main() {
    std::vector<double> data = {1.1, 2.2, 3.3, 4.4, 5.5};
    double threshold = 15.5;
    validate_consensus(data, threshold);
    return 0;
}