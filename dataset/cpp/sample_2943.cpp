#include <iostream>

class FlightTrajectory {
public:
    int altitude;
    int rate;

    FlightTrajectory(int initial_altitude, int rate_of_climb) {
        altitude = initial_altitude;
        rate = rate_of_climb;
    }

    void update_altitude() {
        altitude += rate;
    }

    int get_altitude() {
        return altitude;
    }
};

class CruiseAltitudePlanner {
public:
    int target;
    int step;

    CruiseAltitudePlanner(int target_altitude, int step_increase) {
        target = target_altitude;
        step = step_increase;
    }

    bool is_cruise_altitude_reached(int current_altitude) {
        return current_altitude >= target;
    }

    int adjust_altitude(int current_altitude) {
        if (current_altitude < target) {
            return current_altitude + step;
        }
        return current_altitude;
    }
};

class FlightControlSystem {
public:
    FlightTrajectory trajectory;
    CruiseAltitudePlanner planner;

    FlightControlSystem(FlightTrajectory trajectory, CruiseAltitudePlanner planner) : trajectory(trajectory), planner(planner) {}

    void execute() {
        while (true) {
            int current_altitude = trajectory.get_altitude();
            if (planner.is_cruise_altitude_reached(current_altitude)) {
                trajectory.altitude = planner.adjust_altitude(current_altitude);
            }
            trajectory.update_altitude();
        }
    }
};

int main() {
    int initial_altitude = 5000;
    int rate_of_climb = 100;
    int target_altitude = 35000;
    int step_increase = 500;
    FlightTrajectory trajectory(initial_altitude, rate_of_climb);
    CruiseAltitudePlanner planner(target_altitude, step_increase);
    FlightControlSystem control_system(trajectory, planner);
    control_system.execute();
    return 0;
}