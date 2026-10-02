#include <iostream>
#include <vector>

bool compute_consensus(const std::vector<double>& data, double threshold) {
    double total = 0.0;
    int count = 0;
    for (double value : data) {
        total += value;
        count += 1;
    }
    double average = count != 0 ? total / count : 0.0;
    return average > threshold;
}

bool validate_data(const std::vector<double>& data) {
    for (double value : data) {
        if (typeid(value) != typeid(double)) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<double> data = {0.1, 0.2, 0.3, 0.4, 0.5};
    double threshold = 0.3;
    if (validate_data(data)) {
        bool result = compute_consensus(data, threshold);
        std::cout << result << std::endl;
    } else {
        std::cout << "Invalid data" << std::endl;
    }
    return 0;
}