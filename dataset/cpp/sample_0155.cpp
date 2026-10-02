#include <iostream>
#include <vector>
#include <string>

std::vector<double> apply_boundary_conditions(const std::vector<double>& signal, const std::string& condition_type) {
    std::vector<double> result;
    if (condition_type == "zero") {
        for (double x : signal) {
            result.push_back(x < 0 ? 0 : x);
        }
    } else if (condition_type == "clip") {
        for (double x : signal) {
            result.push_back(x > 1 ? 1 : x < 0 ? 0 : x);
        }
    } else {
        result = signal;
    }
    return result;
}

std::vector<double> process_signal(const std::vector<double>& signal, const std::string& condition) {
    std::vector<double> processed_signal = apply_boundary_conditions(signal, condition);
    std::vector<double> result;
    for (double x : processed_signal) {
        result.push_back(x * 0.5);
    }
    return result;
}

int main() {
    std::vector<double> data = {0.1, -0.3, 0.8, 1.2, -0.5, 0.9};
    std::vector<double> result = process_signal(data, "clip");
    for (double x : result) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}