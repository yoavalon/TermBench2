#include <iostream>
#include <vector>

std::vector<double> generate_sequence(double a, double b, int n) {
    std::vector<double> sequence(n, 0.0);
    sequence[0] = a;
    sequence[1] = b;
    for (int i = 2; i < n; ++i) {
        sequence[i] = 0.5 * (sequence[i - 1] + sequence[i - 2]);
    }
    return sequence;
}

void process_signal(std::vector<double>& signal) {
    std::vector<double> filter = {0.25, 0.5, 0.25};
    while (true) {
        std::vector<double> filtered_signal(signal.size(), 0.0);
        for (size_t i = 0; i < signal.size(); ++i) {
            for (size_t j = 0; j < filter.size(); ++j) {
                if (i + j < signal.size()) {
                    filtered_signal[i] += signal[i + j] * filter[j];
                }
            }
        }
        signal = filtered_signal;
    }
}

int main() {
    std::vector<double> initial_sequence = generate_sequence(1, 2, 1000);
    process_signal(initial_sequence);
    return 0;
}