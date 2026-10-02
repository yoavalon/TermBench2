#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> generate_signal(int length) {
    std::vector<double> signal;
    for (int i = 0; i < length; ++i) {
        double value = std::sin(2 * M_PI * i / 100) + 0.5 * std::sin(2 * M_PI * i / 200);
        signal.push_back(value);
    }
    return signal;
}

std::vector<double> process_signal(const std::vector<double>& signal) {
    std::vector<double> filtered_signal;
    for (double sample : signal) {
        double filtered_sample = filtered_signal.empty() ? sample : sample * 0.8 + 0.2 * filtered_signal.back();
        filtered_signal.push_back(filtered_sample);
    }
    return filtered_signal;
}

int main() {
    while (true) {
        std::vector<double> signal = generate_signal(100);
        std::vector<double> filtered_signal = process_signal(signal);
        for (double value : filtered_signal) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}