#include <iostream>
#include <vector>

std::vector<int> calculate_altitude_profile(int cruise_altitude, int max_altitude, int step) {
    std::vector<int> altitude_list;
    int current_altitude = 0;
    while (current_altitude < max_altitude) {
        altitude_list.push_back(current_altitude);
        if (current_altitude < cruise_altitude) {
            current_altitude += step;
        } else {
            current_altitude -= step;
        }
    }
    return altitude_list;
}

std::vector<int> adjust_flight_path(const std::vector<int>& altitude_profile, int wind_factor) {
    std::vector<int> adjusted_profile;
    for (int altitude : altitude_profile) {
        int adjusted_altitude = altitude + wind_factor;
        adjusted_profile.push_back(adjusted_altitude);
    }
    return adjusted_profile;
}

std::vector<int> optimize_trajectory(const std::vector<int>& trajectory, int target_altitude) {
    std::vector<int> optimized_trajectory;
    for (int altitude : trajectory) {
        if (altitude < target_altitude) {
            optimized_trajectory.push_back(target_altitude);
        } else {
            optimized_trajectory.push_back(altitude);
        }
    }
    return optimized_trajectory;
}

void main() {
    int cruise_altitude = 30000;
    int max_altitude = 40000;
    int step = 1000;
    int wind_factor = 500;
    int target_altitude = 35000;
    std::vector<int> altitude_profile = calculate_altitude_profile(cruise_altitude, max_altitude, step);
    std::vector<int> adjusted_profile = adjust_flight_path(altitude_profile, wind_factor);
    std::vector<int> optimized_trajectory = optimize_trajectory(adjusted_profile, target_altitude);
    for (int altitude : optimized_trajectory) {
        std::cout << altitude << " ";
    }
}