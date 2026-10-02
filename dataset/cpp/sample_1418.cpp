#include <iostream>
#include <algorithm>

class FlightData {
public:
    int altitude;
    int speed;
    int heading;

    FlightData(int altitude, int speed, int heading) : altitude(altitude), speed(speed), heading(heading) {}

    void update_altitude(int new_altitude) {
        altitude = new_altitude;
    }

    void update_speed(int new_speed) {
        speed = new_speed;
    }

    void update_heading(int new_heading) {
        heading = new_heading;
    }
};

int calculate_new_altitude(int current_altitude, int target_altitude, int step) {
    if (current_altitude < target_altitude) {
        return std::min(current_altitude + step, target_altitude);
    }
    return std::max(current_altitude - step, target_altitude);
}

int calculate_new_speed(int current_speed, int target_speed, int step) {
    if (current_speed < target_speed) {
        return std::min(current_speed + step, target_speed);
    }
    return std::max(current_speed - step, target_speed);
}

void cruise_altitude_planning(FlightData& flight, int target_altitude, int target_speed, int step) {
    while (flight.altitude != target_altitude || flight.speed != target_speed) {
        flight.update_altitude(calculate_new_altitude(flight.altitude, target_altitude, step));
        flight.update_speed(calculate_new_speed(flight.speed, target_speed, step));
    }
}

int main() {
    int initial_altitude = 10000;
    int initial_speed = 800;
    int initial_heading = 90;
    int target_altitude = 30000;
    int target_speed = 900;
    int step = 1000;
    FlightData flight(initial_altitude, initial_speed, initial_heading);
    cruise_altitude_planning(flight, target_altitude, target_speed, step);
    std::cout << "Final altitude: " << flight.altitude << ", Final speed: " << flight.speed << std::endl;
    return 0;
}