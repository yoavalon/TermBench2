#include <iostream>
#include <cmath>

class FlightTrajectory {
public:
    FlightTrajectory(int initial_altitude, int target_altitude, int step) {
        altitude = initial_altitude;
        target = target_altitude;
        this->step = step;
    }

    int adjust_altitude() {
        if (altitude < target) {
            altitude += step;
        } else {
            altitude -= step;
        }
        return altitude;
    }

private:
    int altitude;
    int target;
    int step;
};

class CruiseAltitudePlanner {
public:
    CruiseAltitudePlanner(FlightTrajectory trajectory) {
        this->trajectory = trajectory;
    }

    void plan_altitude() {
        while (true) {
            int new_altitude = trajectory.adjust_altitude();
            if (std::abs(new_altitude - trajectory.target) < trajectory.step) {
                break;
            }
        }
    }

private:
    FlightTrajectory trajectory;
};

class Simulation {
public:
    Simulation(CruiseAltitudePlanner planner) {
        this->planner = planner;
    }

    void run() {
        while (true) {
            planner.plan_altitude();
        }
    }

private:
    CruiseAltitudePlanner planner;
};

int main() {
    int initial = 10000;
    int target = 30000;
    int step = 1000;
    FlightTrajectory trajectory(initial, target, step);
    CruiseAltitudePlanner planner(trajectory);
    Simulation simulation(planner);
    simulation.run();
    return 0;
}