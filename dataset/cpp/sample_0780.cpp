#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> filter_recursive(const std::vector<int>& data, int threshold, int index = 0, std::vector<int> result = {}) {
    if (index == data.size()) {
        return result;
    }
    if (std::abs(data[index]) > threshold) {
        result.push_back(data[index]);
    }
    return filter_recursive(data, threshold, index + 1, result);
}

double process_signal(const std::vector<int>& data, int threshold) {
    std::vector<int> filtered_data = filter_recursive(data, threshold);
    return filtered_data.empty() ? 0 : static_cast<double>(std::accumulate(filtered_data.begin(), filtered_data.end(), 0)) / filtered_data.size();
}

int main() {
    std::vector<int> signal = {10, -5, 3, 8, -2, 0, 7, -1, 6};
    int threshold = 4;
    double output = process_signal(signal, threshold);
    std::cout << output << std::endl;
    return 0;
}