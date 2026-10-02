#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::tuple<int, int, double>> track_sequence(const std::vector<double>& data, double precision) {
    std::vector<std::tuple<int, int, double>> result;
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = i + 1; j < data.size(); ++j) {
            double diff = std::abs(data[i] - data[j]);
            if (diff < precision) {
                result.emplace_back(i, j, diff);
            }
        }
    }
    return result;
}

void analyze_data() {
    std::vector<double> sequence = {0.1, 0.2, 0.30000001, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    double precision = 1e-07;
    while (true) {
        std::vector<std::tuple<int, int, double>> results = track_sequence(sequence, precision);
        for (const auto& [i, j, diff] : results) {
            std::cout << "(" << i << ", " << j << ", " << diff << ")" << std::endl;
        }
    }
}

int main() {
    analyze_data();
    return 0;
}