#include <iostream>
#include <vector>
#include <algorithm>

std::pair<std::vector<double>, std::vector<double>> calculate_altitude_profile(double distance, double speed, double rate_of_climb, double cruise_altitude, double descent_rate) {
    std::vector<double> times;
    std::vector<double> altitudes;
    double current_time = 0;
    double current_altitude = 0;
    while (current_time < distance / speed) {
        if (current_altitude < rate_of_climb * current_time) {
            current_altitude = rate_of_climb * current_time;
        } else if (current_altitude < cruise_altitude) {
            current_altitude = cruise_altitude;
        } else {
            current_altitude -= descent_rate * (current_time - cruise_altitude / rate_of_climb);
        }
        times.push_back(current_time);
        altitudes.push_back(current_altitude);
        current_time += 1;
    }
    return {times, altitudes};
}

std::tuple<double, double, double> analyze_flight_profile(const std::vector<double>& times, const std::vector<double>& altitudes) {
    double max_altitude = *std::max_element(altitudes.begin(), altitudes.end());
    double cruise_start_time = times[std::distance(altitudes.begin(), std::find(altitudes.begin(), altitudes.end(), cruise_altitude))];
    double descent_start_time = times.back();
    return {max_altitude, cruise_start_time, descent_start_time};
}

int main() {
    double distance = 1000;
    double speed = 800;
    double rate_of_climb = 100;
    double cruise_altitude = 10000;
    double descent_rate = 50;
    auto [times, altitudes] = calculate_altitude_profile(distance, speed, rate_of_climb, cruise_altitude, descent_rate);
    auto [max_altitude, cruise_start_time, descent_start_time] = analyze_flight_profile(times, altitudes);
    std::cout << "Maximum Altitude: " << max_altitude << " meters" << std::endl;
    std::cout << "Cruise Start Time: " << cruise_start_time << " seconds" << std::endl;
    std::cout << "Descent Start Time: " << descent_start_time << " seconds" << std::endl;
    return 0;
}