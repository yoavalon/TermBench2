#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> calculate_altitude_sequence(int initial_altitude, int increment, int steps) {
    std::vector<int> sequence;
    for (int i = 0; i < steps; ++i) {
        sequence.push_back(initial_altitude + i * increment);
    }
    return sequence;
}

int find_optimal_cruise_altitude(const std::vector<int>& altitudes, int max_fuel_consumption) {
    auto it = std::find_if(altitudes.rbegin(), altitudes.rend(), [max_fuel_consumption](int x) {
        return x <= max_fuel_consumption;
    });
    return (it != altitudes.rend()) ? *it : 0;
}

int main() {
    int initial = 10000;
    int increment = 1000;
    int steps = 10;
    int max_fuel = 15000;
    std::vector<int> altitudes = calculate_altitude_sequence(initial, increment, steps);
    int optimal_altitude = find_optimal_cruise_altitude(altitudes, max_fuel);
    std::cout << optimal_altitude << std::endl;
    return 0;
}