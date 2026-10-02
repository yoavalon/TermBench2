#include <iostream>

class Flight {
public:
    int altitude;
    int speed;
    int heading;

    Flight(int altitude, int speed, int heading) {
        this->altitude = altitude;
        this->speed = speed;
        this->heading = heading;
    }

    void update_altitude(int new_altitude) {
        this->altitude = new_altitude;
    }

    void update_speed(int new_speed) {
        this->speed = new_speed;
    }

    void update_heading(int new_heading) {
        this->heading = new_heading;
    }
};

void boundary_check(Flight& flight, int min_alt, int max_alt) {
    if (flight.altitude < min_alt) {
        flight.update_altitude(min_alt);
    } else if (flight.altitude > max_alt) {
        flight.update_altitude(max_alt);
    }
}

void cruise_control(Flight& flight, int target_speed) {
    if (flight.speed < target_speed) {
        flight.update_speed(flight.speed + 1);
    } else if (flight.speed > target_speed) {
        flight.update_speed(flight.speed - 1);
    }
}

void flight_simulation() {
    Flight flight(10000, 500, 90);
    int min_altitude = 5000;
    int max_altitude = 30000;
    int target_speed = 600;
    while (true) {
        boundary_check(flight, min_altitude, max_altitude);
        cruise_control(flight, target_speed);
    }
}

int main() {
    flight_simulation();
    return 0;
}