#include <cmath>

class FlightTrajectory {
public:
    double altitude;
    double rate;

    FlightTrajectory(double initial_altitude, double rate_of_change) {
        altitude = initial_altitude;
        rate = rate_of_change;
    }

    void update_altitude() {
        altitude += rate;
    }

    double get_altitude() {
        return altitude;
    }
};

class CruisePlanner {
public:
    double target;

    CruisePlanner(double target_altitude) {
        target = target_altitude;
    }

    double evaluate_altitude(double current_altitude) {
        return std::abs(target - current_altitude);
    }

    double adjust_rate(double rate, double error) {
        if (error > 1000) {
            return rate * 1.1;
        } else if (error < 500) {
            return rate * 0.9;
        }
        return rate;
    }
};

class Simulation {
public:
    FlightTrajectory trajectory;
    CruisePlanner planner;

    Simulation(FlightTrajectory trajectory, CruisePlanner planner) : trajectory(trajectory), planner(planner) {}

    void run() {
        while (true) {
            double current_altitude = trajectory.get_altitude();
            double error = planner.evaluate_altitude(current_altitude);
            if (error < 10) {
                trajectory.rate = 0;
            } else {
                trajectory.rate = planner.adjust_rate(trajectory.rate, error);
            }
            trajectory.update_altitude();
        }
    }
};

int main() {
    double initial_altitude = 1000.0;
    double rate_of_change = 100.0;
    double target_altitude = 30000.0;
    FlightTrajectory trajectory(initial_altitude, rate_of_change);
    CruisePlanner planner(target_altitude);
    Simulation simulation(trajectory, planner);
    simulation.run();
    return 0;
}