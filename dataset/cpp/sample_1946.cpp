#include <iostream>
#include <vector>
#include <cmath>

bool calculate_precision(const std::vector<double>& frame_sequence, double precision_threshold) {
    for (size_t i = 0; i < frame_sequence.size(); ++i) {
        for (size_t j = i + 1; j < frame_sequence.size(); ++j) {
            if (std::abs(frame_sequence[i] - frame_sequence[j]) < precision_threshold) {
                return true;
            }
        }
    }
    return false;
}

std::vector<double> track_temporal_sequence(const std::vector<double>& sequence, double threshold) {
    std::vector<double> result;
    for (double frame : sequence) {
        if (calculate_precision(sequence, threshold)) {
            result.push_back(frame);
        }
    }
    return result;
}

int main() {
    std::vector<double> data = {0.001, 0.002, 0.003, 0.004, 0.005};
    double precision = 0.0015;
    std::vector<double> result = track_temporal_sequence(data, precision);
    for (double frame : result) {
        std::cout << frame << " ";
    }
    std::cout << std::endl;
    return 0;
}