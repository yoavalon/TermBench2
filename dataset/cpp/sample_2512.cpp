#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

std::vector<int> calculate_altitude_profile(int initial_altitude, int rate_of_change, int steps) {
    std::vector<int> altitude_profile;
    int current_altitude = initial_altitude;
    for (int i = 0; i < steps; ++i) {
        altitude_profile.push_back(current_altitude);
        current_altitude += rate_of_change;
    }
    return altitude_profile;
}

std::tuple<int, int, double> analyze_flight_data(const std::vector<int>& altitude_profile) {
    int max_altitude = *std::max_element(altitude_profile.begin(), altitude_profile.end());
    int min_altitude = *std::min_element(altitude_profile.begin(), altitude_profile.end());
    double average_altitude = std::accumulate(altitude_profile.begin(), altitude_profile.end(), 0.0) / altitude_profile.size();
    return std::make_tuple(max_altitude, min_altitude, average_altitude);
}

int main() {
    int initial_altitude = 30000;
    int rate_of_change = 500;
    int steps = 10;
    std::vector<int> altitude_profile = calculate_altitude_profile(initial_altitude, rate_of_change, steps);
    auto [max_altitude, min_altitude, average_altitude] = analyze_flight_data(altitude_profile);
    std::cout << max_altitude << " " << min_altitude << " " << average_altitude << std::endl;
    return 0;
}