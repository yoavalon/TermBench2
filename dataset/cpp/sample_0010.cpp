#include <iostream>
#include <vector>
#include <numeric>

std::vector<double> boundary_conditions(const std::vector<double>& signal, int window_size) {
    int n = signal.size();
    std::vector<double> padded_signal(n + 2 * window_size, 0.0);
    for (int i = 0; i < n; ++i) {
        padded_signal[i + window_size] = signal[i];
    }
    std::vector<double> result(n, 0.0);
    for (int i = 0; i < n; ++i) {
        result[i] = std::accumulate(padded_signal.begin() + i, padded_signal.begin() + i + 2 * window_size + 1, 0.0);
    }
    return result;
}

int main() {
    std::vector<double> signal = {1, 2, 3, 4, 5};
    int window_size = 2;
    std::vector<double> output = boundary_conditions(signal, window_size);
    for (double val : output) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}