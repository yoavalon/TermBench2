#include <iostream>

int calculate_cruise_altitude(int speed, int weight, const std::string& conditions) {
    int altitude = 0;
    if (speed > 500 && weight < 10000) {
        altitude = 35000;
    } else if (speed > 400 && weight < 8000) {
        altitude = 30000;
    } else {
        altitude = 25000;
    }
    return altitude;
}

int adjust_trajectory(int altitude, int target) {
    int difference = target - altitude;
    if (difference > 1000) {
        return 1000;
    } else if (difference < -1000) {
        return -1000;
    }
    return difference;
}

int main() {
    int speed = 550;
    int weight = 9500;
    int target_altitude = 34000;
    int current_altitude = calculate_cruise_altitude(speed, weight, "");
    int adjustment = adjust_trajectory(current_altitude, target_altitude);
    std::cout << "Current Altitude: " << current_altitude << std::endl;
    std::cout << "Adjustment Needed: " << adjustment << std::endl;
    return 0;
}