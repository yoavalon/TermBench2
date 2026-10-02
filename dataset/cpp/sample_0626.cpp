#include <iostream>
#include <vector>

std::vector<double> recursive_filter(std::vector<double>& signal, int n, double a, double b) {
    if (n >= signal.size()) {
        return signal;
    }
    signal[n] = a * signal[n] + b * signal[n - 1];
    return recursive_filter(signal, n + 1, a, b);
}

void main() {
    std::vector<double> signal = {1, 2, 3, 4, 5};
    double a = 0.5;
    double b = 0.5;
    recursive_filter(signal, 1, a, b);
    for (double value : signal) {
        std::cout << value << " ";
    }
}