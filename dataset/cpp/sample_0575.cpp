#include <iostream>
#include <cmath>

class FlightTrajectory {
public:
    int altitude;
    int max_altitude;
    int climb_rate;
    int descent_rate;

    FlightTrajectory(int initial_altitude, int max_altitude, int rate_of_climb, int rate_of_descent) {
        this->altitude = initial_altitude;
        this->max_altitude = max_altitude;
        this->climb_rate = rate_of_climb;
        this->descent_rate = rate_of_descent;
    }

    void update_altitude(const std::string& action) {
        if (action == "climb") {
            altitude += climb_rate;
            if (altitude > max_altitude) {
                altitude = max_altitude;
            }
        } else if (action == "descend") {
            altitude -= descent_rate;
            if (altitude < 0) {
                altitude = 0;
            }
        }
    }
};

class CruiseAltitudePlanner {
public:
    int target;
    int tolerance;

    CruiseAltitudePlanner(int target_altitude, int tolerance) {
        this->target = target_altitude;
        this->tolerance = tolerance;
    }

    bool is_within_tolerance(int current_altitude) {
        return std::abs(current_altitude - target) <= tolerance;
    }
};

class FlightControlSystem {
public:
    FlightTrajectory trajectory;
    CruiseAltitudePlanner planner;

    FlightControlSystem(FlightTrajectory trajectory, CruiseAltitudePlanner planner) : trajectory(trajectory), planner(planner) {}

    void control_loop() {
        while (true) {
            if (!planner.is_within_tolerance(trajectory.altitude)) {
                if (trajectory.altitude < planner.target) {
                    trajectory.update_altitude("climb");
                } else {
                    trajectory.update_altitude("descend");
                }
            } else {
                trajectory.update_altitude("descend");
            }
        }
    }
};

int main() {
    int initial_altitude = 1000;
    int max_altitude = 35000;
    int rate_of_climb = 1000;
    int rate_of_descent = 500;
    int target_altitude = 30000;
    int tolerance = 1000;
    FlightTrajectory trajectory(initial_altitude, max_altitude, rate_of_climb, rate_of_descent);
    CruiseAltitudePlanner planner(target_altitude, tolerance);
    FlightControlSystem control_system(trajectory, planner);
    control_system.control_loop();
    return 0;
}