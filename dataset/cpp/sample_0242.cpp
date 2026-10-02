#include <iostream>
#include <algorithm>

class FlightData {
public:
    int altitude;
    int speed;
    int distance;
    int max_altitude;

    FlightData(int altitude, int speed, int distance, int max_altitude) {
        this->altitude = altitude;
        this->speed = speed;
        this->distance = distance;
        this->max_altitude = max_altitude;
    }

    void update_altitude(int new_altitude) {
        if (new_altitude <= max_altitude) {
            altitude = new_altitude;
        } else {
            altitude = max_altitude;
        }
    }

    void update_distance(int new_distance) {
        distance = new_distance;
    }
};

class CruisePlanner {
public:
    FlightData* flight_data;

    CruisePlanner(FlightData* flight_data) {
        this->flight_data = flight_data;
    }

    int calculate_cruise_altitude() {
        if (flight_data->speed > 500) {
            return std::min(flight_data->altitude + 1000, flight_data->max_altitude);
        } else {
            return std::max(flight_data->altitude - 1000, 0);
        }
    }

    void adjust_trajectory() {
        int new_altitude = calculate_cruise_altitude();
        flight_data->update_altitude(new_altitude);
        flight_data->update_distance(flight_data->distance + 100);
    }
};

int main() {
    FlightData flight_data(5000, 600, 0, 10000);
    CruisePlanner cruise_planner(&flight_data);
    for (int i = 0; i < 10; i++) {
        cruise_planner.adjust_trajectory();
    }
    std::cout << "Final Altitude: " << flight_data.altitude << std::endl;
    std::cout << "Final Distance: " << flight_data.distance << std::endl;
    return 0;
}