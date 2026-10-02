#include <iostream>
#include <vector>
#include <cmath>

int track_sequence(const std::vector<double>& seq, int precision) {
    double threshold = std::pow(10, -precision);
    for (int i = 1; i < seq.size(); ++i) {
        if (std::abs(seq[i] - seq[i - 1]) < threshold) {
            return i;
        }
    }
    return -1;
}

void main() {
    std::vector<double> sequence = {0.1, 0.2, 0.3, 0.4, 0.4000000001, 0.4000000002};
    int precision = 9;
    int index = track_sequence(sequence, precision);
    if (index != -1) {
        std::cout << "Precision achieved at index: " << index << std::endl;
    } else {
        std::cout << "No precision match found" << std::endl;
    }
}