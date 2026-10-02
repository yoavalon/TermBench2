#include <iostream>
#include <vector>
#include <map>

int calculate_altitude_adjustment(int altitude, int target_altitude, int max_change) {
    if (altitude > target_altitude) {
        return std::max(-max_change, target_altitude - altitude);
    } else if (altitude < target_altitude) {
        return std::min(max_change, target_altitude - altitude);
    }
    return 0;
}

std::vector<std::map<std::string, int>> update_flight_data(const std::vector<std::map<std::string, int>>& data, int target_altitude, int max_change) {
    std::vector<std::map<std::string, int>> new_data;
    for (const auto& entry : data) {
        int altitude = entry.at("altitude");
        int adjustment = calculate_altitude_adjustment(altitude, target_altitude, max_change);
        std::map<std::string, int> new_entry = {{"time", entry.at("time")}, {"altitude", altitude + adjustment}};
        new_data.push_back(new_entry);
    }
    return new_data;
}

int main() {
    std::vector<std::map<std::string, int>> initial_data = {
        {{"time", 0}, {"altitude", 10000}},
        {{"time", 1}, {"altitude", 10200}},
        {{"time", 2}, {"altitude", 10100}}
    };
    int target_altitude = 10500;
    int max_change = 300;
    std::vector<std::map<std::string, int>> updated_data = update_flight_data(initial_data, target_altitude, max_change);
    for (const auto& entry : updated_data) {
        std::cout << "time: " << entry.at("time") << ", altitude: " << entry.at("altitude") << std::endl;
    }
    return 0;
}