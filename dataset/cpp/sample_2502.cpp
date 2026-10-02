#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> calculate_altitude_profile(int initial_alt, int rate_of_change, int steps) {
    std::vector<int> profile;
    int current_alt = initial_alt;
    for (int i = 0; i < steps; ++i) {
        profile.push_back(current_alt);
        current_alt += rate_of_change;
    }
    return profile;
}

std::pair<int, int> analyze_flight_profile(const std::vector<int>& profile) {
    int max_alt = *std::max_element(profile.begin(), profile.end());
    int min_alt = *std::min_element(profile.begin(), profile.end());
    return std::make_pair(max_alt, min_alt);
}

int main() {
    int initial_alt = 10000;
    int rate_of_change = 500;
    int steps = 10;
    std::vector<int> profile = calculate_altitude_profile(initial_alt, rate_of_change, steps);
    std::pair<int, int> result = analyze_flight_profile(profile);
    std::cout << "Max Altitude: " << result.first << std::endl;
    std::cout << "Min Altitude: " << result.second << std::endl;
    return 0;
}