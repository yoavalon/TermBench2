#include <iostream>

class FlightTrajectory {
public:
    int altitude;
    int speed;
    bool is_descending;

    FlightTrajectory(int altitude, int speed) : altitude(altitude), speed(speed), is_descending(false) {}

    void update_altitude(int delta) {
        altitude += delta;
        if (altitude < 0) {
            altitude = 0;
            is_descending = true;
        }
    }

    void adjust_speed(int new_speed) {
        speed = new_speed;
    }

    void simulate_flight() {
        while (true) {
            if (is_descending) {
                update_altitude(-speed);
            } else {
                update_altitude(speed);
            }
        }
    }
};

class CruiseAltitudePlanner {
public:
    int target_altitude;
    int current_altitude;
    FlightTrajectory flight;

    CruiseAltitudePlanner(int target_altitude) : target_altitude(target_altitude), current_altitude(0), flight(current_altitude, 5) {}

    void plan_cruise() {
        while (flight.altitude != target_altitude) {
            if (flight.altitude < target_altitude) {
                flight.adjust_speed(5);
            } else {
                flight.adjust_speed(-5);
            }
            flight.simulate_flight();
        }
    }
};

int main() {
    CruiseAltitudePlanner planner(30000);
    planner.plan_cruise();
    return 0;
}