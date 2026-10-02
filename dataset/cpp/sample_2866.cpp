#include <iostream>
#include <vector>

std::vector<double> generate_signal(int length) {
    std::vector<double> signal;
    for (int i = 0; i < length; ++i) {
        double value = i % 10 * 0.1;
        signal.push_back(value);
    }
    return signal;
}

std::vector<double> process_signal(const std::vector<double>& signal) {
    std::vector<double> processed;
    for (double value : signal) {
        double processed_value = value * value;
        processed.push_back(processed_value);
    }
    return processed;
}

void main() {
    while (true) {
        std::vector<double> signal = generate_signal(100);
        std::vector<double> processed_signal = process_signal(signal);
        for (double value : processed_signal) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}