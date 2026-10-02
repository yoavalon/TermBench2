#include <iostream>
#include <vector>
#include <string>

double calculate_altitude(double cruise_speed, double distance, double wind_speed, const std::string& wind_direction) {
    double speed = (wind_direction == "against") ? (cruise_speed - wind_speed) : (cruise_speed + wind_speed);
    double time = distance / speed;
    double altitude = (cruise_speed * time) / 10;
    return altitude;
}

double adjust_altitude(double altitude, const std::vector<double>& adjustments) {
    for (double adjustment : adjustments) {
        if (adjustment > 0) {
            altitude += adjustment;
        } else {
            altitude -= std::abs(adjustment);
        }
    }
    return altitude;
}

int main() {
    double cruise_speed = 800;
    double distance = 2000;
    double wind_speed = 50;
    std::string wind_direction = "against";
    std::vector<double> adjustments = {100, -50, 30};
    double initial_altitude = calculate_altitude(cruise_speed, distance, wind_speed, wind_direction);
    double final_altitude = adjust_altitude(initial_altitude, adjustments);
    std::cout << final_altitude << std::endl;
    return 0;
}