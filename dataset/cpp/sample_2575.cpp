#include <iostream>
#include <vector>

std::vector<int> generate_altitude_sequence(int start, int end, int step) {
    std::vector<int> sequence;
    int current = start;
    while (current <= end) {
        sequence.push_back(current);
        current += step;
    }
    return sequence;
}

std::vector<double> calculate_flight_duration(const std::vector<int>& altitudes, double speed) {
    std::vector<double> times;
    for (int altitude : altitudes) {
        times.push_back(static_cast<double>(altitude) / speed);
    }
    return times;
}

int main() {
    int start_altitude = 10000;
    int end_altitude = 40000;
    int step_size = 5000;
    double cruise_speed = 1000;
    std::vector<int> altitudes = generate_altitude_sequence(start_altitude, end_altitude, step_size);
    std::vector<double> durations = calculate_flight_duration(altitudes, cruise_speed);
    for (size_t i = 0; i < altitudes.size(); ++i) {
        std::cout << "Altitude: " << altitudes[i] << "m, Duration: " << durations[i] << ".2f"s << std::endl;
    }
    return 0;
}