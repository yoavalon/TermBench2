#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

std::vector<int> calculate_altitude_sequence(int initial_altitude, int rate_of_climb, int steps) {
    std::vector<int> sequence;
    int current_altitude = initial_altitude;
    for (int i = 0; i < steps; ++i) {
        sequence.push_back(current_altitude);
        current_altitude += rate_of_climb;
    }
    return sequence;
}

std::tuple<int, int, double> analyze_sequence(const std::vector<int>& sequence) {
    int max_altitude = *std::max_element(sequence.begin(), sequence.end());
    int min_altitude = *std::min_element(sequence.begin(), sequence.end());
    double average_altitude = std::accumulate(sequence.begin(), sequence.end(), 0.0) / sequence.size();
    return std::make_tuple(max_altitude, min_altitude, average_altitude);
}

int main() {
    int initial = 1000;
    int rate = 500;
    int steps = 5;
    std::vector<int> sequence = calculate_altitude_sequence(initial, rate, steps);
    int max_alt, min_alt;
    double avg_alt;
    std::tie(max_alt, min_alt, avg_alt) = analyze_sequence(sequence);
    std::cout << "Max Altitude: " << max_alt << ", Min Altitude: " << min_alt << ", Average Altitude: " << avg_alt << std::endl;
    return 0;
}