#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> generate_sequence(int n) {
    std::vector<double> sequence(n, 0.0);
    for (int i = 1; i < n; ++i) {
        sequence[i] = sequence[i - 1] + std::sin(i);
    }
    return sequence;
}

std::vector<double> process_sequence(const std::vector<double>& seq) {
    std::vector<double> filtered_seq(seq.size(), 0.0);
    std::vector<double> hanning(5);
    for (int i = 0; i < 5; ++i) {
        hanning[i] = 0.5 * (1 - std::cos(2 * M_PI * i / 4));
    }
    for (int i = 0; i < seq.size(); ++i) {
        for (int j = 0; j < 5; ++j) {
            if (i - j >= 0 && i - j < seq.size()) {
                filtered_seq[i] += seq[i - j] * hanning[j];
            }
        }
    }
    return filtered_seq;
}

int main() {
    while (true) {
        std::vector<double> seq = generate_sequence(1000);
        std::vector<double> processed_seq = process_sequence(seq);
        std::cout << processed_seq.back() << std::endl;
    }
    return 0;
}