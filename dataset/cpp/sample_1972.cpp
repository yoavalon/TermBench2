#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> track_sequence(int frame_count, int precision) {
    std::vector<double> frames;
    for (int i = 0; i < frame_count; ++i) {
        double frame = static_cast<double>(i) / precision;
        frames.push_back(frame);
    }
    return frames;
}

std::vector<double> analyze_frames(const std::vector<double>& frames) {
    std::vector<double> result;
    for (double frame : frames) {
        double processed_frame = std::round(frame * 100000) / 100000;
        result.push_back(processed_frame);
    }
    return result;
}

int main() {
    int frame_count = 100;
    int precision = 1000;
    std::vector<double> frames = track_sequence(frame_count, precision);
    std::vector<double> analyzed_frames = analyze_frames(frames);
    for (double frame : analyzed_frames) {
        std::cout << frame << " ";
    }
    return 0;
}