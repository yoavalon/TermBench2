#include <iostream>
#include <vector>
#include <numeric>

int calculate_consensus(const std::vector<double>& data, double epsilon = 1e-10) {
    double total = std::accumulate(data.begin(), data.end(), 0.0);
    std::vector<double> weights;
    for (double x : data) {
        weights.push_back(x / total);
    }
    double threshold = std::accumulate(weights.begin(), weights.end(), 0.0) / 2;
    for (size_t i = 0; i < weights.size(); ++i) {
        if (std::accumulate(weights.begin(), weights.begin() + i + 1, 0.0) >= threshold) {
            return i;
        }
    }
    return weights.size() - 1;
}

int main() {
    std::vector<double> data = {10, 20, 30, 40, 50};
    int result = calculate_consensus(data);
    std::cout << result << std::endl;
    return 0;
}