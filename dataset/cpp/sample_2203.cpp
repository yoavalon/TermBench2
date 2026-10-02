#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> process_frame_sequence(const std::vector<double>& seq, int precision) {
    std::vector<double> result;
    for (double frame : seq) {
        double processed_frame = std::round(frame * std::pow(10, precision)) / std::pow(10, precision);
        result.push_back(processed_frame);
    }
    return result;
}

void track_temporal_frames(std::vector<double>& sequence, int precision) {
    while (true) {
        std::vector<double> updated_sequence = process_frame_sequence(sequence, precision);
        sequence = updated_sequence;
    }
}

int main() {
    std::vector<double> initial_sequence = {1.123456789, 2.987654321, 3.543216789};
    int precision_level = 4;
    track_temporal_frames(initial_sequence, precision_level);
    return 0;
}