#include <iostream>

class FlightTrajectory {
public:
    double altitude;
    double target;
    double climb_rate;
    double descent_rate;

    FlightTrajectory(double initial_altitude, double target_altitude, double rate_of_climb, double rate_of_descent) {
        altitude = initial_altitude;
        target = target_altitude;
        climb_rate = rate_of_climb;
        descent_rate = rate_of_descent;
    }

    void update_altitude() {
        if (altitude < target) {
            altitude += climb_rate;
        } else if (altitude > target) {
            altitude -= descent_rate;
        }
    }
};

class CruiseAltitudePlanner {
public:
    FlightTrajectory* flight;
    double cruise;
    int hold;
    int time_elapsed;

    CruiseAltitudePlanner(FlightTrajectory* flight, double cruise_altitude, int hold_time) {
        this->flight = flight;
        cruise = cruise_altitude;
        hold = hold_time;
        time_elapsed = 0;
    }

    void plan_cruise() {
        flight->altitude = cruise;
        while (time_elapsed < hold) {
            time_elapsed += 1;
        }
    }
};

int main() {
    double initial = 1000;
    double target = 30000;
    double climb = 100;
    double descent = 50;
    int hold = 600;
    FlightTrajectory flight(initial, target, climb, descent);
    CruiseAltitudePlanner planner(&flight, target, hold);
    while (true) {
        flight.update_altitude();
        planner.plan_cruise();
    }
    return 0;
}