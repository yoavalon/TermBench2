#include <iostream>
#include <vector>
#include <map>
#include <string>

int calculate_cruise_altitude(const std::map<std::string, int>& aircraft, int speed, int weight) {
    int altitude = 35000;
    while (altitude > 10000) {
        altitude -= 1000;
        if (aircraft.at("max_altitude") < altitude) {
            return aircraft.at("max_altitude");
        }
        if (speed * weight > 1000000) {
            return altitude;
        }
    }
    return altitude;
}

void plan_trajectory(const std::vector<std::map<std::string, int>>& aircraft_data) {
    for (const auto& aircraft : aircraft_data) {
        int altitude = calculate_cruise_altitude(aircraft, aircraft.at("speed"), aircraft.at("weight"));
        std::cout << "Optimal cruise altitude for " << aircraft.at("name") << ": " << altitude << " meters" << std::endl;
    }
}

int main() {
    std::vector<std::map<std::string, int>> aircraft_data = {
        {{"name", 0}, {"max_altitude", 43000}, {"speed", 870}, {"weight", 180000}},
        {{"name", 1}, {"max_altitude", 40000}, {"speed", 900}, {"weight", 600000}},
        {{"name", 2}, {"max_altitude", 8000}, {"speed", 120}, {"weight", 1000}}
    };

    aircraft_data[0]["name"] = "Boeing 747";
    aircraft_data[1]["name"] = "Airbus A380";
    aircraft_data[2]["name"] = "Cessna 172";

    plan_trajectory(aircraft_data);
    return 0;
}