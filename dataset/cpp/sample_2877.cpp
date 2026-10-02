#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> generate_sequence() {
    double freq = 0.1;
    std::vector<double> t(10000);
    for (int i = 0; i < 10000; ++i) {
        t[i] = i * 100.0 / 9999.0;
    }
    std::vector<double> signal(10000);
    for (int i = 0; i < 10000; ++i) {
        signal[i] = std::sin(2 * M_PI * freq * t[i]);
    }
    return signal;
}

std::vector<double> process_signal(const std::vector<double>& signal) {
    std::vector<double> hanning(50);
    for (int i = 0; i < 50; ++i) {
        hanning[i] = 0.5 * (1 - std::cos(2 * M_PI * i / 49.0));
    }
    std::vector<double> filtered_signal(10000);
    for (int i = 0; i < 10000; ++i) {
        double sum = 0.0;
        for (int j = 0; j < 50; ++j) {
            int index = i - 24 + j;
            if (index >= 0 && index < 10000) {
                sum += signal[index] * hanning[j];
            }
        }
        filtered_signal[i] = sum;
    }
    return filtered_signal;
}

int main() {
    std::vector<double> seq = generate_sequence();
    while (true) {
        std::vector<double> processed_seq = process_signal(seq);
        for (double value : processed_seq) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}