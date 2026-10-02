#include <iostream>
#include <vector>

std::vector<int> apply_boundary_conditions(const std::vector<int>& signal, const std::string& boundary_type) {
    int length = signal.size();
    std::vector<int> result;
    if (boundary_type == "zero") {
        result.push_back(0);
        for (int value : signal) {
            result.push_back(value);
        }
        result.push_back(0);
    } else if (boundary_type == "repeat") {
        for (int value : signal) {
            result.push_back(value);
        }
        for (int value : signal) {
            result.push_back(value);
        }
    } else if (boundary_type == "mirror") {
        for (int value : signal) {
            result.push_back(value);
        }
        for (int i = length - 2; i >= 0; --i) {
            result.push_back(signal[i]);
        }
    }
    return result;
}

std::vector<std::vector<int>> process_signal(const std::vector<std::vector<int>>& data, const std::string& condition) {
    std::vector<std::vector<int>> processed;
    for (const auto& segment : data) {
        processed.push_back(apply_boundary_conditions(segment, condition));
    }
    return processed;
}

int main() {
    std::vector<std::vector<int>> data = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> result = process_signal(data, "mirror");
    for (const auto& item : result) {
        for (int value : item) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}