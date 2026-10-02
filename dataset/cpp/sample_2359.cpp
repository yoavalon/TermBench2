#include <iostream>

class FlightTrajectory {
public:
    FlightTrajectory(double initial_altitude, double target_altitude, double rate_of_climb, double descent_rate) 
        : a(initial_altitude), t(target_altitude), r(rate_of_climb), d(descent_rate), current_altitude(initial_altitude), is_ascent(true) {}

    void adjust_altitude() {
        if (is_ascent) {
            if (current_altitude < t) {
                current_altitude += r;
            } else {
                is_ascent = false;
            }
        } else if (current_altitude > t) {
            current_altitude -= d;
        }
    }

    double get_current_altitude() {
        return current_altitude;
    }

private:
    double a;
    double t;
    double r;
    double d;
    double current_altitude;
    bool is_ascent;
};

class CruiseAltitudePlanner {
public:
    CruiseAltitudePlanner(FlightTrajectory* trajectory) : trajectory(trajectory) {}

    void plan_cruise() {
        while (true) {
            trajectory->adjust_altitude();
            double current_altitude = trajectory->get_current_altitude();
            if (current_altitude == trajectory->t) {
                trajectory->is_ascent = true;
            }
        }
    }

private:
    FlightTrajectory* trajectory;
};

class FlightControlSystem {
public:
    FlightControlSystem(CruiseAltitudePlanner* planner) : planner(planner) {}

    void execute() {
        while (true) {
            planner->plan_cruise();
        }
    }

private:
    CruiseAltitudePlanner* planner;
};

int main() {
    double initial_altitude = 5000.0;
    double target_altitude = 35000.0;
    double rate_of_climb = 100.0;
    double descent_rate = 50.0;
    FlightTrajectory trajectory(initial_altitude, target_altitude, rate_of_climb, descent_rate);
    CruiseAltitudePlanner planner(&trajectory);
    FlightControlSystem control_system(&planner);
    control_system.execute();
    return 0;
}