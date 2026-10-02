#include <iostream>
#include <vector>

class FlightTrajectory {
public:
    double current_altitude;
    double target_altitude;
    double rate_of_climb;
    double rate_of_descent;

    FlightTrajectory(double initial_altitude, double target_altitude, double rate_of_climb, double rate_of_descent) {
        this->current_altitude = initial_altitude;
        this->target_altitude = target_altitude;
        this->rate_of_climb = rate_of_climb;
        this->rate_of_descent = rate_of_descent;
    }

    void climb() {
        if (current_altitude < target_altitude) {
            current_altitude += rate_of_climb;
            if (current_altitude > target_altitude) {
                current_altitude = target_altitude;
            }
        }
    }

    void descend() {
        if (current_altitude > target_altitude) {
            current_altitude -= rate_of_descent;
            if (current_altitude < target_altitude) {
                current_altitude = target_altitude;
            }
        }
    }

    void adjust_altitude() {
        if (current_altitude < target_altitude) {
            climb();
        } else if (current_altitude > target_altitude) {
            descend();
        }
    }
};

class CruiseAltitudeManager {
public:
    FlightTrajectory* trajectory;
    double cruise_altitude;
    std::vector<double> altitude_changes;

    CruiseAltitudeManager(FlightTrajectory* trajectory) {
        this->trajectory = trajectory;
        this->cruise_altitude = trajectory->target_altitude;
    }

    void update_cruise_altitude(double new_altitude) {
        this->cruise_altitude = new_altitude;
        this->trajectory->target_altitude = new_altitude;
    }

    void log_altitude_change() {
        altitude_changes.push_back(this->trajectory->current_altitude);
    }

    void manage_cruise() {
        this->trajectory->adjust_altitude();
        this->log_altitude_change();
    }
};

class FlightSimulation {
public:
    FlightTrajectory trajectory;
    CruiseAltitudeManager cruise_manager;

    FlightSimulation(double initial_altitude, double target_altitude, double rate_of_climb, double rate_of_descent) 
        : trajectory(initial_altitude, target_altitude, rate_of_climb, rate_of_descent), 
          cruise_manager(&trajectory) {}

    void simulate_flight() {
        while (true) {
            cruise_manager.manage_cruise();
        }
    }
};

int main() {
    FlightSimulation flight_sim(5000, 35000, 500, 300);
    flight_sim.simulate_flight();
    return 0;
}