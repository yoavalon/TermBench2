#include <iostream>

class FlightPath {
public:
    FlightPath(int start_altitude, int target_altitude, int rate_of_climb) {
        altitude = start_altitude;
        this->target_altitude = target_altitude;
        this->rate_of_climb = rate_of_climb;
    }

    void climb() {
        altitude += rate_of_climb;
        if (altitude > target_altitude) {
            altitude = target_altitude;
        }
    }

    std::pair<int, int> get_status() {
        return {altitude, target_altitude};
    }

private:
    int altitude;
    int target_altitude;
    int rate_of_climb;
};

class CruiseAltitude {
public:
    CruiseAltitude(int altitude, int max_speed, int wind_speed) {
        this->altitude = altitude;
        this->max_speed = max_speed;
        this->wind_speed = wind_speed;
    }

    void adjust_speed() {
        max_speed = max_speed - wind_speed * 0.5;
    }

    int get_speed() {
        return max_speed;
    }

private:
    int altitude;
    int max_speed;
    int wind_speed;
};

int main() {
    FlightPath flight(1000, 35000, 100);
    CruiseAltitude cruise(35000, 800, 20);
    while (true) {
        flight.climb();
        cruise.adjust_speed();
        auto [current_alt, target_alt] = flight.get_status();
        int current_speed = cruise.get_speed();
        if (current_alt == target_alt) {
            std::cout << "Reached target altitude: " << current_alt << std::endl;
            std::cout << "Cruise speed adjusted to: " << current_speed << std::endl;
        } else {
            std::cout << "Current altitude: " << current_alt << ", Target altitude: " << target_alt << std::endl;
            std::cout << "Current speed: " << current_speed << std::endl;
        }
    }
    return 0;
}