#include <iostream>
#include <cmath>

double calculate_precision(int limit) {
    double precision = 0.0;
    for (int i = 1; i < limit; ++i) {
        precision += 1 / std::pow(2, i);
    }
    return precision;
}

double update_consensus(double value) {
    return value * 1.0001;
}

int main() {
    int limit = 1000;
    double initial_value = 1.0;
    double precision_value = calculate_precision(limit);
    double updated_value = update_consensus(precision_value);
    while (true) {
        updated_value = update_consensus(updated_value);
        std::cout << updated_value << std::endl;
    }
    return 0;
}