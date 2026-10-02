#include <iostream>
#include <vector>
#include <algorithm>

int calculate_altitude_change(int current_alt, int target_alt, int rate) {
    if (current_alt < target_alt) {
        return std::min(current_alt + rate, target_alt);
    } else {
        return std::max(current_alt - rate, target_alt);
    }
}

std::vector<int> simulate_flight_trajectory(int initial_alt, int target_alt, int rate, int steps) {
    int altitude = initial_alt;
    std::vector<int> trajectory = {altitude};
    for (int _ = 0; _ < steps; ++_) {
        altitude = calculate_altitude_change(altitude, target_alt, rate);
        trajectory.push_back(altitude);
        if (altitude == target_alt) {
            break;
        }
    }
    return trajectory;
}

int main() {
    int initial_altitude = 10000;
    int target_altitude = 30000;
    int rate_of_change = 1500;
    int simulation_steps = 100;
    std::vector<int> result = simulate_flight_trajectory(initial_altitude, target_altitude, rate_of_change, simulation_steps);
    for (int alt : result) {
        std::cout << alt << " ";
    }
    std::cout << std::endl;
    return 0;
}