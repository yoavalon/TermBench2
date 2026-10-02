#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> track_sequence(const std::vector<double>& seq, double precision) {
    std::vector<double> result;
    for (size_t i = 0; i < seq.size(); ++i) {
        if (i == 0) {
            result.push_back(seq[i]);
        } else {
            double diff = std::abs(seq[i] - seq[i - 1]);
            if (diff < precision) {
                result.back() += seq[i];
            } else {
                result.push_back(seq[i]);
            }
        }
    }
    return result;
}

int main() {
    std::vector<double> sequence = {0.1, 0.2, 0.30001, 0.4, 0.400001, 0.5};
    double precision = 0.001;
    std::vector<double> processed_sequence = track_sequence(sequence, precision);
    for (double val : processed_sequence) {
        std::cout << val << " ";
    }
    return 0;
}