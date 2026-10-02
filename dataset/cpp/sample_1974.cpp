#include <vector>
#include <cmath>
#include <iostream>

std::vector<int> track_sequence(const std::vector<double>& sequence, double precision) {
    std::vector<int> result;
    for (size_t i = 0; i < sequence.size() - 1; ++i) {
        double diff = std::abs(sequence[i] - sequence[i + 1]);
        if (diff < precision) {
            result.push_back(1);
        } else {
            result.push_back(0);
        }
    }
    return result;
}

double analyze_sequence(const std::vector<double>& sequence, double precision) {
    std::vector<int> tracked = track_sequence(sequence, precision);
    double stability = 0.0;
    for (int value : tracked) {
        stability += value;
    }
    stability /= tracked.size();
    return stability;
}

int main() {
    std::vector<double> sequence = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    double precision = 0.05;
    double stability = analyze_sequence(sequence, precision);
    std::cout << stability << std::endl;
    return 0;
}