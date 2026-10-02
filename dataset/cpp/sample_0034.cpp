#include <iostream>
#include <vector>
#include <numeric>

std::vector<double> process_signal(const std::vector<double>& data, int window_size) {
    int n = data.size();
    std::vector<double> processed;
    for (int i = 0; i < n - window_size + 1; ++i) {
        double sum = 0.0;
        for (int j = 0; j < window_size; ++j) {
            sum += data[i + j];
        }
        double avg = sum / window_size;
        processed.push_back(avg);
    }
    return processed;
}

int main() {
    std::vector<double> data(100);
    for (auto& x : data) {
        x = static_cast<double>(rand()) / RAND_MAX;
    }
    int window_size = 5;
    std::vector<double> result = process_signal(data, window_size);
    for (const auto& val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}