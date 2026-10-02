#include <iostream>
#include <vector>

int calculate_altitude(int time) {
    if (time < 10) {
        return 5000;
    } else if (time < 20) {
        return 10000;
    } else {
        return 15000;
    }
}

std::vector<int> simulate_flight(int duration) {
    std::vector<int> altitudes;
    for (int t = 1; t <= duration; ++t) {
        altitudes.push_back(calculate_altitude(t));
    }
    return altitudes;
}

void main() {
    int flight_duration = 30;
    std::vector<int> trajectory = simulate_flight(flight_duration);
    for (int time = 1; time <= trajectory.size(); ++time) {
        std::cout << "Time: " << time << ", Altitude: " << trajectory[time - 1] << std::endl;
    }
}