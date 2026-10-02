#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> apply_boundary_conditions(const std::vector<int>& signal, const std::string& boundary_type) {
    if (boundary_type == "zero") {
        std::vector<int> padded_signal = signal;
        padded_signal.insert(padded_signal.end(), 10, 0);
        return padded_signal;
    } else if (boundary_type == "reflect") {
        std::vector<int> padded_signal = signal;
        for (int i = 0; i < 10; ++i) {
            padded_signal.push_back(signal[signal.size() - 1 - i]);
        }
        return padded_signal;
    } else if (boundary_type == "wrap") {
        std::vector<int> padded_signal = signal;
        for (int i = 0; i < 10; ++i) {
            padded_signal.push_back(signal[i % signal.size()]);
        }
        return padded_signal;
    } else {
        return signal;
    }
}

std::vector<int> process_signal(const std::vector<int>& signal) {
    std::string boundary_type = "reflect";
    std::vector<int> processed_signal = apply_boundary_conditions(signal, boundary_type);
    return processed_signal;
}

int main() {
    std::vector<int> signal = {1, 2, 3, 4, 5};
    std::vector<int> result = process_signal(signal);
    for (int value : result) {
        std::cout << value << " ";
    }
    return 0;
}